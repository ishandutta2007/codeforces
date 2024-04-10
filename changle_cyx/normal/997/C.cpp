#include <bits/stdc++.h>

typedef long long s64; 

const int mod = 998244353; 
const int MaxN = 1e6 + 5; 

int n, ans; 
int fac[MaxN], inv[MaxN], pw[MaxN], f[MaxN]; 

inline void add(int &x, const int &y)
{
	x += y; 
	x >= mod ? x -= mod : 0; 
	x < 0 ? x += mod : 0; 
}

inline int qpow(int a, s64 b)
{
	int res = 1; 
	for (; b; b >>= 1, a = 1LL * a * a % mod)
		if (b & 1)
			res = 1LL * res * a % mod; 
	return res; 
}

inline int C(int n, int m)
{
	if (n < 0 || m < 0 || n < m)
		return 0; 
	return 1LL * fac[n] * inv[m] % mod * inv[n - m] % mod; 
}

int main()
{
//	freopen("matrix.in", "r", stdin); 
//	freopen("matrix.out", "w", stdout); 
	
	std::cin >> n; 
	
	pw[0] = fac[0] = 1; 
	for (int i = 1; i <= n; ++i)
	{
		pw[i] = 3LL * pw[i - 1] % mod; 
		fac[i] = 1LL * fac[i - 1] * i % mod; 
	}
	inv[n] = qpow(fac[n], mod - 2); 
	for (int i = n - 1; i >= 0; --i)
		inv[i] = 1LL * inv[i + 1] * (i + 1) % mod; 
	
	int ind = qpow(pw[n], mod - 2); 
	for (int i = 1; i <= n; ++i)
	{
		int tmp = 1LL * pw[i] * ind % mod; 
		int res = qpow((tmp + mod - 1) % mod, n); 
		if (n & 1)
			res = ((s64)mod * 2 - res - 1) % mod; 
		else
			res = (res + mod - 1) % mod; 
		res = 1LL * res * (i & 1 ? 1 : -1) * C(n, i) % mod * qpow(3, 1LL * n * (n - i) + 1) % mod; 
		add(ans, res); 
	}
	
	for (int i = 1; i <= n; ++i)
	{
		int type = i & 1 ? 1 : -1; 
		int res = C(n, i); 
		add(ans, 1LL * type * qpow(3, 1LL * n * (n - i) + i) % mod * res % mod); 
		add(ans, 1LL * type * qpow(3, 1LL * n * (n - i) + i) % mod * res % mod); 
	}
	
	std::cout << ans << std::endl;
	
	fclose(stdin); 
	fclose(stdout); 
	return 0; 
}