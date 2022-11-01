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

int main()
{
#ifdef orzczk
	freopen("input.txt", "r", stdin); 
#endif

	int a1, a2, k1, k2, n; 
	read(a1), read(a2), read(k1), read(k2), read(n); 

	if (k1 > k2)
		std::swap(a1, a2), std::swap(k1, k2); 

	int n1 = n, c1 = 0; 
	n1 -= (k1 - 1) * a1 + (k2 - 1) * a2; 
	printf("%d ", n1 > 0 ? n1 : 0); 

	int n2 = n, c2 = 0; 
	
	c2 = std::min(a1, n / k1); 
	n2 -= k1 * a1; 

	if (n2 > 0)
		c2 += std::min(a2, n2 / k2); 
	printf("%d\n", c2); 

	return 0; 
}