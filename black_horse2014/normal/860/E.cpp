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

const int MAXN = 510000;

int T;
int b[MAXN], d[MAXN], chk[MAXN], id[MAXN], st[MAXN], en[MAXN], f[19][MAXN], par[MAXN];
pair<int, int> a[MAXN];

VI adj[MAXN];
long long ans[MAXN], sz[MAXN];

void dfs(int u) {
	d[u] = d[f[0][u]] + 1;
	st[u] = ++T;
	for (int i = 1; i < 19; i++) f[i][u] = f[i-1][f[i-1][u]];
	for (int i = 0; i < sz(adj[u]); i++) dfs(adj[u][i]);
	en[u] = T;
}

bool cmp(int u, int v) {
	if (d[u] != d[v]) return d[u] < d[v];
	return st[u] < st[v];
}

inline int lca(int u, int v) {
	if (d[u] < d[v]) swap(u, v);
	for (int i = 0, diff = d[u] - d[v]; (1<<i) <= diff; i++) if (diff>>i&1) u = f[i][u];
	if (u == v) return u;
	for (int i = 31-__builtin_clz(d[u]); i >= 0; i--) if (f[i][u] != f[i][v]) u = f[i][u], v = f[i][v];
	return f[0][u];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	int r = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &f[0][i]);
		if (f[0][i]) adj[f[0][i]].push_back(i);
		else r = i;
	}
	dfs(r);
	for (int i = 1; i <= n; i++) id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	T = 0;
	for (int i = 1, j; i <= n; i = j) {
		T++;
		int m = 0;
		for (j = i; j <= n && d[id[i]] == d[id[j]]; j++) {
			int u = id[j]; chk[u] = T, sz[u] = 1, a[++m] = make_pair(st[u], u);
			if (j > i) {
				int v = lca(u, id[j-1]);
				if (chk[v] != T) chk[v] = T, sz[v] = 0, a[++m] = make_pair(st[v], v);
			}
		}
		sort(a + 1, a + m + 1);
		int l = 0;
		for (int k = 1; k <= m; k++) {
			int u = a[k].second;
			while (l > 0 && en[b[l]] < st[u]) l--;
			par[u] = b[l]; b[++l] = u;
		}
		for (int k = m; k > 0; k--) {
			int u = a[k].second;
			if (par[u]) sz[par[u]] += sz[u];
		}
		for (int k = 1; k <= m; k++) {
			int u = a[k].second;
			sz[u] = sz[par[u]] + sz[u] * (d[u] - d[par[u]]);
			if (d[u] == d[id[i]]) ans[u] = ans[f[0][u]] + sz[u] - 1;
		}
	}
	for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
	puts("");
	return 0;
}