//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include <ctime>
#include<list>
#include <numeric>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int128 LLL;
//typedef __int64 LL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<long double, long double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef long double ld;

#define MAXN 500005
//#define MAXN 100

int n, m_my, m_ur;
struct Edge {
	int u, v, d, x;
};

vector<Edge> my, ur;

struct UF {
	int n;
	VI par;
	UF() {}
	UF(int _n) {
		n = _n;
		par = VI(n + 1, 0);
		for (int i = 1; i <= n; i++) par[i] = i;
	}

	int Join(int a, int b) {
		a = Par(a);
		b = Par(b);
		if (a != b) par[a] = b;
		return a != b;
	}

	int Par(int a) {
		if (a == par[a]) return a;
		return par[a] = Par(par[a]);
	}
};

struct Tree {
	VI adj[MAXN];
	int n;
	VI vis;

	int anc[MAXN][20];
	int cst[MAXN][20];
	VI depth;

	Tree() {}
	Tree(int _n) {
		n = _n;
		vis = VI(n + 1, 0);
		depth = VI(n + 1, 0);
	}

	void add(Edge& e) {
		adj[e.u].push_back(e.v);
		adj[e.v].push_back(e.u);
	}

	void dfs(int at, int par, int cost, int marker) {
		depth[at] = depth[par] + 1;
		vis[at] = marker;
		anc[at][0] = par;
		cst[at][0] = cost;
		for (int i = 1; i < 20; i++) {
			anc[at][i] = anc[anc[at][i - 1]][i - 1];
			cst[at][i] = cost;
		}
		for (auto& e : adj[at]) {
			if (par == e) continue;
			dfs(e, at, cost, marker);
		}
	}

	void process() {
		int marker = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i] == 0) {
				marker++;
				dfs(i, i, 1000000001, marker);
			}
		}
	}

	LL dfs(int at, int par) {
		vis[at] = 1;
		LL ret = 0;
		for (int v : adj[at]) {
			if (v != par) {
				LL now = dfs(v, at);
				if (now == -1) return -1;
				ret += now;
			}
		}
		if (at == par) return ret;
		for (int i = 19; i >= 1; i--) {
			// cst[at][i]
			cst[at][i - 1] = MIN(cst[at][i - 1], cst[at][i]);
			cst[anc[at][i - 1]][i - 1] = MIN(cst[anc[at][i - 1]][i - 1], cst[at][i]);
		}
		if (cst[at][0] > 1000000000) return -1;
		return ret + cst[at][0];
	}

	LL solve() {
		vis = VI(n + 1, 0);
		LL ret = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			LL now = dfs(i, i);
			if (now == -1) return -1;
			ret += now;
		}
		return ret;
	}

	void apply(int u, int v, int d) {
		for (int i = 19; i >= 0; i--) {
			if (depth[anc[u][i]] >= depth[v]) {
				cst[u][i] = MIN(cst[u][i], d);
				u = anc[u][i];
			}
		}
	}

	int lca(int u, int v) {
		if (vis[u] != vis[v]) return -1;
		if (depth[u] < depth[v]) swap(u, v);
		for (int i = 19; i >= 0; i--) {
			if (depth[anc[u][i]] >= depth[v]) {
				u = anc[u][i];
			}
		}

		for (int i = 19; i >= 0; i--) {
			if (anc[u][i] != anc[v][i]) {
				u = anc[u][i];
				v = anc[v][i];
			}
		}

		if (u != v) {
			return anc[u][0];
		}
		return u;
	}

};

void solve(int ks) {
	scanf("%d %d %d", &n, &m_my, &m_ur);
	Tree tr(n);
	UF uf(n);
	for (int i = 0; i < m_my; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		my.push_back({ u, v, 0, 0 });
		uf.Join(u, v);
	}
	LL ans = 0;
	for (int i = 0; i < m_ur; i++) {
		int u, v, d;
		scanf("%d %d %d", &u, &v, &d);
		ur.push_back({ u, v, d, 1 });
		if (uf.Join(u, v)) {
			my.push_back(ur.back());
			ans -= ur.back().d;
		}
	}
	for (auto& e : my) tr.add(e);
	tr.process();
	for (auto& e : ur) {
		int c = tr.lca(e.u, e.v);
		if (c == -1) continue;
		tr.apply(e.u, c, e.d);
		tr.apply(e.v, c, e.d);
	}

	ans += tr.solve();
	printf("%lld\n", ans);
}

int main()
{
#ifdef LOCAL
	double start_time = clock();
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif

	if (0) {
		int T;
		scanf("%d", &T);
		for (int ks = 1; ks <= T; ks++) solve(ks);
	}
	else {
		solve(0);
	}

#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}