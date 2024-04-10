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

namespace ModuloCalculator
{
	const int mod = 998244353; 

	inline void add(int &x, const int &y)
	{
		if (x += y, x >= mod)
			x -= mod; 
	}
	inline void dec(int &x, const int &y)
	{
		if (x -= y, x < 0)
			x += mod; 
	}
	inline int plus(int x, const int &y)
	{
		return add(x, y), x; 
	}
	inline int minus(int x, const int &y)
	{
		return dec(x, y), x; 
	}
	inline void addprod(int &x, const int &y, const int &z)
	{
		x = (1LL * y * z + x) % mod; 
	}
	inline void decprod(int &x, const int &y, const int &z)
	{
		x = (1LL * y * z - x + mod) % mod; 
		x = minus(0, x); 
	}
	inline int qpow(int x, int y)
	{
		int res = 1; 
		for (; y; y >>= 1, x = 1LL * x * x % mod)
			if (y & 1)
				res = 1LL * res * x % mod; 
		return res; 
	}
}
using namespace ModuloCalculator; 

const int MaxN = 2e5 + 5;
const int MaxE = MaxN << 1; 

int n; 
int ect, adj[MaxN], nxt[MaxE], to[MaxE], id[MaxE]; 

int f[MaxN], g[MaxN], h[MaxN]; 

#define foredge(u) for (int e = adj[u], v; v = to[e], e; e = nxt[e])

inline void addEdge(int u, int v, int w)
{
	nxt[++ect] = adj[u]; 
	adj[u] = ect; 
	to[ect] = v; 
	id[ect] = w; 
}

inline void dfs(int u, int pre = 0, int dwn = 0)
{
	foredge(u)
		if (v != pre)
			dfs(v, u, id[e]); 

	int tot = 0, i = 0; 
	static int son[MaxN], pref[MaxN], sufg[MaxN]; 

	foredge(u)
		if (v != pre)
			son[++tot] = v; 

	pref[0] = sufg[tot + 1] = 1; 
	for (int i = 1; i <= tot; ++i)
		pref[i] = 1LL * pref[i - 1] * f[son[i]] % mod;  
	for (int i = tot; i >= 1; --i)
		sufg[i] = 1LL * sufg[i + 1] * g[son[i]] % mod; 

	f[u] = h[u] = sufg[1]; 

	int resg = 1; 
	foredge(u)
		if (v != pre)
		{
			++i; 
			
			int cur = 1LL * pref[i - 1] * sufg[i + 1] % mod * h[v] % mod; 
			
			add(f[u], cur); 
			if (id[e] < dwn)
				resg = 1LL * resg * g[v] % mod, add(g[u], cur); 
			else
				resg = 1LL * resg * f[v] % mod, add(h[u], cur); 
		}
	add(g[u], resg); 
}

int main()
{
	read(n); 
	for (int i = 1; i < n; ++i)
	{
		int u, v; 
		read(u), read(v); 
		addEdge(u, v, i); 
		addEdge(v, u, i); 
	}

	dfs(1); 

	std::cout << f[1] << '\n'; 

	return 0; 
}