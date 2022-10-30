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

const int MAXN = 1555;

VI adj[MAXN];
int sz[MAXN], ans[MAXN], _ans[MAXN];
double ang[MAXN][MAXN];

int x[MAXN], y[MAXN];

void dfs(int u, int p) {
	sz[u] = 1;
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		dfs(v, u);
		sz[u] += sz[v];
	}
}

int pivot;

bool cmp(int u, int v) {
	return ang[pivot][u] < ang[pivot][v];
}

void solve(int u, int p, VI &V) {
	for (int i = 0; i < sz(V); i++) {
		if (x[V[i]] < x[V[0]] || (x[V[i]] == x[V[0]] && y[V[i]] < y[V[0]])) swap(V[0], V[i]);
	}
	ans[u] = pivot = V[0];
	V.erase(V.begin());
	sort(all(V), cmp);
	int cur = 0;
	VI A;
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		A.clear();
		for (int j = 0; j < sz[v]; j++) A.pb(V[cur+j]);
		solve(v, u, A);
		cur += sz[v];
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ang[i][j] = atan2(y[j] - y[i], x[j] - x[i]);
		}
	}
	dfs(1, 0);
	VI V;
	for (int i = 1; i <= n; i++) V.pb(i);
	solve(1, 0, V);
	for (int i = 1; i <= n; i++) _ans[ans[i]] = i;
	for (int i = 1; i <= n; i++) {
		printf("%d%c", _ans[i], i < n ? ' ' : '\n');
	}
	return 0;
}