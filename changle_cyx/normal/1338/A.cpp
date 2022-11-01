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

const int MaxN = 1e5 + 5; 

int n, a[MaxN]; 

inline int calc(int x)
{
	if (x <= 0)
		return 0; 

	int cnt = 0; 
	while (((1LL << cnt) - 1) < x)
		++cnt; 
	return cnt; 
}

inline void work()
{
	read(n); 

	int maxans = 0; 
	for (int i = 1; i <= n; ++i)
	{
		read(a[i]); 
		if (i > 1)
		{
			relax(maxans, calc(a[i - 1] - a[i])); 
			relax(a[i], a[i - 1]); 
		}
	}

	putint(maxans); 
	putchar('\n'); 
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
		work(); 
	}

	return 0; 
}