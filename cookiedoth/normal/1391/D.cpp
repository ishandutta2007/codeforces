/*

Code for problem D by cookiedoth
Generated 10 Aug 2020 at 05.49 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

-_-
~_^
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

int n, m;
vector<string> a;

void rotate() {
	vector<string> _a(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			_a[j].push_back(a[i][j]);
		}
	}
	a = _a;
	swap(n, m);
}

void read() {
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
	}
	if (n > m) {
		rotate();
	}
}

int ok[8][8];

void calc_ok() {
	for (int mask1 = 0; mask1 < (1 << n); ++mask1) {
		for (int mask2 = 0; mask2 < (1 << n); ++mask2) {
			ok[mask1][mask2] = 1;
			for (int i = 0; i <= n - 2; ++i) {
				int val = (((mask1 >> i) & 1) ^ ((mask1 >> (i + 1)) & 1) ^
					((mask2 >> i) & 1) ^ ((mask2 >> (i + 1)) & 1));
				chkmin(ok[mask1][mask2], val);
			}
		}
	}
}

const int INF = 1e9 + 228;
int dp[8], _dp[8];

void recalc_dp(int column_id) {
	fill(_dp, _dp + (1 << n), INF);
	for (int old_mask = 0; old_mask < (1 << n); ++old_mask) {
		for (int new_mask = 0; new_mask < (1 << n); ++new_mask) {
			int diff = 0;
			for (int i = 0; i < n; ++i) {
				diff += ((a[i][column_id] - '0') != ((new_mask >> i) & 1));
			}
			if (ok[old_mask][new_mask]) {
				chkmin(_dp[new_mask], dp[old_mask] + diff);
			}
		}
	}
	swap(dp, _dp);
	// output(dp, dp + (1 << n));
}

signed main() {
	fast_io();
	read();
	if (n >= 4) {
		cout << -1 << '\n';
		exit(0);
	}
	calc_ok();
	for (int i = 0; i < m; ++i) {
		recalc_dp(i);
	}
	int ans = (*min_element(dp, dp + (1 << n)));
	cout << ans << '\n';
}