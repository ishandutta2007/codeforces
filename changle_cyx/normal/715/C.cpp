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
inline bool tense(T &x, const T &y)
{
	return x > y ? x = y, true : false; 
}

template <class T>
inline bool relax(T &x, const T &y)
{
	return x < y ? x = y, true : false; 
}

typedef long long s64; 
typedef std::vector<int> vi; 

#define debug(x) std::cerr << #x << " = " << x << '\n'
#define trav(u) for (halfEdge *e = adj[u]; e; e = e->next)
#define edge(u) trav(u) if (e->v != fa[u] && !vis[e->v])

const int MaxNV = 1e5 + 5; 
const int MaxNE = MaxNV << 1; 

struct halfEdge
{
	int v, w; 
	halfEdge *next; 
}adj_pool[MaxNE], *adj[MaxNV], *adj_tail = adj_pool; 

s64 ans; 

int n, mod, pw[MaxNV]; 
int f[MaxNV], g[MaxNV]; 

bool vis[MaxNV]; 
int sze[MaxNV], son[MaxNV], dep[MaxNV]; 
int fa[MaxNV], stk[MaxNV], top, G, min_son; 

std::map<int, int> S; 

inline int exgcd(int a, int b, int &x, int &y)
{
	if (!b) return x = 1, y = 0, a; 
	int res = exgcd(b, a % b, y, x); 
	return y -= a / b * x, res; 
}

inline int get_inv(int x)
{
	int res, y; 
	return exgcd(x, mod, res, y), (res % mod + mod) % mod; 
}

inline void addEdge(int u, int v, int w)
{
	adj_tail->v = v; 
	adj_tail->w = w; 
	adj_tail->next = adj[u]; 
	adj[u] = adj_tail++; 
}

inline void dfs_size(int u)
{
	sze[u] = 1, son[u] = 0;
	stk[++top] = u; 
	edge(u)
	{
		fa[e->v] = u; 
		dfs_size(e->v); 
		
		sze[u] += sze[e->v]; 
		relax(son[u], sze[e->v]); 
	}
}

inline void calc_G(int st)
{
	top = fa[st] = 0; 
	dfs_size(st); 
	
	min_son = MaxNV; 
	for (int i = 1; i <= top; ++i)
	{
		int u = stk[i]; fa[u] = 0; 
		relax(son[u], top - sze[u]); 
		if (tense(min_son, son[u])) G = u; 
	}
}

inline void dfs_query(int u)
{
//	debug(u), debug(f[u]), debug(g[u]), debug(dep[u]), debug(pw[dep[u]]), debug(get_inv(pw[dep[u]])), debug((mod - 1LL * g[u] * get_inv(pw[dep[u]]) % mod + mod) % mod); 
//	debug(S[(mod - 1LL * g[u] * get_inv(pw[dep[u]]) % mod + mod) % mod]), puts(""); 

	ans += S[(mod - 1LL * g[u] * get_inv(pw[dep[u]]) % mod + mod) % mod]; 
	edge(u)
	{
		fa[e->v] = u; 
		dep[e->v] = dep[u] + 1; 

		f[e->v] = (1LL * pw[dep[u]] * e->w + f[u]) % mod; 
		g[e->v] = (10LL * g[u] + e->w) % mod; 

		dfs_query(e->v); 
	}
}

inline void dfs_modify(int u)
{
	++S[f[u]]; edge(u) dfs_modify(e->v); 
}

inline void point_solve(int st)
{
	calc_G(st); 

//	puts("============="); 
//	debug(G); 

	S.clear(); 
	S[0] = 1; 

	vi T(0); 
	edge(G)
	{
		T.push_back(e->v); 

		fa[e->v] = G; 
		dep[e->v] = 1; 
		f[e->v] = g[e->v] = e->w % mod; 
//		puts("-----"); 

		dfs_query(e->v); 
		dfs_modify(e->v); 
	}

	S.clear(); 
	for (int i = T.size() - 1; i >= 0; --i)
	{
//		puts("-----"); 
		dfs_query(T[i]); 
		dfs_modify(T[i]); 
	}

	vis[G] = true; ans += S[0]; 
	edge(G) point_solve(e->v); 
}

int main()
{
#ifdef orzczk
	freopen("CF715C.in", "r", stdin); 
#endif

	read(n), read(mod); 

	pw[0] = 1; 
	for (int i = 1; i <= n; ++i)
		pw[i] = 10LL * pw[i - 1] % mod; 
	for (int i = 1; i < n; ++i)
	{
		int u, v, w; 
		read(u), read(v), read(w); ++u, ++v; 
		addEdge(u, v, w), addEdge(v, u, w); 
	}

	point_solve(1); 

	std::cout << ans << std::endl; 

	return 0; 
}