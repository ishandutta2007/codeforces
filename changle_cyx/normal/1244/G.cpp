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
	static char buf[25], *tail = buf; 
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

const int MaxN = 1e6 + 5; 

int n; 
s64 K, ans; 
int a[MaxN]; 

int main()
{
#ifdef orzczk
	freopen("input.txt", "r", stdin); 
#endif

	read(n), read(K); 
	if (K < (1LL * n * (n + 1) >> 1))
		return puts("-1"), 0; 

	K -= 1LL * n * (n + 1) >> 1; 
	
	for (int i = 1; i <= n; ++i)
		a[i] = i; 
	for (int i = 1, lim = n >> 1; i <= lim && K; ++i)
		if (K >= n - i + 1 - i)
		{
			K -= n - i + 1 - i; 
			std::swap(a[i], a[n - i + 1]); 
		}
		else
		{
			std::swap(a[n - i + 1 - K], a[n - i + 1]); 
			break; 
		}

	for (int i = 1; i <= n; ++i)
		ans += std::max(i, a[i]); 

	putint(ans), putchar('\n'); 
	for (int i = 1; i <= n; ++i)
		putint(i), putchar(" \n"[i == n]); 
	for (int i = 1; i <= n; ++i)
		putint(a[i]), putchar(" \n"[i == n]); 

	return 0; 
}