#include <bits/stdc++.h>

const int MAXN = 5010;
const int INF = 0x3f3f3f3f;
int A[MAXN], n, B, ansl[MAXN];
int f[MAXN][10010], pre[MAXN][10010];
void gmin(int x, int y, int z, int p) {
	if (z < f[x][y]) f[x][y] = z, pre[x][y] = p;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> B;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	memset(f, 0x3f, sizeof f); **f = 0;
	for (int i = 1, pre = 0; i <= n; pre += A[i++])
		for (int j = 0; j != 10010; ++j) if (f[i - 1][j] != INF) {
			int t = f[i - 1][j], res = B + j - pre + t;
			for (int k = std::min(res, A[i] / 2); ~k; --k)
				gmin(i, j + (A[i] - k) / 10, t + A[i] - k, j);
		}
	int at = std::min_element(f[n], f[n + 1]) - f[n];
	std::cout << f[n][at] << '\n';
	for (int i = n; i; --i)
		ansl[i] = A[i] - f[i][at] + f[i - 1][pre[i][at]], at = pre[i][at];
	for (int i = 1; i <= n; ++i) std::cout << ansl[i] << ' ';
	return 0;
}