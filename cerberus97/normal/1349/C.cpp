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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e3 + 10, inf = 1e9 + 42;

bool a[N][N];
int dist[N][N];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool in_range(int x, int n);

int main() {
	fast_cin();
	int n, m, t;
	cin >> n >> m >> t;
	for (int i = 1; i <= n; ++i) {
		string s; cin >> s;
		for (int j = 1; j <= m; ++j) {
			a[i][j] = (s[j - 1] == '1');
			dist[i][j] = inf;
		}
	}
	queue<pii> q;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int d = 0; d < 4; ++d) {
				int x = i + dx[d];
				int y = j + dy[d];
				if (in_range(x, n) and in_range(y, m) and a[x][y] == a[i][j]) {
					dist[i][j] = 0;
					q.push({i, j});
					break;
				}
			}
		}
	}
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int i = cur.first, j = cur.second;
		for (int d = 0; d < 4; ++d) {
			int x = i + dx[d];
			int y = j + dy[d];
			if (in_range(x, n) and in_range(y, m) and a[x][y] != a[i][j] and dist[i][j] + 1 < dist[x][y]) {
				dist[x][y] = dist[i][j] + 1;
				q.push({x, y});
			}
		}
	}
	while (t--) {
		int i, j; ll p;
		cin >> i >> j >> p;
		if (dist[i][j] == inf or dist[i][j] >= p) {
			cout << a[i][j] << '\n';
		} else {
			cout << (a[i][j] ^ ((p - dist[i][j]) & 1)) << '\n';
		}
	}
}

bool in_range(int x, int n) {
	return (1 <= x and x <= n);
}