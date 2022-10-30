#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

vector<pair<int, int> > V;

int ans[1100][1100];
char s[1100][1100];
bool vis[1100][1100];

int cnt;
int n, m, q;

void dfs(int x, int y) {
	V.push_back(make_pair(x, y));
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= n || nx < 0 || ny < 0 || ny >= m) continue;
		if (s[nx][ny] != '.') {
			cnt++;
			continue;
		}
		if (vis[nx][ny]) continue;
		dfs(nx, ny);
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; i++) scanf("%s", s[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) if (!vis[i][j] && s[i][j] == '.') {
			V.clear();
			cnt = 0;
			dfs(i, j);
			for (auto p : V) ans[p.first][p.second] = cnt;
		}
	}
	while (q--) {
		int x, y; scanf("%d%d", &x, &y); printf("%d\n", ans[x-1][y-1]);
	}
	return 0;
}