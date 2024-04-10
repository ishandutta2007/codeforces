#include <bits/stdc++.h>

typedef long long s64; 

namespace ModuleCalculator
{
	const int mod = 1e9 + 7; 

	inline int qpow(int x, int y)
	{
		int res = 1; 
		for (; y; y >>= 1, x = 1LL * x * x % mod)
			if (y & 1)
				res = 1LL * res * x % mod; 
		return res; 
	}

	inline int minus(int x, const int &y)
	{
		return x -= y, x < 0 ? x + mod : x; 
	}
	inline int plus(int x, const int &y)
	{
		return x += y, x >= mod ? x - mod : x; 
	}

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

	inline int nega(int x)
	{
		return x ? mod - x : 0; 
	}
}

using namespace ModuleCalculator; 

const int MaxN = 210; 
const int inv2 = qpow(2, mod - 2); 

int m, K, prod, root; 

struct number
{
	int a, b; // a + b \sqrt{root}
	number(){}
	number(int _a): a(_a), b(0) {}
	number(int _a, int _b): a(_a), b(_b) {}

	inline number operator + (const number &rhs) const
	{
		return number(plus(a, rhs.a), plus(b, rhs.b)); 
	}
	inline number operator - (const number &rhs) const
	{
		return number(minus(a, rhs.a), minus(b, rhs.b)); 
	}
	inline number operator * (const number &rhs) const
	{
		return number((1LL * a * rhs.a + 1LL * b * rhs.b * root) % mod, (1LL * a * rhs.b + 1LL * b * rhs.a) % mod); 
	}
	inline number operator / (const number &rhs) const
	{
		int inv = qpow(minus(1LL * rhs.a * rhs.a % mod, 1LL * root * rhs.b * rhs.b % mod), mod - 2); 
		return *this * number(rhs.a, nega(rhs.b)) * (number)inv; 
	}
}; 

inline number qpown(number x, s64 y)
{
	number res(1, 0); 
	for (; y; y >>= 1, x = x * x)
		if (y & 1)
			res = res * x; 
	return res; 
}

int f[MaxN][MaxN], C[MaxN][MaxN]; 

inline void init()
{
	prod = 1; 
	for (int i = 1; i <= K; ++i)
		prod = 1LL * prod * i % mod; 
	prod = qpow(prod, mod - 2); 

	f[0][0] = C[0][0] = 1; 
	for (int i = 1; i <= K; ++i)
	{
		C[i][0] = 1; 
		for (int j = 1; j <= i; ++j)
		{
			f[i][j] = f[i - 1][j - 1]; 
			add(C[i][j] = C[i - 1][j], C[i - 1][j - 1]); 
		}
		for (int j = 0; j < i; ++j)
			dec(f[i][j], 1LL * (i - 1) * f[i - 1][j] % mod); 
	}
}

inline number calc(number q, s64 L, s64 R)
{
	if (q.a == 1 && !q.b)
		return (R - L + 1) % mod; 
	else
		return (qpown(q, R + 1) - qpown(q, L)) / (q - number(1)); 
}

inline int solve(s64 L, s64 R)
{
	L += 2, R += 2; 

	root = 5; 
	number a, b, x1, x2; 
	x1 = number(inv2, inv2), x2 = number(inv2, nega(inv2)); 
	a = number(1) / number(0, 1), b = number(mod - 1) / number(0, 1); 

	int res = 0; 
	for (int i = 0; i <= K; ++i)
	{
		number sum(0, 0); 
		for (int j = 0; j <= i; ++j)
			sum = sum + number(C[i][j]) * qpown(a, j) * qpown(b, i - j) * calc(qpown(x1, j) * qpown(x2, i - j), L, R); 
		res = (res + 1LL * f[K][i] * sum.a) % mod; 
	}

	return res; 
}

int main()
{
	s64 L, R; 
	std::cin >> K >> L >> R; init(); 
	std::cout << 1LL * prod * solve(L, R) % mod << '\n'; 

	return 0; 
}