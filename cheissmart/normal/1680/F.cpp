#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

void solve() {
	int n, m;
	cin >> n >> m;
	V<V<pi>> G(n);
	V<pi> es;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v, u--, v--;
		G[u].EB(v, i);
		G[v].EB(u, i);
		es.EB(u, v);
	}

	V<bool> tree(m);
	V<bool> vis(n);
	vi color(n), d(n);
	function<void(int)> dfs = [&] (int u) {
		vis[u] = true;
		for(auto[v, i]:G[u]) if(!vis[v]) {
			tree[i] = true;
			color[v] = color[u] ^ 1;
			d[v] = d[u] + 1;
			dfs(v);
		}
	};
	dfs(0);
	vi bad;
	vi aux(n), no(n);
	for(int i = 0; i < m; i++)
		if(color[es[i].F] == color[es[i].S])
			bad.PB(i);
		else {
			auto[u, v] = es[i];
			if(d[u] < d[v]) swap(u, v);
			if(d[u] != d[v] + 1) {
				no[u]++;
				no[v]--;
			}
		}
	if(SZ(bad) == 0) {
		cout << "YES\n";
		for(int i = 0; i < n; i++)
			cout << color[i];
		cout << '\n';
		return;
	} else if(SZ(bad) == 1) {
		cout << "YES\n";
		for(int i = 0; i < n; i++)
			cout << (color[i] == color[es[bad[0]].F]);
		cout << '\n';
		return;
	}

	for(int i:bad) {
		auto[u, v] = es[i];
		if(d[u] < d[v]) swap(u, v);
		aux[u]++;
		aux[v]--;
	}
	int hebe = -1;

	function<void(int)> dfs2 = [&] (int u) {
		for(auto[v, i]:G[u]) if(d[v] == d[u] + 1) {
			dfs2(v);
			aux[u] += aux[v];
			no[u] += no[v];
		}
		if(aux[u] == SZ(bad) && no[u] == 0)
			hebe = u;
	};
	dfs2(0);
	if(hebe == -1) {
		cout << "NO\n";
		return;
	}

	function<void(int)> dfs3 = [&] (int u) {
		color[u] ^= 1;
		for(auto[v, i]:G[u]) if(d[v] == d[u] + 1)
			dfs3(v);
	};
	dfs3(hebe);
	cerr << es[bad[0]].F << endl;
	cout << "YES\n";
	for(int i = 0; i < n; i++)
		cout << (color[i] == color[hebe]);
	cout << '\n';
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
		
}