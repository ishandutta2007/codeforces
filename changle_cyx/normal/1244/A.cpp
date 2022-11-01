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



int main()
{
#ifdef orzczk
	freopen("input.txt", "r", stdin); 
#endif

	int T; 
	read(T); 
	while (T--)
	{
		int a, b, c, d, k; 
		read(a), read(b), read(c), read(d), read(k); 

		int x = a / c + (bool)(a % c); 
		int y = b / d + (bool)(b % d); 

		if (x + y <= k)
			printf("%d %d\n", x, y); 
		else
			puts("-1"); 
	}
	return 0; 
}