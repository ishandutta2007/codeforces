#include <bits/stdc++.h>

const int MAXN = 100010;
const int INF = 0x3f3f3f3f;
typedef long long LL;
LL A[MAXN];
int n;
int dp[2][MAXN], rk[2][MAXN];
void gmi(int & x, int y) { x > y ? x = y : 0; }
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	LL ma = *std::max_element(A + 1, A + 1 + n);
	for (int i = 1; i <= n; ++i) A[i] = ma - A[i];
	int now = 1, lst = 0;
	memset(dp, 0x3f, sizeof dp);
	for (int i = 1; i <= n; ++i) rk[now][i] = i;
	dp[now][0] = 0;
	for (int i = 0; i < 63; ++i) {
		std::swap(now, lst);
		int buc[2];
		memset(buc, 0, 8);
		for (int j = 1; j <= n; ++j) ++buc[A[j] >> i & 1];
		buc[1] += buc[0];
		for (int j = n; j; --j) {
			const int u = rk[lst][j];
			rk[now][buc[A[u] >> i & 1]--] = u;
		}
		memset(buc, 0, 8);
		for (int j = 1; j <= n; ++j) ++buc[A[j] >> i & 1];
		int bse = 0;
		memset(dp[now], 0x3f, n + 1 << 2);
		for (int j = 0; j <= n; ++j) {
			if (j) {
				const int u = rk[lst][n - j + 1];
				--buc[A[u] >> i & 1];
				++buc[((A[u] >> i) + 1) & 1];
				if (A[u] >> i & 1) ++bse;
			}
			for (int k = 0; k < 2; ++k) {
				int nt = k * buc[1] + bse;
				gmi(dp[now][nt], dp[lst][j] + buc[k ^ 1]);
			}
		}
	}
	std::cout << dp[now][0] << std::endl;
	return 0;
}