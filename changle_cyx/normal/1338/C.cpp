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
typedef unsigned long long s64; 
typedef long double ld; 
typedef std::pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

s64 n; 
int opt; 

inline s64 solve(s64 n, s64 s)
{
	if (s == 1)
		return 0; 

	if (n < s / 4)
		return solve(n, s / 4); 
	else if (n < s / 4 * 2)
		return solve(n - s / 4, s / 4) + s / 2; 
	else if (n < s / 4 * 3)
		return solve(n - s / 2, s / 4) + s / 4 * 3; 
	else
		return solve(n - s / 4 * 3, s / 4) + s / 4; 
}

inline void work()
{
	int bit = 0; 
	s64 sum = 0; 

	while ((sum + (1LL << bit) * 3) < n)
		sum += (1LL << bit) * 3, bit += 2; 

	n -= sum + 1; 
	opt = n % 3; 
	n /= 3; 

//	std::cout << n << ':' << opt << ' ' << sum << ' ' << (1LL << bit) << ' '; 

	if (opt == 0)
		printf("%lld\n", n + sum + 1); 
	else if (opt == 1)
		printf("%lld\n", solve(n, 1LL << bit) + sum + 1 + (1LL << bit)); 
	else
		printf("%lld\n", (n + sum + 1) ^ (solve(n, 1LL << bit) + sum + 1 + (1LL << bit))); 
}

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	int T; 
	read(T); 
	while (T--)
	{
		read(n); 
		work(); 
	}

	return 0; 
}