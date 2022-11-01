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
	if (!x)
		putchar('0'); 
	else
	{
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}

template <class T>
inline void relax(T &x, const T &y)
{
	if (x < y)
		x = y; 
}

typedef long long s64; 

const int MaxNV = 3e5 + 5; 
const int MaxNE = MaxNV << 1; 

int n, ans, fa[MaxNV], f[MaxNV], g[MaxNV]; 
int ect, adj[MaxNV], nxt[MaxNE], to[MaxNE];

int cntson[MaxNV];  

#define forson(u) for (int e = adj[u], v; v = to[e], e; e = nxt[e]) if (v != fa[u])

inline void addEdge(int u, int v)
{
	nxt[++ect] = adj[u]; 
	adj[u] = ect; 
	to[ect] = v; 
}

inline bool cmp(int u, int v)
{
	return f[u] > f[v]; 
}

inline void dfs1(int u)
{
	std::vector<int> f_v(0); 

	f[u] = 1; 
	forson(u)
	{
		fa[v] = u; 
		dfs1(v); 

		f_v.push_back(v); 
	}

	std::sort(f_v.begin(), f_v.end(), cmp); 

	cntson[u] = f_v.size(); 
	if (!cntson[u])
		return; 

	if (cntson[u] == 1)
		f[u] = 1 + f[f_v[0]];  
	else if (u == 1)
		f[u] = 1 + f[f_v[0]] + f[f_v[1]] + cntson[u] - 2; 
	else
		f[u] = 1 + f[f_v[0]] + cntson[u] - 1; 

	//printf("%d: %d\n", u, f[u]); 
}

inline void dfs2(int u)
{
	std::vector<int> f_v(0); 

	f[u] = 1; 
	forson(u)
		f_v.push_back(v); 

	if (u != 1)
	{
		f[0] = g[u], f_v.push_back(0); 
	}
	std::sort(f_v.begin(), f_v.end(), cmp); 

	int tmp = f_v.size(); 
	if (tmp == 1)
		relax(ans, 1 + f[f_v[0]]);  
	else
		relax(ans, 1 + f[f_v[0]] + f[f_v[1]] + tmp - 2); 

	int sum = 1; 
	for (int i = 0; i < tmp && i < 1; ++i)
		sum += f[f_v[i]]; 
	for (int i = 1; i < tmp; ++i)
		++sum; 

	for (int i = 0; i < tmp; ++i)
	{
		int v = f_v[i]; 
		if (v == 0)
			continue; 

		if (i > 0)
			g[v] = sum - 1; 
		else
			g[v] = sum - f[v]; 

	//	printf("%d %d\n", v, g[v]); 
	}

	forson(u)
		dfs2(v); 
}

int main()
{
	int T; 
	read(T); 
	while (T--)
	{
		read(n); 

		ect = ans = 0; 
		for (int i = 1; i <= n; ++i)
			adj[i] = 0; 
		for (int i = 1; i < n; ++i)
		{
			int u, v; 
			read(u), read(v); 
			addEdge(u, v), addEdge(v, u); 
		}

		dfs1(1); 
		ans = f[1]; 
		dfs2(1); 

		putint(ans), putchar('\n'); 
	}
	return 0; 
}