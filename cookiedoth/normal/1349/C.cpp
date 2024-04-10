/*

Code for problem C by cookiedoth
Generated 12 May 2020 at 03.54 PM


 ] 
 
Il] 


>_<
o_O
-_-

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int INF = 1e9 + 228;
const int mx = 1010;
int n, m, t, a[mx][mx];
vector<pair<int, int> > dir = {
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0}
};

void read() {
	cin >> n >> m >> t;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			a[i][j] = c - '0';
		}
	}
}

vector<pair<int, int> > last_cmp;

int ok(int x, int y) {
	return (x >= 0 && y >= 0 && x < n && y < m);
}

int used[mx][mx], d[mx][mx];

void dfs(int x, int y) {
	last_cmp.emplace_back(x, y);
	used[x][y] = 1;
	for (auto pp : dir) {
		int x1 = x + pp.first;
		int y1 = y + pp.second;
		if (ok(x1, y1) && used[x1][y1] == 0 && a[x1][y1] == a[x][y]) {
			dfs(x1, y1);
		}
	}
}

queue<pair<int, int> > q;

void process_dfs() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			d[i][j] = INF;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (used[i][j] == 0) {
				last_cmp.clear();
				dfs(i, j);
				if (last_cmp.size() >= 2) {
					for (auto pp : last_cmp) {
						d[pp.first][pp.second] = 0;
						q.push(pp);
					}
				}
			}
		}
	}
}

void bfs() {
	while (!q.empty()) {
		pair<int, int> pp = q.front();
		q.pop();
		for (auto pp1 : dir) {
			int x = pp.first + pp1.first;
			int y = pp.second + pp1.second;
			if (ok(x, y) && d[x][y] == INF) {
				d[x][y] = d[pp.first][pp.second] + 1;
				q.push({x, y});
			}
		}
	}
}

int query(int x, int y, ll t) {
	if (d[x][y] == INF) {
		return a[x][y];
	} else {
		if (t <= d[x][y]) {
			return a[x][y];
		} else {
			return (a[x][y] ^ ((t - d[x][y]) % 2));
		}
	}
}

void process() {
	for (int i = 0; i < t; ++i) {
		int x, y;
		ll t;
		cin >> x >> y >> t;
		x--;
		y--;
		int ans = query(x, y, t);
		cout << ans << '\n';
	}
}

signed main() {
	fast_io();
	read();
	process_dfs();
	bfs();
	process();
}