#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int map[1000][1000][4];
int main()
{
	int mx, my;
	scanf("%d%d", &mx, &my);
	int cnt = 0;
	for (int i = 0; i < mx; i++)
	{
		for (int j = 0; j < my; j++)
		{
			scanf("%d", &map[i][j][0]);
			map[i][j][1] = map[i][j][2] = map[i][j][3] = map[i][j][0];
			cnt += map[i][j][0];
		}
	}
	for (int i = 0; i < mx; i++)for (int j = 1; j < my; j++)map[i][j][0] |= map[i][j - 1][0];
	for (int i = 0; i < mx; i++)for (int j = my - 2; j >= 0; j--)map[i][j][1] |= map[i][j + 1][1];
	for (int i = 1; i < mx; i++)for (int j = 0; j < my; j++)map[i][j][2] |= map[i - 1][j][2];
	for (int i = mx - 2; i >= 0; i--)for (int j = 0; j < my; j++)map[i][j][3] |= map[i + 1][j][3];
	int r = 0;
	for (int i = 0; i < mx; i++)for (int j = 0; j < my; j++)for (int k = 0; k < 4; k++)r += map[i][j][k];
	printf("%d\n", r - cnt * 4);
}