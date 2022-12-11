#include <bits/stdc++.h>

const int MAXN = 210;
int mat[MAXN][MAXN];
int n, m;
int bak;
int pre[MAXN], tag[MAXN], tcol[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			std::cin >> mat[i][j], mat[i][j] ^= 1;
	for (int i = 0; i <= m; ++i) {
		for (int j = 1; j <= m; ++j)
			tag[j] = (j <= i) ^ mat[1][j];
		int fir = n + 1;
		for (int j = 1; j <= n; ++j) {
			int ch = tag[1] ^ mat[j][1];
			for (int k = 1; k <= m && (mat[j][k] ^ tag[k]) == ch; ++k)
				pre[j] = k;
			for (int k = pre[j] + 1; k <= m; ++k)
				if ((mat[j][k] ^ tag[k]) == ch)
					fir = -1;
		}
		for (int j = 1; j <= n; ++j)
			if (pre[j] != m) {
				if (fir != n + 1) { fir = -1; break; }
				fir = j;
			}
		if (fir == -1) continue;
		for (int j = 1; j <= n; ++j)
			tcol[j] = (j <= fir) ^ mat[j][1] ^ tag[1];
		std::cout << "YES" << std::endl;
		for (int j = 1; j <= n; ++j) std::cout << tcol[j];
		std::cout << std::endl;
		for (int j = 1; j <= m; ++j) std::cout << tag[j];
		std::cout << std::endl;
		return 0;
	}
	std::cout << "NO" << std::endl;
	return 0;
}