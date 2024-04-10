#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

template <class T>
inline void read(T &x)
{
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

const int MaxN = 2e5 + 5; 
const int MaxNV = 4e5 + 5; 
const int MaxNE = 4e5 + 5; 

typedef std::pair<int, int> pi; 
typedef std::vector<pi> vpi; 
#define mp(x, y) std::make_pair(x, y)

#define trav(u) for (halfEdge *e = adj[u]; e; e = e->next)

struct halfEdge
{
	int v; 
	halfEdge *next; 
}; 

halfEdge *adj[MaxNV]; 
halfEdge adj_pool[MaxNE], *adj_tail = adj_pool; 

inline void addEdge(const int &u, const int &v)
{
	adj_tail->next = adj[u], adj_tail->v = v, adj[u] = adj_tail++; 
}

int n, tot, Q; 
int val[MaxN], lc[MaxN], rc[MaxN], dis[MaxN]; 
int ufs_fa[MaxN]; 

vpi V; 

inline int ufs_find(int x)
{
	if (ufs_fa[x] == x)
		return x; 
	return ufs_fa[x] = ufs_find(ufs_fa[x]); 
}

inline void dfs(int u)
{
	if (u <= n) printf("%d ", u); 
	trav(u) dfs(e->v); 
}

int main()
{
	read(n); tot = n; 
	for (int i = 1; i <= (n << 1); ++i)
		ufs_fa[i] = i; 
	
	for (int i = 1; i < n; ++i)
	{
		int x, y; 
		read(x), read(y); 
		
		x = ufs_find(x);
		y = ufs_find(y); 
		
		ufs_fa[x] = ufs_fa[y] = ++tot; 
		addEdge(tot, x), addEdge(tot, y); 
	}
	
	dfs(tot);  
	
	return 0; 
}