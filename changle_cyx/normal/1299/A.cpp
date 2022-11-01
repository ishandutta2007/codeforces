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

int n; 
int a[MaxN], b[MaxN], cnt[MaxN]; 
bool vis[MaxN]; 

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	read(n); 
	for (int i = 1; i <= n; ++i)
	{
		read(a[i]); 
		for (int j = 0; j <= 30; ++j)
			cnt[j] += a[i] >> j & 1; 
	}

	int c = 0; 
	for (int i = 30; i >= 0; --i)
		if (cnt[i] == 1)
		{
			for (int j = 1; j <= n; ++j)
				if (!vis[j] && (a[j] >> i & 1))
				{
					b[++c] = a[j]; 
					vis[j] = true; 
					break; 
				}
		}

	for (int i = 1; i <= n; ++i)
		if (!vis[i])
			b[++c] = a[i]; 
	for (int i = 1; i <= n; ++i)
		printf("%d ", b[i]); 
	puts(""); 

	return 0; 
}