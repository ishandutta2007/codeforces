#include <bits/stdc++.h>

template <class T>
inline void read(T &x)
{
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

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
		for (int i = 1; i < n; ++i)
			if (i < rev[i]) std::swap(a[i], a[rev[i]]); 
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
			int inv = qpow(n, mod - 2); 
			for (int i = 0; i < n; ++i)
				a[i] = 1LL * a[i] * inv % mod; 
		}
	}

	inline void poly_init(const int &n)
	{
		L = 1, P = 0; 
		while (L < n) L <<= 1, ++P; 
		for (int i = 1; i < L; ++i)
			rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << P - 1); 
	}

	inline void poly_mul(int *a, int *b, int *c, int n, int m)
	{
		int t = n + m - 1; 
		poly_init(t); 

		static int ta[MaxN], tb[MaxN]; 
		for (int i = 0; i < L; ++i) ta[i] = tb[i] = 0; 
		for (int i = 0; i < n; ++i) ta[i] = a[i]; 
		for (int i = 0; i < m; ++i) tb[i] = b[i]; 

		DFT(ta, L, 1), DFT(tb, L, 1); 
		for (int i = 0; i < L; ++i) c[i] = 1LL * ta[i] * tb[i] % mod;  
		DFT(c, L, -1); 
		for (int i = t; i < L; ++i) c[i] = 0; 
	}

	inline void poly_inv(int *a, int *b, int n)
	{
		for (int i = 1; i < (n << 1); ++i) b[i] = 0;  
		b[0] = qpow(a[0], mod - 2); int m = 1; 
		while (m < n)
		{
			m <<= 1; poly_init(m << 1); 

			static int ta[MaxN], tb[MaxN]; 
			for (int i = 0; i < L; ++i) ta[i] = tb[i] = 0; 
			for (int i = 0; i < m; ++i) ta[i] = a[i], tb[i] = b[i]; 
			DFT(ta, L, 1), DFT(tb, L, 1); 
			for (int i = 0; i < L; ++i)
				tb[i] = (2LL * tb[i] % mod - 1LL * ta[i] * tb[i] % mod * tb[i] % mod + mod) % mod;
			DFT(tb, L, -1); 

			for (int i = 0; i < m; ++i)
				b[i] = tb[i]; 
		}
		for (int i = n; i < m; ++i) b[i] = 0; 
	}

	inline void poly_sqrt(int *a, int *b, int n) //A(0)=1
	{
		b[0] = 1; int m = 1; 

		const int inv2 = (mod + 1) / 2; 
		while (m < n)
		{
			static int ta[MaxN], tb[MaxN]; 

			m <<= 1; 
			for (int i = 0; i < (m << 1); ++i) ta[i] = tb[i] = 0; 
			for (int i = 0; i < m; ++i) ta[i] = b[i]; 
			poly_inv(ta, tb, m); 
			poly_mul(a, tb, ta, m, m); 
			
			for (int i = 0; i < m; ++i)
				b[i] = 1LL * inv2 * (b[i] + ta[i]) % mod; 

		}
		for (int i = n; i < m; ++i) b[i] = 0; 
	}
}

int n, m; 
int g[MaxN], f[MaxN]; 

template <class T>
inline void relax(T &x, const T &y)
{
	if (x < y) x = y; 
}

int main()
{
#ifdef orzczk
	freopen("input.txt", "r", stdin); 
#endif

	read(n), read(m); 

	++m; 
	for (int i = 1; i <= n; ++i)
	{
		int x; read(x); 
		g[x] = 1; 
	}
	for (int i = m; i <= 100000; ++i) g[i] = 0; 

	for (int i = 0; i < m; ++i)
		g[i] = 1LL * (mod - 4) * g[i] % mod; 
	g[0] = 1; 

	poly::poly_sqrt(g, f, m); ++f[0]; 
	poly::poly_inv(f, g, m); 

	for (int i = 1; i < m; ++i)
		printf("%d\n", 2LL * g[i] % mod); 

	return 0; 
}