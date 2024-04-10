#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 110;
typedef long long LL;
const LL DX = 10000000;
int xs[MAXN], ys[MAXN], n, map[11][11];
LL f[3][MAXN], dis[3][3][MAXN][MAXN];
inline int getElementByID(int x, int y) { return map[x][y]; }
const char wx[3][10] = {
	"4655",
	"4466",
	"66447733"
} ;
const char wy[3][10] = {
	"5546",
	"4646",
	"73736464"
} ;
const int SZ[3] = {4, 4, 8} ;
inline void getmin(LL & x, const LL y) { if (x > y) x = y; }
int main() {
	scanf("%d", &n);
	const int MAXNODE = n * n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &map[i][j]);
			xs[map[i][j]] = i; ys[map[i][j]] = j;
		}
	memset(dis, 0x3f, sizeof dis);
	for (int frm = 0; frm != 3; ++frm)
		for (int tar = 0; tar != 3; ++tar)
			for (int i = 1; i <= MAXNODE; ++i) {
				for (int delta = 1; delta <= (tar == 2 ? 1 : n); ++delta) {
					for (int k = 0; k != SZ[tar]; ++k) {
						const int tx = xs[i] + (wx[tar][k] - '5') * delta;
						const int ty = ys[i] + (wy[tar][k] - '5') * delta;
						if (tx < 1 || ty < 1 || tx > n || ty > n) continue;
						dis[frm][tar][i][getElementByID(tx, ty)] = DX + (tar != frm) * (DX + 1);
					}
					// std::cout << "ADDEDGE " << frm << " " << i << " " << tar << " " << getElementByID(tx, ty) << " " << DX + (tar != frm) << std::endl;
				}
			}
	for (int ki = 0; ki != 3; ++ki)
		for (int k = 1; k <= MAXNODE; ++k)
			for (int ii = 0; ii != 3; ++ii)
				for (int i = 1; i <= MAXNODE; ++i)
					for (int ji = 0; ji != 3; ++ji)
						for (int j = 1; j <= MAXNODE; ++j)
							getmin(dis[ii][ji][i][j], dis[ii][ki][i][k] + dis[ki][ji][k][j]);
	memset(f, 0x3f, sizeof f);
	f[0][1] = f[1][1] = f[2][1] = 0;
	for (int i = 2; i <= MAXNODE; ++i) {
		for (int frm = 0; frm != 3; ++frm)
			for (int tar = 0; tar != 3; ++tar)
				getmin(f[tar][i], f[frm][i - 1] + dis[frm][tar][i - 1][i]);
//		for (int j = 0; j != 3; ++j) std::cout << f[j][i] << " ";
//		std::cout << std::endl;
//		for (int tar = 0; tar != 3; ++tar)
//			for (int frm = 0; frm != 3; ++frm)
//				if (f[tar][i] == f[frm][i - 1] + dis[frm][tar][i - 1][i]) {
//					std::cout << tar << " FROM " << frm << " " << dis[frm][tar][i - 1][i] << std::endl;
//				}
	}
	LL ans = 0x3f3f3f3f3f3f3f3fLL;
	for (int i = 0; i != 3; ++i) getmin(ans, f[i][MAXNODE]);
	printf("%lld %lld\n", ans / DX, ans % DX);
	return 0;
}