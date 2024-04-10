#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};

const int N = 55;
const int M = 22000;
bool vis[N][N];
int T, chk[N][N], id[N], tx[N], ty[N], x[N], y[N], ans[N][N], ret[N * N], c;
vector<int> vec, Y;
int Fx[M], Fy[M], Tx[M], Ty[M], moves;
void move(int u, int xx, int yy) {
	assert(!vis[xx][yy]);
	assert(abs(x[u] - xx) + abs(y[u] - yy) == 1);
	vis[x[u]][y[u]] = false;
	Fx[moves] = x[u], Fy[moves] = y[u];
	x[u] = xx, y[u] = yy;
	vis[x[u]][y[u]] = true;
	Tx[moves] = x[u], Ty[moves] = y[u];
	moves++;
	if (moves > 10800) while (true) {}
}

void moveTo(int u, int TX, int TY) {
	queue<pair<int, int> > Q;
	Q.push(make_pair(x[u], y[u]));
	T++;
	chk[x[u]][y[u]] = T;
	while (!Q.empty()) {
		pair<int, int> e = Q.front();
		Q.pop();
		if ((TX == -1 || e.first == TX) && (TY == -1 || e.second == TY)) {
			int xx = e.first, yy = e.second;
			c = 0;
			while (xx != x[u] || yy != y[u]) {
				int tp = ans[xx][yy];
				ret[c++] = tp;
				xx -= dx[tp], yy -= dy[tp];
			}
			for (int j = c - 1; j >= 0; j--) move(u, x[u] + dx[ret[j]], y[u] + dy[ret[j]]);
			break;
		}
		for (int j = 0; j < 4; j++) {
			int xx = e.first + dx[j], yy = e.second + dy[j];
			if (vis[xx][yy]) continue;
			if (chk[xx][yy] == T) continue;
			chk[xx][yy] = T;
			ans[xx][yy] = j;
			Q.push(make_pair(xx, yy));
		}
	}
}
int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) scanf("%d%d", x + i, y + i), id[i] = i, vis[x[i]][y[i]] = true;
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= n + 1; j++) if (i == 0 || i == n + 1 || j == 0 || j == n + 1) vis[i][j] = true;
	for (int i = 1; i <= m; i++) scanf("%d%d", tx + i, ty + i);
	if (n == 1) return puts("0"), 0;
	sort(id + 1, id + m + 1, [](int i, int j) {
		return x[i] != x[j] ? x[i] < x[j] : y[i] < y[j];
	});
	for (int i = m; i >= 1; i--) {
		int u = id[i];
		while (!vis[x[u] + 1][y[u]]) move(u, x[u] + 1, y[u]);
	}
	sort(id + 1, id + m + 1, [](int i, int j) {
		return x[i] != x[j] ? x[i] < x[j] : y[i] < y[j];
	});
	for (int i = 1; i <= m; i++) {
		int u = id[i];
		moveTo(u, n, -1);
	}
	for (int i = 1; i <= m; i++) if (tx[i] >= n - 1) vec.push_back(i);
	sort(vec.begin(), vec.end(), [](int i, int j) {
		return tx[i] != tx[j] ? tx[i] < tx[j] : ty[i] < ty[j];
	});
	for (auto u: vec) {
		Y.push_back(y[u]);
		move(u, x[u] - 1, y[u]);
		if (n > 2) move(u, x[u] - 1, y[u]);
	}
	sort(Y.begin(), Y.end());
	for (int i = 0; i < vec.size(); i++) {
		int u = vec[i];
		moveTo(u, n, Y[i]);
	}
	for (int i = 1; i <= m; i++) assert(x[i] == n);
	sort(id + 1, id + m + 1, [](int i, int j) {
		return tx[i] != tx[j] ? tx[i] < tx[j] : ty[i] < ty[j]; 
	});
	for (int i = 1; i < m; i++) assert(tx[id[i]] < tx[id[i + 1]] || tx[id[i]] == tx[id[i + 1]] && ty[id[i]] < ty[id[i + 1]]);
	for (int i = 1; i <= m; i++) {
		int u = id[i];
		if (tx[u] == n - 1) {
			move(u, x[u] - 1, y[u]);
			while (!vis[x[u]][y[u] - 1]) move(u, x[u], y[u] - 1);
			continue;
		}
		if (tx[u] == n) {
			while (!vis[x[u]][y[u] - 1]) move(u, x[u], y[u] - 1);
			continue;
		}
		moveTo(u, tx[u], ty[u]);
	}
	for (int i = m; i >= 1; i--) {
		int u = id[i];
		if (tx[u] < n - 1) break;
		assert(y[u] <= ty[u]);
		while (y[u] != ty[u]) move(u, x[u], y[u] + 1);
	}
	printf("%d\n", moves);
	for (int i = 0; i < moves; i++) printf("%d %d %d %d\n", Fx[i], Fy[i], Tx[i], Ty[i]);
	for (int i = 1; i <= m; i++) assert(tx[i] == x[i] && ty[i] == y[i]);
	return 0;
}