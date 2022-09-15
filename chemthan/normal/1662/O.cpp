#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	set<pair<int, int>> adj[21][360];
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 360; j++) {
			// to the next level
			adj[i][j].insert({i+1, j});
			adj[i+1][j].insert({i, j});

			// to adjacent angles
			adj[i][j].insert({i, (j+1)%360});
			adj[i][j].insert({i, (j+359)%360});
		}
	}

	int n; cin >> n;
	while (n--) {
		char c; cin >> c;
		if (c == 'C') {
			int r, t1, t2; cin >> r >> t1 >> t2;
			for (; t1 != t2; t1 = (t1+1) % 360) {
				// destroy edge {r, t1} <--> {r-1, t1}
				adj[r][t1].erase({r-1, t1});
				adj[r-1][t1].erase({r, t1});
			}
		} else {
			int r1, r2, t; cin >> r1 >> r2 >> t;
			for (; r1 != r2; r1++) {
				// destroy edge {r1, t} <--> {r1, t-1}
				adj[r1][t].erase({r1, (t+359)%360});
				adj[r1][(t+359)%360].erase({r1, t});
			}
		}
	}

	// get to level 20 and win
	bool vis[21][360];
	memset(vis, 0, sizeof(vis));

	queue<pair<int, int>> q;
	for (int i = 0; i < 360; i++) {
		q.push({0, i}); vis[0][i] = 1;
	}

	while (q.size()) {
		auto [r, t] = q.front(); q.pop();
		for (auto [u, v]: adj[r][t]) {
			if (!vis[u][v]) {
				if (u == 20) {
					cout << "YES\n";
					return;
				}
				q.push({u, v}); vis[u][v] = 1;
			}
		}
	}
	cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}