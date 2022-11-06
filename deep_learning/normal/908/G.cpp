#include <iostream>
#include <cstring>
#include <cstdio>
#define MOD 1000000007
using namespace std; 
typedef long long ll; 
ll dp[705][2], sum[705][2]; 
char str[705]; 
inline void upd(ll &x, ll y)
{
	x += y; 
	if (x >= MOD)
		x -= MOD;
}
int main()
{
	// freopen("908G.in", "r", stdin); 
	scanf("%s", str); 
	int n = strlen(str); 
	ll ans = 0; 
	for (int d = 1; d <= 9; d++)
	{
		memset(dp, 0, sizeof(dp)); 
		memset(sum, 0, sizeof(sum)); 
		dp[0][0] = 1; 
		for (int i = 0; i < n; i++)
		{
			for (int k = 0; k < 2; k++)
			{
				for (int x = 0; x < 10; x++)
				{
					if (!k && x > str[i] - '0')
						continue; 
					upd(dp[i + 1][k | (x < str[i] - '0')], dp[i][k]);
					if (x < d)
						upd(sum[i + 1][k | (x < str[i] - '0')], sum[i][k]); 
					else
						upd(sum[i + 1][k | (x < str[i] - '0')], (sum[i][k] * 10 + dp[i][k]) % MOD); 
				}
			}
		}
		upd(ans, sum[n][0]); 
		upd(ans, sum[n][1]); 
	}
	printf("%lld\n", ans);
	return 0; 
}