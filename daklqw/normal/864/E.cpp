#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXD = 2010;
const int MAXN = 110;
int ts[MAXN], ds[MAXN], ps[MAXN], f[MAXN][MAXD], pre[MAXN][MAXD], n, li[MAXN], bak, rk[MAXN];
inline bool cmp(int a, int b) { return ds[a] < ds[b]; }
inline void getmax(int & x, const int y) { if (x < y) x = y; }
int main() {
	scanf("%d", &n);
	int md = 0;
	for (int i = 1; i <= n; ++i) scanf("%d%d%d", ts + i, ds + i, ps + i), md = std::max(md, ds[i]), rk[i] = i;
	std::sort(rk + 1, rk + 1 + n, cmp);
	for (int j = 1; j <= n; ++j) {
		int u = rk[j];
		for (int i = ds[u] - ts[u]; i > 0; --i) 
			if (f[j][i + ts[u]] < f[j - 1][i] + ps[u]) {
				// std::cout << "DEBER " << i << " " << f[j - 1][i] + ps[j] << std::endl;
				f[j][i + ts[u]] = f[j - 1][i] + ps[u];
				pre[j][i + ts[u]] = u;
			}
		for (int i = 0; i <= md; ++i)
			if (f[j][i] < f[j - 1][i]) {
				// std::cout << "DEBER " << i << " " << f[j - 1][i] << std::endl;
				f[j][i] = f[j - 1][i];
				pre[j][i] = 0;
			}
		// for (int i = 0; i <= md; ++i) printf("%d ", f[j][i]); putchar(10);
	}
	int as = 0;
	for (int i = 1; i <= md; ++i) if (f[n][i] > f[n][as]) as = i;
	int now = as;
	for (int i = n; i; --i) {
		int p = pre[i][now];
		if (p) li[++bak] = p;
		now -= ts[p];
	}
	printf("%d\n", f[n][as]);
	printf("%d\n", bak);
	for (int i = bak; i; --i) printf("%d ", li[i]); putchar(10);
	return 0;
}