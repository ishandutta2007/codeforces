#include <bits/stdc++.h>

const int MAXN = 1010;
const int dr[8][2] = {
	{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
	{1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};
int n, m;
bool avai(int x, int y) {
	if (x < 1 || y < 1 || x > n || y > m) return false;
	return true;
}
struct bfs {
	int dis[MAXN][MAXN];
	void solve(int x, int y) {
		dis[x][y] = 1;
		std::queue<int> qx, qy;
		qx.push(x), qy.push(y);
		while (!qx.empty()) {
			int x = qx.front(), y = qy.front();
			qx.pop(), qy.pop();
			for (int i = 0; i != 8; ++i) {
				int tx = x + dr[i][0];
				int ty = y + dr[i][1];
				if (!avai(tx, ty) || dis[tx][ty]) continue;
				dis[tx][ty] = dis[x][y] + 1;
				qx.push(tx), qy.push(ty);
			}
		}
	}
} T1, T2;
int ax, ay;
int get(int x, int y) { return (x + y) & 1; }
void cho(int x) {
	std::cout << (x == 0 ? "WHITE" : "BLACK") << std::endl;
}
void read() {
	std::cin >> ax >> ay;
}
void print(int x, int y, bfs *d, bool flg = false) {
	if (d->dis[x][y] <= 1) return ;
	int px = -1, py = -1;
	for (int i = 0; i < 8; ++i) {
		int tx = x + dr[i][0], ty = y + dr[i][1];
		if (!avai(tx, ty)) continue;
		if (tx == ax && ty == ay) {
			std::cout << tx << ' ' << ty << std::endl;
			exit(0);
		}
		if (d->dis[tx][ty] == d->dis[x][y] - 1) px = tx, py = ty;
	}
	std::cout << px << ' ' << py << std::endl;
	if (d->dis[px][py] > 1 || flg) read();
	print(px, py, d, flg);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	int x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;
	T1.solve(n / 2, m / 2);
	T2.solve(n / 2 + 1, m / 2);
	if (get(x1, y1) == get(x2, y2)) {
		if (T2.dis[x2][y2] < T1.dis[x1][y1])
			cho(1), read(), print(x2, y2, &T2);
		else if (T1.dis[x2][y2] <= T1.dis[x1][y1]) {
			cho(1), read(), print(x2, y2, &T1, true);
			print(n / 2, m / 2, &T2);
		} else cho(0), ax = x2, ay = y2, print(x1, y1, &T1);
	} else {
		if (T1.dis[x1][y1] <= T2.dis[x2][y2])
			cho(0), print(x1, y1, &T1);
		else if (T2.dis[x1][y1] <= T2.dis[x2][y2] + 1) {
			cho(0), print(x1, y1, &T2, true);
			print(n / 2 + 1, m / 2, &T1);
		} else cho(1), read(), print(x2, y2, &T2);
	}
	return 0;
}