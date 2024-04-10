#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

char c[5][5];
int c1, c2;

int main(){
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++){
			cin >> c[i][j];
			if (c[i][j] == '0')	c[i][j] = 'O';
			if (c[i][j] == 'X')	
				c1++;
			if (c[i][j] == 'O')
				c2++;
		}	
	if (c2 > c1 || c1 - 1 > c2){
		cout << "illegal\n";
		return 0;
	}

	char turn;
	if (c1 == c2)
		turn = 'X';
	else
		turn = 'O';

	bool wx = false, wo = false;
	if (c[0][0] == c[0][1] && c[0][1] == c[0][2]){
		if (c[0][0] == 'X')	wx = 1;
		else if (c[0][0] == 'O')	wo = 1;
	}
	if (c[1][0] == c[1][1] && c[1][1] == c[1][2]){
		if (c[1][0] == 'X')	wx = 1;
		else if(c[1][0] == 'O')	wo = 1;
	}
	if (c[2][0] == c[2][1] && c[2][1] == c[2][2]){
		if (c[2][0] == 'X')	wx = 1;
		else if(c[2][0] == 'O')	wo = 1;
	}
	if (c[0][0] == c[1][0] && c[1][0] == c[2][0]){
		if (c[0][0] == 'X')	wx = 1;
		else if(c[0][0] == 'O')	wo = 1;
	}
	if (c[0][1] == c[1][1] && c[1][1] == c[2][1]){
		if (c[0][1] == 'X')	wx = 1;
		else if (c[0][1] == 'O')	wo = 1;
	}
	if (c[0][2] == c[1][2] && c[1][2] == c[2][2]){
		if (c[0][2] == 'X')	wx = 1;
		else if (c[0][2] == 'O')	wo = 1;
	}
	if (c[0][0] == c[1][1] && c[1][1] == c[2][2]){
		if (c[0][0] == 'X')	wx = 1;
		else if (c[0][0] == 'O')	wo = 1;
	}
	if (c[0][2] == c[1][1] && c[1][1] == c[2][0]){
		if (c[0][2] == 'X')	wx = 1;
		else if (c[0][2] == 'O')	wo = 1;
	}


	if (wx && wo){
		cout << "illegal\n";
		return 0;
	}

	if (c1 + c2 == 9 && wx == 0 && wo == 0){//draw
		cout << "draw\n";
		return 0;
	}
	if ((turn == 'X' && wx) || (turn == 'O' && wo)){
		cout << "illegal\n";
		return 0;
	}


	if (wx == 0 && wo == 0){
		if (turn == 'X')
			cout << "first\n";
		else
			cout << "second\n";
		return 0;
	}

	bool fl = 1;
	if (wx){
		wx = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (c[i][j] == 'X'){
					c[i][j] = '.';
					wx = 0;
					if (c[0][0] == c[0][1] && c[0][1] == c[0][2]){
						if (c[0][0] == 'X')	wx = 1;
						else if (c[0][0] == 'O')	wo = 1;
					}
					if (c[1][0] == c[1][1] && c[1][1] == c[1][2]){
						if (c[1][0] == 'X')	wx = 1;
						else if(c[1][0] == 'O')	wo = 1;
					}
					if (c[2][0] == c[2][1] && c[2][1] == c[2][2]){
						if (c[2][0] == 'X')	wx = 1;
						else if(c[2][0] == 'O')	wo = 1;
					}
					if (c[0][0] == c[1][0] && c[1][0] == c[2][0]){
						if (c[0][0] == 'X')	wx = 1;
						else if(c[0][0] == 'O')	wo = 1;
					}
					if (c[0][1] == c[1][1] && c[1][1] == c[2][1]){
						if (c[0][1] == 'X')	wx = 1;
						else if (c[0][1] == 'O')	wo = 1;
					}
					if (c[0][2] == c[1][2] && c[1][2] == c[2][2]){
						if (c[0][2] == 'X')	wx = 1;
						else if (c[0][2] == 'O')	wo = 1;
					}
					if (c[0][0] == c[1][1] && c[1][1] == c[2][2]){
						if (c[0][0] == 'X')	wx = 1;
						else if (c[0][0] == 'O')	wo = 1;
					}
					if (c[0][2] == c[1][1] && c[1][1] == c[2][0]){
						if (c[0][2] == 'X')	wx = 1;
						else if (c[0][2] == 'O')	wo = 1;
					}

					if (wx == 0){
						cout << "the first player won\n";
						return 0;
					}
					c[i][j] = 'X';
				}
	}
	if (wo){
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (c[i][j] == 'O'){
					c[i][j] = '.';
					wo = 0;
					if (c[0][0] == c[0][1] && c[0][1] == c[0][2]){
						if (c[0][0] == 'X')	wx = 1;
						else if (c[0][0] == 'O')	wo = 1;
					}
					if (c[1][0] == c[1][1] && c[1][1] == c[1][2]){
						if (c[1][0] == 'X')	wx = 1;
						else if(c[1][0] == 'O')	wo = 1;
					}
					if (c[2][0] == c[2][1] && c[2][1] == c[2][2]){
						if (c[2][0] == 'X')	wx = 1;
						else if(c[2][0] == 'O')	wo = 1;
					}
					if (c[0][0] == c[1][0] && c[1][0] == c[2][0]){
						if (c[0][0] == 'X')	wx = 1;
						else if(c[0][0] == 'O')	wo = 1;
					}
					if (c[0][1] == c[1][1] && c[1][1] == c[2][1]){
						if (c[0][1] == 'X')	wx = 1;
						else if (c[0][1] == 'O')	wo = 1;
					}
					if (c[0][2] == c[1][2] && c[1][2] == c[2][2]){
						if (c[0][2] == 'X')	wx = 1;
						else if (c[0][2] == 'O')	wo = 1;
					}
					if (c[0][0] == c[1][1] && c[1][1] == c[2][2]){
						if (c[0][0] == 'X')	wx = 1;
						else if (c[0][0] == 'O')	wo = 1;
					}
					if (c[0][2] == c[1][1] && c[1][1] == c[2][0]){
						if (c[0][2] == 'X')	wx = 1;
						else if (c[0][2] == 'O')	wo = 1;
					}
					if (wo == 0){
						cout << "the second player won\n";
						return 0;
					}
					c[i][j] = 'O';
				}
	}
	cout << "illegal\n";
	return 0;
}