#ifndef ONLINE_JUDGE
#define LOCAL
#endif

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug-template.hpp"
#endif

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

struct DSU {
	vector<int> rnk, par, sz;
	vector<tuple<int, int, int>> data;
	void init(int n) {
		rnk.resize(n, 0);
		par.resize(n);
		sz.resize(n, 1);
		iota(par.begin(), par.end(), 0);
		data.clear();
	}
	int find_set(int x) {
		while (x != par[x]) {
			x = par[x];
		}
		return x;
	}
	void merge(int x, int y) {
		int px = find_set(x), py = find_set(y);
		if (px == py) {
			return;
		}
		if (rnk[px] > rnk[py]) {
			swap(px, py);
		}
		if (rnk[px] == rnk[py]) {
			data.emplace_back(py, -1, -1);
			data.emplace_back(px, py, sz[py]);
			rnk[py]++;
			par[px] = py;
			sz[py] += sz[px];
		} else {
			data.emplace_back(px, py, sz[py]);
			par[px] = py;
			sz[py] += sz[px];
		}
	}
	void restore(int last) {
		while (data.size() > last) {
			auto t = data.back(); data.pop_back();
			int x, y, z; tie(x, y, z) = t;
			if (y == -1) {
				rnk[x]--;
			} else {
				par[x] = x;
				sz[y] = z;
			}
		}
	}
} dsu;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, q, m; cin >> n >> q >> m;
	dsu.init(n);
	vector<int> op(q);
	vector<int> x(q), y(q);
	vector<int> start = {0};
	for (int i = 0; i < q; i++) {
		cin >> op[i];
		if (op[i] == 1) {
			cin >> x[i] >> y[i];
			x[i]--, y[i]--;
		} else if (op[i] == 2) {
			cin >> x[i];
			x[i]--;
		} else {
			start.push_back(i + 1);
		}
	}
	start.push_back(q);
	int N = 1 << 20;
	vector<vector<pair<int, int>>> E(N);
	function<void(int, int, int, int, int, int, int)> add = [&](int u, int l, int r, int ll, int rr, int x, int y) {
		if (ll <= l && r <= rr) {
			E[u].emplace_back(x, y);
			return;
		}
		int mid = l + r >> 1;
		if (ll <= mid) {
			add(u + u, l, mid, ll, rr, x, y);
		}
		if (mid < rr) {
			add(u + u + 1, mid + 1, r, ll, rr, x, y);
		}
	};
	function<void(int, int, int)> dfs = [&](int u, int l, int r) {
		int last = dsu.data.size();
		for (auto e : E[u]) {
			dsu.merge(e.first, e.second);
		}
		if (l == r) {
			if (op[l] == 2) {
				cout << dsu.sz[dsu.find_set(x[l])] << "\n";
			}
			dsu.restore(last);
			return;
		}
		int mid = l + r >> 1;
		dfs(u + u, l, mid);
		dfs(u + u + 1, mid + 1, r);
		dsu.restore(last);
	};
	int cur = 0;
	for (int i = 0; i < q; i++) {
		if (op[i] == 1) {
			int to = q - 1;
			if (cur + m < start.size()) {
				to = start[cur + m] - 1;
			}
			add(1, 0, q - 1, i, to, x[i], y[i]);
		} else if (op[i] == 3) {
			cur++;
		}
	}
	dfs(1, 0, q - 1);
	return 0;
}
/*
5 12 2
1 1 2
1 1 3
1 3 4
2 4
2 5
3
2 1
1 1 2
1 3 2
2 1
3
2 1
*/