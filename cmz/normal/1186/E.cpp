// luogu-judger-enable-o2
#include <cstdio>

const int N = 1e3 + 5;

int n, m, q, sum[N][N];

int opt(int x, int y) {
	return (__builtin_popcount(x) + __builtin_popcount(y)) & 1;
}
int calc(int x, int y, int opt) {
	return opt == 0 ? sum[x][y] : x * y - sum[x][y];
}
long long I(int x, int y, int r, int c) {
	long long ans = 1LL * r * c / 2 * n * m;
	if ((r & 1) && (c & 1)) ans += calc(n, m, opt(r - 1, c - 1));
	return ans;
}
long long D(int x, int y, int r, int c) {
	int xx = r * n;
	long long ans = 1LL * c / 2 * (x - xx) * m;
	if (c & 1) ans += calc(x - xx, m, opt(r, c - 1));
	return ans;
}
long long R(int x, int y, int r, int c) {
	int yy = c * m;
	long long ans = 1LL * r / 2 * n * (y - yy);
	if (r & 1) ans += calc(n, y - yy, opt(r - 1, c));
	return ans;
}
long long O(int x, int y, int r, int c) {
	int xx = r * n, yy = c * m;
	return calc(x - xx, y - yy, opt(r, c));
}
long long query(int x, int y) {
	if (x == 0 || y == 0) return 0;
	int r = (x - 1) / n, c = (y - 1) / m;
	if (r == 0 && c == 0) return O(x, y, r, c);
	if (r == 0) return D(x, y, r, c) + O(x, y, r, c);
	if (c == 0) return R(x, y, r, c) + O(x, y, r, c);
	return I(x, y, r, c) + D(x, y, r, c) + R(x, y, r, c) + O(x, y, r, c);
}
long long query(int x1, int y1, int x2, int y2) {
	return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
}
long long kkkk;
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x;
			scanf("%1d", &x);
			sum[i][j] = x + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= q; i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%lld\n", query(x1, y1, x2, y2));
	}
	return 0;
}