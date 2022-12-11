#include <bits/stdc++.h>

const int MAXN = 310;
typedef std::string str;
typedef std::vector<int> VI;
str src[MAXN][MAXN], dst[MAXN][MAXN], tmp[MAXN][MAXN];
int c0[MAXN], c1[MAXN], n, m;
std::vector<VI> ansl;
void move(VI t) {
	char ch = tmp[t[0]][t[1]][0];
	tmp[t[0]][t[1]] = tmp[t[0]][t[1]].substr(1);
	tmp[t[2]][t[3]] += ch;
	assert((t[0] == t[2]) + (t[1] == t[3]) == 1);
}
void push(VI t) {
	ansl.push_back(t);
	// move(t);
}
void dbg(str arr[MAXN][MAXN] = tmp) {
	for (int i = 1; i <= n; ++i, std::cout << '\n')
		for (int j = 1; j <= m; ++j)
			std::cout << arr[i][j] << " | ";
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			std::cin >> src[i][j];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			std::cin >> dst[i][j];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			std::reverse(src[i][j].begin(), src[i][j].end());
			std::reverse(dst[i][j].begin(), dst[i][j].end());
			tmp[i][j] = src[i][j];
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			for (auto t : src[i][j]) {
				int tx, ty;
				if (t == '0') {
					ty = 1;
					if (j != 1) tx = i; else tx = i == 1 ? n : 1;
					++c0[tx];
				} else {
					ty = m;
					if (j != m) tx = i; else tx = i == 1 ? n : 1;
					++c1[tx];
				}
				push(VI({i, j, tx, ty}));
			}
			if (j != 1 && j != m)
				for (auto t : dst[i][j])
					--(t == '0' ? c0 : c1)[i];
		}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n && c0[i] < 0; )
			if (j != i && c0[j] > 0) {
				push((VI) {j, 1, i, 1});
				--c0[j], ++c0[i];
			} else ++j;
		for (int j = 1; j <= n && c1[i] < 0; )
			if (j != i && c1[j] > 0) {
				push((VI) {j, m, i, m});
				--c1[j], ++c1[i];
			} else ++j;
		for (int j = 2; j < m; ++j)
			for (auto t : dst[i][j])
				push((VI) {i, t == '0' ? 1 : m, i, j});
	}
	for (int i = 1; i < n; ++i) while (c0[i] > 0)
		push((VI) {i, 1, n, 1}), --c0[i];
	for (int i = 2; i <= n; ++i) while (c1[i] > 0)
		push((VI) {i, m, 1, m}), --c1[i];
	for (int i = n; i; --i) {
		for (auto t : dst[i][1])
			push((VI) {t == '0' ? n : 1, t == '0' ? 1 : m, 1, 1});
		for (auto t : dst[n - i + 1][m])
			push((VI) {t == '0' ? n : 1, t == '0' ? 1 : m, n, m});
	}
	for (int i = n; i > 1; --i)
		for (auto t : dst[i][1])
			push((VI) {1, 1, i, 1});
	for (int i = 1; i < n; ++i)
		for (auto t : dst[i][m])
			push((VI) {n, m, i, m});
	std::cout << ansl.size() << std::endl;
	for (auto t : ansl) {
		for (auto q : t)
			std::cout << q << ' ';
		std::cout << '\n';
	}
	// dbg(), dbg(dst);
	return 0;
}