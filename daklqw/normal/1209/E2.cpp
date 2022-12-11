#include <bits/stdc++.h>

const int MAXN = 2010;

int n, m, arr[MAXN][12], deb[MAXN], li[MAXN];
void gma(int & x, int y) { x < y ? x = y : 0; }
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int T; std::cin >> T;
	while (T --> 0) {
		std::cin >> m >> n;
		for (int i = 0; i < m; ++i)
			for (int j = 1; j <= n; ++j)
				std::cin >> arr[j][i];
		for (int i = 1; i <= n; ++i) {
			deb[li[i] = i] = 0;
			for (int j = 0; j < m; ++j)
				gma(deb[i], arr[i][j]);
		}
		auto cmp = [] (int a, int b) {
			return deb[a] > deb[b];
		} ;
		std::sort(li + 1, li + 1 + n, cmp);
		const int U = 1 << m;
		static int f[1 << 12], g[1 << 12], h[1 << 12];
		memset(f, 0, U << 2);
		memset(h, 0, U << 2);
		for (int T = 1; T <= n && T <= m; ++T) {
			const int i = li[T];
			memset(g, 0, U << 2);
			for (int j = 0; j != U; ++j) {
				for (int k = 0; k < m; ++k) {
					int t = 0;
					for (int p = k, q = 0; q < m; ++p, ++q)
						if (j >> q & 1)
							t += arr[i][p % m];
					gma(g[j], t);
				}
			}
			for (int j = 0; j != U; ++j)
				for (int l = j; l; l = l - 1 & j)
					gma(h[j], g[l] + f[j ^ l]);
			for (int j = 0; j != U; ++j) gma(f[j], h[j]);
		}
		std::cout << *std::max_element(f, f + U) << '\n';
	}
	return 0;
}