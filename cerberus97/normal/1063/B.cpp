/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e3 + 10;
const ll inf = 1e15;

char grid[N][N];
ll dist[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int steps = 0;

void bfs(int i, int j, ll d);

int main() {
	fast_cin();
	int n, m, r, c, x, y;
	cin >> n >> m >> r >> c >> x >> y;
	for (int i = 1; i <= n; ++i) {
		cin >> (grid[i] + 1);
		for (int j = 1; j <= m; ++j) {
			dist[i][j] = inf;
		}
	}
	bfs(r, c, 0);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			// cout << dist[i][j] << ' ';
			ll ld = dist[i][j];
			ll rd = j - c + ld;
			if (ld <= x and rd <= y) {
				++ans;
			}
		}
		// cout << endl;
	}
	cout << ans << endl;
	// cout << steps << endl;
}

void bfs(int sx, int sy, ll d) {
	// ++steps;
	// if (steps % 10000 == 0) {
	// 	cout << steps / 10000 << endl;
	// }

	dist[sx][sy] = d;
	deque<pii> q;
	q.push_back({sx, sy});
	while (!q.empty()) {
		auto p = q.front();
		q.pop_front();
		int i = p.first, j = p.second;
		for (int dir = 0; dir < 4; ++dir) {
			int x = i + dx[dir];
			int y = j + dy[dir];
			if (grid[x][y] == '.') {
				if (y >= j) {
					if (dist[x][y] > dist[i][j]) {
						dist[x][y] = dist[i][j];
						q.push_front({x, y});
					}
				} else if (dist[x][y] > dist[i][j] + 1) {
					dist[x][y] = dist[i][j] + 1;
					q.push_back({x, y});
				}
			}
		}
	}
}