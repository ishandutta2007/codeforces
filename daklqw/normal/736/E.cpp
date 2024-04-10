#include <bits/stdc++.h>

const int MAXN = 3010;
int n, m, A[MAXN];
int mat[MAXN][MAXN], rk[MAXN];
void bye() { std::cout << "no" << std::endl; exit(0); }
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> m >> n;
	int rest = m * (m - 1);
	for (int i = 1; i <= n; ++i) std::cin >> A[i], rest -= A[i];
	if (rest < 0) bye();
	if (n < m) {
		int tr = rest / (m - n), md = rest % (m - n);
		for (int i = 1; i <= m - n; ++i)
			A[i + n] = tr + (i <= md);
		if (A[n] < A[n + 1]) bye();
	} else if (rest) bye();
	for (int i = 1; i <= m; ++i) rk[i] = i;
	for (int i = m; i > 1; --i) {
		for (int j = 1; j <= i; ++j) if (A[rk[j]] > (i - 1) * 2) bye();
		std::sort(rk + 1, rk + i + 1, [] (int a, int b) { return A[a] > A[b]; });
		for (int j = i - 1; j; --j) {
			int u = rk[j], v = rk[i], d;
			if (A[v] || A[u] == 1) {
				d = std::min(A[v], 2);
				if (A[u] == 1) d = 1;
			} else d = 0;
			if (d < 0) bye();
			A[v] -= d; A[u] -= 2 - d;
			mat[u][v] = 2 - d, mat[v][u] = d;
		}
		for (int j = 1; j <= i; ++j) if (A[rk[j]] < 0) bye();
	}
	for (int i = 1; i <= m; ++i) if (A[i]) bye();
	std::cout << "yes" << std::endl;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i == j) std::cout << 'X';
			else if (mat[i][j] == 0) std::cout << 'L';
			else if (mat[i][j] == 1) std::cout << 'D';
			else std::cout << 'W';
		}
		std::cout << '\n';
	}
	return 0;
}