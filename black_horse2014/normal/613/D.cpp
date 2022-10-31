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

const int MAXN = 111111;

int st[MAXN], en[MAXN], b[MAXN], num[MAXN], f[17][MAXN], T;
int dp[MAXN], chk[MAXN];
long long ans[2][MAXN];

VI adj[MAXN], con[MAXN];

void dfs(int u, int p) {
	st[u] = ++T, num[T] = u;
	f[0][u] = p, dp[u] = dp[p] + 1;
	for (int i = 1; i < 17; i++) f[i][u] = f[i-1][f[i-1][u]];
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		dfs(v, u);
	}
	en[u] = T;
}

int lca(int u, int v) {
	if (dp[u] < dp[v]) swap(u, v);
	int d = dp[u] - dp[v];
	for (int i = 16; i >= 0; i--) if (d >> i & 1) u = f[i][u];
	if (u == v) return u;
	for (int i = 16; i >= 0; i--) {
		if (f[i][u] == f[i][v]) continue;
		u = f[i][u], v = f[i][v];
	}
	return f[0][u];
}

set<int> S;

void add(int u, int flg) {
	S.insert(st[u]);
	if (flg) chk[u] = 1;
}

const int INF = 1e9;
void dfs(int u) {
	ans[1][u] = ans[0][u] = INF;
	for (int i = 0; i < sz(con[u]); i++) {
		int v = con[u][i];
		dfs(v);
	}
	long long sum0 = 0, sum1 = 0, delta = 1LL<<60;
	for (int i = 0; i < sz(con[u]); i++) {
		int v = con[u][i];
		if (ans[1][v] >= INF) {
			sum0 += INF, sum1 += INF;
			continue;
		}
		if (chk[v] && chk[u] && dp[v] == dp[u] + 1) {
			sum0 += INF, sum1 += INF;
			continue;
		}
		sum0 += ans[0][v];
		chkmin(delta, ans[1][v] - ans[0][v]);
		if (chk[u]) sum1 += min(ans[1][v] + 1, ans[0][v]);
		else sum1 += ans[1][v];
	}
	if (sum1 >= INF) ans[0][u] = ans[1][u] = INF;
	else {
		if (chk[u]) {
			ans[0][u] = INF;
			ans[1][u] = min(sum0, sum1);
		} else {
			ans[0][u] = min(sum0, sum1 + 1);
			ans[1][u] = min(ans[0][u], sum0 + delta);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	T = 0; dfs(1, 0);
	int q; scanf("%d", &q);
	while (q--) {
		S.clear();
		int k; scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			int x; scanf("%d", &x);
			if (S.empty()) {
				add(x, 1);
				continue;
			}
			set<int> :: iterator it = S.lower_bound(st[x]);
			if (it == S.end() || it == S.begin()) {
				int L = *S.begin();
				int R = *(--S.end());
				int u = lca(num[L], x), v = lca(num[R], x);
				if (dp[u] < dp[v]) swap(u, v);
				add(u, 0), add(x, 1);
			} else {
				int R = *it, L = *(--it);
				int u = lca(num[L], x), v = lca(num[R], x);
				if (dp[u] < dp[v]) swap(u, v);
				add(u, 0), add(x, 1);
			}
		}
		int bn = 0, r = num[*S.begin()];
		for (set<int> :: iterator it = S.begin(); it != S.end(); it++) {
			int u = num[*it];
			while (bn > 0 && en[b[bn-1]] < st[u]) bn--;
			if (bn > 0) con[b[bn-1]].push_back(u);
			b[bn++] = u;
		}
		dfs(r);
		for (set<int> :: iterator it = S.begin(); it != S.end(); it++) chk[num[*it]] = 0, con[num[*it]].clear();
		if (ans[1][r] >= INF) ans[1][r] = -1;
		printf("%lld\n", ans[1][r]);
	}
	return 0;
}