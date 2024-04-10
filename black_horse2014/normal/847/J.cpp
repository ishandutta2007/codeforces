#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef double DB;

#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#define X first
#define Y second

#define Error(x) cout << #x << " = " << x << endl

template <typename T, typename U>
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}

namespace Dinic {
	typedef int F;
	const F INF = 1e9+1e8;

	const int N = 11111;
	const int M = 111111;

	int fst[N], nxt[M], to[M];
	F cap[M];
	int dis[N], q[N], ptr[N];
	int V, E;

	void init() {
		memset(fst, -1, sizeof fst);
		V = E = 0;
	}
	inline int add_node() { V++; return V-1; }
	inline void add_edge(int u, int v, F c) {
		to[E] = v, cap[E] = c, nxt[E] = fst[u], fst[u] = E++;
		to[E] = u, cap[E] = 0, nxt[E] = fst[v], fst[v] = E++;
	}
	inline bool bfs(int S, int T, int n) {
		memset(dis, -1, sizeof(int) * n);
		int h = 0, t = 0;
		dis[S] = 0, q[t++] = S;
		while (h < t) {
			int u = q[h++];
			for (int e = fst[u]; ~e; e = nxt[e]) if (cap[e] > 0 && dis[to[e]] == -1) {
				dis[to[e]] = dis[u] + 1, q[t++] = to[e];
				if (to[e] == T) return 1;
			}
		}
		return (dis[T] != -1);
	}
	F dfs(int u, int T, F f) {
		if (u == T) return f;
		for (int &e = ptr[u]; ~e; e = nxt[e]) if (cap[e] > 0 && dis[to[e]] > dis[u]) {
			F ret = dfs(to[e], T, min(f, cap[e]));
			if (ret > 0) {
				cap[e] -= ret, cap[e ^ 1] += ret;
				return ret;
			}
		}
		return 0;
	}
	F max_flow(int S, int T, int n = V) {
		F ret = 0;
		while (bfs(S, T, n)) {
			memcpy(ptr, fst, sizeof(int) * n);
			for (F cur; (cur = dfs(S, T, INF)) > 0; ret += cur);
		}
		return ret;
	}
}

int a[5555], b[5555], ans[5555];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; scanf("%d%d", &n, &m);
	int S = 0, T = n + m + 1;
	for (int i = 1; i <= m; i++) scanf("%d%d", &a[i], &b[i]);
	int lo = (m+n-1)/n-1, hi = n-1;
	while (hi - lo > 1) {
		int mid = lo + hi >> 1;
		Dinic::init();
		for (int i = 1; i <= m; i++) Dinic::add_edge(a[i], n + i, 1), Dinic::add_edge(b[i], n + i, 1);
		for (int i = 1; i <= n; i++) Dinic::add_edge(0, i, mid);
		for (int i = n + 1; i <= n + m; i++) Dinic::add_edge(i, n + m + 1, 1);
		if (Dinic::max_flow(0, n + m + 1, n + m + 2) < m) lo = mid;
		else hi = mid;
	}
	Dinic::init();
	for (int i = 1; i <= m; i++) Dinic::add_edge(a[i], n + i, 1), Dinic::add_edge(b[i], n + i, 1);
	for (int i = 1; i <= n; i++) Dinic::add_edge(0, i, hi);
	for (int i = n + 1; i <= n + m; i++) Dinic::add_edge(i, n + m + 1, 1);
	assert(Dinic::max_flow(0, n + m + 1, n + m + 2) == m);
	for (int i = 0; i < Dinic::E; i += 2) {
		int u = Dinic::to[i], v = Dinic::to[i^1];
		if (u > S && u < T && v > S && v < T) {
			if (Dinic::cap[i]) {
			} else {
				assert(Dinic::cap[i^1]);
				ans[u-n] = v;
			}
		}
	}
	cout << hi << endl;
	for (int i = 1; i <= m; i++) printf("%d %d\n", ans[i], a[i] + b[i] - ans[i]);
	return 0;
}