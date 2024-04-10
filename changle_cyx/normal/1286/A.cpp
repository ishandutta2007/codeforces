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

const int MaxN = 105; 

int n, a[MaxN]; 
int f[MaxN][MaxN][MaxN][2]; 

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	read(n); 
	int c0 = n >> 1, c1 = n - c0; 
	for (int i = 1; i <= n; ++i)
	{
		read(a[i]); 
		if (!a[i])
			continue; 
		if (a[i] & 1)
			--c1; 
		else
			--c0; 
	}

	if (n == 1)
		return puts("0"), 0; 
	if (n == 2)
		return puts("1"), 0; 

	memset(f, 0x3f, sizeof(f)); 

	f[0][c0][c1][0] = 0;
	for (int i = 0; i < n; ++i)
		for (int j0 = 0; j0 <= c0; ++j0)
			for (int j1 = 0; j1 <= c1; ++j1)
				for (int opt = 0; opt <= 1; ++opt)
					if (f[i][j0][j1][opt] < 0x3f3f3f3f)
					{
						int v = f[i][j0][j1][opt]; 
						if (a[i + 1])
						{
							tense(f[i + 1][j0][j1][a[i + 1] % 2], v + (i && a[i + 1] % 2 != opt)); 
							continue; 
						}
						if (j0)
							tense(f[i + 1][j0 - 1][j1][0], f[i][j0][j1][opt] + (i && opt != 0)); 
						if (j1)
							tense(f[i + 1][j0][j1 - 1][1], f[i][j0][j1][opt] + (i && opt != 1)); 
					}

	std::cout << std::min(f[n][0][0][0], f[n][0][0][1]) << '\n'; 

	return 0; 
}