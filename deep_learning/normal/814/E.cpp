#include <iostream>
#include <cstdio>
#define MOD 1000000007
using namespace std; 
typedef long long ll; 
ll dp[55][55], g[55][55][55], fact[55], inv[55]; 
int deg[55]; 
inline ll quick_pow(ll a, int n)
{
	ll res = 1;
	while (n)
	{
		if (n & 1)
			(res *= a) %= MOD; 
		(a *= a) %= MOD; 
		n >>= 1; 
	}
	return res; 
}
inline ll C(int n, int m)
{
	return fact[n] * inv[m] % MOD * inv[n - m] % MOD; 
}
int main()
{
	// freopen("814E.in", "r", stdin); 
	fact[0] = inv[0] = 1; 
	for (int i = 1; i < 55; i++)
	{
		fact[i] = fact[i - 1] * i % MOD; 
		inv[i] = quick_pow(fact[i], MOD - 2); 
	}
	int n; 
	scanf("%d", &n); 
	for (int i = 1; i <= n; i++)
		scanf("%d", deg + i); 
	g[0][0][0] = 1; 
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n - i; j++)
		{
			if (!i && !j)
				continue; 
			if (!i)
			{
				for (int k = 2; k < j; k++)
					(g[0][i][j] += g[0][i][j - k - 1] * C(j - 1, k) % MOD * fact[k] % MOD * inv[2] % MOD) %= MOD; 
			}
			else
			{
				if (i >= 2)
					(g[0][i][j] += g[0][i - 2][j] * (i - 1)) %= MOD; 
				if (j >= 1)
					(g[0][i][j] += g[0][i][j - 1] * j) %= MOD; 
			}
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int sum = 0; sum < n - i; sum++)
		{
			for (int k = 0; k <= sum; k++)
			{
				int j = sum - k; 
				if (!j && !k)
					continue; 
				if (j)
					(g[i][j][k] += g[i - 1][j - 1][k] * j) %= MOD; 
				if (k)
					(g[i][j][k] += g[i - 1][j + 1][k - 1] * k) %= MOD; 
			}
		}
	}
	dp[deg[1] + 1][deg[1]] = 1; 
	for (int i = deg[1] + 2; i <= n; i++)
	{
		for (int j = 1; j < i - deg[1]; j++)
		{
			int cnt2 = 0, cnt3 = 0; 
			for (int k = 1; k < i - j; k++)
			{
				(deg[i - j - k + 1] == 2 ? cnt2 : cnt3)++; 
				(dp[i][j] += g[j][cnt2][cnt3] * dp[i - j][k]) %= MOD; 
			}
		}
	}
	ll ans = 0; 
	int cnt2 = 0, cnt3 = 0; 
	for (int i = 1; i < n; i++)
	{
		(deg[n - i + 1] == 2 ? cnt2 : cnt3)++;
		(ans += dp[n][i] * g[0][cnt2][cnt3]) %= MOD; 
	}
	printf("%lld\n", ans);
	return 0; 
}