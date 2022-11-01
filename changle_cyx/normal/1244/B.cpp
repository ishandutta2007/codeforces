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

const int MaxN = 1e3 + 5; 

int n; 
char s[MaxN]; 

int main()
{
	int T; 
	read(T); 
	while (T--)
	{
		read(n); 
		scanf("%s", s + 1); 

		int ans = n; 
		for (int i = 1; i <= n; ++i)
		{
			if (s[i] == '1')
			{
				relax(ans, std::max(n - i + 1, i) * 2); 
			}
		}

		printf("%d\n", ans); 
	}
	return 0; 
}