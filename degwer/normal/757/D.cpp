#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef pair<int, int>pii;
typedef long long ll;
ll mod = 1000000007;
int dp[2][22][1 << 20];
bool isok[1 << 20];
int main()
{
	int num;
	string str;
	cin >> num >> str;
	int cur = 0;
	ll ans = 0;
	dp[0][0][0] = 1;
	for (int i = 1; i <= 20; i++)isok[(1 << i) - 1] = true;
	for (int i = 0; i < num; i++)
	{
		int d[5];
		fill(d, d + 5, 0);
		int t = 0;
		for (int j = 0; j < 5; j++)
		{
			d[j] = t;
			if (i - j - 1 >= 0)t += (str[i - j - 1] - '0') << j;
		}
		bool flag[100];
		fill(flag, flag + 100, false);
		for (int j = 0; j < 5; j++)
		{
			int bef = d[j];
			int aft = bef * 2 + str[i] - '0';
			if (flag[bef])continue;
			flag[bef] = true;
			if (aft <= 20)
			{
				//printf("%d %d\n", bef, aft);
				int cc = 1 - cur;
				for (int k = 0; k < (1 << 20); k++)
				{
					if (!dp[cur][bef][k])continue;
					//printf("   %d %d  %I64d\n", k, bef, dp[cur][k][bef]);
					if (aft <= 15)
					{
						dp[cc][aft][k] += dp[cur][bef][k];
						if (dp[cc][aft][k] >= mod)dp[cc][aft][k] -= mod;
					}
					if (aft > 0)
					{
						int x = k | (1 << (aft - 1));
						dp[cc][0][x] += dp[cur][bef][k];
						if (dp[cc][0][x] >= mod)dp[cc][0][x] -= mod;
						if (isok[x])ans += dp[cur][bef][k];
					}
				}
			}
			for (int k = 0; k < (1 << 20); k++)
			{
				dp[cur][bef][k] = 0;
			}
		}
		dp[1 - cur][0][0]++, dp[1 - cur][0][0] %= mod;
		cur = 1 - cur;
		//for (int k = 0; k < (1 << 3); k++)for (int j = 0; j < 10;j++)if(dp[cur][k][j]!=0)printf("%d %d %d %d\n", i, k, j, dp[cur][k][j]);
	}
	printf("%I64d\n", ans%mod);
}