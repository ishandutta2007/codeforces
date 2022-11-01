#include <bits/stdc++.h>

template <class T>
inline void read(T &x)
{
	static char ch; 
	static bool opt; 
	while (!isdigit(ch = getchar()) && ch != '-'); 
	x = (opt = ch == '-') ? 0 : ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
	if (opt)
		x = ~x + 1; 
}

template <class T>
inline void putint(T x)
{
	static char buf[15], *tail = buf; 
	if (x < 0)
		x = ~x + 1, putchar('-'); 
	if (!x)
		putchar('0'); 
	else
	{
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

template <class T>
inline bool tense(T &x, const T &y)
{
	return x > y ? x = y, true : false; 
}

template <class T>
inline bool relax(T &x, const T &y)
{
	return x < y ? x = y, true : false; 
}

typedef unsigned u32; 
typedef long long s64; 
typedef unsigned long long u64; 
typedef std::pair<int, int> pii; 

#define mp(x, y) std::make_pair(x, y)

inline s64 exgcd(s64 a, s64 b, s64 &x, s64 &y)
{
	if (!b)
	{
		x = 1, y = 0; 
		return a; 
	}
	s64 res = exgcd(b, a % b, y, x); 
	y -= a / b * x; 
	return res; 
}	

int main()
{
#ifdef orzczk
	freopen("input.txt", "r", stdin); 
#endif

	s64 n, p, a, b; 
	read(n), read(p), read(b), read(a); 

	s64 t_gcd = std::__gcd(a, b); 
	if (p % t_gcd)
		return puts("-1"), 0; 

	s64 x, y; 
	exgcd(a, b, x, y); 

	s64 mod = b / t_gcd; 
	x = (1LL * (p / t_gcd) % mod * x % mod + mod) % mod; 
	y = (p - a * x) / b; 

	s64 z = n - x - y; 
	if (z >= 0 && y >= 0)
		std::cout << y << ' ' << x << ' ' << z << '\n'; 
	else
		puts("-1"); 

	return 0; 
}