#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 1000000000
int dp[4001][140][70][2];
int dat[4000];
int rui[4001];
int num;
int calc(int lb, int ub, int now, int t)
{
	if (ub - lb + 1 < now)return 0;
	int zt = (num - ub) - lb + 70;
	if (dp[lb][zt][now][t] != INF)return dp[lb][zt][now][t];
	if (ub - lb + 1 == now)
	{
		if (t == 0)return dp[lb][zt][now][t] = rui[ub + 1] - rui[lb];
		else return dp[lb][zt][now][t] = -rui[ub + 1] + rui[lb];
	}
	if (t == 0)
	{
		return dp[lb][zt][now][t] = max(calc(lb + now, ub, now, 1) + rui[lb + now] - rui[lb], calc(lb + now + 1, ub, now + 1, 1) + rui[lb + now + 1] - rui[lb]);
	}
	else
	{
		return dp[lb][zt][now][t] = min(calc(lb, ub - now, now, 0) - rui[ub + 1] + rui[ub + 1 - now], calc(lb, ub - now - 1, now + 1, 0) - rui[ub + 1] + rui[ub - now]);
	}
}
int main()
{
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%d", &dat[i]);
	for (int i = 0; i < num; i++)rui[i + 1] = rui[i] + dat[i];
	for (int i = 0; i <= 4000; i++)for (int j = 0; j < 140; j++)for (int k = 0; k < 70; k++)for (int l = 0; l < 2; l++)dp[i][j][k][l] = INF;
	printf("%d\n", calc(0, num - 1, 1, 0));
}