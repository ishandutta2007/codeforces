#include <bits/stdc++.h>

const int MAXN = 510;
typedef long long LL;
void gma(LL & x, LL y) { x < y ? x = y : 0; }
int n;
struct obj {
	int a, b, k;
	int val(int at) {
		return std::max<LL>(0, a - (LL) b * std::min(k, at - 1));
	}
} ps[MAXN];
LL dp[MAXN][MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> ps[i].a >> ps[i].b >> ps[i].k;
	std::sort(ps + 1, ps + 1 + n, [] (obj a, obj b) {
		return a.b > b.b;
	});
	memset(dp, 0xcf, sizeof dp);
	dp[0][0] = 0;
	LL ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			gma(dp[i][j], dp[i - 1][j] + ps[i].val(0x3f3f3f3f));
			if (j) gma(dp[i][j], dp[i - 1][j - 1] + ps[i].val(j));
			gma(ans, dp[i][j]);
		}
	}
	std::cout << ans << std::endl;
	return 0;
}