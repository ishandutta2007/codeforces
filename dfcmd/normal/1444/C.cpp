#include <bits/stdc++.h>

const int N = 500005;

int n, m, k;
int c[N];
std::vector<int> E[N];
std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> M;

int col[N], idx, bel[N];
bool odd[N];

bool dfs(int u, int c) {
	bel[u] = idx;
	col[u] = c;
	for (int v : E[u]) {
		if (col[v] == -1) {
			if (!dfs(v, c ^ 1)) {
				return false;
			}
		} else if (col[v] == c) {
			return false;
		}
	}
	return true;
}

std::map<int, std::vector<int>> G;
std::map<int, int> Gc;

bool Gdfs(int u, int c) {
	Gc[u] = c;
	for (int v : G[u]) {
		if (!Gc.count(v)) {
			if (!Gdfs(v, c ^ 1)) {
				return false;
			}
		} else if (Gc[v] == c) {
			return false;
		}
	}
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		std::cin >> c[i];
		col[i] = -1, bel[i] = 0;
	}
	for (int i = 1; i <= m; ++i) {
		int u, v;
		std::cin >> u >> v;
		if (c[u] > c[v]) {
			std::swap(u, v);
		}
		if (c[u] == c[v]) {
			E[u].push_back(v);
			E[v].push_back(u);
		} else {
			M[{c[u], c[v]}].push_back({u, v});
		}
	}

	idx = 0;
	for (int i = 1; i <= n; ++i) {
		if (col[i] == -1) {
			++idx;
			if (!dfs(i, 0)) {
				odd[c[i]] = true;
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= k; ++i) {
		cnt += !odd[i];
	}
	long long ans = 1ll * cnt * (cnt - 1) / 2;
	for (const auto &it : M) {
		int a = it.first.first, b = it.first.second;
		if (odd[a] || odd[b]) {
			continue;
		}
		auto get = [&](int x) {
			return bel[x] << 1 | col[x];
		};
		G.clear();
		Gc.clear();
		for (auto e : it.second) {
			int u = get(e.first), v = get(e.second);
			G[u].push_back(v);
			G[v].push_back(u);
			G[u].push_back(u ^ 1);
			G[u ^ 1].push_back(u);
			G[v].push_back(v ^ 1);
			G[v ^ 1].push_back(v);
		}
		bool flag = 1;
		for (auto v : G) {
			if (!Gc.count(v.first)) {
				if (!Gdfs(v.first, 0)) {
					flag = 0;
					break;
				}
			}
		}
		ans -= !flag;
	}
	std::cout << ans << std::endl;
}