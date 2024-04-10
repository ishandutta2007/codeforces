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

int dis[MAXN], dp[MAXN], vis[MAXN], T;

vector<int> adj[MAXN], V[MAXN];
vector<long long> S[MAXN];

void dfs(int u, int p, int d) {
	vis[u] = T, dp[u] = d;
	V[T].push_back(u);
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		dfs(v, u, d + 1);
	}
}

void dfs1(int u, int p, int d) {
	dp[u] = d;
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		dfs1(v, u, d + 1);
	}
}

map<long long, long long> H;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m, q; cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].pb(v), adj[v].pb(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			T++; 
			dfs(i, 0, 0);
			int a = i;
			for (int j = 0; j < sz(V[T]); j++) {
				int u = V[T][j];
				if (dp[u] > dp[a]) a = u;
			}
			dfs1(a, 0, 0);
			int b = a;
			for (int j = 0; j < sz(V[T]); j++) {
				int u = V[T][j];
				if (dp[u] > dp[b]) b = u;
				dis[u] = dp[u];
			}
			dfs1(b, 0, 0);
			for (int j = 0; j < sz(V[T]); j++) {
				int u = V[T][j];
				dis[u] = max(dis[u], dp[u]);
				V[T][j] = dis[u];
			}
			sort(all(V[T]));
			S[T].resize(sz(V[T])+1);
			long long sum = 0;
			for (int j = 0; j < sz(V[T]); j++) S[T][j] = sum, sum += V[T][j];
			S[T][sz(V[T])] = sum;
		}
	}
	while (q--) {
		int u, v; scanf("%d%d", &u, &v);
		if (vis[u] == vis[v]) {
			puts("-1");
			continue;
		}
		u = vis[u], v = vis[v];
		if (sz(V[u]) > sz(V[v])) swap(u, v);
		if (H.count(1LL * u * (T + 1) + v)) {
			printf("%.10lf\n", 1.0 * H[1LL*u*(T+1)+v] / sz(V[u]) / sz(V[v]));
			continue;
		}
		int D = max(V[u].back(), V[v].back());
		long long ans = 0;
		if (sz(V[u]) <= 200) {
			for (int i = 0; i < sz(V[u]); i++) {
				int x = V[u][i];
				int cnt = upper_bound(all(V[v]), D - x - 1) - V[v].begin();
				ans += 1LL * D * cnt + (S[v].back() - S[v][cnt]) + 1LL * (x + 1) * (sz(V[v]) - cnt);
			}
		} else {
			for (int i = 0, j = sz(V[v]) - 1; i < sz(V[u]); i++) {
				int x = V[u][i];
				while (j >= 0 && V[v][j] + x + 1 > D) j--;
				ans += 1LL * D * (j + 1) + S[v].back() - S[v][j+1] + 1LL * (x + 1) * (sz(V[v]) - j - 1);
			}
		}
		H[1LL*u*(T+1)+v] = ans;
		printf("%.10lf\n", 1.0 * ans / sz(V[u]) / sz(V[v]));
	}
	return 0;
}