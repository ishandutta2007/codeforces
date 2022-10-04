/*

Code for problem D by cookiedoth
Generated 07 Jun 2020 at 06.14 PM


 ] 
 
Il] 


>_<
o_O
^_^

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

int n, m;
vector<string> a;
vector<pair<int, int> > dir = {
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0}
};

int ok(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

const int mx = 55;
int goods, bads, all_goods, used[mx][mx];

void dfs(int x, int y) {
	if (a[x][y] == 'G') {
		goods++;
	}
	if (a[x][y] == 'B') {
		bads++;
	}
	used[x][y] = 1;
	for (auto pp : dir) {
		int x1 = pp.first + x;
		int y1 = pp.second + y;
		if (ok(x1, y1) && used[x1][y1] == 0 && a[x1][y1] != '#') {
			dfs(x1, y1);
		}
	}
}

void solve() {
	cin >> n >> m;
	a.assign(n, string());
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	all_goods = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 'B') {
				for (auto pp : dir) {
					int i1 = i + pp.first;
					int j1 = j + pp.second;
					if (ok(i1, j1) && a[i1][j1] == '.') {
						a[i1][j1] = '#';
					}
				}
			}
			if (a[i][j] == 'G') {
				all_goods++;
			}
		}
	}
	bads = 0;
	goods = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			used[i][j] = 0;
		}
	}
	if (a[n - 1][m - 1] != '#') {
		dfs(n - 1, m - 1);
	}
	if (goods == all_goods && bads == 0) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}