#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	
	int num4 = s.length() / 4;
	int numR = 0;
	int numB = 0;
	int numY = 0;
	int numG = 0;

	for (int i = 0; i < num4 * 4; ++i)
	{
		if (s[i] == 'R') numR++;
		if (s[i] == 'B') numB++;
		if (s[i] == 'Y') numY++;
		if (s[i] == 'G') numG++;
	}

	int r = num4 - numR;
	int b = num4 - numB;
	int y = num4 - numY;
	int g = num4 - numG;

	int zalyshok = s.length() - 4 * num4;
	
	if (zalyshok > 0)
	{
		for (int i = 0; i < num4 * 4; ++i)
		{
			if (i % 4 == 0 && s[i] != '!' && s[num4 * 4] == '!')
			{
				if (s[i] == 'R') r++;
				if (s[i] == 'B') b++;
				if (s[i] == 'Y') y++;
				if (s[i] == 'G') g++;
				break;
			}
		}
	}
	if (zalyshok > 1)
	{
		for (int i = 0; i < num4 * 4; ++i)
		{

			if (i % 4 == 1 && s[i] != '!' && s[num4 * 4 + 1] == '!')
			{
				if (s[i] == 'R') r++;
				if (s[i] == 'B') b++;
				if (s[i] == 'Y') y++;
				if (s[i] == 'G') g++;
				break;
			}
		}
	}
	if (zalyshok > 2)
	{
		for (int i = 0; i < num4 * 4; ++i)
		{
			if (i % 4 == 2 && s[i] != '!' && s[num4 * 4 + 2] == '!')
			{
				if (s[i] == 'R') r++;
				if (s[i] == 'B') b++;
				if (s[i] == 'Y') y++;
				if (s[i] == 'G') g++;
				break;
			}
		}
	}
		

	cout << r << " " << b << " " << y << " " << g;
	return 0;
}