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

const int N = 1e3 + 10;

struct pt {
	int x, y;
	bool operator==(const pt& o) const {
		return tie(x, y) == tie(o.x, o.y);
	}
};

pt a[N][N];
char grid[N][N];
bool done[N][N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char to_dir[4] = {'R', 'L', 'D', 'U'};
char opp_dir[4] = {'L', 'R', 'U', 'D'};

int main() {
	fast_cin();
	int n; cin >> n;
	queue<pt> q;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j].x >> a[i][j].y;
			if (tie(a[i][j].x, a[i][j].y) == tie(i, j)) {
				done[i][j] = true;
				grid[i][j] = 'X';
				q.push(a[i][j]);
			}
		}
	}
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int x = p.x + dx[dir];
			int y = p.y + dy[dir];
			if (x < 1 or x > n or y < 1 or y > n or done[x][y]) {
				continue;
			} else if (a[x][y] == a[p.x][p.y]) {
				done[x][y] = true;
				grid[x][y] = opp_dir[dir];
				q.push({x, y});
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (!done[i][j]) {
				if (a[i][j].x != -1) {
					cout << "INVALID\n";
					return 0;
				}
				bool ok = false;
				for (int dir = 0; dir < 4; ++dir) {
					int x = i + dx[dir];
					int y = j + dy[dir];
					if (x < 1 or x > n or y < 1 or y > n) {
						continue;
					} else if (a[x][y] == a[i][j]) {
						ok = true;
						grid[i][j] = to_dir[dir];
						break;
					}
				}
				if (!ok) {
					cout << "INVALID\n";
					return 0;
				}
			}
		}
	}
	cout << "VALID\n";
	for (int i = 1; i <= n; ++i) {
		cout << (grid[i] + 1) << '\n';
	}
}