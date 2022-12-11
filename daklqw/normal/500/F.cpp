#include <bits/stdc++.h>

const int MAXN = 2e4 + 10;
typedef std::vector<int> VI;
typedef std::pair<int, int> pi;
std::vector<pi> hav[MAXN << 2];
void add(int u, int l, int r, int L, int R, pi x) {
	if (L <= l && r <= R)
		return (void) hav[u].push_back(x);
	int mid = l + r >> 1;
	if (L <= mid) add(u << 1, l, mid, L, R, x);
	if (mid < R) add(u << 1 | 1, mid + 1, r, L, R, x);
}
int ansl[MAXN];
std::vector<int> qs[MAXN];
int ds[MAXN];
void gma(int & x, int y) { x < y ? x = y : 0; }
void dfs(int u, int l, int r, VI dp) {
	for (auto t : hav[u]) {
		for (int i = 4000 - t.first; ~i; --i)
			gma(dp[i + t.first], dp[i] + t.second);
	}
	if (l == r) {
		for (auto t : qs[l])
			ansl[t] = dp[ds[t]];
		return ;
	}
	int mid = l + r >> 1;
	dfs(u << 1, l, mid, dp);
	dfs(u << 1 | 1, mid + 1, r, dp);
}
int n, P;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> P;
	for (int i = 1; i <= n; ++i) {
		int a, b, c;
		std::cin >> a >> b >> c;
		add(1, 1, 20000, c, std::min(c + P - 1, 20000), pi(a, b));
	}
	int Q; std::cin >> Q;
	for (int i = 1, a; i <= Q; ++i)
		std::cin >> a >> ds[i], qs[a].push_back(i);
	dfs(1, 1, 20000, VI(4001, 0));
	for (int i = 1; i <= Q; ++i)
		std::cout << ansl[i] << '\n';
	return 0;
}