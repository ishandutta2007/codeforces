#include <bits/stdc++.h>

const int P = 1000000007;

int qpow(int a, int b) {
	int s = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			s = 1ll * s * a % P;
		}
		a = 1ll * a * a % P;
	}
	return s;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v);
		E[v].push_back(u);
	}

	std::vector<std::vector<int>> C(n, std::vector<int>(n));
	for (int i = 0; i < n; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
		}
	}

	std::vector<std::vector<int>> f(n, std::vector<int>(n));
	for (int j = 1; j < n; ++j) {
		f[0][j] = 1;
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < n; ++j) {
			if (i + j < n) {
				for (int k = 0; k < j; ++k) {
					f[i][j] = (f[i][j] + 1ll * C[i + k - 1][k] * qpow(2, P - 1 - (i + k))) % P;
				}
			}
		}
	}

	int ans = 0;
	for (int rt = 0; rt < n; ++rt) {
		std::vector<int> dep(n);
		std::vector<std::vector<int>> S(n);
		std::function<void(int, int)> dfs = [&](int u, int fa) {
			S[u].push_back(u);
			for (int v : E[u]) {
				if (v != fa) {
					dep[v] = dep[u] + 1;
					dfs(v, u);
					for (int x : S[v]) {
						for (int y : S[u]) {
							int dx = dep[x] - dep[u], dy = dep[y] - dep[u];
							if (x > y) {
								ans = (ans + f[dx][dy]) % P;
							} else {
								ans = (ans + f[dy][dx]) % P;
							}
						}
					}
					for (int x : S[v]) {
						S[u].push_back(x);
					}
				}
			}
		};
		dep[rt] = 0;
		dfs(rt, -1);
	}
	std::cout << 1ll * ans * qpow(n, P - 2) % P << "\n";
}