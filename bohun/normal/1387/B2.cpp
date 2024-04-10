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

const int N = 111111;

int n, siz[N], out[N];
vector <int> G[N], nodes, q;
ll ans;

int dfs(int v, int p) {
	siz[v] = 1;
	for (auto u : G[v])
		if (u != p)
			siz[v] += dfs(u, v);
	return siz[v];
}

void solve(int v, int p, int d = 1) {
	ans += d;
	nodes.pb(v);
	for (auto u : G[v])
		if (u != p)
			solve(u, v, d + 1);
}

int main() {	
	scanf ("%d", &n);
	rep(i, 2, n) {
		int u, v;
		scanf ("%d%d", &u, &v);
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1, 0);
	int c = 1, p = 1, flag;
	while (true) {
		flag = 0;
		for (auto u : G[c])
			if (u != p && n < 2 * siz[u]) {
				p = c;
				c = u;
				flag = 1;
				break;
			}
		if (!flag) break;
	}
	
	dfs(c, 0);
	sort(all(G[c]), [&](int a, int b) {
		return siz[a] > siz[b];
	});
	for (auto u : G[c]) {
		nodes.clear();
		solve(u, c);
		for (auto x : nodes)
			q.pb(x);
	}
	q.pb(c);
		
	printf ("%lld\n", 2 * ans);
	rep(i, 0, n - 1)
		out[q[i]] = q[(i + n / 2) % n];
	rep(i, 1, n)
		printf ("%d ", out[i]);
	
	return 0;
}