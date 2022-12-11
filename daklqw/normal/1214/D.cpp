#include <bits/stdc++.h>

const int MAXN = 1000010;
int dp[MAXN], n, m, ind[MAXN];
char buf[MAXN];
int map[MAXN], dfn[MAXN], idfn[MAXN], tot;
int get(int x, int y) { return (x - 1) * m + y - 1; }
void getmin(int & x, int y) { x > y ? x = y : 0; }
const int vx[2] = {0, 1}, vy[2] = {1, 0};
bool vis[MAXN], vis2[MAXN];
bool bfs() {
	std::queue<int> qx, qy;
	qx.push(1), qy.push(1);
	vis[get(1, 1)] = true;
	while (!qx.empty()) {
		int x = qx.front(), y = qy.front();
		qx.pop(), qy.pop();
		for (int i = 0; i != 2; ++i) {
			int tx = x + vx[i], ty = y + vy[i];
			if (tx > n || ty > m) continue;
			int t = get(tx, ty);
			if (vis[t]) continue;
			if (map[t]) continue;
			vis[t] = true;
			qx.push(tx), qy.push(ty);
		}
	}
	qx.push(n), qy.push(m);
	vis2[get(n, m)] = true;
	while (!qx.empty()) {
		int x = qx.front(), y = qy.front();
		qx.pop(), qy.pop();
		for (int i = 0; i != 2; ++i) {
			int tx = x - vx[i], ty = y - vy[i];
			if (tx < 1 || ty < 1) continue;
			int t = get(tx, ty);
			if (vis2[t]) continue;
			if (map[t]) continue;
			vis2[t] = true;
			qx.push(tx), qy.push(ty);
		}
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) if (vis[get(i, j)] && vis2[get(i, j)]) {
			for (int k = 0; k != 2; ++k) {
				int tx = i + vx[k], ty = j + vy[k];
				if (tx > n || ty > m) continue;
				++ind[get(tx, ty)];
			}
		}
	qx.push(1), qy.push(1);
	while (!qx.empty()) {
		int x = qx.front(), y = qy.front();
		qx.pop(), qy.pop();
		idfn[dfn[get(x, y)] = ++tot] = get(x, y);
		for (int i = 0; i != 2; ++i) {
			int tx = x + vx[i], ty = y + vy[i];
			if (tx > n || ty > m) continue;
			int t = get(tx, ty);
			if (!vis[t] || !vis2[t]) continue;
			if (map[t]) continue;
			if (!--ind[t])
				qx.push(tx), qy.push(ty);
		}
	}
	return vis[get(n, m)];
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		std::cin >> buf + 1;
		for (int j = 1; j <= m; ++j)
			map[get(i, j)] = buf[j] == '#';
	}
	int ans = 2;
	if (!bfs()) ans = 0;
	else {
		int right = 0;
		for (int i = 1; i <= tot; ++i) {
			if (i != 1 && i != tot) {
				if (right == i) ans = 1;
			}
			int y = idfn[i] % m + 1, x = idfn[i] / m + 1;
			// std::cout << x << ' ' << y << std::endl;
			for (int k = 0; k != 2; ++k) {
				int tx = x + vx[k], ty = y + vy[k];
				if (tx > n || ty > m) continue;
				right = std::max(right, dfn[get(tx, ty)]);
			}
		}
	}
	std::cout << ans << std::endl;
	return 0;
}