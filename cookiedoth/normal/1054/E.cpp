/*

Code for problem E by savkinsd2089
Generated 18 Oct 2018 at 08.07 pm
The Moon is Waxing Gibbous (68% of Full)










(@)(@)(@)(@)(@)

^_^
>_<
^_^

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

struct action {
	int x1, y1, x2, y2;
};

const int mx = 328;
deque<int> a[mx][mx], b[mx][mx];
vector<action> ans;

void make(int x1, int y1, int x2, int y2) {
	if (x1 == x2 || y1 == y2) {
		ans.push_back({x1, y1, x2, y2});
		assert(!a[x1][y1].empty());
		int val = a[x1][y1].back();
		a[x1][y1].pop_back();
		a[x2][y2].push_front(val);
	}
	else {
		if (a[x2][y1].empty()) {
			make(x1, y1, x2, y1);
			make(x2, y1, x2, y2);
		}
		else {
			if (a[x1][y2].empty()) {
				make(x1, y1, x1, y2);
				make(x1, y2, x2, y2);
			}
			else {
				assert(0);
			}
		}
	}
}

int get_type(int x, int y) {
	if (x + y == 1)
		return 0;
	if (x + y == 0)
		return 1;
	return 2;
}

int n, m, sz0, sz1;

void print_result() {
	#ifdef DEBUG
	cerr << "result" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (auto x : a[i][j]) {
				cerr << x;
			}
			cerr << " ";
		}
		cerr << endl;
	}
	#endif
}

signed main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			string s;
			cin >> s;
			for (int x = 0; x < s.size(); ++x) {
				a[i][j].push_back(s[x] - '0');
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			string s;
			cin >> s;
			for (int x = 0; x < s.size(); ++x) {
				b[i][j].push_back(s[x] - '0');
			}
			reverse(all(b[i][j]));
		}
	}
	sz0 = a[0][1].size(), sz1 = a[1][0].size();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (get_type(i, j)) {
				while (!a[i][j].empty()) {
					make(i, j, a[i][j].back(), 1 - a[i][j].back());
				}
			}
		}
	}

	print_result();

	for (int i = 0; i < sz0; ++i) {
		int val = a[0][1].back();
		make(0, 1, 0, 0);
		make(0, 0, val, 1 - val);
	}
	for (int i = 0; i < sz1; ++i) {
		int val = a[1][0].back();
		make(1, 0, 0, 0);
		make(0, 0, val, 1 - val);
	}

	print_result();

	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (get_type(i, j) == 2) {
				for (auto x : b[i][j]) {
					make(x, 1 - x, i, j);
				}
			}
		}
	}

	print_result();

	for (auto x : b[1][0]) {
		make(x, 1 - x, 0, 0);
		make(0, 0, 1, 0);
	}
	for (auto x : b[0][1]) {
		make(x, 1 - x, 0, 0);
		make(0, 0, 0, 1);
	}
	for (auto x : b[0][0]) {
		make(x, 1 - x, 0, 0);
	}

	print_result();

	cout << ans.size() << endl;
	for (auto pp : ans) {
		cout << pp.x1 + 1 << " " << pp.y1 + 1 << " " << pp.x2 + 1 << " " << pp.y2 + 1 << endl;
	}
}