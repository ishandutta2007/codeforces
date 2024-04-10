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
inline void putint(T x)
{
	static char buf[20], *tail = buf; 
	if (x)
	{
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
	else
		putchar('0'); 
}

template <class T>
inline bool relax(T &x, const T &y)
{
	return x < y ? x = y, true : false; 
}

#define trav(u) for (halfEdge *e = adj[u]; e; e = e->next)

const int MaxNV = 1e6 + 5; 
const int MaxNE = MaxNV << 1; 

struct halfEdge
{
	int v; 
	halfEdge *next; 
}adj_pool[MaxNE], *adj[MaxNV], *adj_tail = adj_pool; 

int n; 
int son[MaxNV], maxdep[MaxNV]; 

int ans[MaxNV], maxans[MaxNV]; 
int pool[MaxNE], *tail = pool, *f[MaxNV]; 

inline void addEdge(int u, int v)
{
	adj_tail->v = v; 
	adj_tail->next = adj[u]; 
	adj[u] = adj_tail++; 
}

inline void get_memory(int u)
{
	f[u] = tail; 
	tail += maxdep[u] + 1; 
}

inline void dfs1(int u, int pre)
{
	trav(u) if (e->v != pre)
	{
		dfs1(e->v, u); 
		if (relax(maxdep[u], maxdep[e->v] + 1))
			son[u] = e->v;  
	}
}

inline void dfs2(int u, int pre)
{
	if (son[u])
	{
		f[son[u]] = f[u] + 1; 
		dfs2(son[u], u); 
	}

	f[u][0] = 1; 
	ans[u] = ans[son[u]] + 1; 
	maxans[u] = maxans[son[u]]; 
	
	if (maxans[u] <= 1)
		maxans[u] = 1, ans[u] = 0; 

	trav(u) if (e->v != pre && e->v != son[u])
	{
		get_memory(e->v); 
		dfs2(e->v, u); 

		for (int i = 1; i <= maxdep[e->v] + 1; ++i)
		{
			f[u][i] += f[e->v][i - 1]; 
			if (f[u][i] > maxans[u] || f[u][i] == maxans[u] && i < ans[u])
				maxans[u] = f[u][i], ans[u] = i; 
		}
	}
}

int main()
{
#ifdef orzczk
	freopen("input.txt", "r", stdin); 
#endif

	read(n); 
	for (int i = 1; i < n; ++i)
	{
		int u, v; 
		read(u), read(v); 
		addEdge(u, v), addEdge(v, u); 
	}

	dfs1(1, 0); 
	get_memory(1); 
	dfs2(1, 0); 

	for (int i = 1; i <= n; ++i)
		putint(ans[i]), putchar('\n'); 

	return 0; 
}