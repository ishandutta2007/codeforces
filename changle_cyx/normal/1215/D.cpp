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

int n; 
char s[MaxN]; 

int sa, sb; 
int a, b; 

int main()
{
#ifdef orzczk
	freopen("input.txt", "r", stdin); 
#endif

	read(n); 
	scanf("%s", s + 1); 

	int half = n >> 1; 
	for (int i = 1; i <= half; ++i)
	{
		if (s[i] == '?')
			++a; 
		else
			sa += s[i] - '0'; 
	}
	for (int i = half + 1; i <= n; ++i)
	{
		if (s[i] == '?')
			++b;
		 else
		 	sb += s[i] - '0'; 
	}

	while (a && b)
		--a, --b; 

	if (!a && !b)
		return puts(sa != sb ? "Monocarp" : "Bicarp"), 0; 

	if (!a)
		std::swap(a, b), std::swap(sa, sb); 

	if (sa > sb)
		return puts("Monocarp"), 0; 
	else
	{
		int d = sb - sa; 
		a >>= 1; 
		if (a * 9 > d)
			puts("Monocarp"); 
		else
			puts(a * 9 == sb - sa ? "Bicarp" : "Monocarp"); 
	}

	return 0; 
}