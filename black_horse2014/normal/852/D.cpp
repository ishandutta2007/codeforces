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

const int INF = 1e7;

namespace Dinic {
	typedef int F;
	const F INF = 1e9+1e8;

	const int MAXN = 1000;
	const int MAXM = 444444;

	int fst[MAXN], nxt[MAXM], to[MAXM];
	F cap[MAXM];
	int dis[MAXN], q[MAXN], ptr[MAXN];
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

int N, K, V, E;

int num[777], cnt[777];
int dis[777][777];

bool can(int t) {
	Dinic::init();
	int S = Dinic::add_node();
	int T = Dinic::add_node();
	for (int i = 1; i <= V; i++) num[i] = Dinic::add_node(), Dinic::add_edge(num[i], T, 1);
	for (int i = 1; i <= V; i++) if (cnt[i]) {
		int cur = Dinic::add_node();
		Dinic::add_edge(S, cur, cnt[i]);
		for (int j = 1; j <= V; j++) if (dis[i][j] <= t) Dinic::add_edge(cur, num[j], 1);
	}
	return Dinic::max_flow(S, T) >= K;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d%d%d", &V, &E, &N, &K);
	for (int i = 0, x; i < N; i++) scanf("%d", &x), cnt[x]++;
	int tot = 0;
	for (int i = 1; i <= V; i++) if (cnt[i]) tot++;
	if (tot >= K) return puts("0"), 0;
	for (int i = 1; i <= V; i++) for (int j = 1; j <= V; j++) dis[i][j] = (i == j ? 0 : INF);
	for (int i = 0; i < E; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		chkmin(dis[u][v], w), chkmin(dis[v][u], w);
	}
	for (int k = 1; k <= V; k++) 
		for (int i = 1; i <= V; i++) 
			for (int j = 1; j <= V; j++) chkmin(dis[i][j], dis[i][k] + dis[k][j]);
	int lo = 0, hi = 1731311;
	if (!can(hi)) return puts("-1"), 0;
	while (hi - lo > 1) {
		int mid = lo + hi >> 1;
		if (can(mid)) hi = mid;
		else lo = mid;
	}
	printf("%d\n", hi);
	return 0;
}