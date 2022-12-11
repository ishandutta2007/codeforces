#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;
int n, m, r, c, x, y, map[2010][2010], xt[2010][2010], yt[2010][2010];
bool vis[2010][2010];
string buf;
deque<int> qx, qy;
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> r >> c >> x >> y;
	for (int i = 1; i <= n; ++i) {
		cin >> buf;
		for (int j = 1; j <= m; ++j)
			map[i][j] = buf[j - 1] == '.';
	}
	xt[r][c] = x; yt[r][c] = y; vis[r][c] = true;
	qx.push_back(r); qy.push_back(c);
	while (!qx.empty()) {
		const int ox = qx.front(), oy = qy.front();
		qx.pop_front(); qy.pop_front();
		for (int i = 0; i != 4; ++i) {
			int tx = ox + ("0211"[i] - '1');
			int ty = oy + ("1102"[i] - '1');
			if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
			if (!map[tx][ty] || vis[tx][ty]) continue;
			if (i == 2 && !xt[ox][oy]) continue;
			if (i == 3 && !yt[ox][oy]) continue;
			vis[tx][ty] = true;
			xt[tx][ty] = xt[ox][oy] - (i == 2);
			yt[tx][ty] = yt[ox][oy] - (i == 3);
			if (i > 1) qx.push_back(tx), qy.push_back(ty);
			else qx.push_front(tx), qy.push_front(ty);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			ans += vis[i][j];
	cout << ans << endl;
	return 0;
}