#include <iostream>
#include <cstring>
#include <cstdio>
#define MOD 998244353
using namespace std; 
typedef long long ll; 
ll C[4005][4005], fact[2005]; 
int f[2001][11][2001], g[2001][11][2001], a[2005], b[2005]; 
char str[15]; 
int main()
{
	// freopen("856C.in", "r", stdin); 
	C[0][0] = 1; 
	for (int i = 1; i < 4005; i++)
	{
		C[i][0] = 1; 
		for (int j = 1; j <= i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD; 
	}
	fact[0] = 1; 
	for (int i = 1; i < 2005; i++)
		fact[i] = fact[i - 1] * i % MOD; 
	int t; 
	scanf("%d", &t); 
	while (t--)
	{
		int n, odd = 0, even = 0; 
		scanf("%d", &n); 
		for (int i = 0; i < n; i++)
		{
			scanf("%s", str); 
			int len = strlen(str), sum = 0;
			for (int j = 0; j < len; j++)
				sum = (sum * 10 + str[j] - '0') % 11; 
			if (len & 1)
				a[++odd] = sum; 
			else
				b[++even] = sum; 
		}
		if (!odd)
		{
			int sum = 0;
			for (int i = 1; i <= even; i++)
				sum = (sum + b[i]) % 11; 
			if (sum)
				printf("0\n");
			else
				printf("%lld\n", fact[n]);
			continue; 
		}
		f[0][0][0] = 1; 
		for (int i = 1; i <= odd; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				for (int k = 0; k <= i; k++)
				{
					f[i][j][k] = 0; 
					if (k)
						(f[i][j][k] += f[i - 1][(j - a[i] + 11) % 11][k - 1]) %= MOD; 
					(f[i][j][k] += f[i - 1][(j + a[i]) % 11][k]) %= MOD; 
				}
			}
		}
		g[0][0][0] = 1; 
		for (int i = 1; i <= even; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				for (int k = 0; k <= i; k++)
				{
					g[i][j][k] = 0; 
					if (k)
						(g[i][j][k] += g[i - 1][(j - b[i] + 11) % 11][k - 1]) %= MOD; 
					(g[i][j][k] += g[i - 1][(j + b[i]) % 11][k]) %= MOD; 
				}
			}
		}
		ll ans = 0; 
		int x = odd + 1 >> 1, y = odd + 2 >> 1; 
		for (int i = 0; i <= even; i++)
		{
			for (int r = 0; r < 11; r++)
				(ans += (ll)f[odd][r][x] * g[even][(11 - r) % 11][i] % MOD * C[i + y - 1][y - 1] % MOD
						* C[even - i + odd - y][odd - y] % MOD * fact[i] % MOD * fact[even - i] % MOD) %= MOD;
		}
		printf("%lld\n", ans * fact[x] % MOD * fact[odd - x] % MOD);
	}
	return 0;
}