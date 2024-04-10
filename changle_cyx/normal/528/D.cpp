#include <bits/stdc++.h>

const int MaxN = 1e6 + 5; 
const int mod = 998244353; 

namespace poly
{	
	int P, L; 
	int rev[MaxN]; 

	inline int qpow(int x, int y)
	{
		int res = 1; 
		for (; y; y >>= 1, x = 1LL * x * x % mod)
			if (y & 1) res = 1LL * res * x % mod; 
		return res; 
	}

	inline void DFT(int *a, const int &n, const int &opt)
	{
		for (int i = 1; i < n; ++i) if (i < rev[i])
			std::swap(a[i], a[rev[i]]); 
		int g = opt == 1 ? 3 : (mod + 1) / 3; 
		for (int k = 1; k < n; k <<= 1)
		{
			int omega = qpow(g, (mod - 1) / (k << 1)); 
			for (int i = 0; i < n; i += k << 1)
			{
				int x = 1; 
				for (int j = 0; j < k; ++j)
				{
					int u = a[i + j], v = 1LL * x * a[i + j + k] % mod; 
					a[i + j] = u + v >= mod ? u + v - mod : u + v; 
					a[i + j + k] = u - v < 0 ? u - v + mod : u - v; 
					x = 1LL * x * omega % mod; 
				}
			}
		}
		if (opt == -1)
		{
			int inv = qpow(L, mod - 2); 
			for (int i = 0; i < L; ++i)
				a[i] = 1LL * a[i] * inv % mod; 
		}
	}

	inline void poly_init(int n)
	{
		P = 0, L = 1; 
		while (L < n) L <<= 1, ++P; 
		for (int i = 1; i < L; ++i)
			rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << P - 1); 
	}

	inline void poly_mul(int *a, int *b, int *c, const int &n, const int &m)
	{
		int t = n + m - 1; 
		poly_init(t); 

		DFT(a, L, 1), DFT(b, L, 1); 
		for (int i = 0; i < L; ++i) c[i] = 1LL * a[i] * b[i] % mod; 
		DFT(c, L, -1); 

		for (int i = t; i < L; ++i) c[i] = 0; 
	}
}

using poly::poly_mul; 

int n, m, K, cnt[MaxN][4]; 
int a[4][MaxN], b[4][MaxN], res[4][MaxN]; 

char s[MaxN], t[MaxN]; 

inline int getpos(const char &ch)
{
	return (ch == 'A' ? 0 : (ch == 'G' ? 1 : (ch == 'C' ? 2 : 3))); 
}

inline bool query(int l, int r, int p)
{
	l = std::max(l, 0); 
	r = std::min(r, n - 1); 
	return cnt[r][p] - (l ? cnt[l - 1][p] : 0) > 0; 
}

int main()
{
#ifdef orzczk
	freopen("input.txt", "r", stdin); 
#endif
	
	scanf("%d%d%d%s%s", &n, &m, &K, s, t); 
	std::reverse(t, t + m); 

	cnt[0][getpos(s[0])] = 1; 
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < 4; ++j) cnt[i][j] = cnt[i - 1][j]; 
		++cnt[i][getpos(s[i])]; 
	}

	for (int c = 0; c < 4; ++c)
	{
		for (int i = 0; i < n; ++i)
			a[c][i] = query(i - K, i + K, c); 
		for (int i = 0; i < m; ++i)
			b[c][i] = getpos(t[i]) == c; 
		poly_mul(a[c], b[c], res[c], n, m); 
	}

	int ans = 0; 
	
	// for (int c = 0; c < 4; ++c)
	// {
	// 	for (int i = 0; i < n + m - 1; ++i)
	// 		printf("%d ", res[c][i]); 
	// 	puts(""); 
	// }

	for (int i = 0; i < n; ++i)
	{
		int p = i + m - 1, tot = 0; 
		for (int c = 0; c < 4; ++c)
			tot += res[c][p]; 
		ans += tot == m; 
	}

	std::cout << ans << std::endl; 

	return 0; 
}