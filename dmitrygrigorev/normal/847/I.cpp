#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define int long long
#define x first
#define y second

const int MAXN = 250;
char arr[MAXN + 2][MAXN + 2];
int level[MAXN + 2][MAXN + 2];
int bfs[MAXN + 2][MAXN + 2];

signed main() {
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < MAXN + 2; i++) {
		for (int j = 0; j < MAXN + 2; j++) {
			arr[i][j] = '*';
			level[i][j] = 0;
			bfs[i][j] = -1;
		}
	}

	int n, m, q, p;
	cin >> n >> m >> p >> q;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	// cout << "HERE\n";
	// int x;
	// cin >> x;

	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};

	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			if ('A' <= arr[x][y] && arr[x][y] <= 'Z') {
				queue <pair <int, int> > Q;
				Q.push(make_pair(x, y));
				bfs[x][y] = ((arr[x][y] - 'A' + 1) * p);
				vector <pair <int, int> > used;
				while (!Q.empty()) {
					pair <int, int> v = Q.front(); Q.pop();
					used.push_back(v);
					if (bfs[v.x][v.y] / 2 == 0) continue; 
					for (int d = 0; d < 4; d++) {
						int nx = v.x + dx[d];
						int ny = v.y + dy[d];
						if (arr[nx][ny] != '*' && bfs[nx][ny] == -1) {
							bfs[nx][ny] = bfs[v.x][v.y] / 2;
							Q.push(make_pair(nx, ny));
						}
					}
				}
				for (auto v : used) {
					level[v.x][v.y] += bfs[v.x][v.y];
					bfs[v.x][v.y] = -1;
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cnt += (level[i][j] > q);
			// cout << level[i][j] << " ";
		}
		// cout << endl;
	}
	cout << cnt;
	return 0;
}