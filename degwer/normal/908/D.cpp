#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll po(ll a, ll b)
{
	if (b == 0)return 1;
	ll z = po(a, b / 2);
	z = z*z%mod;
	if (b & 1)z = z*a%mod;
	return z;
}
ll inv(ll a)
{
	return po(a, mod - 2);
}
ll dp[1010][1010];
int main()
{
	int num;
	ll pa, pb;
	scanf("%d%I64d%I64d", &num, &pa, &pb);
	ll s = inv(pa + pb);
	pa = pa*s%mod, pb = pb*s%mod;
	dp[1][0] = 1;
	ll ans = 0;
	for (int i = 1; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * pa) % mod;
			if (j + i < num)
			{
				dp[i][j + i] = (dp[i][j + i] + dp[i][j] * pb) % mod;
			}
			else ans += dp[i][j] * pb%mod *(j + i), ans %= mod;
		}
	}
	for (int i = 0; i < num; i++)
	{
		ans += dp[num][i] * (num + i + inv(pb) + mod - 1) % mod;
		ans %= mod;
	}
	printf("%I64d\n", ans);
}