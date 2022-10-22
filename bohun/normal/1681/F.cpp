#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define cat(x) cout << #x << ": " << x << endl
using ll = unsigned long long;
using namespace std;

const int N = 500500;

int n, in[N], out[N], sz[N], jump[N][19], dep[N], dp[N];
vector<int> e[N], v[N];
vector<pair<int, int>> adj[N];
vector<tuple<int, int, int>> mp;
ll res;

int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	per(i, 0, 18)
		if (dep[jump[x][i]] >= dep[y])
			x = jump[x][i];
	if (x == y) return x;
	per(i, 0, 18)
		if (jump[x][i] != jump[y][i]) {
			x = jump[x][i];
			y = jump[y][i];
		}
	return jump[x][0];
}

int dfs(int u, int p) {
	dep[u] = dep[p] + 1;

	jump[u][0] = p;
	rep(i, 1, 18)
		jump[u][i] = jump[jump[u][i - 1]][i - 1];

	sz[u] = 1;
	in[u] = ++*in;
	for (auto v : e[u]) {
		if (v != p) {
			sz[u] += dfs(v, u);
		}
	}

	out[u] = ++*in;
	return sz[u];
}

bool up(int x, int y) {
	return in[x] <= in[y] && in[y] <= out[x];
}

void solve1(int u) {
	dp[u] = 0;
	for (auto [v, w] : adj[u]) {
		solve1(v);
		if (w == 1) {
			dp[u] += sz[v];
		}
		else {
			dp[u] += dp[v];
		}
	}
}

void solve2(int u, int up) {
	for (auto [v, w] : adj[u]) {
		if (w == 1) {
			ll x = sz[v] - dp[v];
			ll y = (n - sz[v]) - (up + dp[u] - sz[v]);
			res += x * y;
		}

		if (w == 0) {
			solve2(v, up + dp[u] - dp[v]);
		}
		else {
			solve2(v, n - sz[v]);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	rep(i, 2, n) {
		int x, y, w;
		cin >> x >> y >> w;
		e[x].push_back(y);
		e[y].push_back(x);
		mp.push_back({x, y, w});
		mp.push_back({y, x, w});
		v[w].push_back(x);
		v[w].push_back(y);
	}

	sort(mp.begin(), mp.end());

	dfs(1, 1);

	rep(color, 1, n) {
		if (v[color].empty()) continue;

		vector<int> a = v[color];
		sort(a.begin(), a.end(), [&](int x, int y) {
			return in[x] < in[y];
		});
		a.erase(unique(a.begin(), a.end()), a.end());

		vector<int> b = a;
		rep(i, 0, int(a.size()) - 2)
			b.push_back(lca(a[i], a[i + 1]));

		sort(b.begin(), b.end(), [&](int x, int y) {
			return in[x] < in[y];
		});
		b.erase(unique(b.begin(), b.end()), b.end());

		for (auto u : b) adj[u].clear();

		vector<int> st = {b[0]};

		auto add_edge = [&]() {
			assert(st.size() >= 2);
			int u = st.back();
			st.pop_back();
			int v = st.back();

			auto it = lower_bound(mp.begin(), mp.end(), make_tuple(u, v, 0));
			int w = 0;
			if (it != mp.end()) {
				auto [U, V, W] = *it;
				if (u == U && v == V && W == color) {
					w = 1;
				}
			}
			adj[v].push_back({u, w});
		};

		rep(i, 1, int(b.size()) - 1) {
			int u = b[i];
			while (!up(st.back(), u)) {
				add_edge();
			}
			st.push_back(u);
		}

		while (st.size() >= 2) add_edge();

		solve1(b[0]);
		solve2(b[0], 0);
	}

	cout << res << "\n";

	return 0;
}