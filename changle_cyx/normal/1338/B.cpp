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
typedef std::vector<int> vi; 
typedef std::pair<int, int> pii; 
#define mp(x, y) std::make_pair(x, y)

const int MaxN = 1e5 + 5; 

int n; 
int deg[MaxN]; 
vi adj[MaxN], son[MaxN]; 

int dep[MaxN]; 

int minans = 1, maxans; 
int f[MaxN], g[MaxN]; 

int cur, cnt; 

inline void dfs(int u, int pre = 0)
{
	son[u].clear(); 
	for (int v : adj[u])
		if (v != pre)
			son[u].push_back(v); 

	if (!son[u].size())
	{
		if (dep[u] & 1)
			minans = 3; 
		cur = 0; 

		f[u] = g[u] = 0; 
		return; 
	}

	int cnt = 0; 
	for (int v : son[u])
	{
		dep[v] = dep[u] + 1; 
		cnt += adj[v].size() == 1; 

		dfs(v, u); 
		++cur; 
	}

	if (cnt > 1)
		maxans -= cnt - 1; 
}

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	read(n); 
	for (int i = 1; i < n; ++i)
	{
		int u, v; 
		read(u), read(v); 
		++deg[u], ++deg[v]; 
		adj[u].push_back(v); 
		adj[v].push_back(u); 
	}

	maxans = n - 1; 
	for (int i = 1; i <= n; ++i)
		if (deg[i] == 1)
		{
			dfs(i); 

			std::cout << minans << ' '; 
			break; 
		}

	maxans = n - 1, cnt = 0; 
	for (int i = 1; i <= n; ++i)
		if (deg[i] != 1)
		{
			dep[i] = 0; 
			dfs(i); 
			std::cout << maxans << '\n'; 
			break; 
		}

	return 0; 
}