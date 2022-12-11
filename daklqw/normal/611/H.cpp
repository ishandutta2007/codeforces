#include <bits/stdc++.h>

void bye() { exit((std::cout << -1 << std::endl, 0)); }
int n;
int up = 7;
const int MAXN = 200010;
int hav[10][10], node[10], pw[10], ori[10];
int xs[MAXN], ys[MAXN], bak;

int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	pw[1] = 1;
	for (int i = 2; i != 10; ++i) pw[i] = pw[i - 1] * 10;
	std::cin >> n;
	for (int i = 1; i < n; ++i) {
		static char s1[10], s2[10];
		std::cin >> s1 >> s2;
		int l1 = strlen(s1), l2 = strlen(s2);
		++hav[l1][l2], ++hav[l2][l1];
	}
	for (int i = 1; i <= n; ++i) {
		int t = i, d = 0; while (t) t /= 10, ++d; ++node[d];
	}
	while (!node[up]) --up;
	for (int i = 1; i <= up; ++i) {
		while (hav[i][i] > 0) {
			++bak;
			xs[bak] = pw[i] + node[i] - 1;
			ys[bak] = pw[i] + node[i] - 2;
			--node[i];
			hav[i][i] -= 2;
		}
		if (node[i] <= 0) bye();
	}
	auto hall = [] (int lim = false) {
		const int U = 1 << up;
		for (int i = 1; i <= up; ++i)
			for (int j = 1; j <= up; ++j)
				if (hav[i][j] < 0)
					return false;
		int tc = 0;
		for (int i = 1; i <= up; ++i) tc += !!node[i];
		for (int i = 1; i + 1 < U; ++i) {
			int lhs = 0;
			for (int j = 0; j < up; ++j)
				if (i >> j & 1) {
					lhs += node[j + 1];
					if (!node[j + 1]) lhs = -0x3f3f3f3f;
				}
			if (lhs < 0) continue;
			if (lim && __builtin_popcount(i) == tc) continue;
			for (int j = 0; j < up; ++j)
				for (int k = j + 1; k < up; ++k)
					if ((i >> k & 1) || (i >> j & 1))
						lhs -= hav[j + 1][k + 1];
			if (lhs > 0) return false;
		}
		return true;
	} ;
	if (!hall()) { bye(); }
	memcpy(ori, node, sizeof ori);
	static int tfa[10], rk[10];
	for (int i = 2; i < up; ++i) tfa[i] = 1;
	for (int i = 1; i <= up; ++i) rk[i] = i, --node[i];
	if (up > 1) while (true) {
		for (int i = up; i; --i)
			if (++tfa[i] == i) tfa[i] = 1; else break;
		bool can = false;
		do {
			for (int i = 2; i <= up; ++i)
				--hav[rk[tfa[i]]][rk[i]], --hav[rk[i]][rk[tfa[i]]];
			if (hall()) {
				for (int i = 2; i <= up; ++i) {
					++bak;
					int u = rk[tfa[i]], v = rk[i];
					xs[bak] = pw[u] + ori[u] - 1;
					ys[bak] = pw[v] + ori[v] - 1;
				}
				can = true;
				break;
			}
			for (int i = 2; i <= up; ++i)
				++hav[rk[tfa[i]]][rk[i]], ++hav[rk[i]][rk[tfa[i]]];
		} while (std::next_permutation(rk + 1, rk + 1 + up));
		if (can) break;
	}
	for (int i = 1; i <= up; ++i) while (node[i])
		for (int j = 1; j <= up; ++j) if (ori[j] && hav[i][j]) {
			--hav[i][j]; --hav[j][i]; --node[i];
			if (hall()) {
				++bak;
				xs[bak] = pw[i] + node[i];
				ys[bak] = pw[j] + ori[j] - 1;
				break;
			}
			++hav[i][j]; ++hav[j][i]; ++node[i];
		}
	for (int i = 1; i <= bak; ++i)
		std::cout << xs[i] << ' ' << ys[i] << '\n';
	return 0;
}