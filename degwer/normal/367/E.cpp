#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll dp[2][320][320];
int main()
{
	int num, len, mok;
	scanf("%d%d%d", &num, &len, &mok);
	mok--;
	if (num > len)
	{
		printf("0\n");
		return 0;
	}
	int cur = 0;
	dp[0][0][0] = 1;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j <= num; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				if (i != mok)dp[1 - cur][j][k] += dp[cur][j][k];
				if (i != mok&&j > k)dp[1 - cur][j][k + 1] += dp[cur][j][k];
				dp[1 - cur][j + 1][k] += dp[cur][j][k];
				dp[1 - cur][j + 1][k + 1] += dp[cur][j][k];
			}
		}
		for (int j = 0; j <= num; j++)for (int k = 0; k <= num; k++)dp[cur][j][k] = 0;
		cur = 1 - cur;
		for (int j = 0; j <= num; j++)for (int k = 0; k <= num; k++)dp[cur][j][k] %= mod;
	}
	ll ans = dp[cur][num][num];
	for (int i = 1; i <= num; i++)ans = ans*i%mod;
	printf("%I64d\n", ans);
}