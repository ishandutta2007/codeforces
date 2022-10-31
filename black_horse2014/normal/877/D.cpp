#include <bits/stdc++.h>
using namespace std;

const int N = 1100;

vector<pair<int, int> > E;
set<int> R[N], C[N];
set<int> :: iterator it;

int l[N][N], r[N][N], d[N][N], u[N][N], dis[N][N];
char s[N][N];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> s[i];
	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	sx--, sy--, ex--, ey--;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (!i || s[i - 1][j] == '#') u[i][j] = 0;
			else u[i][j] = u[i - 1][j] + 1;
			if (!j || s[i][j - 1] == '#') l[i][j] = 0;
			else l[i][j] = l[i][j - 1] + 1;
		}
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--) {
			if (i == n - 1 || s[i + 1][j] == '#') d[i][j] = 0;
			else d[i][j] = d[i + 1][j] + 1;
			if (j == m - 1 || s[i][j + 1] == '#') r[i][j] = 0;
			else r[i][j] = r[i][j + 1] + 1;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			R[i].insert(j);
			C[j].insert(i);
		}
	queue<pair<int, int> > que;
	dis[sx][sy] = 1;
	que.push(make_pair(sx, sy));
	while (!que.empty()) {
		pair<int, int> e = que.front();
		que.pop();
		if (e.first == ex && e.second == ey) return printf("%d\n", dis[ex][ey] - 1), 0;
		int x = e.first, y = e.second;
		C[y].erase(x);
		R[x].erase(y);
		int dx = x - 1, ux = max(x - k, x - u[x][y]);
		for (it = C[y].lower_bound(ux); it != C[y].end() && *it <= dx; it++) {
			int xx = *it;
			dis[xx][y] = dis[x][y] + 1;
			que.push(make_pair(xx, y));
			E.push_back(make_pair(xx, y));
		}
		ux = x + 1, dx = min(x + k, x + d[x][y]);
		for (it = C[y].lower_bound(ux); it != C[y].end() && *it <= dx; it++) {
			int xx = *it;
			dis[xx][y] = dis[x][y] + 1;
			que.push(make_pair(xx, y));
			E.push_back(make_pair(xx, y));
		}
		int ry = y - 1, ly = max(y - k, y - l[x][y]);
		for (it = R[x].lower_bound(ly); it != R[x].end() && *it <= ry; it++) {
			int yy = *it;
			dis[x][yy] = dis[x][y] + 1;
			que.push(make_pair(x, yy));
			E.push_back(make_pair(x, yy));
		}
		ly = y + 1, ry = min(y + k, y + r[x][y]);
		for (it = R[x].lower_bound(ly); it != R[x].end() && *it <= ry; it++) {
			int yy = *it;
			dis[x][yy] = dis[x][y] + 1;
			que.push(make_pair(x, yy));
			E.push_back(make_pair(x, yy));
		}
		for (auto pi : E) R[pi.first].erase(pi.second), C[pi.second].erase(pi.first);
		E.clear();
	}
	return puts("-1"), 0;
}