#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using tree = vector<vector<pair<int, int>>>;
using vi = vector<int>;

int p, n, ctr;
tree T;
vi edge_data, vert_data;
void solve(int p, int u, int e, bool b = false) {
	if (e == -1) {
		vert_data[u] = n;
	} else {
		edge_data[e] = (b ? n : 0) + ctr;
		vert_data[u] = (b ? 0 : n) + ctr;
		++ctr;
	}
	for (const auto &ed : T[u]) {
		if(ed.first != p)
			solve(u, ed.first, ed.second, !b);
	}
}

void solve() {
	cin >> p;
	n = 1 << p;
	T = tree(n);
	edge_data = vi(n - 1);
	vert_data = vi(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		T[u].emplace_back(v, i);
		T[v].emplace_back(u, i);
	}
	ctr = 1;
	solve(-1, 0, -1);
	cout << "1\n";
	for(int x : vert_data)
		cout << x << ' ';
	cout << '\n';
	for(int x : edge_data)
		cout << x << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}