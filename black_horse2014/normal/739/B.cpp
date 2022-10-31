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

const int MAXN = 222222;

VPII adj[MAXN];
long long dis[MAXN];
int ans[MAXN], par[MAXN], a[MAXN];

vector<PLI> V;

void dfs(int u) {
	V.push_back(PLI(dis[u], u));
	int j = lower_bound(all(V), PLI(dis[u] - a[u], 0)) - V.begin();
	ans[par[V[j].second]]--, ans[par[u]]++;
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i].first, w = adj[u][i].second;
		par[v] = u;
		dis[v] = dis[u] + w;
		dfs(v);
	}
	V.pop_back();
}

void solve(int u) {
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i].first;
		solve(v);
		ans[u] += ans[v];
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 2; i <= n; i++) {
		int p, w; scanf("%d%d", &p, &w);
		adj[p].push_back(PII(i, w));
	}
	dfs(1);
	solve(1);
	for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i < n ? ' ' : '\n');
	return 0;
}