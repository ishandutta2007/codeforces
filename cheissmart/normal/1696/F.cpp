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

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, N = 101;

bool same[N][N][N];

void solve() {
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			for(int k = 0; k < n; k++) {
				char c; cin >> c;
				same[i][j][k] = c - '0';
				same[j][i][k] = c - '0';
			}
		}
	}

	for(int _ = 1; _ < n; _++) {
		V<vi> G(n);
		V<pi> edges;
		V<V<bool>> vis(n, V<bool>(n));
		edges.EB(0, _), vis[0][_] = true;
		for(int i = 0; i < SZ(edges) && SZ(edges) < n; i++) {
			auto [u, v] = edges[i];
			G[u].PB(v);
			G[v].PB(u);
			for(int __ = 0; __ < 2; __++) {
				for(int w = 0; w < n; w++) if(w != u && same[u][w][v]) {
					pi p = {min(v, w), max(v, w)};
					if(!vis[p.F][p.S]) {
						vis[p.F][p.S] = true;
						edges.PB(p);
					}
				}
				swap(u, v);
			}
		}
		if(SZ(edges) != n - 1)
			continue;
		// is tree
		bool ok = true;
		V<bool> vis2(n);
		function<void(int, int)> dfs = [&] (int u, int p) {
			vis2[u] = true;
			for(int v:G[u]) if(v != p) {
				if(vis2[v]) ok = false;
				else dfs(v, u);
			}
		};
		dfs(0, -1);
		for(int u = 0; u < n && ok; u++) {
			vi d(n);
			function<void(int, int)> dfs = [&] (int u, int p) {
				for(int v:G[u]) if(v != p) {
					d[v] = d[u] + 1;
					dfs(v, u);
				}
			};
			dfs(u, -1);
			for(int x = 0; x < n && ok; x++) {
				for(int y = x + 1; y < n && ok; y++) {
					ok &= same[x][y][u] == (d[x] == d[y]);
				}
			}
		}
		if(ok) {
			cout << "Yes\n";
			for(auto[u, v]:edges) {
				cout << u + 1 << " " << v + 1 << '\n';
			}
			return;
		}
	}
	cout << "No\n";
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--)
		solve();

}