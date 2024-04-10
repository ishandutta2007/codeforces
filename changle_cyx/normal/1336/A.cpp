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

const int MaxN = 2e5 + 5; 

s64 res; 
int n, K; 
vi adj[MaxN]; 

int sze[MaxN], dep[MaxN], id[MaxN], dis[MaxN]; 
bool tag[MaxN]; 

inline bool cmp(int x, int y)
{
	return dep[x] - sze[x] > dep[y] - sze[y]; 
}

inline void dfs_init(int u, int pre = 0)
{
	for (int v : adj[u])
		if (v != pre)
		{
			dep[v] = dep[u] + 1; 
			dfs_init(v, u); 

			sze[u] += sze[v]; 
		}
	++sze[u]; 
}

inline void dfs_solve(int u, int pre = 0)
{
	if (tag[u])
		res += dis[u]; 
	for (int v : adj[u])
		if (v != pre)
		{
			dis[v] += dis[u]; 
			dfs_solve(v, u); 
		}
}

int main()
{
#ifdef orzczk
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout); 
#endif

	read(n), read(K); 
	for (int i = 1; i <= n; ++i)
		id[i] = i, dis[i] = 1; 

	for (int i = 1; i < n; ++i)
	{
		int u, v; 
		read(u), read(v); 
		adj[u].push_back(v); 
		adj[v].push_back(u); 
	}

	dfs_init(1); 
	std::sort(id + 1, id + n + 1, cmp); 

	for (int i = 1; i <= K; ++i)
		--dis[id[i]], tag[id[i]] = true; 

	dfs_solve(1); 
	std::cout << res << '\n'; 

	return 0; 
}