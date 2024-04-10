#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2222;
int a[maxn][maxn], n, m, q;
int vis[maxn][maxn];
void update(int r, int c) {
	while (r >= 1 && a[r][c] == 2) {
		vis[r][c] = true;
		r -= 1;
	}
}
int solve(int r, int c) {
	while (r <= n && !vis[r][c]) {
		int x = r, y = c;
		if (a[r][c] == 1)
			c += 1;
		else if (a[r][c] == 2)
			r += 1;
		else
			c -= 1;
		a[x][y] = 2;
	}
	update(r - 1, c);
	return c;
}
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	while (q--) {
		int r = 1, c = 0;
		scanf("%d", &c);
		int ans = solve(r, c);
		printf("%d ", ans);
	}
	printf("\n");
	return 0;
}