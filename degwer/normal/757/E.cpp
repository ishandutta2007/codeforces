#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll dp[1000001][21];
vector<int>dat[1000001];
int main()
{
	dp[0][0] = 1;
	for (int i = 1; i <= 20; i++)dp[0][i] = 2;
	for (int i = 1; i <= 1000000; i++)
	{
		dp[i][0] = 1;
		for (int j = 1; j <= 20; j++)dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
	}
	for (int i = 2; i <= 1000000; i++)
	{
		if (!dat[i].empty())continue;
		for (int j = i; j <= 1000000; j += i)dat[j].push_back(i);
	}
	int query;
	scanf("%d", &query);
	for (int p = 0; p < query; p++)
	{
		int kai, num;
		scanf("%d%d", &kai, &num);
		ll ans = 1;
		for (int i = 0; i < dat[num].size(); i++)
		{
			int t = num;
			int c = 0;
			for (;;)
			{
				if (t%dat[num][i] != 0)break;
				t /= dat[num][i];
				c++;
			}
			ans = ans*dp[kai][c] % mod;
		}
		printf("%I64d\n", ans);
	}
}