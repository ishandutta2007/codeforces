#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <limits>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

bool a[100][100][100];

int xc, yc, zc;

bool at(int x, int y, int z)
{
	if (x < 0 || x >= xc)
		return 0;
	if (y < 0 || y >= yc)
		return 0;
	if (z < 0 || z >= zc)
		return 0;
	return a[x][y][z];
}

int check(int x, int y, int z)
{
	if (!at(x, y, z))
		return 0;
	if (at(x + 1, y, z))
	{
		if (at(x - 1, y, z))
			return 1;
		if (at(x, y - 1, z) && !at(x + 1, y - 1, z))
			return 1;
		if (at(x, y, z - 1) && !at(x + 1, y, z - 1))
			return 1;
	}
	if (at(x, y + 1, z))
	{
		if (at(x, y - 1, z))
			return 1;
		if (at(x - 1, y, z) && !at(x - 1, y + 1, z))
			return 1;
		if (at(x, y, z - 1) && !at(x, y + 1, z - 1))
			return 1;
	}
	if (at(x, y, z + 1))
	{
		if (at(x, y, z - 1))
			return 1;
		if (at(x - 1, y, z) && !at(x - 1, y, z + 1))
			return 1;
		if (at(x, y - 1, z) && !at(x, y - 1, z + 1))
			return 1;
	}
	return 0;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> xc >> yc >> zc;
	string s;
	for (int i = 0; i < xc; i++)
	{
		for (int j = 0; j < yc; j++)
		{
			cin >> s;
			for (int k = 0; k < zc; k++)
				a[i][j][k] = (s[k] == '1');
		}
	}
	int ans = 0;
	for (int i = 0; i < xc; i++)
		for (int j = 0; j < yc; j++)
			for (int k = 0; k < zc; k++)
			{
				ans += check(i, j, k);
			}
	cout << ans;
}