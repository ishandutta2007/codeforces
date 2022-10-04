/*

Code for problem A by cookiedoth
Generated 07 Jun 2020 at 06.35 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

-_-
z_z
=_=

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

const int mx = 55;
int n, m, occ_row[mx], occ_col[mx];

void solve() {
	cin >> n >> m;
	fill(occ_row, occ_row + n, 0);
	fill(occ_col, occ_col + m, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int x;
			cin >> x;
			if (x) {
				occ_row[i] = 1;
				occ_col[j] = 1;
			}
		}
	}
	int free_rows = 0, free_cols = 0;
	for (int i = 0; i < n; ++i) {
		free_rows += (occ_row[i] == 0);
	}
	for (int i = 0; i < m; ++i) {
		free_cols += (occ_col[i] == 0);
	}
	cout << (min(free_rows, free_cols) % 2 ? "Ashish" : "Vivek") << "\n";
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}