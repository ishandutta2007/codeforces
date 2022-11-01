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

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
//	freopen("a.out", "w", stdout); 
#endif

	int T, d, mod; 

	read(T); 
	while (T--)
	{
		read(d), read(mod); 

		int high = 0; 
		while ((1 << (high + 1)) <= d)
			++high; 

		static int f[33][33]; 
		memset(f, 0, sizeof(f)); 

		f[0][0] = f[0][1] = 1 % mod; 

		int res = 0; 
		for (int i = 1; i <= high; ++i)
		{
			int cur = i < high ? (1 << i) : d - (1 << high) + 1; 

		//	std::cout << ':' << i << ' ' << cur << '\n'; 
			for (int j = 0; j <= i; ++j)
				f[i][j] = f[i - 1][j]; 
			for (int j = 1; j <= i + 1; ++j)
				f[i][j] = (f[i][j] + 1LL * f[i - 1][j - 1] * cur) % mod;
		}
		for (int j = 1; j <= high + 1; ++j)
			res = (res + f[high][j]) % mod; 

		putint(res), putchar('\n'); 
	}

	return 0; 
}