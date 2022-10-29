#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int m[100][100];
int main()
{
	int mx, my;
	scanf("%d%d", &mx, &my);
	int sx, sy, gx, gy;
	for (int i = 1; i <= mx; i++)
	{
		for (int j = 1; j <= my; j++)
		{
			char z;
			scanf(" %c", &z);
			if (z != '#')m[i][j] = 1;
			if (z == 'S')sx = i, sy = j;
			if (z == 'E')gx = i, gy = j;
		}
	}
	string s;
	cin >> s;
	int d[4];
	for (int i = 0; i < 4; i++)d[i] = i;
	int r = 0;
	for (int p = 0; p < 24; p++)
	{
		int nx = sx, ny = sy;
		for (int i = 0; i < s.size(); i++)
		{
			nx = nx + dx[d[s[i] - '0']], ny = ny + dy[d[s[i] - '0']];
			if (m[nx][ny] == 0)break;
			if (nx == gx&&ny == gy)
			{
				r++;
				break;
			}
		}
		next_permutation(d, d + 4);
	}
	printf("%d\n", r);
}