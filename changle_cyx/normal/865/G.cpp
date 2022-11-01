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

template <class T>
inline void relax(T &x, const T &y)
{
	if (x < y)
		x = y; 
}

namespace ModuloCalculator
{ 
	const int mod = 1e9 + 7; 

	inline void add(int &x, const int &y)
	{
		if (x += y, x >= mod)
			x -= mod; 
	}
	inline void dec(int &x, const int &y)
	{
		if (x -= y, x < 0)
			x += mod; 
	}
	inline int qpow(int x, int y)
	{
		int res = 1; 
		for (; y; y >>= 1, x = 1LL * x * x % mod)
			if (y & 1)
				res = 1LL * res * x % mod; 
		return res; 
	}
}

using namespace ModuloCalculator; 

typedef long long s64; 

const int MaxN = 12; 
const int MaxM = 102; 
const int MaxB = 505; 

s64 K; 
int n, m, maxb;

struct poly
{
	int n, a[MaxB]; 

	poly(){}
	poly(int _n):
		n(_n) {memset(a, 0, sizeof(a));}

	inline void tense_size(int m)
	{
		while (n > m)
			a[--n] = 0; 
	}
	inline poly operator + (const poly &rhs) const
	{
		int m = std::max(n, rhs.n); 
		poly res(m); 

		for (int i = 0; i < m; ++i)
			add(res.a[i] = a[i], rhs.a[i]); 
		return res; 
	}
	inline poly operator * (const poly &rhs) const
	{
		poly res(n + rhs.n - 1); 
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < rhs.n; ++j)
				add(res.a[i + j], 1LL * a[i] * rhs.a[j] % mod); 
		return res; 
	}
	inline poly operator % (const poly &rhs) const
	{
		poly res = *this; 
		int inv = qpow(rhs.a[rhs.n - 1], mod - 2); 
		for (int i = n - 1; i >= rhs.n - 1; --i)
		{
			int d = 1LL * res.a[i] * inv % mod; 
			for (int j = 0; j < rhs.n; ++j)
				dec(res.a[i - rhs.n + j + 1], 1LL * d * rhs.a[j] % mod); 
		}
		return res.tense_size(rhs.n - 1), res; 
	}
}P, resT[MaxN]; 

inline poly poly_pow(poly x, s64 y, poly p)
{
	poly res(1); res.a[0] = 1; 
	for (; y; y >>= 1, x = x * x % p)
		if (y & 1)
			res = res * x % p; 
	return res; 
}

int main()
{
	read(n), read(m), read(K); 

	static int b[MaxM], a[MaxN]; 
	for (int i = 1; i <= n; ++i)
		read(a[i]); 
	for (int i = 1; i <= m; ++i)
		read(b[i]), relax(maxb, b[i]); 

	P = poly(maxb + 1), P.a[maxb] = 1; 
	for (int i = 1; i <= m; ++i)
		dec(P.a[maxb - b[i]], 1); 

	for (int j = 1; j <= n; ++j)
		resT[j] = poly(1), resT[j].a[0] = 1; 

	poly cur(2); cur.a[1] = 1; cur = cur % P; 
	for (int i = 0; i <= 29; ++i, cur = cur * cur % P)
	{
		for (int j = 1; j <= n; ++j)
			if (a[j] >> i & 1)
				resT[j] = resT[j] * cur % P; 
	}

	poly F(1); 
	for (int i = 1; i <= n; ++i)
		F = F + resT[i]; 
	F = poly_pow(F, K, P); 

	for (int i = F.n - 1; i >= 0; --i)
		for (int j = 1; j <= m; ++j)
			if (i >= b[j])
				add(F.a[i - b[j]], F.a[i]); 
	std::cout << F.a[0] << '\n'; 
	
	return 0; 
}