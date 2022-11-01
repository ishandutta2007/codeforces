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
	{
		x = ~x + 1; 
		putchar('-'); 
	}

	if (!x)
		putchar('0'); 
	else
	{
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

const int MaxN = 2e5 + 5; 

typedef long long s64; 

int n, a[MaxN]; 
int opt[MaxN], cntneg, cntpos; 
s64 ansneg, anspos; 

int main()
{
#ifdef orzczk
	freopen("input.txt", "r", stdin); 
#endif

	read(n); 
	for (int i = 1; i <= n; ++i)
		read(a[i]); 

	++cntpos; 
	for (int i = 1; i <= n; ++i)
	{
		opt[i] = (i == 1 ? 1 : opt[i - 1]) * (a[i] > 0 ? 1 : -1); 

		if (opt[i] > 0)
			ansneg += cntneg, anspos += cntpos, ++cntpos; 
		else
			ansneg += cntpos, anspos += cntneg, ++cntneg; 
	}

	std::cout << ansneg << ' ' << anspos << '\n'; 

	return 0; 
}