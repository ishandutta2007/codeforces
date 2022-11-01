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
	static char buf[15], *tail = buf; 
	if (!x)
	{
		putchar('0'); 
		return; 
	}

	for (; x; x /= 10) *++tail = x % 10 + '0'; 
	for (; tail != buf; --tail) putchar(*tail); 
}

const int MaxLog = 18; 
const int MaxM = 3e2 + 5; 
const int MaxNV = 1e5 + 5; 
const int MaxNE = MaxNV << 1; 

const int mod = 1e9 + 7; 

int n, Q; 
int anc[MaxNV][MaxLog + 1], dep[MaxNV]; 
int dfs_clock, dfn[MaxNV], rdfn[MaxNV]; 

int adj[MaxNV]; 
int ect, to[MaxNE], nxt[MaxNE]; 

int f[MaxNV][MaxM]; 
int bit[MaxNV], g[MaxNV]; 

inline bool cmp(int x, int y)
{
	return g[x] < g[y]; 
}

inline void add(int &x, const int &y)
{
	x += y; 
	if (x >= mod)
		x -= mod; 
}

inline void addEdge(int u, int v)
{
	nxt[++ect] = adj[u]; 
	adj[u] = ect; 
	to[ect] = v; 
}

inline void bit_modify(int x, int del)
{
	for (; x <= n; x += x & -x)
		bit[x] += del; 
}

inline int bit_query(int x)
{
	int res = 0; 
	for (; x; x ^= x & -x)
		res += bit[x]; 
	return res; 
}

inline void dfs_init(int u)
{
	dfn[u] = ++dfs_clock; 
	for (int i = 0; anc[u][i]; ++i)
		anc[u][i + 1] = anc[anc[u][i]][i]; 

	for (int e = adj[u]; e; e = nxt[e])
		if (to[e] != anc[u][0])
		{
			int v = to[e]; 
			anc[v][0] = u; 
			dep[v] = dep[u] + 1; 

			dfs_init(v); 
		}
	rdfn[u] = dfs_clock; 
}

inline int query_lca(int u, int v)
{
	if (dep[u] < dep[v])
		std::swap(u, v); 

	for (int d = dep[u] - dep[v], i = 0; d; d >>= 1, ++i)
		if (d & 1)
			u = anc[u][i]; 
	if (u == v)
		return u; 

	for (int i = MaxLog; i >= 0; --i)
		if (anc[u][i] != anc[v][i])
		{
			u = anc[u][i]; 
			v = anc[v][i]; 
		}

	return anc[u][0]; 
}

inline void tree_modify(int u, int del)
{
	bit_modify(dfn[u], del); 
	bit_modify(rdfn[u] + 1, -del); 
}

inline int path_query(int u, int v)
{
	int lca = query_lca(u, v); 
	int res = bit_query(dfn[u]) + bit_query(dfn[v]) - bit_query(dfn[lca]); 
	if (lca != 1)
		res -= bit_query(dfn[anc[lca][0]]); 
	return res; 
}

int main()
{
//	freopen("tree.in", "r", stdin); 
//	freopen("tree.out", "w", stdout); 

	read(n), read(Q); 
	for (int i = 1; i < n; ++i)
	{
		int u, v; 
		read(u), read(v); 
		addEdge(u, v), addEdge(v, u); 
	}

	dfs_init(1); 

	for (int i = 1; i <= Q; ++i)
	{
		int k, m, r; 
		std::vector<int> V(0); 
		read(k), read(m), read(r); 

		for (int i = 0; i < k; ++i)
		{
			int x; 
			read(x); 
			V.push_back(x); 

			tree_modify(x, 1); 
		}

		for (int i = 0; i < k; ++i)
			g[V[i]] = path_query(V[i], r) - 1;
		std::sort(V.begin(), V.end(), cmp); 

		f[0][0] = 1; 
		for (int i = 1; i <= k; ++i)
		{
			int t = g[V[i - 1]]; 
			for (int j = 1; j <= t; ++j)
				f[i][j] = f[i - 1][j - 1]; 
			for (int j = t + 1; j <= m; ++j)
				f[i][j] = (1LL * f[i - 1][j] * (j - t) + f[i - 1][j - 1]) % mod; 
		}

		int ans = 0; 
		for (int j = 1; j <= m; ++j)
			add(ans, f[k][j]); 
		putint(ans), putchar('\n'); 

		for (int i = 0; i < k; ++i)
			tree_modify(V[i], -1); 
	}

	return 0; 
}