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

const int base = 26; 
const int MaxN = 2e6 + 5; 

namespace PAM
{
	char s[MaxN]; 

	int cur_n, lst, nT; 
	int len[MaxN], par[MaxN], dep[MaxN]; 
	int trans[MaxN][base]; 

	inline void init()
	{
		for (int i = 0; i <= nT; ++i)
		{
			len[i] = par[i] = dep[i] = 0; 
			memset(trans[i], 0, sizeof(trans[i])); 
		}

		cur_n = lst = 0, nT = 1; 
		par[1] = par[0] = 1; 
		len[1] = -1; 
	}

	inline int find(int x)
	{
		while (s[cur_n] != s[cur_n - 1 - len[x]])
			x = par[x]; 
		return x; 
	}

	inline void extend(int ch)
	{
		s[++cur_n] = ch; 
		ch -= 'a'; 

		int cur = find(lst); 
		if (!trans[cur][ch])
		{
			int x = ++nT; 
			par[x] = trans[find(par[cur])][ch]; 
			dep[x] = dep[par[x]] + 1; 
			len[trans[cur][ch] = x] = len[cur] + 2; 
		}
		lst = trans[cur][ch]; 
	}
}

int n; 
char s[MaxN]; 

inline void solve()
{
	int p = 0; 
	while ((p + 1) * 2 <= n && s[p + 1] == s[n - p])
		++p; 

	PAM::init(); 

	int maxans = p, maxpos = p, maxopt = 0, ansp = p; 
	for (int i = p + 1; i <= n; ++i)
	{
		PAM::extend(s[i]); 
		int suf = PAM::len[PAM::lst]; 

		if (i - suf <= p && i <= n - p && relax(maxans, i + i - suf))
			maxpos = i, maxopt = 0, ansp = i - suf; 
		if (i >= n - p && i - suf + 1 <= n - p && relax(maxans, n - (i - suf + 1) + 1 + n - i))
			maxpos = i - suf + 1, maxopt = 1, ansp = n - i; 
	}

//	std::cerr << p << ':' << maxans << ' ' << maxpos << ' ' << maxopt << '\n';

	if (maxopt == 0)
	{
		for (int i = 1; i <= maxpos; ++i)
			putchar(s[i]); 
		for (int i = n - ansp + 1; i <= n; ++i)
			putchar(s[i]); 
	}
	else
	{
		for (int i = 1; i <= ansp; ++i)
			putchar(s[i]); 
		for (int i = maxpos; i <= n; ++i)
			putchar(s[i]); 
	}

	puts(""); 
}

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	int T; 
	read(T); 
	while (T--)
	{
		scanf("%s", s + 1); 
		n = strlen(s + 1); 

		solve(); 
	}

	return 0; 
}