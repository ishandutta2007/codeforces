#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using ll = long long;
using namespace std;

const int N = 1e5 + 10;

int n, depth[N];
vector <int> G[N];

pair<int, int> deepest;

void dfs(int v, int p, int dep) {
	depth[v] = dep;
	deepest = max(deepest, mp(dep, v));
	for (auto u : G[v])
		if (u != p)
			dfs(u, v, dep + 1);
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		int a, b, da, db;
		scanf ("%d%d%d%d%d", &n, &a, &b, &da, &db);
		rep(i, 1, n) G[i].clear();
		rep(i, 1, n - 1) {
			int u, v;
			scanf ("%d%d", &u, &v);
			G[u].pb(v);
			G[v].pb(u);
		}
		
		dfs(a, 0, 0);
		if (depth[b] <= da) {
			printf ("Alice\n");
			continue;
		}
		
		deepest = mp(0, 0);
		dfs(1, 0, 0);
		int root = deepest.se;
		deepest = mp(0, 0);
		dfs(root, 0, 0);
		
		if (da >= db || deepest.fi <= 2 * da) {
			printf ("Alice\n");
			continue;
		}
		if (db > 2 * da)
			printf ("Bob\n");
		else
			printf ("Alice\n");
	}
	return 0;
}