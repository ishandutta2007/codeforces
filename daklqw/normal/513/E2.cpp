#include <bits/stdc++.h>

const int MAXN = 3e4 + 10;

int f[210][MAXN], g[210][MAXN], h[210][MAXN], n, K;
int A[MAXN], pre[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K;
	for (int i = 1; i <= n; ++i) {
		std::cin >> A[i];
		pre[i] = pre[i - 1] + A[i];
	}
	memset(f, 0xcf, sizeof f);
	memset(g, 0xcf, sizeof g);
	const int NINF = **f;
	f[0][0] = g[0][0] = 0;
	for (int i = 1; i <= K; ++i) {
		int co = i == 1 || i == K ? 1 : 2;
		int pr, fr;
		fr = pr = NINF;
		for (int j = 0; j <= n; ++j) {
			f[i][j] = pre[j] * co + pr;
			fr = std::max(fr, g[i - 1][j]);
			if (fr != NINF)
				pr = std::max(pr, fr - pre[j] * co);
		}
		fr = pr = NINF;
		for (int j = 0; j <= n; ++j) {
			g[i][j] = -pre[j] * co + pr;
			fr = std::max(fr, f[i - 1][j]);
			if (fr != NINF)
				pr = std::max(pr, fr + pre[j] * co);
		}
		if (co != 1) {
			fr = pr = NINF;
			for (int j = 0; j <= n; ++j) {
				f[i][j] = std::max(f[i][j], fr);
				g[i][j] = std::max(g[i][j], pr);
				fr = std::max(fr, f[i - 1][j]);
				pr = std::max(pr, g[i - 1][j]);
			}
		}
	}
	int ans = NINF;
	ans = std::max(*std::max_element(f[K], f[K + 1]), ans);
	ans = std::max(*std::max_element(g[K], g[K + 1]), ans);
	std::cout << ans << std::endl;
	return 0;
}