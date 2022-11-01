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

const int MaxLog = 20; 
const int mod = 1e9 + 7; 
const int MaxNV = 4e5 + 5; 
const int MaxNE = MaxNV << 1; 

struct halfEdge
{
	int v; 
	halfEdge *next; 
}adj_pool[MaxNE], *adj[MaxNV], *adj_tail = adj_pool; 

std::vector<int> S[MaxNV], T[MaxNV]; 
int ans, dfn_seq[MaxNV], g[MaxNV], f[MaxNV], idx[MaxNV]; 
int n, phi[MaxNV], miu[MaxNV], a[MaxNV], dep[MaxNV]; 

inline void add(int &x, const int &y) {x += y; if (x >= mod) x -= mod; if (x < 0) x += mod;}
inline void addEdge(int u, int v) {adj_tail->v = v; adj_tail->next = adj[u]; adj[u] = adj_tail++;}
inline int qpow(int x, int y) {int res = 1; for (; y; y >>= 1, x = 1LL * x * x % mod) if (y & 1) res = 1LL * res * x % mod; return res;}

inline void sieve(int n)
{
	static bool sie[MaxNV]; 
	static int cnt, pri[MaxNV]; 
	
	phi[1] = miu[1] = 1; 
	for (int i = 2; i <= n; ++i)
	{
		if (!sie[i])
			phi[pri[++cnt] = i] = i - 1, miu[i] = -1; 
		for (int j = 1; j <= cnt && 1LL * pri[j] * i <= n; ++j)
		{
			int x = pri[j] * i; 
			sie[x] = true; 
			if (i % pri[j] == 0)
			{
				miu[x] = 0; 
				phi[x] = pri[j] * phi[i]; 
				break; 
			}
			else
			{
				miu[x] = -miu[i]; 
				phi[x] = (pri[j] - 1) * phi[i]; 
			}
		}
	}
}

namespace init_dfs
{
	int dfs_clock, dfn[MaxNV], fir[MaxNV], logval[MaxNV << 1]; 
	int tot, seq[MaxNV << 1], minv[MaxLog + 1][MaxNV << 1]; 
	
	inline bool cmp(const int &x, const int &y) {return dfn[x] < dfn[y];}
	inline int minpos(const int &x, const int &y) {return dfn[x] < dfn[y] ? x : y;}
	
	inline void dfs_init(int u, int pre)
	{
		dep[u] = dep[pre] + 1; 
		dfn[u] = ++dfs_clock, seq[fir[u] = ++tot] = u; 
		for (halfEdge *e = adj[u]; e; e = e->next)
			if (e->v != pre) dfs_init(e->v, u), seq[++tot] = u; 
	}
	
	inline void init()
	{
		dfs_init(1, 0); 
		logval[0] = -1; 
		for (int i = 1; i <= tot; ++i) minv[0][i] = seq[i]; 
		for (int i = 1; i <= tot; ++i) logval[i] = logval[i >> 1] + 1; 
		for (int j = 1; j <= MaxLog; ++j)
			for (int i = 1; i + (1 << j) - 1 <= tot; ++i)
				minv[j][i] = minpos(minv[j - 1][i], minv[j - 1][i + (1 << j - 1)]); 
		
		for (int i = 1; i <= n; ++i) dfn_seq[i] = i; 
		std::sort(dfn_seq + 1, dfn_seq + n + 1, cmp); 
		
		for (int i = 1; i <= n; ++i)
			for (int j = i; j <= n; j += i)
				T[idx[j]].push_back(i); 
		for (int i = 1; i <= n; ++i)
		{
			int u = dfn_seq[i], val = a[u]; 
			for (int j = 0, jm = T[u].size(); j < jm; ++j)
				S[T[u][j]].push_back(u); 
		}
	}
	
	inline int query_lca(int u, int v)
	{
		int l = fir[u], r = fir[v]; 
		if (l > r) std::swap(l, r); 
		
		int k = logval[r - l + 1]; 
		return minpos(minv[k][l], minv[k][r - (1 << k) + 1]); 
	}
}using init_dfs::query_lca; 

namespace vir_tree
{
	bool tag[MaxNV]; 
	
	int res1, res2; 
	int tot_vir, par[MaxNV], vir[MaxNV], dis[MaxNV], f[MaxNV], g[MaxNV]; 
	int ect, rt, adj[MaxNV], nxt[MaxNE], to[MaxNE], len[MaxNE]; 
	
