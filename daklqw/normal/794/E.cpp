#include <bits/stdc++.h>

const int MAXN = 300010;
int A[MAXN], n;
int f[MAXN], g[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	for (int i = 1; i < n; ++i)
		f[i] = std::max(A[i], A[i + 1]);
	for (int i = 2; i < n; ++i)
		g[i] = std::max(std::min(A[i - 1], A[i]), std::min(A[i], A[i + 1]));
	int fl = n / 2 + 1, fr = (n + 1) / 2 - 1, fa = 0;
	int gl = (n + 1) / 2 + 1, gr = (n + 2) / 2 - 1, ga = 0;
	for (int i = 0; i < n; ++i) {
		if ((n - i) & 1) {
			if (i == n - 1) {
				std::cout << *std::max_element(A + 1, A + 1 + n) << '\n';
			} else {
				ga = std::max(ga, g[--gl]);
				ga = std::max(ga, g[++gr]);
				std::cout << ga << ' ';
			}
		} else {
			fa = std::max(fa, f[--fl]);
			fa = std::max(fa, f[++fr]);
			std::cout << fa << ' ';
		}
	}
	return 0;
}