/*

Code for problem B by cookiedoth
Generated 06 May 2020 at 05.49 PM










(@)(@)(@)(@)(@)

=_=
\_()_/
o_O

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

const int mx = 1010;
int n, m, a[mx][mx];
vector<pair<int, int> > dir = {
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0}
};

void read() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			a[i][j] = (c == '#');
		}
	}
}

int blocked[mx][mx], rsum[mx], csum[mx];

void check() {
	for (int i = 0; i < n; ++i) {
		int to_block = 0;
		for (int j = 1; j < m; ++j) {
			if (a[i][j] == 0 && a[i][j - 1] == 1) {
				to_block = 1;
			}
			chkmax(blocked[i][j], to_block);
		}
		to_block = 0;
		for (int j = m - 2; j >= 0; --j) {
			if (a[i][j] == 0 && a[i][j + 1] == 1) {
				to_block = 1;
			}
			chkmax(blocked[i][j], to_block);
		}
	}
	for (int i = 0; i < m; ++i) {
		int to_block = 0;
		for (int j = 1; j < n; ++j) {
			if (a[j][i] == 0 && a[j - 1][i] == 1) {
				to_block = 1;
			}
			chkmax(blocked[j][i], to_block);
		}
		to_block = 0;
		for (int j = n - 2; j >= 0; --j) {
			if (a[j][i] == 0 && a[j + 1][i] == 1) {
				to_block = 1;
			}
			chkmax(blocked[j][i], to_block);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			rsum[i] += blocked[i][j];
			csum[j] += blocked[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		if (rsum[i] == m) {
			cout << -1 << endl;
			exit(0);
		}
	}
	for (int i = 0; i < m; ++i) {
		if (csum[i] == n) {
			cout << -1 << endl;
			exit(0);
		}
	}
}

int used[mx][mx];

void dfs(int x, int y) {
	used[x][y] = 1;
	for (auto pp : dir) {
		int x1 = x + pp.first;
		int y1 = y + pp.second;
		if (x1 >= 0 && y1 >= 0 && x1 < n && y1 < m && used[x1][y1] == 0 && a[x1][y1] == 1) {
			dfs(x1, y1);
		}
	}
}

void print_cmp() {
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (used[i][j] == 0 && a[i][j] == 1) {
				dfs(i, j);
				ans++;
			}
		}
	}
	cout << ans << endl;
}

signed main() {
	fast_io();
	read();
	check();
	print_cmp();
}