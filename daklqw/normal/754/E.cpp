#include <bits/stdc++.h>

const int MAXN = 410;
typedef std::bitset<MAXN> B;
B ans[MAXN], c[26][MAXN];
int n, m, R, C;
char S[MAXN][MAXN], T[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) std::cin >> S[i];
	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < m; ++k)
				if (S[j][k] != 'a' + i)
					c[i][j].set(k);
	std::cin >> R >> C;
	for (int i = 0; i < R; ++i) {
		std::cin >> T;
		for (int j = 0; j < C; ++j) if (T[j] != '?') {
			int ch = T[j] - 'a';
			for (int k = 0; k < n; ++k) {
				int _k = (k - i + n) % n, _j = j % m;
				ans[_k] |= c[ch][k] >> _j;
				ans[_k] |= c[ch][k] << m - _j;
			}
		}
	}
	for (int i = 0; i < n; ++i, std::cout << '\n')
		for (int j = 0; j < m; ++j)
			std::cout << (!ans[i][j]);
	return 0;
}