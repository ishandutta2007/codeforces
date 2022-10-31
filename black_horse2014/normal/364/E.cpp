#include <cstdio>
#include <algorithm>
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define MX 2505

typedef long long ll;
int a[2][MX][MX], pl[7], pr[7];
int n, m, K;
ll ans;

inline int get(int sx, int sy, int tx, int ty, int d) {
	return a[d][tx][ty] - a[d][sx - 1][ty] - a[d][tx][sy - 1] + a[d][sx - 1][sy - 1];
}

void find(int sx, int sy, int tx, int ty, int d) {
	if (tx - sx > ty - sy) {
		std::swap(sx, sy);
		std::swap(tx, ty);
		d ^= 1;
	}
	if (ty == sy) {
		ans += (get(sx, sy, sx, sy, d) == K);
		return;
	}
	
	int mid = sy + ty >> 1;
	find(sx, sy, tx, mid, d);
	find(sx, mid + 1, tx, ty, d);
	rep(i, sx, tx) {
		rep(k, 0, K) pl[k] = sy, pr[k] = ty;
		rep(j, i, tx) {
			rep(k, 0, K) {
				while (get(i, pl[k], j, mid, d) > k) pl[k]++;
				while (get(i, mid + 1, j, pr[k], d) > k) pr[k]--;
			}
			rep(k, 0, K)
				ans += ((k? pl[k - 1]: mid + 1) - pl[k]) * (pr[K - k] - ((K - k)? pr[K - k - 1]: mid));
		}
	}
}

main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
	char tp[MX];
	scanf("%d%d%d", &n, &m, &K);
	rep(i, 1, n) {
		scanf("%s", tp);
		rep(j, 1, m) {
			a[0][i][j] = a[0][i][j - 1] + a[0][i - 1][j] - a[0][i - 1][j - 1] + (tp[j - 1] == '1');
			a[1][j][i] = a[1][j][i - 1] + a[1][j - 1][i] - a[1][j - 1][i - 1] + (tp[j - 1] == '1');
		}
	}
	
	find(1, 1, n, m, 0);
	printf("%I64d\n", ans);
}