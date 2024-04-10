#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 3003;

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;
	V<vi> g(n + 1), G;
	vi e(m);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		e[i] = u ^ v;
		g[u].PB(i);
		g[v].PB(i);
	}
	for(int i = 1; i <= n; i++) {
		vi adj(n + 1);
		for(int j:g[i]) adj[e[j] ^ i] = 1;
		int cnt = 0;
		for(int j = 1; j <= n; j++) if(j != i)
			if(adj[j] == 0 && g[j].size() % 2 == 1)
				cnt++;
		if(cnt >= 2) continue;
		auto eulerian_path = [&] (int end_node) -> vi{
			int odd_cnt = 0;
			vi deg(n + 1);
			for(int i = 1; i <= n; i++) {
				for(int j:G[i]) if(e[j] != -1)
					deg[i]++;
				if(deg[i] & 1)
					odd_cnt++;
			}
			if(odd_cnt > 2) return {};
			if(odd_cnt == 2 && deg[end_node] % 2 == 0) return {};
			vi path, vis(n + 1);
			function<void(int)> dfs = [&] (int u) {
				vis[u] = 1;
				while(G[u].size()) {
					int ei = G[u].back(); G[u].pop_back();
					if(e[ei] == -1) continue;
					int v = e[ei] ^ u;
					e[ei] = -1;
					dfs(v);
				}
				path.PB(u);
			};
			dfs(i);
			for(int i = 1; i <= n; i++) if(deg[i] && vis[i] == 0) return {};
			return path;
		};
		{ // no adj have odd deg
			V<pi> undo;
			for(int j:g[i]) {
				int k = e[j] ^ i;
				if(g[k].size() & 1) {
					undo.EB(j, e[j]);
					e[j] = -1;
				}
			}
			vi ee = e;
			G = g;
			vi path = eulerian_path(i);
			e = ee;
			if(path.size()) {
				path.PB(-1);
				for(pi p:undo) {
					int k = p.S ^ i;
					path.PB(k);
					path.PB(i);
				}
				cout << path.size() << '\n';
				for(int u:path)
					cout << u << ' ';
				cout << '\n';
				exit(0);
			}
			for(pi p:undo)
				e[p.F] = p.S;
		}
		{ // one adj have odd deg
			V<pi> undo;
			int odd_adj_cnt = 0;
			for(int j:g[i]) {
				int k = e[j] ^ i;
				if(g[k].size() & 1) {
					odd_adj_cnt++;
				}
			}
			if(!(cnt == 1 && (int(g[i].size()) - odd_adj_cnt + 1) % 2 == 1)) {
				for(int j:g[i]) {
					int k = e[j] ^ i;
					if(g[k].size() & 1) {
						undo.EB(j, e[j]);
						e[j] = -1;	
					}
					for(pi p:undo) {
						e[p.F] = p.S;
						vi ee = e;
						G = g;
						vi path = eulerian_path(i);
						e = ee;
						if(path.size()) {
							path.PB(-1);
							for(pi pp:undo) {
								if(pp.F == p.F) continue;
								int k = pp.S ^ i;
								path.PB(k);
								path.PB(i);
							}
							cout << path.size() << '\n';
							for(int u:path)
								cout << u << ' ';
							cout << '\n';
							exit(0);
						}
						e[p.F] = -1;
					}
				}

			}
			for(pi p:undo)
				e[p.F] = p.S;
		}
 	}
 	cout << 0 << '\n';

}