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
inline void putint(T x)
{
	static char buf[15], *tail = buf; 
	if (!x)
		putchar('0'); 
	else
	{
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

const int mod = 998244353; 

inline void add(int &x, const int &y)
{
	if (x += y, x >= mod)
		x -= mod; 
}

inline int qpow(int x, int y)
{
	int res = 1; 
	for (; y; y >>= 1, x = 1LL * x * x % mod)
		if (y & 1)
			res = 1LL * res * x % mod; 
	return res; 
}

const int MaxN = 2e5 + 5; 
const int MaxM = 3e3 + 5; 

int n, m; 
int sumw, s0, s1; 
int a[MaxN], w[MaxN];

int f[MaxM][MaxM]; 
int sum_inv[2][MaxM]; 

int main()
{
	read(n), read(m); 
	for (int i = 1; i <= n; ++i)
		read(a[i]); 
	for (int i = 1; i <= n; ++i)
	{
		read(w[i]); 
		sumw += w[i]; 
		(a[i] ? s1 : s0) += w[i]; 
	}

	for (int i = 0; i <= m && i <= sumw; ++i)
		sum_inv[0][i] = qpow(sumw - i, mod - 2); 
	for (int i = 0; i <= m; ++i)
		sum_inv[1][i] = qpow(sumw + i, mod - 2); 

	f[0][0] = 1; 
	for (int i = 0; i < m; ++i)
		for (int j = 0; j <= i; ++j)
			if (f[i][j])
			{
				int d = i - 2 * j; 
				int inv = d >= 0 ? sum_inv[1][d] : sum_inv[0][-d]; 
				int val = 1LL * f[i][j] * inv % mod; 

				f[i + 1][j + 0] = (f[i + 1][j + 0] + 1LL * val * (s1 + i - j)) % mod; 
				f[i + 1][j + 1] = (f[i + 1][j + 1] + 1LL * val * (s0 - j) % mod) % mod;  
			}

	int s0_inv = qpow(s0, mod - 2); 
	int s1_inv = qpow(s1, mod - 2); 

	int sum0 = 0, sum1 = 0; 
	for (int j = 0; j <= m && j <= s0; ++j)
		sum0 = (sum0 + 1LL * f[m][j] * (s0 - j)) % mod; 
	for (int j = 0; j <= m; ++j)
		sum1 = (sum1 + 1LL * f[m][j] * (s1 + m - j)) % mod; 

	for (int i = 1; i <= n; ++i)
	{
		if (a[i] == 0)
			putint(1LL * w[i] * s0_inv % mod * sum0 % mod); 
		else
			putint(1LL * w[i] * s1_inv % mod * sum1 % mod); 

		putchar('\n'); 
	}

	return 0; 
}