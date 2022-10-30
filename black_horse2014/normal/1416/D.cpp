#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, q; cin >> n >> m >> q;
	vector<int> p(n + m);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	vector<int> a(m), b(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
		--a[i], --b[i];
	}
	vector<int> f(n + m);
	for (int i = 0; i < n + m; i++) {
		f[i] = i;
	}
	vector<int> t(q), o(q);
	vector<int> del(m);
	for (int i = 0; i < q; i++) {
		cin >> t[i] >> o[i];
		--o[i];
		if (t[i] == 2) {
			del[o[i]] = 1;
		}
	}
	vector<vector<int>> adj(n + m);
	function<int(int)> find_set = [&](int u) {
		return f[u] == u ? u : f[u] = find_set(f[u]);
	};
	int cur = n;
	for (int i = 0; i < m; i++) {
		if (del[i]) {
			continue;
		}
		int x = find_set(a[i]);
		int y = find_set(b[i]);
		if (x != y) {
			f[x] = f[y] = cur;
			adj[cur].push_back(x);
			adj[cur].push_back(y);
//			cerr << "cur " << cur << ' ' << x << endl;
//			cerr << "cur " << cur << ' ' << y << endl;
			cur++;
		}
	}
	for (int i = q - 1; i >= 0; i--) {
		if (t[i] == 2) {
			int j = o[i];
			int x = find_set(a[j]);
			int y = find_set(b[j]);
			if (x != y) {
				f[x] = f[y] = cur;
				adj[cur].push_back(x);
				adj[cur].push_back(y);
//				cerr << "cur " << cur << ' ' << x << endl;
//				cerr << "cur " << cur << ' ' << y << endl;
				cur++;
			}
		} else {
			o[i] = find_set(o[i]);
		}
	}
	vector<int> st(n + m), en(n + m);
	int T = 0;
	function<void(int)> dfs = [&](int u) {
		st[u] = T++;
		for (int v : adj[u]) {
			dfs(v);
		}
		en[u] = T;
	};
	int N = 1 << (33 - __builtin_clz(n + m));
	vector<pair<int, int>> d(N);
	auto update = [&](int u, pair<int, int> x) {
		u += N / 2;
		for (d[u] = x, u >>= 1; u; u >>= 1) {
			d[u] = max(d[u + u], d[u + u + 1]);
		}
	};
	auto query = [&](int l, int r) {
		l += N / 2, r += N / 2;
		pair<int, int> ret = {0, 0};
		while (l < r) {
			if (l & 1) {
				ret = max(ret, d[l]);
				l++;
			}
			if (r & 1) {
				ret = max(ret, d[r - 1]);
				r--;
			}
			l >>= 1, r >>= 1;
		}
		return ret;
	};
	for (int i = 0; i < n + m; i++) {
		if (find_set(i) == i) {
			dfs(i);
		}
	}
	for (int i = 0; i < n; i++) {
		update(st[i], {p[i], i});
	}
	for (int i = 0; i < q; i++) {
		if (t[i] == 1) {
			auto ret = query(st[o[i]], en[o[i]]);
			update(st[ret.second], {0, ret.second});
			cout << ret.first << "\n";
		}
	}
	return 0;
}