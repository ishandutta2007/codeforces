#include <bits/stdc++.h>

const int MAXN = 24 * 50000 + 10;
int n, A[51];
int mat[3][30];
int li1[51], li2[51];
int f[25][MAXN], g[25][MAXN];
int tot;
inline int dis(int x) {
	return std::max(x, tot - x);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n * 2; ++i) std::cin >> A[i];
	std::sort(A + 1, A + 1 + n * 2);
	mat[1][1] = A[1], mat[2][n] = A[2];
	tot = 0; int tota = 0;
	for (int i = 3; i <= n * 2; ++i) tot += A[i];
	for (int i = 1; i < n; ++i) tota += li1[i - 1] = A[2 + i];
	memset(f, -1, sizeof f);
	memset(g, -1, sizeof g);
	static int sm[1 << 24];
	const int U = 1 << n - 1;
	for (int i = 0; i != U; ++i) {
		sm[i] = sm[i & i - 1] + li1[__builtin_ctz(i)];
		f[__builtin_popcount(i)][sm[i]] = i;
	}
	for (int i = 1; i < n; ++i) li2[i - 1] = A[n * 2 - i + 1];
	for (int i = 0; i != U; ++i) {
		sm[i] = sm[i & i - 1] + li2[__builtin_ctz(i)];
		g[__builtin_popcount(i)][sm[i]] = i;
	}
	int ans = 0x3f3f3f3f, ax = 0, ay = 0;
	for (int i = 0; i < n; ++i) {
		static int li[MAXN]; int bak = 0;
		for (int j = 0; j <= tot - tota; ++j)
			if (g[n - 1 - i][j] != -1) li[++bak] = j;
		for (int j = 0; j <= tota; ++j)
			if (f[i][j] != -1) {
				while (bak > 1 && dis(j + li[bak]) > dis(j + li[bak - 1]))
					--bak;
				if (dis(j + li[bak]) < ans) {
					ans = dis(j + li[bak]);
					ax = f[i][j], ay = g[n - 1 - i][li[bak]];
				}
			}
	}
	int bu = 2, bd = 1;
	for (int i = 0; i + 1 < n; ++i)
		if (ax >> i & 1) mat[1][bu++] = li1[i];
		else mat[2][bd++] = li1[i];
	for (int i = 0; i + 1 < n; ++i)
		if (ay >> i & 1) mat[1][bu++] = li2[i];
		else mat[2][bd++] = li2[i];
	std::sort(mat[1] + 2, mat[1] + n + 1);
	std::sort(mat[2] + 1, mat[2] + n, std::greater<int>());
	for (int i = 1; i <= 2; ++i, std::cout << '\n')
		for (int j = 1; j <= n; ++j)
			std::cout << mat[i][j] << ' ';
	return 0;
}