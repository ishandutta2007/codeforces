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

const int MaxN = 2e3 + 5; 

int n, rt; 
int a[MaxN]; 
int fa[MaxN], c[MaxN], sze[MaxN]; 
std::vector<int> son[MaxN], sub[MaxN]; 

inline void invalid()
{
	puts("NO"); 
	exit(0); 
}

inline void dfs(int u)
{
	sze[u] = 0; 
	a[u] = c[u] + 1; 
	sub[u].push_back(u); 

	for (int v : son[u])
	{
		dfs(v); 

		if (c[u] >= sze[v])
		{
			c[u] -= sze[v]; 
			for (int w : sub[v])
				a[w] += sze[u]; 
		}
		else if (c[u])
		{
			for (int w : sub[v])
				if (a[w] <= c[u])
					a[w] += sze[u]; 
				else
					a[w] += sze[u] + 1; 
			c[u] = 0; 
		}
		else
		{
			for (int w : sub[v])
				a[w] += sze[u] + 1; 
		}

		sze[u] += sze[v]; 
		for (int w : sub[v])
			sub[u].push_back(w); 
	}
	++sze[u]; 

	if (c[u])
		invalid(); 
}

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	read(n); 
	for (int i = 1; i <= n; ++i)
	{
		read(fa[i]), read(c[i]); 
		if (!fa[i])
			rt = i; 
		else
			son[fa[i]].push_back(i); 
	}

	dfs(rt); 

	puts("YES"); 
	for (int i = 1; i <= n; ++i)
		printf("%d%c", a[i], " \n"[i == n]); 

	return 0; 
}