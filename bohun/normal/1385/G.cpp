#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;	

const int N = 2e5 + 100;

int n;
int t[2][N];
vector <int> vals[N];
vector <pair<int, int>> G[N];
bool vis[N];
int color[N];
vector <int> C[2];
bool cycle;

void dfs(int v) {
	vis[v] = true;
	C[color[v]].pb(v);
	for (auto it : G[v]) {
		if (vis[it.fi] && (color[v] ^ it.se) != color[it.fi])
			cycle = true;
		if (!vis[it.fi]) {
			color[it.fi] = color[v] ^ it.se;
			dfs(it.fi);
		}
	}
}

void solve() {
	scanf ("%d", &n);
	rep(i, 1, n) G[i].clear(), vals[i].clear();
	rep(j, 0, 1)
		rep(i, 1, n) {
			scanf ("%d", &t[j][i]);
			vals[t[j][i]].pb(i);
		}
	rep(i, 1, n) {
		if (ss(vals[i]) != 2) {
			printf ("-1\n");
			return;
		}
		int u = vals[i][0], v = vals[i][1], w;
		if (u == v) continue;
		w = ((t[0][u] == t[0][v] && t[0][u] == i) || (t[1][u] == t[1][v] && t[1][u] == i));
		G[u].pb(mp(v, w));
		G[v].pb(mp(u, w));
	}
	cycle = false;
	rep(i, 1, n) vis[i] = false;
	vector <int> ans;
	rep(i, 1, n)
		if (!vis[i]) {
			rep(j, 0, 1) C[j].clear();
			dfs(i);
			if (ss(C[0]) > ss(C[1])) swap(C[0], C[1]);
			for (auto it : C[0])
				ans.pb(it);
		}
	if (cycle) printf ("-1\n");
	printf ("%d\n", ss(ans));
	for (auto it : ans) printf ("%d ", it);
	printf ("\n");
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}