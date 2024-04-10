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
const int MOD = 1e9 + 7;

int r[MAXN], a[MAXN], st[MAXN], T, num[MAXN], f[18][MAXN];
int dp[MAXN], F[MAXN], G[MAXN], H[MAXN], I[MAXN];
int q[MAXN], b[MAXN], C;
int en[MAXN], sg[MAXN], phi[MAXN], val[MAXN], chk[MAXN], prm[MAXN], prn;

VI adj[MAXN], con[MAXN];
VI V[MAXN];

void dfs(int u, int p) {
	st[u] = ++T, num[T] = u;
	f[0][u] = p, dp[u] = dp[p] + 1;
	for (int i = 1; i < 18; i++) f[i][u] = f[i-1][f[i-1][u]];
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
	for (int i = 17; i >= 0; i--) if (d >> i & 1) u = f[i][u];
	if (u == v) return u;
	for (int i = 17; i >= 0; i--) {
		if (f[i][u] == f[i][v]) continue;
		u = f[i][u], v = f[i][v];
	}
	return f[0][u];
}

set<int> S;

void add(int u) {
	S.insert(st[u]);
}

void dfs(int u) {
	G[u] = a[u] * (chk[u] == C);
	H[u] = 1LL * a[u] * a[u] % MOD * (chk[u] == C);
	I[u] = 0;
	for (int i = 0; i < sz(con[u]); i++) {
		int v = con[u][i];
		dfs(v);
		G[u] = (G[u] + G[v]) % MOD;
		H[u] = (H[u] + H[v]) % MOD;
		I[u] = (I[u] + (1LL * G[v] * G[v] % MOD + MOD - H[v])) % MOD;
	}
	I[u] = (1LL * G[u] * G[u] % MOD + MOD - H[u] + MOD - I[u]) % MOD;
}

int modExp(int a, int n, int p) {
	int ret = 1;
	for (; n; n >>= 1, a = (LL)a * a % p) if (n & 1) ret = 1LL * ret * a % p;
	return ret;
}

int main() {
	int n; scanf("%d", &n);
	r[1] = 1;
	for (int i = 2; i <= n; i++) r[i] = (LL)(MOD - r[MOD % i]) * (MOD / i) % MOD;
	sg[1] = phi[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!chk[i]) {
			chk[i] = i;
			sg[i] = -1;
			phi[i] = i-1;
			prm[prn++] = i;
		}
		for (int j = 0; j < prn && prm[j] <= n/i; j++) {
			chk[i * prm[j]] = prm[j];
			sg[i * prm[j]] = -sg[i];
			phi[i * prm[j]] = phi[i] * (prm[j] - 1);
			if (i % prm[j] == 0) {
				sg[i * prm[j]] = 0;
				phi[i * prm[j]] += phi[i];
				break;
			}
		}
	}
	val[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (sg[i] != 0) {
			int j = i / chk[i];
			val[i] = 1LL * val[j] * (1 - r[chk[i]] + MOD) % MOD;
		}
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		int x = a[i];
		VI d;
		for (int y = x; y > 1; y /= chk[y]) d.pb(chk[y]);
		d.erase(unique(all(d)), d.end());
		for (int j = 0; j < bit(sz(d)); j++) {
			q[j] = (j == 0 ? 1 : q[j - (j & -j)] * d[ctzi(j)]);
			V[q[j]].push_back(i);
		}
	}
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].pb(v), adj[v].pb(u);
	}
	for (int i = 1; i <= n; i++) a[i] = phi[a[i]];
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		if (V[i].empty()) continue;
		int sum = 0;
		for (int j = 0; j < sz(V[i]); j++) sum = (sum + a[V[i][j]]) % MOD;
		F[i] = 0;
		for (int j = 0; j < sz(V[i]); j++) F[i] = (F[i] + 1LL * a[V[i][j]] * dp[V[i][j]] % MOD * (sum + MOD - a[V[i][j]])) % MOD;
		S.clear();
		C++;
		for (int j = 0; j < sz(V[i]); j++) {
			int x = V[i][j];
			if (S.empty()) {
				add(x), chk[x] = C;
				continue;
			}
			set<int> :: iterator it = S.lower_bound(st[x]);
			if (it == S.end() || it == S.begin()) {
				int L = *S.begin();
				int R = *(--S.end());
				int u = lca(num[L], x), v = lca(num[R], x);
				if (dp[u] < dp[v]) swap(u, v);
				add(u); add(x), chk[x] = C;
			} else {
				int R = *it, L = *(--it);
				int u = lca(num[L], x), v = lca(num[R], x);
				if (dp[u] < dp[v]) swap(u, v);
				add(u); add(x), chk[x] = C;
			}
		}
		int bn = 0, rt = num[*S.begin()];
		for (set<int> :: iterator it = S.begin(); it != S.end(); it++) {
			int u = num[*it];
			while (bn > 0 && en[b[bn-1]] < st[u]) bn--;
			if (bn > 0) con[b[bn-1]].push_back(u);
			b[bn++] = u;
		}
		dfs(rt);
		for (set<int> :: iterator it = S.begin(); it != S.end(); it++) {
			int u = num[*it];
			F[i] = (F[i] + 1LL * (MOD - I[u]) * dp[u]) % MOD;
			con[u].clear();
		}
	}
	int ans = 0;
	for (int i = n; i > 0; i--) {
		for (int j = 2*i; j <= n; j += i) F[i] = (F[i] + MOD - F[j]) % MOD;
		ans = (ans + 1LL * modExp(val[i], MOD-2, MOD) * F[i]) % MOD;
	}
	ans = 2LL * ans * r[n] % MOD * r[n-1] % MOD;
	printf("%d\n", ans);
	return 0;
}