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

int n, m;

const int MAXN = 2*111111;

long long cnt[5][MAXN], sum[5][MAXN];
long long ans;

VI adj[MAXN];

void dfs(int u, int p) {
	cnt[0][u] = 1;
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		dfs(v, u);
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < m; k++) {
				ans += sum[j][u] * cnt[k][v] + sum[k][v] * cnt[j][u];
				if (j) ans -= cnt[j][u] * cnt[k][v];
				if (k) ans -= cnt[j][u] * cnt[k][v];
				ans += cnt[j][u] * cnt[k][v] * ((j + k) / m + 1);
			}
		}
		if (m > 1) {
			for (int j = 0; j < m; j++) cnt[j][u] += cnt[(j + m - 1) % m][v], sum[j][u] += (j == 1 ? cnt[(j + m - 1) % m][v] : 0) + sum[(j + m - 1) % m][v];
		} else {
			cnt[0][u] += cnt[0][v], sum[0][u] += sum[0][v] + cnt[0][v];
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].pb(v), adj[v].pb(u);
	}
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}