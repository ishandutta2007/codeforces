#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <time.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template <class A> ostream& operator << (ostream& out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if (i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 1010;
char buf[N];

int n, m, k;
string s[N];
int d[N][N];

bool read() {
	if (scanf("%d %d %d", &n, &m, &k) != 3)
		return false;
	forn(i, n) {
		scanf("%s", buf);
		s[i] = buf;
	}
	return true;
}

string dc[] = { "D", "L", "R", "U" };
int dx[] = { +1, 0, 0, -1 };
int dy[] = { 0, -1, 1, 0 };

bool ok(int x, int y) {
	return (0 <= x && x < n) && (0 <= y && y < m) && (s[x][y] != '*');
}

void bfs(int sx, int sy) {
	forn(i, n) forn(j, m)
		d[i][j] = INF;
	d[sx][sy] = 0;
	queue<pt> q;
	q.push(mp(sx, sy));
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		forn(i, 4) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (ok(nx, ny) && d[nx][ny] == INF) {
				d[nx][ny] = d[x][y] + 1;
				q.push(mp(nx, ny));
			}
		}
	}
}

void solve() {
	int sx = -1, sy = -1;
	forn(i, n) forn(j, m) {
		if (s[i][j] == 'X')
			sx = i, sy = j;
	}
	bfs(sx, sy);

	string ans;

	while (k > 0) {
		bool f = false;
		forn(i, 4) {
			int nx = sx + dx[i];
			int ny = sy + dy[i];
			if (ok(nx, ny) && d[nx][ny] < k) {
				ans += dc[i];
				sx = nx;
				sy = ny;
				k--;
				f = true;
				break;
			}
		}
		if (!f) {
			puts("IMPOSSIBLE");
			return;
		}
	}

	printf("%s\n", ans.c_str());
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tt = clock();

#endif

	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

	while (read()) {
		solve();

#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif

	}
}