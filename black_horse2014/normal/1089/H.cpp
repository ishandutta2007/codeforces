#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

vector<int> adj[N], con[N], radj[N], comp[N];
int vis[N], chk[N], q[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		int n, m; string s; cin >> n >> m >> s;
		for (int i = 0; i < n + n; i++) adj[i].clear();
		for (int i = 0; i < n + n; i++) radj[i].clear();
		auto add_edge = [&](int u, int v) {
			adj[u].push_back(v);
			radj[v].push_back(u);
		};
		for (int i = 0; i < m; i++) {
			int u, v; cin >> u >> v;
			if (u > 0) u--;
			else u = -u - 1 + n;
			if (v > 0) v--;
			else v = -v - 1 + n;
			add_edge((u + n) % (2 * n), v);
			add_edge((v + n) % (2 * n), u);
		}
		for (int i = 0; i < n + n; i++) vis[i] = 0;
		int qn = 0;
		function<void(int)> dfs = [&](int u) {
			vis[u] = 1;
			for (int v : adj[u]) if (!vis[v]) dfs(v);
			q[qn++] = u;
		};
		int T = 0;
		function<void(int)> rdfs = [&](int u) {
			vis[u] = T;
			for (int v : radj[u]) if (!vis[v]) rdfs(v);
		};
		for (int i = 0; i < n + n; i++) if (!vis[i]) dfs(i);
		for (int i = 0; i < n + n; i++) vis[i] = 0;
		for (int i = n + n - 1; i >= 0; i--) if (!vis[q[i]]) ++T, rdfs(q[i]);
		auto solve = [&]() {
			for (int i = 0; i < n; i++) if (vis[i] == vis[i + n]) return 0;
			for (int i = 1; i <= T; i++) con[i].clear(), comp[i].clear();
			for (int i = 0; i < n + n; i++) {
//				cerr << "i = " << i << ' ' << vis[i] << endl;
				comp[vis[i]].push_back(i % n);
			}
			for (int i = 1; i <= T; i++) {
			    sort(comp[i].begin(), comp[i].end());
				int cnt = 0;
				for (int u : comp[i]) {
//					cerr << i << ' ' << u << endl;
					if (s[u] == 'A') {
						if (cnt) return 0;
					}
					cnt++;
				}
			}
			for (int i = 1; i <= T; i++) {
				chk[i] = 0;
				for (int u : comp[i]) {
					if (s[u] == 'A') chk[i] = 1;
				}
//				cerr << i << ' ' << chk[i] << endl;
			}
			for (int i = 0; i < n + n; i++) {
				for (int j : adj[i]) {
//					cerr << "i = " << i << ' ' << "j = " << j << endl;
					if (vis[i] == vis[j]) continue;
//					cerr << "con = " << vis[i] << ' ' << vis[j] << endl;
					con[vis[i]].push_back(vis[j]);
				}
			}
			for (int i = T; i > 0; i--) {
				if (chk[i]) {
					for (int j : con[i]) {
						if (chk[j]) return 0;
					}
				} else {
					for (int j : con[i]) {
						if (chk[j]) chk[i] = 1;
					}
				}
			}
			return 1;
		};
		if (solve()) puts("TRUE");
		else puts("FALSE");
	}
	return 0;
}