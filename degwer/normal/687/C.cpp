#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
bool dp[2][501][501];
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	vector<int>v;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		v.push_back(z);
	}
	for (int i = 0; i <= gen; i++)for (int j = 0; j <= gen; j++)dp[0][i][j] = dp[1][i][j] = false;
	int cur = 0;
	dp[0][0][0] = true;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j <= gen; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				if (!dp[cur][j][k])continue;
				if (j + v[i] <= gen)
				{
					dp[1 - cur][j + v[i]][k + v[i]] = true;
					dp[1 - cur][j + v[i]][k] = true;
				}
				dp[1 - cur][j][k] = true;
			}
		}
		for (int j = 0; j <= gen; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[cur][j][k] = false;
			}
		}
		cur ^= 1;
	}
	vector<int>ans;
	for (int i = 0; i <= gen; i++)if (dp[cur][gen][i])ans.push_back(i);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
	{
		if (i != 0)printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}