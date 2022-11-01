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

typedef long long s64; 

#define lcc x << 1, l, mid
#define rcc x << 1 | 1, mid + 1, r
#define trav(u) for (halfEdge *e = adj[u]; e; e = e->next)

const int MaxNV = 4e5 + 5; 
const int MaxNE = MaxNV << 1; 
const int MaxNS = MaxNV << 2; 

struct halfEdge
{
	int v; 
	halfEdge *next; 
}adj_pool[MaxNE], *adj[MaxNV], *adj_tail = adj_pool; 

int n, m, c[MaxNV]; 
int dfs_clock, dfn[MaxNV][2], idx[MaxNV]; 

int tag[MaxNS]; 
s64 sum[MaxNS]; 

inline void addEdge(int u, int v)
{
	adj_tail->v = v; 
	adj_tail->next = adj[u]; 
	adj[u] = adj_tail++; 
}

inline void dfs_init(int u, int pre)
{
	idx[dfn[u][0] = ++dfs_clock] = u; 
	trav(u) if (e->v != pre)
		dfs_init(e->v, u); 
	dfn[u][1] = dfs_clock; 
}

inline void upt(int x)
{
	sum[x] = sum[x << 1] | sum[x << 1 | 1]; 
}

inline void dnt(int x)
{
	if (tag[x])
	{
		tag[x << 1] = tag[x << 1 | 1] = tag[x]; 
		sum[x << 1] = sum[x << 1 | 1] = 1LL << tag[x]; 
		tag[x] = 0; 
	}
}

inline void seg_init(int x, int l, int r)
{
	if (l == r) return (void)(sum[x] = 1LL << c[idx[l]]); 
	int mid = l + r >> 1; 
	seg_init(lcc), seg_init(rcc), upt(x); 
}

inline void modify(int x, int l, int r, int u, int v, int val)
{
	if (u <= l && r <= v) return (void)(tag[x] = val, sum[x] = 1LL << val); 
	int mid = l + r >> 1; dnt(x); 
	if (u <= mid) modify(lcc, u, v, val); 
	if (v > mid) modify(rcc, u, v, val); 
	upt(x); 
}

inline s64 query(int x, int l, int r, int u, int v)
{
	if (u <= l && r <= v) return sum[x]; 
	s64 res = 0; int mid = l + r >> 1; dnt(x); 
	if (u <= mid) res |= query(lcc, u, v); 
	if (v > mid) res |= query(rcc, u, v); 
	return res; 
}
 

inline int cnt(s64 x)
{
	int res = 0; 
	while (x) ++res, x ^= x & -x; 
	return res; 
}

int main()
{
#ifdef orzczk
	freopen("CF620E.in", "r", stdin); 
#endif

	read(n), read(m); 
	for (int i = 1; i <= n; ++i)
		read(c[i]); 
	for (int i = 1; i < n; ++i)
	{
		int u, v; 
		read(u), read(v); 
		addEdge(u, v), addEdge(v, u); 
	}
	
	dfs_init(1, 0); 
	seg_init(1, 1, n); 

	while (m--)
	{
		int opt, x, y; 
		read(opt), read(x); 
		if (opt == 1) read(y), modify(1, 1, n, dfn[x][0], dfn[x][1], y); 
		else printf("%d\n", cnt(query(1, 1, n, dfn[x][0], dfn[x][1]))); 
	}

	return 0; 
}