#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
int ans[4001][4001];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
void dfs(int x, int y)
{
	int t = ans[x][y] / 4;
	ans[x][y] %= 4;
	for (int i = 0; i < 4; i++)ans[x + dx[i]][y + dy[i]] += t;
	for (int i = 0; i < 4; i++)if (ans[x + dx[i]][y + dy[i]] >= 4)dfs(x + dx[i], y + dy[i]);
}
int main()
{
	int num, query;
	scanf("%d%d", &num, &query);
	ans[2000][2000] = num;
	dfs(2000, 2000);
	for (int p = 0; p < query; p++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		if (abs(za) > 2000 || abs(zb)>2000)printf("0\n");
		else printf("%d\n", ans[za + 2000][zb + 2000]);
	}
}