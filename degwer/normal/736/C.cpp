#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pat[100];
vector<int>ko[100];
typedef long long ll;
ll mod = 1000000007;
ll dp[100][22][21];
int num, gen;
bool flag[100];
void dfs(int node)
{
	flag[node] = true;
	for (int i = 0; i < pat[node].size(); i++)
	{
		if (!flag[pat[node][i]])
		{
			ko[node].push_back(pat[node][i]);
			dfs(pat[node][i]);
		}
	}
}
void calc(int node)
{
	ll d[2][22][21];
	int cur = 0;
	for (int i = 0; i < 22; i++)for (int j = 0; j < 21; j++)d[0][i][j] = d[1][i][j] = 0;
	d[0][gen + 1][0] = 1;
	for (int i = 0; i < ko[node].size(); i++)
	{
		calc(ko[node][i]);
		for (int j = 0; j <= gen + 1; j++)
		{
			for (int k = 0; k <= gen; k++)
			{
				for (int l = 0; l <= gen + 1; l++)
				{
					for (int m = 0; m <= gen; m++)
					{
						int x = 0;
						if (j + m > gen)x = max(x, m);
						if (l + k > gen)x = max(x, k);
						d[1 - cur][min(j, l)][x] += d[cur][j][k] * dp[ko[node][i]][l][m];
						d[1 - cur][min(j, l)][x] %= mod;
					}
				}
			}
		}
		for (int j = 0; j <= gen + 1; j++)for (int k = 0; k <= gen; k++)d[cur][j][k] = 0;
		cur = 1 - cur;
	}
	for (int i = 0; i <= gen + 1; i++)
	{
		if (i <= gen)
		{
			dp[node][min(gen + 1, i + 1)][0] += d[cur][i][0];
			dp[node][min(gen + 1, i + 1)][0] %= mod;
		}
		else
		{
			dp[node][min(gen + 1, i + 1)][1] += d[cur][i][0];
			dp[node][min(gen + 1, i + 1)][1] %= mod;
		}
		for (int j = 1; j < gen; j++)
		{
			dp[node][min(gen + 1, i + 1)][j + 1] += d[cur][i][j];
			dp[node][min(gen + 1, i + 1)][j + 1] %= mod;
		}
		for (int j = 0; j <= gen; j++)
		{
			dp[node][1][0] += d[cur][i][j];
			dp[node][1][0] %= mod;
		}
	}
	/*printf("node %d:\n", node + 1);
	for (int i = 0; i <= gen + 1; i++)
	{
		for (int j = 0; j <= gen; j++)
		{
			printf("%I64d ", dp[node][i][j]);
		}
		printf("\n");
	}*/
}
int main()
{
	scanf("%d%d", &num, &gen);
	for (int i = 0; i < num - 1; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		pat[za].push_back(zb);
		pat[zb].push_back(za);
	}
	dfs(0);
	calc(0);
	ll ans = 0;
	for (int i = 0; i <= gen + 1; i++)ans += dp[0][i][0];
	printf("%I64d\n", ans%mod);
}