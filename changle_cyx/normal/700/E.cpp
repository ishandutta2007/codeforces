#include <bits/stdc++.h>

template <class T>
inline void relax(T &x, const T &y)
{
	if (x < y) x = y; 
}

const int base = 26; 
const int MaxN = 4e5 + 5; 
const int MaxNode = MaxN * 50; 

struct node
{
	bool is; 
	int par, pos, maxl, trans[base]; 
}tr[MaxN]; 

struct halfEdge
{
	int v; 
	halfEdge *next; 
}adj_pool[MaxN], *adj[MaxN], *adj_tail = adj_pool; 

#define trav(u) for (halfEdge *e = adj[u]; e; e = e->next)

int n; 
char s[MaxN]; 

int f[MaxN], ans; 
int tot = 1, lst = 1, nowlen; 

int rt[MaxN]; 
int cnt, sze[MaxNode], lc[MaxNode], rc[MaxNode]; 

inline void addEdge(int u, int v)
{
//	printf("%d %d\n", u, v); 
	adj_tail->v = v; 
	adj_tail->next = adj[u]; 
	adj[u] = adj_tail++; 
}

inline void extend(int c)
{
	int x = lst; 
	tr[lst = ++tot].maxl = ++nowlen; 
	tr[lst].pos = nowlen, tr[lst].is = true; 
	for (; x && !tr[x].trans[c]; x = tr[x].par)
		tr[x].trans[c] = lst; 
	if (!x) tr[lst].par = 1; 
	else
	{
		int y = tr[x].trans[c]; 
		if (tr[x].maxl + 1 == tr[y].maxl)
			tr[lst].par = y; 
		else
		{
			int p = ++tot; 
			tr[p] = tr[y], tr[p].is = false; 
			tr[p].maxl = tr[x].maxl + 1; 
			tr[y].par = tr[lst].par = p; 
			for (; x && tr[x].trans[c] == y; x = tr[x].par)
				tr[x].trans[c] = p; 
		}
	}
}

inline void build(int &x, int l, int r, int pos)
{
	if (l == r) return (void)(sze[x = ++cnt] = 1); 
	int mid = l + r >> 1; 

	sze[x = ++cnt] = 1; 
	pos <= mid ? build(lc[x], l, mid, pos) : build(rc[x], mid + 1, r, pos); 
}

inline int merge(int u, int v, int l, int r)
{
	if (!u || !v) return u + v; 
	if (l == r) return sze[++cnt] = sze[u] + sze[v], cnt; 
	
	int res = ++cnt; 
	int mid = l + r >> 1; 
	
	lc[res] = merge(lc[u], lc[v], l, mid); 
	rc[res] = merge(rc[u], rc[v], mid + 1, r); 
	sze[res] = sze[u] + sze[v]; 

	return res; 
}

inline int query(int x, int l, int r, int u, int v)
{
	if (u <= l && r <= v) return sze[x]; 
	int mid = l + r >> 1, res = 0; 
	if (u <= mid) res += query(lc[x], l, mid, u, v); 
	if (v > mid) res += query(rc[x], mid + 1, r, u, v); 
	return res; 
}

inline void dfs_init(int u)
{
	trav(u)
	{
		dfs_init(e->v); 
		rt[u] = merge(rt[u], rt[e->v], 1, n); 
	}
}

inline void dfs_ans(int u, int mx)
{
	if (u != 1)
	{
		if (mx == 1) f[mx = u] = 1; 
		else
		{
			int qr = tr[u].pos; 
			int ql = qr - tr[u].maxl + (tr[tr[mx].par].maxl + 1); 
			if (query(rt[mx], 1, n, ql, qr) > 1)
				f[u] = f[mx] + 1, mx = u; 
			else
				f[u] = f[mx]; 
		}
	}
	else
		mx = 1; 

//	printf("f[%d]: %d\n", u, f[u]); 
	relax(ans, f[u]); 
	trav(u) dfs_ans(e->v, mx); 
}

inline void build_tree()
{
	for (int i = 2; i <= tot; ++i)
	{
		addEdge(tr[i].par, i); 
//		printf("%d: %d %d\n", i, tr[i].pos, tr[i].maxl); 
		if (tr[i].is) build(rt[i], 1, n, tr[i].maxl); 
	}
}

int main()
{
    scanf("%d", &n); 
	scanf("%s", s + 1); 
	for (int i = 1; i <= n; ++i)
		extend(s[i] - 'a'); 
	build_tree(), dfs_init(1), dfs_ans(1, 0); 

	printf("%d\n", ans); 

	return 0; 
}