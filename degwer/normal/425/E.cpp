#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll dp[501][501];
ll p2[1000001];
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	p2[0] = 1;
	for (int i = 1; i <= 1000000; i++)p2[i] = p2[i - 1] * 2 % mod;
	dp[0][0] = 1;
	for (int i = 0; i < num; i++)
	{
		for (int j = 1; j <= num - i; j++)
		{
			ll coef = (p2[j] + mod - 1)*p2[i*j] % mod;
			for (int k = 0; k < gen; k++)
			{
				dp[i + j][k + 1] += dp[i][k] * coef;
				dp[i + j][k + 1] %= mod;
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i <= num; i++)
	{
		ans += dp[i][gen] * p2[i*(num - i)];
		ans %= mod;
	}
	printf("%I64d\n", ans);
}