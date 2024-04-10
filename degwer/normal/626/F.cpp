#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll dp[2][201][1001];
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
	v.push_back(500);
	sort(v.begin(), v.end());
	dp[0][0][0] = 1;
	int cur = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j <= num; j++)
		{
			for (int k = 0; k <= gen; k++)
			{
				if (k + (v[i + 1] - v[i])*j <= gen)
				{
					dp[1 - cur][j][k + (v[i + 1] - v[i])*j] += dp[cur][j][k]*(j+1);
					dp[1 - cur][j][k + (v[i + 1] - v[i])*j] %= mod;
				}
				if (j >= 1 && k + (v[i + 1] - v[i])*(j - 1) <= gen)
				{
					dp[1 - cur][j-1][k + (v[i + 1] - v[i])*(j - 1)] += dp[cur][j][k]*j;
					dp[1 - cur][j-1][k + (v[i + 1] - v[i])*(j - 1)] %= mod;
				}
				if (j <= num - 1 && k + (v[i + 1] - v[i])*(j + 1) <= gen)
				{
					dp[1 - cur][j+1][k + (v[i + 1] - v[i])*(j + 1)] += dp[cur][j][k];
					dp[1 - cur][j+1][k + (v[i + 1] - v[i])*(j + 1)] %= mod;
				}
			}
		}
		for (int j = 0; j <= num; j++)for (int k = 0; k <= gen; k++)dp[cur][j][k] = 0;
		cur = 1 - cur;
	}
	ll sum = 0;
	for (int i = 0; i <= gen; i++)
	{
		sum += dp[cur][0][i];
		sum %= mod;
	}
	printf("%I64d\n", sum);
}