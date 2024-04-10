#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
char c[4][4];

bool isWinner()
{
	for (int i = 0; i < 4; ++i)
	{
		if (c[i][0] == c[i][1] && c[i][0] == c[i][2] && c[i][0] != '.') return true;
		if (c[i][1] == c[i][2] && c[i][1] == c[i][3] && c[i][1] != '.') return true;
		if (c[0][i] == c[1][i] && c[0][i] == c[2][i] && c[0][i] != '.') return true;
		if (c[3][i] == c[1][i] && c[3][i] == c[2][i] && c[3][i] != '.') return true;
	}

	if (c[0][1] == c[1][2] && c[0][1] == c[2][3] && c[0][1] != '.') return true;
	if (c[1][0] == c[2][1] && c[1][0] == c[3][2] && c[1][0] != '.') return true;

	if (c[0][0] == c[1][1] && c[0][0] == c[2][2] && c[0][0] != '.') return true;
	if (c[1][1] == c[2][2] && c[1][1] == c[3][3] && c[1][1] != '.') return true;
	//

	if (c[0][2] == c[1][1] && c[0][2] == c[2][0] && c[0][2] != '.') return true;
	if (c[3][1] == c[2][2] && c[3][1] == c[1][3] && c[3][1] != '.') return true;

	if (c[0][3] == c[1][2] && c[0][3] == c[2][1] && c[0][3] != '.') return true;
	if (c[1][2] == c[2][1] && c[1][2] == c[3][0] && c[1][2] != '.') return true;
	


	return false;
}

int main()
{
	
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			cin >> c[i][j];

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (c[i][j] == '.')
			{
				c[i][j] = 'x';
				if (isWinner())
				{
					cout << "YES";
					return 0;
				}
				else
					c[i][j] = '.';
			}
		}
	}

	cout << "NO";
	return 0;
}