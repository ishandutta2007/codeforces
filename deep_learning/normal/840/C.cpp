#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#define MOD 1000000007
using namespace std; 
typedef long long ll; 
ll dp[305], dp1[305];
int C[305][305], arr[305], app[305], v[305], tot; 
map<int, int> cnt; 
int main()
{
	// freopen("840C.in", "r", stdin); 
	int n; 
	scanf("%d", &n); 
	C[0][0] = 1; 
	for (int i = 1; i <= n; i++)
	{
		C[i][0] = 1; 
		for (int j = 0; j < n; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD; 
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i); 
		for (int j = 2; j * j <= arr[i]; j++)
		{
			while (!(arr[i] % (j * j)))
				arr[i] /= j * j; 
		}
		if (!cnt[arr[i]])
			app[tot++] = arr[i]; 
		cnt[arr[i]]++; 
	}
	for (int i = 0; i < tot; i++)
		v[i] = cnt[app[i]]; 
	sort(v, v + tot, greater<int>()); 
	int sum = v[0]; 
	dp[sum - 1] = 1; 
	for (int i = 1; i < tot; i++)
	{
		for (int j = sum + v[i]; j >= 0; j--)
			dp1[j] = 0; 
		for (int j = 0; j < sum; j++)
		{
			if (!dp[j])
				continue; 
			for (int k = 1; k <= v[i]; k++)
			{
				for (int x = 0; x <= j && x <= k; x++)
				{
					if (sum - j + 1 >= k - x)
						(dp1[j - x + v[i] - k] += dp[j] * C[v[i] - 1][k - 1] % MOD * C[j][x] % MOD
						 * C[sum - j + 1][k - x] % MOD) %= MOD; 
				}
			}
		}
		sum += v[i]; 
		memcpy(dp, dp1, sum + 1 << 3); 
	}
	ll ans = dp[0]; 
	for (int i = 0; i < tot; i++)
	{
		for (int j = 1; j <= v[i]; j++)
			(ans *= j) %= MOD; 
	}
	printf("%lld\n", ans);
	return 0; 
}