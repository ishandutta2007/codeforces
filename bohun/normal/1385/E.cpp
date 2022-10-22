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

const int N = 2e5 + 101;

int n, m, id[N];
vector <pair<int, int>> ed[2];
vector <int> G[N], post;

bool vis[N];

void dfs(int v) {
	vis[v] = 1;
	for (auto it : G[v])
		if (!vis[it])
			dfs(it);
	post.pb(v);
}

void solve() {
	scanf ("%d%d", &n, &m);
	rep(i, 1, n) G[i].clear(), vis[i] = false;
	rep(i, 0, 1) ed[i].clear();
	
	rep(i, 1, m) {
		int u, v, t;
		scanf ("%d%d%d", &t, &u, &v);
		ed[t].pb({u, v});
		if (t) G[u].pb(v);
	}
	post.clear();
	rep(i, 1, n) if (!vis[i]) dfs(i);
	reverse(all(post));
	rep(i, 0, n - 1) id[post[i]] = i;
	rep(i, 1, n)
		for (auto it : G[i])
			if (id[i] > id[it]) {
				printf ("NO\n");
				return;
			}
	printf ("YES\n");
	for (auto &it : ed[0]) {
		if (id[it.fi] > id[it.se])
			swap(it.fi, it.se);
		printf ("%d %d\n", it.fi, it.se);
	}
	for (auto it : ed[1])
		printf ("%d %d\n", it.fi, it.se);
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}