	inline void addEdge(int u, int v, int w)
	{
	//	printf("edge = %d %d: %d\n", u, v, w); 
		nxt[++ect] = adj[u], to[ect] = v, len[ect] = w, adj[u] = ect; 
	}
	
	inline bool build_vir(int d)
	{
		static int stk[MaxNV], top; 
		
		tot_vir = ect = 0; 
		for (int i = 0, im = S[d].size(); i < im; ++i)
			tag[vir[++tot_vir] = S[d][i]] = true; 
		if (!tot_vir) return false; 
		
		par[stk[rt = top = 1] = vir[1]] = 0; 
		for (int i = 2, tmp = tot_vir; i <= tmp; ++i)
		{
			int u = vir[i], lca = query_lca(u, stk[top]); 
			while (dep[lca] < dep[stk[top]])
			{
				if (dep[stk[top - 1]] < dep[lca]) par[stk[top]] = lca; 
				--top; 
			}
			if (lca != stk[top]) par[vir[++tot_vir] = stk[++top] = lca] = stk[top - 1]; 
			par[stk[++top] = u] = lca; 
		}
		
		rt = stk[1]; 
		for (int i = 1; i <= tot_vir; ++i) if (vir[i] != rt)
			addEdge(par[vir[i]], vir[i], dep[vir[i]] - dep[par[vir[i]]]); 
		return true; 
	}
	
	inline void dfs(int u, int pre)
	{
		f[u] = tag[u] ? 1LL * phi[a[u]] * phi[a[u]] % mod : 0; 
		
		g[u] = tag[u] * phi[a[u]]; 
		for (int e = adj[u], v; v = to[e], e; e = nxt[e])
			if (v != pre)
			{
				dis[v] = dis[u] + len[e]; 
				dfs(v, u); 
				
				add(f[u], 2LL * g[u] * g[v] % mod); 
				add(g[u], g[v]); 
			}
//		printf("%d: : ff = %d, gg = %d\n", u, f[u], g[u]); 
		add(res1, 1LL * dis[u] * f[u] % mod); 
	}
	
	inline int solve()
	{	
		int totphi = 0; 
		res1 = res2 = 0; 
//		for (int i = 1; i <= tot_vir; ++i)
//			printf("%d: par = %d, rt = %d\n", vir[i], par[vir[i]], rt); 
		for (int i = 1; i <= tot_vir; ++i)
			if (tag[vir[i]])
				add(totphi, phi[a[vir[i]]]); 
		
		dfs(rt, 0); 
		
		for (int i = 1; i <= tot_vir; ++i)
			if (tag[vir[i]])
				add(res2, 2LL * dis[vir[i]] * phi[a[vir[i]]] % mod * totphi % mod); 
//		printf("ans = %d\n", (res2 - res1 + mod) % mod); 
		
//		puts(""); 
		
		add(res1, res1); 
		
		for (int i = 1; i <= tot_vir; ++i)
			adj[vir[i]] = tag[vir[i]] = 0; 
		return (res2 - res1 + mod) % mod; 
	}
}

int main()
{
//	freopen("sm.in", "r", stdin); 
//	freopen("sm.out", "w", stdout); 
	
	read(n); sieve(n); 
	for (int i = 1; i <= n; ++i) read(a[i]), idx[a[i]] = i; 
	for (int i = 1; i < n; ++i)
	{
		int u, v; 
		read(u), read(v); 
		addEdge(u, v), addEdge(v, u); 
	}
	
	init_dfs::init(); 
	for (int d = 1; d <= n; ++d)
		if (vir_tree::build_vir(d))
			g[d] = vir_tree::solve(); 
	for (int d = 1; d <= n; ++d)
		for (int k = d; k <= n; k += d)
			add(f[d], 1LL * miu[k / d] * g[k] % mod); 
	
	ans = 0; 
	for (int d = 1; d <= n; ++d)
		add(ans, 1LL * d * qpow(phi[d], mod - 2) % mod * f[d] % mod); 
	
	std::cout << 1LL * ans * qpow(n, mod - 2) % mod * qpow(n - 1, mod - 2) % mod << std::endl; 
	
	fclose(stdin); 
	fclose(stdout); 
	return 0; 
}