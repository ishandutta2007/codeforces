#include <bits/stdc++.h>

const int mod = 1e9 + 7; 
const int inv2 = (mod + 1) >> 1; 

inline void add(int &x, const int &y)
{
	if (x += y, x >= mod)
		x -= mod; 
}

const int MaxN = 3e2 + 5; 

int n, d[MaxN]; 
int f[MaxN][MaxN], g[MaxN][MaxN][MaxN]; 
int fac[MaxN], fac_inv[MaxN], ind[MaxN]; 

inline void fac_init(int n)
{
	fac[0] = fac_inv[0] = 1; 
	for (int i = 1; i <= n; ++i)
	{
		ind[i] = i == 1 ? 1 : 1LL * (mod - mod / i) * ind[mod % i] % mod; 
		fac_inv[i] = 1LL * fac_inv[i - 1] * ind[i] % mod; 
		fac[i] = 1LL * fac[i - 1] * i % mod; 
	}
}

inline int C(int n, int m)
{
	if (n < m || n < 0 || m < 0)
		return 0; 
	return 1LL * fac[n] * fac_inv[m] % mod * fac_inv[n - m] % mod; 
}

int main()
{
	scanf("%d", &n), fac_init(n); 
	for (int i = 1; i <= n; ++i)
		scanf("%d", d + i);  

	for (int i = 0; i <= n; ++i)
		for (int j = 0; i + j <= n; ++j)
			if (!i && !j)
				g[0][0][0] = 1; 
			else if (!i)
			{
				for (int k = 3; k <= j; ++k)
					add(g[0][0][j], 1LL * g[0][0][j - k] * C(j - 1, k - 1) % mod * fac[k - 1] % mod * inv2 % mod); 
			}
			else
			{
				if (i >= 2)
					add(g[0][i][j], 1LL * g[0][i - 2][j] * (i - 1) % mod); 
				if (j >= 1)
					add(g[0][i][j], 1LL * g[0][i][j - 1] * j % mod); 
			}

	for (int i = 1; i <= n; ++i)
		for (int j = 0; i + j <= n; ++j)
			for (int k = 0; i + j + k <= n; ++k)
			{
				if (j)
					add(g[i][j][k], 1LL * j * g[i - 1][j - 1][k] % mod); 
				if (k)
					add(g[i][j][k], 1LL * k * g[i - 1][j + 1][k - 1] % mod); 
			}

	f[d[1] + 1][d[1]] = 1; 
	for (int i = d[1] + 2; i <= n; ++i)
		for (int j = 1, lim = i - d[1]; j < lim; ++j)
		{
			int c2 = 0, c3 = 0; 
			for (int k = 1; k < i - j; ++k)
			{
				++(d[i - j - k + 1] == 2 ? c2 : c3); 
				add(f[i][j], 1LL * f[i - j][k] * g[j][c2][c3] % mod); 
			}
		}

	int c2 = 0, c3 = 0, res = 0; 
	for (int i = 1; i < n; ++i)
	{
		++(d[n - i + 1] == 2 ? c2 : c3); 
		add(res, 1LL * f[n][i] * g[0][c2][c3] % mod); 
	}

	std::cout << res << '\n'; 

	return 0; 
}