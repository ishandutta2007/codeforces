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
	static char buf[45], *tail = buf; 
	if (!x)
		putchar('0'); 
	else
	{
		if (x < 0)
			putchar('-'), x = ~x + 1; 
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

template <class T>
inline bool tense(T &x, const T &y)
{
	return y < x ? x = y, true : false; 
}

template <class T>
inline bool relax(T &x, const T &y)
{
	return x < y ? x = y, true : false; 
}

using std::min; 
using std::max; 
using std::pair; 
using std::cin; 
using std::cout; 
using std::vector; 
typedef long long s64; 
typedef long double ld; 
typedef std::pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

int T, p1, p2, K; 

inline int gcd(int x, int y)
{
	return y ? gcd(y, x % y) : x; 
}

inline bool solve()
{
	if (p1 > p2)
		std::swap(p1, p2); 
	if (K == 1)
		return false; 
	if (p1 == p2)
		return true; 

	int g = gcd(p1, p2); 
	if ((p2 - g - 1) / p1 + 1 >= K)
		return false; 
	return true; 
}

int main()
{
// 	freopen("color.in", "r", stdin); 
// 	freopen("color.out", "w", stdout); 

	read(T); 
	while (T--)
	{
		read(p1), read(p2), read(K); 
		puts(solve() ? "OBEY" : "REBEL"); 
	}

	return 0; 
}