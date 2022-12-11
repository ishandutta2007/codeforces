#include <bits/stdc++.h>

const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int f[2][110][110][110];
int n, m, K, C[110][110];
int main() {
	std::cin >> n >> m >> K;
	++n;
	for (int i = 0; i <= n; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			if (C[i][j] > K) C[i][j] = K + 1;
		}
	}
	int ans = 0;
	int now = 0, lst = 1;
	f[now][0][1][1] = 1;
	for (int i = 0; i < m; ++i) {
		std::swap(now, lst);
		std::memset(f[now], 0, sizeof f[now]);
		for (int j = 0; j <= n; ++j)
		for (int k = 1; k <= n; ++k)
		for (int t = k; t + j <= n; ++t)
		for (int l = 1; l <= K; ++l) {
			if (l * C[t - 1][k - 1] > K) break;
			reduce(f[now][j + t][t - k][l * C[t - 1][k - 1]] += f[lst][j][k][l] - mod);
		}
		for (int j = 1; j <= K; ++j)
			for (int l = 2; l <= n; ++l)
			reduce(ans += mul(f[now][l][0][j], m - i) - mod);
	}
	std::cout << ans << std::endl;
	return 0;
}