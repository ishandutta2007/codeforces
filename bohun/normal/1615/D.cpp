#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define cat(x) cerr << #x << " = " << x << '\n';
using ll = long long;
using namespace std;

const int N = 200200;

int n, m;
vector<pair<int, int>> e[N];
int vis[N];

void solve() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		vis[i] = -1;
		e[i].clear();
	}

	vector<tuple<int, int, int>> edges;
	for (int i = 1; i < n; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		edges.push_back({a, b, w});
		if (w != -1) {
			w = __builtin_popcount(w) % 2;
			e[a].push_back({b, w});
			e[b].push_back({a, w});
		}
	}

	while (m--) {
		int a, b, w;
		cin >> a >> b >> w;
		e[a].push_back({b, w});
		e[b].push_back({a, w});
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i] >= 0)
			continue;
		queue<int> q;
		q.push(i);
		vis[i] = 0;

		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (auto [v, w] : e[u]) {
				if (vis[v] == -1) {
					vis[v] = vis[u] ^ w;
					q.push(v);
				}
				if (vis[v] != (vis[u] ^ w)) {
					cout << "NO\n";
					return;
				}
			}
		}
	}

	cout << "YES\n";
	for (auto [a, b, c] : edges) {
		cout << a << ' ' << b << ' ';
		if (c >= 0)
			cout << c << '\n';
		else
			cout << (vis[a] ^ vis[b]) << '\n';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;

	while (t--)
		solve();

	return 0;
}