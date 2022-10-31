#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <complex>
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

const int MAXN = 5555;

int n, m;
int dis[MAXN], vis[MAXN], dp[MAXN], chk[MAXN];
queue<int> Q;
vector<int> adj[MAXN], radj[MAXN];

int calc(int s) {
	for (int i = 1; i <= n; i++) {
		dis[i] = 0;
	}
	Q.push(s);
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		for (int i = 0; i < sz(adj[u]); i++) {
			int v = adj[u][i];
			if (!dis[v]) {
				dis[v] = dis[u] + 1;
				Q.push(v);
			}
		}
	}
	return dis[s];
}

int q[MAXN], qn;

void dfs(int u) {
	vis[u] = 1;
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (!vis[v]) {
			dfs(v);
		}
	}
	q[qn++] = u;
}

int cnt;
void rdfs(int u) {
	vis[u] = cnt;
	for (int i = 0; i < sz(radj[u]); i++) {
		int v = radj[u][i];
		if (!vis[v]) {
			rdfs(v);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		radj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	memset(vis, 0, sizeof vis);
	for (int i = n-1; i >= 0; i--) {
		int u = q[i];
		if (!vis[u]) {
			cnt++;
			rdfs(u);
		}
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = n+1;
	}
	for (int i = 1; i <= n; i++) {
		chkmin(dp[vis[i]], calc(i));
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < sz(adj[i]); j++) {
			if (vis[adj[i][j]] != vis[i]) {
				chk[vis[i]] = 1;
			}
		}
	}
	int ans = n;
	for (int i = 1; i <= cnt; i++) {
		if (!chk[i] && dp[i]) {
			ans += dp[i]*998+1;
		}
	}
	cout << ans << endl;
	return 0;
}