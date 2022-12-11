#include <bits/stdc++.h>

const int MAXN = 1010;
typedef std::pair<int, int> pi;
std::vector<pi> ansl;
int n;
bool out[MAXN][MAXN];
void readg() {
	memset(out, 0, sizeof out);
	for (int i = 1, b, e; i <= n - 3; ++i)
		std::cin >> b >> e, out[b][e] = out[e][b] = true;
	for (int i = 1; i <= n; ++i) {
		int v = i == n ? 1 : i + 1;
		out[i][v] = out[v][i] = true;
	}
}
void chg(int x, int y, int a, int b, int typ) {
	out[x][y] = out[y][x] = false;
	out[a][b] = out[b][a] = true;
	if (typ) ansl.emplace_back(a, b);
	else ansl.emplace_back(x, y);
}
void solve(int l, int r, int typ) {
	if (l + 1 >= r) return ;
	if (out[l][r]) {
		for (int m = l + 1; m < r; ++m)
			if (out[l][m] && out[m][r]) {
				chg(l, r, 1, m, typ);
				solve(l, m, typ);
				solve(m, r, typ);
				return ;
			}
	} else {
		int lst = l;
		for (int i = l + 1; i <= r; ++i)
			if (out[1][i]) {
				solve(lst, i, typ);
				lst = i;
			}
	}
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	readg();
	solve(2, n, false);
	auto it = ansl.size();
	readg();
	solve(2, n, true);
	std::reverse(ansl.begin() + it, ansl.end());
	std::cout << ansl.size() << std::endl;
	for (auto t : ansl)
		std::cout << t.first << ' ' << t.second << '\n';
	return 0;
}