#include <cstring>
#include <cstdio>
typedef long long ll; 
bool dp[55][55]; 
ll pre[55], arr[55]; 
int main()
{
	// freopen("981D.in", "r", stdin); 
	int n, lim; 
	scanf("%d%d", &n, &lim); 
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", arr + i); 
		pre[i + 1] = pre[i] + arr[i]; 
	}
	ll ans = 0; 
	for (int i = 60; i >= 0; i--)
	{
		ll cur = ans | (1ll << i); 
		memset(dp, false, sizeof(dp)); 
		dp[0][0] = true; 
		for (int j = 0; j <= n; j++)
		{
			for (int k = j; k <= n; k++)
			{
				if ((pre[k] - pre[j] & cur) == cur)
				{
					for (int x = 0; x <= k; x++)
						dp[k][x + 1] |= dp[j][x]; 
				}
			}
		}
		if (dp[n][lim])
			ans = cur; 
	}
	printf("%lld\n", ans);
	return 0; 
}