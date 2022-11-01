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

typedef long long s64; 
typedef long double ld; 
typedef std::pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	int QAQ; 
	read(QAQ); 
	while (QAQ--)
	{
		int n, k1, k2; 
		const int MaxN = 1e2 + 5; 
		int a[MaxN], b[MaxN]; 

		read(n), read(k1), read(k2); 
		for (int i = 1; i <= k1; ++i)
			read(a[i]); 
		for (int i = 1; i <= k2; ++i)
			read(b[i]); 
		std::sort(a + 1, a + k1 + 1); 
		std::sort(b + 1, b + k2 + 1);

		if (a[k1] > b[k2])
			puts("YES"); 
		else
			puts("NO"); 
	}

	return 0; 
}