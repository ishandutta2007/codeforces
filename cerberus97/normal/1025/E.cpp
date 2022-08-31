/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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

const int N = 55, MAX_MOVES = 10800, inf = 1e9;

int t = 0;
struct cube {
	int x, y, dx, dy;
	bool operator<(const cube &o) {
		if (t < 4) {
			if (dx != o.dx) {
				return (t & 1) ? (dx < o.dx) : (dx > o.dx);
			}
			return (t & 2) ? (dy < o.dy) : (dy > o.dy);
		} else {
			if (dy != o.dy) {
				return (t & 1) ? (dy < o.dy) : (dy > o.dy);
			}
			return (t & 2) ? (dx < o.dx) : (dx > o.dx);
		}
	}
} p[N], bak[N];

vector<cube> moves;
int dist[N][N], back[N][N], grid[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int done = 0;

void try_solve(int n, int m);
bool can_move(int i, int d, int n);
bool in_range(int x, int y, int n);
void shift(int x, int y, int n);
void move(int i, int d);
bool solved(int m);
void all_done();
bool get_path(int i, int n);

int main() {
	srand(42);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> p[i].x >> p[i].y;
	}
	for (int i = 1; i <= m; ++i) {
		cin >> p[i].dx >> p[i].dy;
		if (p[i].dx == p[i].x and p[i].dy == p[i].y) {
			++done;
		}
	}
	if (solved(m)) {
		cout << 0 << endl;
		return 0;
	}
	while (true) {
		for (int i = 1; i <= m; ++i) {
			bak[i] = p[i];
		}
		try_solve(n, m);
		++t;
		// if (t % 100 == 0) {
		// 	cout << t << endl;
		// }
		done = 0;
		for (int i = 1; i <= m; ++i) {
			p[i] = bak[i];
			if (p[i].dx == p[i].x and p[i].dy == p[i].y) {
				++done;
			}
		}
	}
}

void try_solve(int n, int m) {
	memset(grid, 0, sizeof(grid));
	moves.clear();
	if (t < 8) {
		sort(p + 1, p + 1 + m);
	} else {
		random_shuffle(p + 1, p + 1 + m);
	}
	for (int i = 1; i <= m; ++i) {
		grid[p[i].x][p[i].y] = i;
	}
	int noise = 2000;
	while (noise) {
		int i = (rand() % m) + 1;
		int d = (rand() % 4);
		if (can_move(i, d, n)) {
			move(i, d);
			--noise;
			if (solved(m)) {
				all_done();
			}
		}
	}
	for (int i = 1; i <= m; ++i) {
		if (p[i].x != p[i].dx or p[i].y != p[i].dy) {
			if (grid[p[i].dx][p[i].dy] != 0) {
				shift(p[i].dx, p[i].dy, n);
			}
			if (!get_path(i, n)) {
				return;
			}
		}
	}
	if (solved(m)) {
		all_done();
	}
}

void shift(int x, int y, int n) {
	for (int i = 1; i < x; ++i) {
		if (grid[i][y] == 0 and grid[i + 1][y]) {
			move(grid[i + 1][y], 0);
		}
	}
	if (grid[x][y] == 0) {
		return;
	}
	for (int i = n; i > x; --i) {
		if (grid[i][y] == 0 and grid[i - 1][y]) {
			move(grid[i - 1][y], 2);
		}
	}
}

bool can_move(int i, int d, int n) {
	int x = p[i].x + dx[d];
	int y = p[i].y + dy[d];
	return (in_range(x, y, n) and !grid[x][y]);
}

bool in_range(int x, int y, int n) {
	return (1 <= x and x <= n and 1 <= y and y <= n);
}

void move(int i, int d) {
	if (p[i].x == p[i].dx and p[i].y == p[i].dy) {
		--done;
	}
	int x = p[i].x + dx[d];
	int y = p[i].y + dy[d];
	moves.pb({p[i].x, p[i].y, x, y});
	swap(grid[x][y], grid[p[i].x][p[i].y]);
	p[i].x = x; p[i].y = y;
	if (p[i].x == p[i].dx and p[i].y == p[i].dy) {
		++done;
	}
}

bool solved(int m) {
	if (done < m or moves.size() > MAX_MOVES) {
		return false;
	}
	return true;
}

void all_done() {
	cout << moves.size() << endl;
	for (auto &i : moves) {
		cout << i.x << ' ' << i.y << ' ' << i.dx << ' ' << i.dy << '\n';
	}
	exit(0);
}

bool get_path(int s, int n) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dist[i][j] = inf;
		}
	}
	dist[p[s].x][p[s].y] = 0;
	queue<pii> q;
	q.push({p[s].x, p[s].y});
	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		if (i == p[s].dx and j == p[s].dy) {
			break;
		}
		q.pop();
		for (int d = 0; d < 4; ++d) {
			int x = i + dx[d];
			int y = j + dy[d];
			if (in_range(x, y, n) and !grid[x][y]) {
				if (dist[x][y] == inf) {
					dist[x][y] = dist[i][j] + 1;
					back[x][y] = (d + 2) % 4;
					q.push({x, y});
				}
			}
		}
	}
	vector<int> ans;
	if (dist[p[s].dx][p[s].dy] == inf) {
		return false;
	}
	int x = p[s].dx, y = p[s].dy;
	while (x != p[s].x or y != p[s].y) {
		int d = back[x][y];
		ans.pb((d + 2) % 4);
		x += dx[d];
		y += dy[d];
	}
	reverse(ans.begin(), ans.end());
	for (auto &d : ans) {
		move(s, d);
	}
	return true;
}