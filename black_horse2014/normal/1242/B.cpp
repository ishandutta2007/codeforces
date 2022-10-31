#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

set<int> adj[N], s;
int que[N * 2];
bool vis[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) s.insert(i);
	while (m--) {
		int u, v; cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	int tot = -1;
	while (s.size()) {
		auto it = s.begin();
		s.erase(it); tot++;
		int hd = 0, tl = 0;
		que[tl++] = *it;
		vis[*it] = 1;
		while (hd < tl) {
			int u = que[hd++];
			set<int> tmp;
			for (auto v : adj[u]) {
				if(s.count(v)) {
					tmp.insert(v);
					s.erase(v);
				}
			}
			for (auto u : s) {
				if (!vis[u]) {
					vis[u] = 1;
					que[tl++] = u;
				}
			}
			s = tmp;
		}
	}
	cout << tot << "\n";
	return 0;
}