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

const int INF = 1e8;
const int MAXN = 55;

int dis[MAXN][MAXN];
VI adj[MAXN], V[MAXN];

int a[MAXN], dp[MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dis[i][j] = (i == j ? 0 : INF);
	for (int i = 1; i < n; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back(v);
		adj[v].push_back(u);
		dis[u][v] = dis[v][u] = w;
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) for (int k = 1; k <= n; k++) dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
	int s, m; scanf("%d%d", &s, &m);
	for (int i = 1; i <= m; i++) {
		int u; scanf("%d", &u);
		int x = s;
		for (auto t : adj[s]) if (dis[t][u] < dis[x][u]) x = t;
		a[x]++;
	}
	vector<int> L;
	for (int i = 1; i <= n; i++) if (adj[i].size() == 1) L.push_back(i);
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < L.size(); j++) {
			int lo = 0, hi = INF;
			int u = L[j];
			while (hi - lo > 1) {
				int mid = lo + hi >> 1, tot = i * L.size();
				for (int k = 0; k < L.size(); k++) tot -= lower_bound(dp[k], dp[k] + i, mid - dis[u][L[k]]) - dp[k];
				if (tot >= i) lo = mid;
				else hi = mid;
			}
			dp[j][i] = lo;
		}
	}
	if (adj[s].size() == 1) {
		for (int j = 0; j < L.size(); j++) {
			if (L[j] == s) {
				cout << dp[j][m] << endl;
				return 0;
			}
		}
	}
	for (int j = 0; j < L.size(); j++) {
		int x = s, u = L[j];
		for (auto t : adj[s]) if (dis[t][u] < dis[x][u]) x = t;
		V[x].push_back(j);
	}
	int ans = INF;
	for (auto t : adj[s]) {
		int lo = 0, hi = INF;
		while (hi - lo > 1) {
			int mid = lo + hi >> 1, tot = m * sz(V[t]);
			for (auto j : V[t]) tot -= lower_bound(dp[j], dp[j] + m, mid - dis[s][L[j]]) - dp[j];
			if (tot >= a[t]) lo = mid;
			else hi = mid;
		}
		ans = min(ans, lo);
	}
	cout << ans << endl;
	return 0;
}