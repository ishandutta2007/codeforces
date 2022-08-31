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
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

vector<string> a;
vector<vector<int>> dist_ok, dist;

void bfs(vector<pii> &sources, int n, int m, vector<vector<int>> &d);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	a.resize(n);
	dist.resize(n);
	dist_ok.resize(n);
	for (int i = 0; i < n; ++i) {
		dist[i].resize(m);
		dist_ok[i].resize(m);
		cin >> a[i];
	}
	vector<pii> sources;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '.') {
				sources.pb({i, j});
			}
		}
	}
	bfs(sources, n, m, dist_ok);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int cand = min(min(i + 1, n - i), min(j + 1, m - j));
			dist_ok[i][j] = min(dist_ok[i][j], cand);
		}
	}
	int lo = 1, hi = min(n, m);
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		sources.clear();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (a[i][j] == 'X' and dist_ok[i][j] > mid) {
					sources.pb({i, j});
				}
			}
		}
		bfs(sources, n, m, dist);
		bool ok = true;
		for (int i = 0; i < n and ok; ++i) {
			for (int j = 0; j < m; ++j) {
				if (a[i][j] == 'X' and dist[i][j] > mid) {
					ok = false;
					break;
				}
				// if (mid == 1) {
				// 	cout << dist[i][j] << ' ';
				// }
			}
			// if (mid == 1) {
			// 	cout << endl;
			// }
		}
		if (ok) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	cout << lo - 1 << '\n';
	sources.clear();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 'X' and dist_ok[i][j] > lo - 1) {
				cout << 'X';
			} else {
				cout << '.';
			}
		}
		cout << '\n';
	}
}

void bfs(vector<pii> &sources, int n, int m, vector<vector<int>> &d) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			d[i][j] = n + m + 10;
		}
	}
	queue<pii> q;
	for (auto &p : sources) {
		d[p.first][p.second] = 0;
		q.push(p);
	}
	while (!q.empty()) {
		int i = q.front().first, j = q.front().second;
		q.pop();
		for (int dx = -1; dx <= 1; ++dx) {
			for (int dy = -1; dy <= 1; ++dy) {
				int x = i + dx;
				int y = j + dy;
				if (0 <= x and x < n and 0 <= y and y < m) {
					if (d[i][j] + 1 < d[x][y]) {
						d[x][y] = d[i][j] + 1;
						q.push({x, y});
					}
				}
			}
		}
	}
}