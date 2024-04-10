#pragma GCC optimize(3)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
// using namespace std;
const int MAXN = 1010;
typedef long long LL;
const int MAXM = 100010;
int opt[MAXM], x0[MAXM], y0[MAXM], x1[MAXM], y1[MAXM], n, m, v[MAXM], ansl[MAXM], map[MAXN][MAXN], ls[MAXM], rs[MAXM], map2[MAXN][MAXN];
int main() {
    scanf("%d%d", &n, &m);
    for (register int i = 1; i <= m; ++i) {
        scanf("%d%d%d%d%d", &opt[i], &x0[i], &y0[i], &x1[i], &y1[i]);
        if (opt[i] == 2) scanf("%d", &v[i]);
    }
	int cnt;
	for (cnt = 1; ; ++cnt) {
		ls[cnt] = n * (cnt - 1) + 1;
		rs[cnt] = std::min(n * cnt, m);
		if (rs[cnt] == m) break;
	}
	for (int T = 1; T <= cnt; ++T) {
		const int L = ls[T], R = rs[T];
		for (register int i = L; i <= R; ++i) if (opt[i] == 2) {
			const int X0 = x0[i], Y0 = y0[i], X1 = x1[i], Y1 = y1[i], V = v[i];
			for (register int j = i + 1; j <= R; ++j) if (opt[j] == 1) {
				const int _x0 = std::max(X0, x0[j]), _x1 = std::min(X1, x1[j]),
					  _y0 = std::max(Y0, y0[j]), _y1 = std::min(Y1, y1[j]);
				if (_x0 > _x1 || _y0 > _y1) continue;
				if (!(_x1 - _x0 & 1) && !(_y1 - _y0 & 1)) ansl[j] ^= V;
			}
            map[X0][Y0] ^= V, map[X0][Y1 + 1] ^= V,
            map[X1 + 1][Y0] ^= V, map[X1 + 1][Y1 + 1] ^= V;
		} else {
            const int X0 = x0[i], X1 = x1[i], Y0 = y0[i], Y1 = y1[i];
            ansl[i] ^= map2[X1][Y1] ^ map2[X0 - 1][Y1] ^ map2[X1][Y0 - 1] ^ map2[X0 - 1][Y0 - 1];
		}
		if (T != cnt) {
        for (register int i = 1, j; i <= n; ++i)
            for (j = 1; j <= n; ++j)
                map2[i][j] = map[i][j] ^ map2[i - 1][j] ^ map2[i][j - 1] ^ map2[i - 1][j - 1];
        for (register int i = 1, j; i <= n; ++i)
            for (j = 1; j <= n; ++j)
                map2[i][j] ^= map2[i - 1][j] ^ map2[i][j - 1] ^ map2[i - 1][j - 1];
		}
	}
    for (register int i = 1; i <= m; ++i) if (opt[i] == 1) printf("%d\n", ansl[i]);
    return 0;
}