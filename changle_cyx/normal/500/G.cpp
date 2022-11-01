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
	static int buf[25], *tail = buf; 
	if (!x)
		putchar('0'); 
	else
	{
		for (; x; x /= 10) *++tail = x % 10 + '0'; 
		for (; tail != buf; --tail) putchar(*tail); 
	}
}


template <class T>
inline void tense(T &x, const T &y)
{
	if (x > y)
		x = y; 
}

typedef long long s64; 

const int MaxLog = 18; 
const int MaxN = 2e5 + 5; 
const s64 INF_s64 = 1145141919810114514LL; 

namespace tree
{
	int log_val[MaxN << 1]; 
	int dep[MaxN], fir[MaxN]; 
	int seq[MaxN << 1], n_seq; 
	int mind[MaxLog + 1][MaxN << 1]; 

	int ect, adj[MaxN]; 
	int to[MaxN << 1], nxt[MaxN << 1]; 

	#define foredge(u) for (int e = adj[u], v; v = to[e], e; e = nxt[e])

	inline int min_dep(int u, int v)
	{
		return dep[u] < dep[v] ? u : v; 
	}

	inline void addEdge(int u, int v)
	{
		nxt[++ect] = adj[u]; 
		adj[u] = ect; 
		to[ect] = v; 
	}

	inline void dfs_init(int u, int pre)
	{
		seq[++n_seq] = u; 
		fir[u] = n_seq; 

		foredge(u)
			if (v != pre)
			{
				dep[v] = dep[u] + 1; 
				dfs_init(v, u); 

				seq[++n_seq] = u; 
			}
	}

	inline void RMQ_init()
	{
		log_val[0] = -1; 
		for (int i = 1; i <= n_seq; ++i)
		{
			mind[0][i] = seq[i]; 
			log_val[i] = log_val[i >> 1] + 1; 
		}
		for (int j = 1; j <= MaxLog; ++j)
			for (int i = 1; i + (1 << j) - 1 <= n_seq; ++i)
				mind[j][i] = min_dep(mind[j - 1][i], mind[j - 1][i + (1 << (j - 1))]); 
	}

	inline int query_lca(int u, int v)
	{
		int l = fir[u], r = fir[v]; 
		if (l > r) std::swap(l, r); 

		int k = log_val[r - l + 1]; 
		return min_dep(mind[k][l], mind[k][r - (1 << k) + 1]); 
	}

	inline int query_dis(int u, int v)
	{
		return dep[u] + dep[v] - (dep[query_lca(u, v)] << 1); 
	}

	inline bool cmp_dep(int u, int v)
	{
		return dep[u] > dep[v]; 
	}
}

#define gcd std::__gcd
using namespace tree; 

inline int exgcd(int a, int b, int &x, int &y)
{
	if (!b)
		return x = 1, y = 0, a; 
	int res = exgcd(b, a % b, y, x); 
	return y -= a / b * x, res; 
}

inline s64 same_dir(int a, int b, int T1, int T2)
{
	int d = gcd(T1, T2), c = b - a; 
	if (c % d) return INF_s64; 

	int p, q; 
	exgcd(T1, T2, p, q); 

	int t = T2 / d; 
	p = (1LL * p * c / d % t + t) % t; 

	return a + 1LL * T1 * p; 
}

inline s64 frac_ceil(s64 a, s64 b)
{
	return a ? (a - 1) / b + 1 : 0; 
}

inline s64 f(int a, int p, int l, int r)
{
	if (l == 0 || r < l)
		return 0; 
	else if (!a)
		return INF_s64; 
	else if (r / a > (l - 1) / a)
		return frac_ceil(l, a); 
	s64 t = f(p % a, a, a - r % a, a - l % a); 
	return t == INF_s64 ? INF_s64 : frac_ceil(l + 1LL * p * t, a); 
}

inline s64 diff_dir(int a, int b, int T1, int T2, int dc)
{
	if ((a + b + dc) & 1)
		return INF_s64; 

	int lef = b - a - dc; 
	int rit = b - a + dc; 
	lef = (lef % T2 + T2) % T2; 
	rit = (rit % T2 + T2) % T2; 

	s64 p = dc * 2 == T2 ? 0 : f(T1, T2, lef, rit); 
	if (p == INF_s64)
		return INF_s64; 

	s64 q = (p * T1 - b + a + dc) / T2; 
//	std::cout << lef << ' ' << rit <<':' << a << ' ' << b << ' ' << T1 << ' ' << T2 << ' ' << dc << ':' << p << ' ' << q << '\n'; 

	return (p * T1 + q * T2 + a + b + dc) >> 1;  
}

inline void solve()
{
	int u1, v1, u2, v2; 
	read(u1), read(v1), read(u2), read(v2); 

	static int cur[4]; 
	cur[0] = query_lca(u1, u2); 
	cur[1] = query_lca(u1, v2); 
	cur[2] = query_lca(v1, u2); 
	cur[3] = query_lca(v1, v2); 
	std::sort(cur, cur + 4, cmp_dep); 

	int c1 = cur[0], c2 = cur[1]; 
	if (c1 == c2 && dep[c1] < std::max(dep[query_lca(u1, v1)], dep[query_lca(u2, v2)]))
	{
		puts("-1"); 
		return; 
	}

	int dc = query_dis(c1, c2); 
	int d1 = query_dis(u1, v1), d2 = query_dis(u2, v2); 
	int t1 = query_dis(u1, c1), t2 = query_dis(u1, c2); 
	int t3 = query_dis(u2, c1), t4 = query_dis(u2, c2); 
	if (t1 <= t2)
		t2 += query_dis(v1, c2) << 1; 
	else
		t1 += query_dis(v1, c1) << 1; 

	if (t3 <= t4)
		t4 += query_dis(v2, c2) << 1; 
	else
		t3 += query_dis(v2, c1) << 1; 

	s64 ans = INF_s64; 
	tense(ans, same_dir(t1, t3, d1 << 1, d2 << 1)); 
	tense(ans, same_dir(t2, t4, d1 << 1, d2 << 1)); 
	tense(ans, diff_dir(t1, t4, d1 << 1, d2 << 1, dc)); 
	tense(ans, diff_dir(t2, t3, d1 << 1, d2 << 1, dc)); 

	if (ans == INF_s64)
		puts("-1"); 
	else
	{
		putint(ans); 
		putchar('\n'); 
	}
}

int n, m; 

int main()
{
	read(n); 
	for (int i = 1; i < n; ++i)
	{
		int u, v; 
		read(u), read(v); 
		addEdge(u, v); 
		addEdge(v, u); 
	}

	dfs_init(1, 0); 
	RMQ_init(); 

	read(m); 
	while (m--)
		solve(); 

	return 0; 
}