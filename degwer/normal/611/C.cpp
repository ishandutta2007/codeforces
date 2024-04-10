#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int map[502][502];
int rx[503][503];
int ry[503][503];
int main()
{
	int mx, my;
	scanf("%d%d", &mx, &my);
	for (int i = 0; i < 502; i++)for (int j = 0; j < 502; j++)map[i][j] = 1;
	for (int i = 0; i < mx; i++)
	{
		for (int j = 0; j < my; j++)
		{
			char z;
			scanf(" %c", &z);
			if (z == '.')map[i+1][j+1] = 0;
		}
	}
	for (int i = 0; i <= mx + 1; i++)
	{
		for (int j = 1; j <= my + 1; j++)
		{
			if (map[i][j - 1] == 0 && map[i][j] == 0)rx[i][j] = rx[i][j - 1] + 1;
			else rx[i][j] = rx[i][j - 1];
		}
	}
	for (int i = 0; i <= my + 1; i++)
	{
		for (int j = 1; j <= mx + 1; j++)
		{
			if (map[j - 1][i] == 0 && map[j][i] == 0)ry[j][i] = ry[j - 1][i] + 1;
			else ry[j][i] = ry[j - 1][i];
		}
	}
	int query;
	scanf("%d", &query);
	for (int i = 0; i < query; i++)
	{
		int lx, ly, ux, uy;
		scanf("%d%d%d%d", &lx, &ly, &ux, &uy);
		int cnt = 0;
		for (int i = lx; i <= ux; i++)cnt += rx[i][uy] - rx[i][ly];
		for (int i = ly; i <= uy; i++)cnt += ry[ux][i] - ry[lx][i];
		printf("%d\n", cnt);
	}
}