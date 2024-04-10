#include <bits/stdc++.h>

template <class T>
inline void read(T &x)
{
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

template <class T>
inline void tense(T &x, const T &y)
{
	if (x > y)
		x = y; 
}

template <class T>
inline void relax(T &x, const T &y)
{
	if (x < y)
		x = y; 
}

typedef std::pair<int, int> pi; 
typedef std::vector<pi> vpi; 
#define mp(x, y) std::make_pair(x, y)

const int MaxNV = 4e3 + 5; 
const int MaxNE = 4e6 + 5; 
const int INF = 0x3f3f3f3f; 

struct halfEdge
{
	int v; 
	halfEdge *next; 
}; 

struct graph
{
	halfEdge *adj[MaxNV]; 
	halfEdge adj_pool[MaxNE], *adj_tail; 
	inline void init()
	{
		adj_tail = adj_pool; 
		for (int i = 0; i < MaxNV; ++i)
			adj[i] = 0; 
	}
	inline void addEdge(const int &u, const int &v)
	{
		adj_tail->next = adj[u], adj_tail->v = v, adj[u] = adj_tail++; 
	}
}G, DAG; 

vpi V, U;  
int n, m, ind[MaxNV], f[MaxNV]; 

int dfs_clock, dfn[MaxNV], low[MaxNV]; 
int top, totcol, stk[MaxNV], col[MaxNV]; 

#define trav(u, G) for (halfEdge *e = G.adj[u]; e; e = e->next)

inline void dfs(const int &u)
{
	dfn[u] = low[u] = ++dfs_clock; 
	stk[++top] = u; 
	trav(u, G)
	{
		if (!dfn[e->v])
			dfs(e->v), tense(low[u], low[e->v]); 
		else if (!col[e->v])
			tense(low[u], dfn[e->v]); 
	}
	if (dfn[u] == low[u])
	{
		++totcol; 
		do
			col[stk[top--]] = totcol; 
		while (stk[top + 1] != u); 
	}
}

int main()
{
	G.init(), DAG.init(); 
	
	read(n), read(m); 
	for (int i = 1; i <= n; ++i)
	{
		static char s[MaxNV]; 
		scanf("%s", s + 1); 
		for (int j = 1; j <= m; ++j)
		{
			if (s[j] == '<')
				U.push_back(mp(i, j + n)), G.addEdge(i, j + n); 
			else if (s[j] == '>')
				U.push_back(mp(i, j + n)), G.addEdge(j + n, i); 
			else
				V.push_back(mp(i, j + n)); 
		}
	}
	
	n += m; 
	
	for (int u = 1; u <= n; ++u)
		if (!dfn[u])
			dfs(u); 
	
	if (totcol != n)
	{
		puts("No"); 
		return 0; 
	}
	
	dfs_clock = totcol = 0; 
	memset(dfn, 0, sizeof(dfn)); 
	memset(col, 0, sizeof(col)); 
	
	for (auto e : V)
		G.addEdge(e.first, e.second), G.addEdge(e.second, e.first); 
	
	for (int u = 1; u <= n; ++u)
		if (!dfn[u])
			dfs(u); 
	
//	for (int u = 1; u <= n; ++u)
//		printf("%d: %d\n", u, col[u]); 
	
	for (auto e : U)
		if (col[e.first] == col[e.second])
		{
			puts("No"); 
			return 0; 
		}
			
	for (int u = 1; u <= n; ++u)
		trav(u, G)
			if (col[u] != col[e->v])
			{
				DAG.addEdge(col[u], col[e->v]); 
				++ind[col[e->v]]; 
			}
	
	static int que[MaxNV], qr; 
	
	for (int i = 1; i <= totcol; ++i)
		if (!ind[i])
		{
			que[++qr] = i; 
			f[i] = 1; 
		}
	
	for (int ql = 1; ql <= qr; ++ql)
	{
		int u = que[ql]; 
//		printf("::%d: %d\n", u, f[u]); 
		trav(u, DAG)
		{
			relax(f[e->v], f[u] + 1); 
			if (!--ind[e->v]) que[++qr] = e->v; 
		}
	}
	
	puts("Yes");  
	for (int i = 1; i <= n - m; ++i)
		printf("%d ", f[col[i]]); puts(""); 
	for (int i = n - m + 1; i <= n; ++i)
		printf("%d ", f[col[i]]);   
	
	return 0; 
}