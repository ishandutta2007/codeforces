#include <iostream>
#include <cstring>
#include <cstdio>
#define MOD 998244353
#define GEN 3
typedef long long ll;
inline int sum(int x, int y)
{
	x += y; 
	if (x >= MOD)
		x -= MOD; 
	return x; 
}
inline int sub(int x, int y)
{
	x -= y; 
	if (x < 0)
		x += MOD; 
	return x; 
}
inline int quick_pow(int a, int n)
{
	int res = 1; 
	while (n)
	{
		if (n & 1)
			res = (ll)res * a % MOD; 
		a = (ll)a * a % MOD; 
		n >>= 1; 
	}
	return res; 
}
namespace poly_ntt_tmp
{
	int lst = -1, rev[400005], alpha[2][400005]; 
}
inline void poly_ntt_init(int n)
{
	using poly_ntt_tmp::lst; 
	using poly_ntt_tmp::rev; 
	using poly_ntt_tmp::alpha; 
	if (lst == n)
		return; 
	alpha[0][0] = alpha[1][0] = 1; 
	alpha[0][1] = quick_pow(GEN, (MOD - 1) / n); 
	alpha[1][1] = quick_pow(alpha[0][1], MOD - 2); 
	for (int i = 1; i < n; i++)
	{
		for (int x = 0; x < 2; x++)
			alpha[x][i] = (ll)alpha[x][i - 1] * alpha[x][1] % MOD; 
	}
	for (int i = 1, j = n >> 1; i + 1 < n; i++)
	{
		rev[i] = j; 
		int k = n >> 1; 
		while (j >= k)
		{
			j -= k; 
			k >>= 1; 
		}
		if (j < k)
			j += k; 
	}
	lst = n;
}
inline void poly_ntt(int *a, int n, bool f)
{
	using poly_ntt_tmp::rev; 
	using poly_ntt_tmp::alpha; 
	poly_ntt_init(n); 
	for (int i = 1; i + 1 < n; i++)
	{
		if (i < rev[i])
			std::swap(a[i], a[rev[i]]); 
	}
	for (int i = 1; i < n; i <<= 1)
	{
		int off = n / (i << 1); 
		for (int j = 0; j < n; j += i << 1)
		{
			for (int k = j, cur = 0; k < j + i; k++, cur += off)
			{
				int x = (ll)alpha[f][cur] * a[k + i] % MOD; 
				a[k + i] = sub(a[k], x); 
				a[k] = sum(a[k], x); 
			}
		}
	}
	if (f)
	{
		int res = quick_pow(n, MOD - 2); 
		for (int i = 0; i < n; i++)
			a[i] = (ll)a[i] * res % MOD; 
	}
}
inline void poly_inv(int *a, int *b, int n)
{
	static int tmp[400005]; 
	b[0] = quick_pow(a[0], MOD - 2); 
	for (int len = 2; (len >> 1) < n; len <<= 1)
	{
		int lim = std::min(n, len); 
		memcpy(tmp, a, lim << 2); 
		memset(tmp + lim, 0, (len << 1) - lim << 2); 
		memset(b + (len >> 1), 0, (len << 1) - (len >> 1) << 2); 
		poly_ntt(b, len << 1, false); 
		poly_ntt(tmp, len << 1, false); 
		for (int i = 0; i < len << 1; i++)
			b[i] = (ll)sub(2, (ll)tmp[i] * b[i] % MOD) * b[i] % MOD; 
		poly_ntt(b, len << 1, true); 
	}
}
inline void poly_sqrt(int *a, int *b, int n)
{
	static int tmp[400005], t[400005]; 
	b[0] = 1; 
	for (int len = 2; (len >> 1) < n; len <<= 1)
	{
		int lim = std::min(n, len); 
		memcpy(t, a, lim << 2); 
		memset(t + lim, 0, (len << 1) - lim << 2); 
		memset(b + (len >> 1), 0, (len << 1) - (len >> 1) << 2); 
		poly_inv(b, tmp, len); 
		memset(tmp + len, 0, len << 2); 
		poly_ntt(t, len << 1, false); 
		poly_ntt(b, len << 1, false); 
		poly_ntt(tmp, len << 1, false); 
		for (int i = 0; i < len << 1; i++)
			b[i] = (ll)sum(b[i], (ll)tmp[i] * t[i] % MOD) * (MOD + 1) / 2 % MOD; 
		poly_ntt(b, len << 1, true); 
		memset(b + len, 0, len << 2); 
	}
}
int a[400005], b[400005]; 
int main()
{
	// freopen("438E.in", "r", stdin); 
	int n, m; 
	scanf("%d%d", &n, &m); 
	for (int i = 0; i < n; i++)
	{
		int x; 
		scanf("%d", &x);
		a[x]++; 
	}
	a[0] = sub(1, a[0]); 
	for (int i = 1; i <= m; i++)
		a[i] = sub(0, (ll)a[i] * 4 % MOD); 
	poly_sqrt(a, b, m + 1); 
	b[0] = sum(b[0], 1);
	poly_inv(b, a, m + 1); 
	for (int i = 1; i <= m; i++)
		printf("%d\n", 2 * a[i] % MOD);
	return 0; 
}