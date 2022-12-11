#include <bits/stdc++.h>

const int MAXN = 55;
typedef std::pair<int, int> pi;
typedef std::vector<pi> V;
char mat[MAXN][MAXN];
int n, m;
V solve(int n, int m) {
	for (int i = 1; i <= n; ++i)
		std::cin >> mat[i] + 1;
	bool rev = m & 1;
	if (rev) {
		int up = std::max(n, m);
		for (int i = 1; i <= up; ++i)
			for (int j = 1; j <= up; ++j) if (i < j)
				std::swap(mat[i][j], mat[j][i]);
		std::swap(n, m);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				if (mat[i][j] == 'L') mat[i][j] = 'U';
				else if (mat[i][j] == 'R') mat[i][j] = 'D';
				else if (mat[i][j] == 'U') mat[i][j] = 'L';
				else mat[i][j] = 'R';
			}
	}
	V res;
	auto rotate = [&res] (int x, int y) {
		res.emplace_back(x, y);
		if (mat[x][y] == 'L') {
			mat[x][y] = mat[x][y + 1] = 'U';
			mat[x + 1][y] = mat[x + 1][y + 1] = 'D';
		} else {
			mat[x][y] = mat[x + 1][y] = 'L';
			mat[x][y + 1] = mat[x + 1][y + 1] = 'R';
		}
	} ;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) if (mat[i][j] == 'U') {
			int x, y;
			for (x = i, y = j; ; ++x, ++y)
				if (mat[x][y + 1] == 'L') {
					if (mat[x + 1][y + 1] == 'L') {
						rotate(x, y + 1);
						break;
					}
				} else break;
			while (x >= i) {
				rotate(x, y);
				if (x > i) rotate(x - 1, y);
				--x, --y;
			}
		}
	if (rev) for (auto & t : res) std::swap(t.first, t.second);
	return res;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	V l = solve(n, m), r = solve(n, m);
	l.insert(l.end(), r.rbegin(), r.rend());
	std::cout << l.size() << std::endl;
	for (auto t : l) std::cout << t.first << ' ' << t.second << '\n';
	return 0;
}