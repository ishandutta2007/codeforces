/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1001, K = 41;
int d[K][K];
int dis[K][N][N];
int a[N][N];
bool vis[K][K];
int gx[4] = {-1, 1, 0, 0};
int gy[4] = {0, 0, -1, 1};
vector <pair <int, int>> v[K];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			a[i][j]--;
			v[a[i][j]].push_back(make_pair(i, j));
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int c = 0; c < K; c++)
				dis[c][i][j] = -1;
	for (int i = 0; i < K; i++) 
		for (int j = 0; j < K; j++)
			d[i][j] = INT_MAX;
	for (int c = 0; c < k; c++) {
		queue <pair <int, int>> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == c) 
					q.push(make_pair(i, j)), dis[c][i][j] = 0;
			}
		}
		vis[c][c] = true;
		while (!q.empty()) {
			int x = q.front().F;
			int y = q.front().S;
			q.pop();
			for (int i = 0; i < 4; i++) {
				if (x + gx[i] < 0 || x + gx[i] >= n || y + gy[i] < 0 || y + gy[i] >= m)
					continue;
				if (dis[c][x + gx[i]][y + gy[i]] == -1) {
					dis[c][x + gx[i]][y + gy[i]] = dis[c][x][y] + 1;
					q.push(make_pair(x + gx[i], y + gy[i]));
					d[c][a[x + gx[i]][y + gy[i]]] = min(d[c][a[x + gx[i]][y + gy[i]]], dis[c][x + gx[i]][y + gy[i]]);
				}
			}
			if (vis[c][a[x][y]])
				continue;
			vis[c][a[x][y]] = true;
			for (int i = 0; i < v[a[x][y]].size(); i++) {
				if (dis[c][v[a[x][y]][i].F][v[a[x][y]][i].S] == -1) {
					dis[c][v[a[x][y]][i].F][v[a[x][y]][i].S] = dis[c][x][y] + 1;
					q.push(v[a[x][y]][i]);
					d[c][a[x][y]] = min(d[c][a[x][y]], dis[c][v[a[x][y]][i].F][v[a[x][y]][i].S]);
				}
			}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1--, c1--, r2--, c2--;
		if (r1 == r2 && c1 == c2) {
			cout << 0 << ' ';
			continue;
		}
		if (a[r1][c1] == a[r2][c2]) {
			cout << 1 << ' ';
			continue;
		}
		int mn = abs(r1 - r2) + abs(c1 - c2);
		for (int i = r1 - 40; i <= r1 + 40; i++) {
			for (int j = c1 - 40; j <= c1 + 40; j++) {
				if (i < 0 || j < 0 || i >= n || j >= m)
					continue;
				int x = abs(r1 - i) + abs(c1 - j) + dis[a[i][j]][r2][c2] + 1;
				mn = min(mn, x);
			}
		}
		mn = min(mn, d[a[r1][c1]][a[r2][c2]] + 2);
		mn = min(mn, dis[a[r1][c1]][r2][c2] + 1);
		mn = min(mn, dis[a[r2][c2]][r1][c1] + 1);
		cout << mn << ' ';
	}
}