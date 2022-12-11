#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

const int MAXN = 1000010;
std::vector<int> dp[MAXN];
int A[MAXN], n, m, t, vx[MAXN];
const int Dollar1 = (scanf("%d%d%d", &n, &m, &t), t);
typedef long long LL;
inline int mul(const int x, const int y) {
	return static_cast<LL> (x) * y % Dollar1;
}
inline int up(int x) { return x -= Dollar1, x + (x >> 31 & Dollar1); }
inline int down(const int x) { return x + (x >> 31 & Dollar1); }
inline void add(int & x, const int y) {
	x += y - Dollar1, x += x >> 31 & Dollar1;
}
inline void dec(int & x, const int y) {
	x -= y, x += x >> 31 & Dollar1;
}
int g[5010][5010], downv[5010], fac[5010];
int main() {
	int tma = 0;
	for (int i = 1; i <= n; ++i) scanf("%d", A + i), tma = std::max(tma, A[i]);
	fac[0] = downv[0] = 1;
	for (int i = 1; i <= tma; ++i) {
		if (m - i + 1 < 0) break;
		downv[i] = mul(downv[i - 1], m - i + 1);
		fac[i] = mul(fac[i - 1], i);
	}
	g[1][1] = 1;
	for (int i = 2; i <= tma; ++i)
		for (int j = i; j <= tma; ++j)
			g[i][j] = up(g[i - 1][j - 1] + mul(g[i][j - 1], i - 1));
	dp[0].push_back(1); vx[0] = 1;
	for (int i = 1; i <= n; ++i) {
		dp[i].push_back(0);
		const int LSZ = dp[i - 1].size();
		for (int j = 1; j <= A[i]; ++j) {
			int nt = mul(downv[j], vx[i - 1]);
			if (LSZ > j) nt = down(nt - mul(dp[i - 1][j], fac[j]));
			nt = mul(nt, g[j][A[i]]);
			dp[i].push_back(nt);
			add(vx[i], nt);
		}
	}
	printf("%d\n", vx[n]);
	return 0;
}