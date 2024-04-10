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

const int mod = 998244353; 

inline void add(int &x, const int &y)
{
	if (x += y, x >= mod)
		x -= mod; 
}

const int MaxN = 3e3 + 5; 

int n, m; 
char s[MaxN], t[MaxN]; 

int res = 0; 
int f[MaxN][MaxN]; 

inline bool check(int x, int y)
{
	if (y > m || y < 0)
		return true; 
	return s[x] == t[y]; 
}

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	scanf("%s%s", s + 1, t + 1); 
	n = strlen(s + 1); 
	m = strlen(t + 1); 

	for (int i = n + 1; i >= m + 1; --i)
		f[i][0] = 1; 
	for (int i = n; i >= 1; --i)
		for (int j = 0; j <= n - i + 1; ++j)
		{
			if (j)
			{
				if (check(i, j))
					add(f[i][j], f[i + 1][j - 1]); 
			}

			if (check(i, n - (n - i + 1 - j) + 1))
				add(f[i][j], f[i + 1][j]); 

		//	std::cout << i << ' ' << j << ' ' << f[i][j] << '\n'; 
	
			if (i == 1)
				add(res, f[i][j]); 
		}

	std::cout << res << '\n'; 

	return 0; 
}