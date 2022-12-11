#include <bits/stdc++.h>

const int MAXN = 2010;
int A[MAXN][MAXN];
char buf[MAXN];
int n, m;
std::queue<std::pair<int, int> > q;
void deal(int x, int y) {
	if (x < 1 || y < 1 || x + 1 > n || y + 1 > m)
		return ;
	int sm = 0;
	for (int i = 0; i <= 1; ++i)
		for (int j = 0; j <= 1; ++j)
			sm += A[x + i][y + j];
	if (sm == 1) {
		for (int i = 0; i <= 1; ++i)
			for (int j = 0; j <= 1; ++j)
				if (A[x + i][y + j]) {
					q.emplace(x + i, y + j);
					A[x + i][y + j] = 0;
				}
	}
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		std::cin >> buf + 1;
		for (int j = 1; j <= m; ++j)
			A[i][j] = buf[j] == '*';
	}
	for (int i = 1; i < n; ++i)
		for (int j = 1; j < m; ++j)
			deal(i, j);
	while (!q.empty()) {
		int x, y;
		std::tie(x, y) = q.front(); q.pop();
		for (int i = -1; i <= 0; ++i)
			for (int j = -1; j <= 0; ++j)
				deal(x + i, y + j);
	}
	for (int i = 1; i <= n; ++i, std::cout << '\n')
		for (int j = 1; j <= m; ++j)
			std::cout << (".*"[A[i][j]]);
	return 0;
}