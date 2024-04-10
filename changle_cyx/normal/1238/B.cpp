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
	if (!x)
		putchar('0'); 
	else
	{
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

typedef long long s64; 

const int MaxN = 1e5 + 5; 

int n, r, a[MaxN]; 


int main()
{
	int T; 
	read(T); 
	while (T--)
	{
		read(n), read(r); 
		for (int i = 1; i <= n; ++i)
		{
			read(a[i]); 
		}
		std::sort(a + 1, a + n + 1); 

		int ans = 0; 

		a[n + 1] = 0; 
		for (int i = n, cur = 0; i >= 1; --i)
		{
			if (a[i] != a[i + 1] && a[i] - 1LL * cur * r > 0)
				++ans, ++cur; 

		}
		putint(ans), putchar('\n'); 
	}
	return 0; 
}