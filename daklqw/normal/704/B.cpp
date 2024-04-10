#include <bits/stdc++.h>

const int MAXN = 5010;
typedef long long LL;
LL dp[2][MAXN];
void getmin(LL & x, LL y) { x > y ? x = y : 0; }
int X[MAXN], A[MAXN], B[MAXN], C[MAXN], D[MAXN];
int L[2][MAXN], R[2][MAXN];
int n, S, E;
inline int tr(int x) { return x == 1 ? -1 : 1; }
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> S >> E;
	for (int i = 1; i <= n; ++i) std::cin >> X[i];
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	for (int i = 1; i <= n; ++i) std::cin >> B[i];
	for (int i = 1; i <= n; ++i) std::cin >> C[i];
	for (int i = 1; i <= n; ++i) std::cin >> D[i];
	for (int i = 1; i <= n; ++i) L[0][i] = D[i] - X[i];
	for (int i = 1; i <= n; ++i) L[1][i] = B[i] - X[i];
	for (int i = 1; i <= n; ++i) R[0][i] = C[i] + X[i];
	for (int i = 1; i <= n; ++i) R[1][i] = A[i] + X[i];
	memset(dp, 0x3f, sizeof dp);
	const LL INF = **dp;
	int now = 1, lst = 0;
	dp[now][0] = 0;
	const int RAN = n;
	for (int i = 1; i <= n; ++i) {
		std::swap(now, lst);
		memset(dp[now], 0x3f, sizeof (dp[now]));
		for (int j = (i > S) + (i > E); j <= RAN; ++j)
			if (dp[lst][j] < INF) {
				LL v = dp[lst][j];
				if (i == S) {
					getmin(dp[now][j + 1], v + L[0][i]);
					if (j > (i > E) || i == n)
						getmin(dp[now][j], v + R[0][i]);
				} else if (i == E) {
					getmin(dp[now][j + 1], v + L[1][i]);
					if (j > (i > S) || i == n)
						getmin(dp[now][j], v + R[1][i]);
				} else {
					if (j > 1) getmin(dp[now][j - 1], v + R[0][i] + R[1][i]);
					getmin(dp[now][j + 1], v + L[0][i] + L[1][i]);
					if (j > (i > S))
						getmin(dp[now][j], v + R[0][i] + L[1][i]);
					if (j > (i > E))
						getmin(dp[now][j], v + L[0][i] + R[1][i]);
				}
			}
	}
	std::cout << dp[now][1] << std::endl;
	return 0;
}