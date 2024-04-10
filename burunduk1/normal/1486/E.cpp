/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int M = 51, N = 1e5;

int d[N][M]; // 0, 1..50

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> g(n);
	while (m--) {
		int a, b, w;
		cin >> a >> b >> w, a--, b--;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}
	memset(d, -1, sizeof(d));
	set<pair<int, int>> s;
	auto make = [&](int v, int cnt, int w, int D) {
		if (cnt == 2)
			D += w * w, w = 0;
		if (d[v][w] == -1 || d[v][w] > D) {
			s.erase({d[v][w], v * M + w});
			d[v][w] = D;
			s.insert({d[v][w], v * M + w});
		}
	};
	make(0, 0, 0, 0);
	while (s.size()) {
		int state = s.begin()->second;
		s.erase(s.begin());
		int v = state / M, w1 = state % M, cnt = w1 > 0;
		for (auto [to, w2] : g[v])
			make(to, cnt + 1, w1 + w2, d[v][w1]);
	}

	forn(i, n)
		cout << d[i][0] << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	solve();
}

/*
11 7
2 2 2 1 1 1 1 1 2 2 2
*/