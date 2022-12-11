#include <bits/stdc++.h>

const int mod = 1000000007;
const int MAXN = 1100010;
std::vector<int> G[MAXN][10], qs[MAXN];
void addedge(int b, int e, int v) {
	G[b][v].push_back(e);
}
int n, m, idx, dp[MAXN];
bool vis[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m; idx = n;
	for (int i = 1; i <= m; ++i) {
		int t1, t2; std::cin >> t1 >> t2;
		static int arr[10], bak; bak = 0;
		int t = i;
		while (t) arr[bak++] = t % 10, t /= 10;
		int lst = t1;
		for (int j = bak - 1; ~j; --j) {
			int now = j ? ++idx : t2;
			addedge(lst, now, arr[j]);
			lst = now;
		}
		for (int j = bak - 1; ~j; --j) {
			int now = j ? ++idx : t1;
			addedge(lst, now, arr[j]);
			lst = now;
		}
	}
	int T;
	qs[T = 1].push_back(1); vis[1] = true;
	for (int P = 1; P <= T; ++P) {
		for (int j = 0; j != 10; ++j) {
			bool flg = false;
			for (auto t : qs[P]) {
				for (auto v : G[t][j]) {
					if (vis[v]) continue;
					vis[v] = true;
					dp[v] = (dp[t] * 10ll + j) % mod;
					qs[T + 1].push_back(v);
					flg = true;
				}
			}
			if (flg) ++T;
		}
	}
	for (int i = 2; i <= n; ++i)
		std::cout << dp[i] << '\n';
	return 0;
}