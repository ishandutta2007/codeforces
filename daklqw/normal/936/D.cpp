#include <bits/stdc++.h>

const int MAXN = 3000010;
const int NINF = 0xcfcfcfcf;
int li[MAXN], bak;
int n, m1, m2, T;
int dp[MAXN][2], pre[MAXN][2];
int isw[MAXN][2];
int xs[MAXN], ys[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m1 >> m2 >> T;
	for (int i = 1; i <= m1; ++i) {
		std::cin >> xs[i];
		li[++bak] = xs[i] - 1; li[++bak] = xs[i]; li[++bak] = xs[i] + 1;
	}
	for (int i = 1; i <= m2; ++i) {
		std::cin >> ys[i];
		li[++bak] = ys[i] - 1; li[++bak] = ys[i]; li[++bak] = ys[i] + 1;
	}
	li[++bak] = 0;
	std::sort(li + 1, li + 1 + bak);
	bak = std::unique(li + 1, li + 1 + bak) - li - 1;
	for (int i = 1; i <= m1; ++i)
		isw[std::lower_bound(li + 1, li + 1 + bak, xs[i]) - li][0] = true;
	for (int i = 1; i <= m2; ++i)
		isw[std::lower_bound(li + 1, li + 1 + bak, ys[i]) - li][1] = true;
	memset(dp, 0xcf, sizeof dp);
	pre[1][0] = pre[1][1] = 2;
	dp[1][0] = dp[1][1] = 0;
	for (int i = 2; i <= bak; ++i) {
		int d = li[i] - li[i - 1];
		for (int j = 0; j < 2; ++j)
			if (dp[i - 1][j] + d - 1 >= isw[i][j] * T) {
				dp[i][j] = dp[i - 1][j] + d - isw[i][j] * T;
				pre[i][j] = 1;
			}
		if (dp[i][0] < 0 && dp[i][1] < 0)
			return std::cout << "No" << std::endl, 0;
		int x = 0, y = 1;
		if (dp[i][x] < dp[i][y]) std::swap(x, y);
		if (std::min(dp[i][x], T) > dp[i][y] && !isw[i][y]) {
			dp[i][y] = std::min(dp[i][x], T);
			pre[i][y] = 2;
		}
	}
	std::cout << "Yes" << std::endl;
	std::vector<int> ax, ay, az;
	int cnt = 0, now = bak, b = dp[bak][0] == NINF ? 1 : 0;
	while (true) {
		if (pre[now][b] == 2) {
			assert(!isw[now][b]);
			int hav = dp[now][b], cur = li[now];
			if (hav < T) cur += T - hav;
			for (int i = 1; i <= cnt; ++i)
				ay.push_back(cur + (cnt - i) * T), az.push_back(b + 1);
			cnt = 0, b ^= 1;
			if (now == 1) break;
			ax.push_back(li[now]);
		} else cnt += isw[now--][b];
	}
	if (b == 0) ax.push_back(0);
	int S = ax.size();
	std::cout << S << '\n';
	for (int i = S - 1; ~i; --i) std::cout << ax[i] << (" \n" [i == 0]);
	S = ay.size();
	std::cout << S << '\n';
	for (int i = S - 1; ~i; --i)
		std::cout << ay[i] << ' ' << az[i] << '\n';
	return 0;
}