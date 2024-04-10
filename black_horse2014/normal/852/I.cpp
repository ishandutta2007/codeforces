#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
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

const int MAXN = 200000+20;
const int K = 555;

int n, m, hn, ordn, tot[MAXN];
int x[MAXN], g[17][MAXN], y[MAXN], a[MAXN], b[MAXN], id[MAXN];
int sex[MAXN], val[MAXN], h[MAXN];
int ord[MAXN], fst[MAXN];
int chk[MAXN], cnt[2][MAXN];

VI adj[MAXN];

long long ans[MAXN];
int dp[MAXN];

void dfs(int u, int e) {
	if (e) ord[ordn++] = e, fst[u] = ordn, y[e] = val[u];
	for (int i = 0; i < sz(adj[u]); i++) {
		int f = adj[u][i];
		if (f != e) {
			int v = x[f] ^ u;
			g[0][v] = u, dp[v] = dp[u] + 1;
			for (int j = 1; j < 17; j++) g[j][v] = g[j-1][g[j-1][v]];
			dfs(v, f);
		}
	}
	if (e) ord[ordn++] = e;
}

bool cmp(int x, int y) {
	if (fst[a[x]] / K != fst[a[y]] / K) return fst[a[x]] / K < fst[a[y]] / K;
	return fst[b[x]] < fst[b[y]];
}

long long ret;

void process(int e) {
	chk[e] ^= 1;
	int v = y[e] >> 1, s = y[e] & 1;
	if (!chk[e]) {
		cnt[s][v]--;
		ret -= cnt[s^1][v];
	}
	if (chk[e]) {
		cnt[s][v]++;
		ret += cnt[s^1][v];
	}
}

inline int lca(int u, int v) {
	if (dp[u] < dp[v]) swap(u, v);
	for (int i = 0, diff = dp[u] - dp[v]; (1<<i) <= diff; i++) if (diff>>i&1) u = g[i][u];
	if (u == v) return u;
	for (int i = 31-__builtin_clz(dp[u]); i >= 0; i--) if (g[i][u] != g[i][v]) u = g[i][u], v = g[i][v];
	return g[0][u];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", &sex[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
	for (int i = 1; i <= n; i++) h[i-1] = val[i];
	sort(h, h + n);
	hn = unique(h, h + n) - h;
	for (int i = 1; i <= n; i++) val[i] = lower_bound(h, h + hn, val[i]) - h;
	for (int i = 1; i <= n; i++) val[i] = val[i]*2 + sex[i];
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(i), adj[v].push_back(i);
		x[i] = u ^ v;
	}
	dp[1] = 1;
	dfs(1, 0);
	cin >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a[i], &b[i]), id[i] = i;
		if (fst[a[i]] > fst[b[i]]) swap(a[i], b[i]);
	}
	sort(id, id + m, cmp);
	for (int i = 0, j; i < m; i = j) {
		int q = fst[a[id[i]]] / K;
		int l = q*K, r = l-1;
		memset(cnt, 0, sizeof cnt);
		memset(chk, 0, sizeof chk);
		ret = 0;
		for (j = i; j < m && fst[a[id[j]]] / K == q; j++) {
			int ll = fst[a[id[j]]], rr = fst[b[id[j]]]-1;
			if (a[id[j]] == b[id[j]]) continue;
			while (r < rr) r++, process(ord[r]);
			while (l > ll) l--, process(ord[l]);
			while (l < ll) process(ord[l]), l++;
			int p = lca(a[id[j]], b[id[j]]);
			ans[id[j]] = ret + cnt[~val[p]&1][val[p]>>1];
		}
	}
	for (int i = 0; i < m; i++) printf("%lld\n", ans[i]);
	return 0;
}