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
		x = ~x + 1, putchar('-'); 
	if (!x)
		putchar('0'); 
	else
	{
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

template <class T>
inline bool tense(T &x, const T &y)
{
	return x > y ? x = y, true : false; 
}

template <class T>
inline bool relax(T &x, const T &y)
{
	return x < y ? x = y, true : false; 
}

typedef unsigned u32; 
typedef long long s64; 
typedef unsigned long long u64; 
typedef std::pair<int, int> pii; 

#define mp(x, y) std::make_pair(x, y)

const int MaxN = 1e5 + 5; 

int n; 
int rt, deg[MaxN]; 

int pos[MaxN], col[MaxN], cst[MaxN][4]; 
int ans[MaxN]; 

s64 minans = 1LL << 60; 

std::vector<int> adj[MaxN]; 

inline int find_rt()
{
	int x = 1, y = 0; 
	while (x)
	{
		if (adj[x].size() == 2)
		{
			if (adj[x][0] != y)
				y = x, x = adj[x][0]; 
			else
				y = x, x = adj[x][1]; 
		}
		else
			return x; 
	}
	return -1; 
}

inline void init_pos()
{
	int x = rt, y = 0; 

	int cnt = 0; 
	while (x)
	{
		pos[++cnt] = x; 
		if (adj[x][0] != y)
			y = x, x = adj[x][0]; 
		else if (adj[x].size() > 1)
			y = x, x = adj[x][1]; 
		else
			break; 
	}
}

inline void solve()
{
	s64 sum = 0; 
	for (int i = 1; i <= n; ++i)
	{
		if (i > 2)
			col[pos[i]] = 6 - col[pos[i - 1]] - col[pos[i - 2]]; 
		sum += cst[pos[i]][col[pos[i]]]; 
	}

	if (tense(minans, sum))
	{
		for (int i = 1; i <= n; ++i)
			ans[i] = col[i]; 
	}
}

int main()
{
#ifdef orzczk
	freopen("input.txt", "r", stdin); 
#endif

	read(n); 
	for (int j = 1; j <= 3; ++j)
	for (int i = 1; i <= n; ++i)
		read(cst[i][j]); 

	for (int i = 1; i < n; ++i)
	{
		int u, v; 
		read(u), read(v); 
		adj[u].push_back(v); 
		adj[v].push_back(u); 
		++deg[u], ++deg[v]; 
	}

	for (int i = 1; i <= n; ++i)
		if (deg[i] > 2)
		{
			puts("-1"); 
			return 0; 
		}

	rt = find_rt(); 
	if (rt == -1)
		return puts("-1"), 0; 

	init_pos(); 
//	std::cout << "rt = " << rt << '\n'; 

	for (col[pos[1]] = 1; col[pos[1]] <= 3; ++col[pos[1]])
	for (col[pos[2]] = 1; col[pos[2]] <= 3; ++col[pos[2]])
		if (col[pos[1]] != col[pos[2]])
			solve(); 

	std::cout << minans << '\n'; 
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]); 

	return 0; 
}