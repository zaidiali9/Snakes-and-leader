#include<iostream>
#include<queue>
#include<time.h>
#include<conio.h>
using namespace std;
class Player {
	string name;
	int score;
	bool winflag;
public:
	Player();
	void setname();
	string getname();
	void editscore(int sc);
	int getscore();
	void if_snake();
	void if_ledder();
	void if_score();
	bool win_flag();
};
Player::Player()	{
	this->name = "";
	this->score = 0;
	this->winflag = false;
}
void Player::setname()	{
	cout << "Enter the Player Name" << endl;
	cin >> this->name;
}

string Player::getname()	{
	return this->name;
}

void Player::editscore(int sc)	{
	if (this->score + sc > 100)	{
		return;
	}
	else {
		this->score = this->score + sc;
		if_snake();
		if_ledder();
		if_score();
	}
}

int Player::getscore()	{
	return this->score;
}

void Player::if_snake()	{	
	if (this->score == 50)	{
		this->score = 40;
	}
	else if (this->score == 90)	{
		this->score = 79;
	}
}

void Player::if_ledder()	{
	
	if (this->score == 20)	{
		this->score = 40;
	
	}
	else if (this->score == 60)	{
		this->score = 75;
	}
}

void Player::if_score()	{
	if (score == 100)
		winflag = 1;
	else
		winflag = 0;
}
bool Player::win_flag()	{
	return this->winflag;
}
bool nflag(queue<Player>players)	{
	queue<Player>temp = players;
	bool flag = false;
	int count = 0;
	for (int i = 0;i < temp.size();i++)	{
		if (temp.front().win_flag())	{
			temp.push(temp.front());
			temp.pop();
			count++;
		}
	}
	if (count == (temp.size() - 1))	{
		return true;
	}
	else {
		return false;
	}
}
int main()	{
	srand(time(0));
	int dice = 0;
	queue<Player>players;
	Player temp;
	int no_players = 0;
	cout << "Enter the number of the Players" << endl;
	cin >> no_players;
	Player* player_sr = new Player[no_players];
	for (int i = 0;i < no_players;i++)	{
		player_sr[i].setname();
		players.push(player_sr[i]);
	}
	bool game_over = true;
	int idx_p = 0;
	while (game_over)	{
		dice = rand() % 6 + 1;
		players.front().editscore(dice);
		cout << endl;
		cout << "Name: " << players.front().getname() << " Score: " << players.front().getscore();
		cout << endl;
		players.push(players.front());
		players.pop();
		if (nflag(players))	{
			game_over = false;
		}
	}
}
