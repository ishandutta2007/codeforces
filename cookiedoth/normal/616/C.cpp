/*

Code for problem C by savkinsd2089
Generated 15 Dec 2018 at 03.26 pm
The Moon is at the First Quarter


  !











~_^
o_O
-_-

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
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
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)

#ifndef TESTING
	#define endl '\n'
#endif

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
int n, m, a[mx][mx], used[mx][mx], cmp[mx][mx], sz[mx * mx], cmp_cnt;
vector<pair<int, int> > d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int check(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}

int dfs(int i, int j, int color) {
	used[i][j] = 1;
	cmp[i][j] = color;
	int res = 1;
	for (auto pp : d) {
		int i1 = i + pp.first;
		int j1 = j + pp.second;
		if (check(i1, j1) && used[i1][j1] == 0 && a[i1][j1] == 0) {
			res += dfs(i1, j1, color);
		}
	}
	return res;
}

signed main() {
	fast_io();
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			if (c == '*') {
				a[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (used[i][j] == 0 && a[i][j] == 0) {
				sz[cmp_cnt] = dfs(i, j, cmp_cnt);
				cmp_cnt++;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 1) {
				set<int> s;
				for (auto pp : d) {
					int i1 = i + pp.first;
					int j1 = j + pp.second;
					if (check(i1, j1) && a[i1][j1] == 0) {
						s.insert(cmp[i1][j1]);
					}
				}
				for (auto cmp_id : s) {
					a[i][j] += sz[cmp_id];
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 0) {
				cout << '.';
			}
			else {
				cout << a[i][j] % 10;
			}
		}
		cout << endl;
	}
}