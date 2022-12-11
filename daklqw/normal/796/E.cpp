#include <bits/stdc++.h>

const int MAXN = 1100;
int dp[2][51][MAXN][51], (*f[51])[51], (*g[51])[51];
int n, P, K;
int A[MAXN], B[MAXN], C[MAXN]; 
void gma(int & x, int y) { x < y ? x = y : 0; }
void read(int * arr) {
	int t, t2; std::cin >> t;
	while (t--) std::cin >> t2, arr[t2] = 1;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> P >> K;
	read(A), read(B);
	for (int i = 1; i <= n; ++i) C[i] = (A[i] || B[i]) + C[i - 1];
	for (int i = 0; i <= K; ++i) f[i] = dp[0][i], g[i] = dp[1][i];
	P = std::min((n / K + 1) * 2, P);
	memset(dp, 0xcf, sizeof dp);
	const size_t CLZ = 51 * 4 * (P + 1);
	f[0][0][0] = 0;
	for (int l = 1; l <= n; ++l) {
		for (int j = 0; j <= P; ++j) {
			for (int k = 1; k <= K; ++k) {
				gma(f[1][j][k - 1], f[0][j][k] + A[l]);
				gma(g[1][j][k - 1], g[0][j][k] + B[l]);
				const int r = std::min(n, l + k - 1);
				gma(g[k][j + 1][K - k], f[0][j][k] + C[r] - C[l - 1]);
				gma(f[k][j + 1][K - k], g[0][j][k] + C[r] - C[l - 1]);
			}
			const int v = std::max(f[0][j][0], g[0][j][0]);
			gma(f[1][j][0], v);
			gma(f[1][j + 1][K - 1], v + A[l]);
			gma(g[1][j + 1][K - 1], v + B[l]);
			const int r = std::min(n, l + K - 1);
			gma(f[K][j + 2][0], v + C[r] - C[l - 1]);
		}
		memset(f[0], 0xcf, CLZ), memset(g[0], 0xcf, CLZ);
		for (int j = 0; j < K; ++j)
			std::swap(f[j], f[j + 1]), std::swap(g[j], g[j + 1]);
	}
	int Ans = 0;
	for (int i = 0; i <= K; ++i)
		for (int j = 0; j <= P; ++j)
			for (int k = 0; k <= K; ++k)
				gma(Ans, f[i][j][k]), gma(Ans, g[i][j][k]);
	std::cout << Ans << std::endl;
	return 0;
}