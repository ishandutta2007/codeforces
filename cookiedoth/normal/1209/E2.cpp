/*

Code for problem E2 by cookiedoth
Generated 14 Sep 2019 at 05.42 P



10%

30%

50%

70%

100%

\_()_/
^_^
~_^

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

const int N = 12;
const int mx = 2010;
const int SZ = (1 << N);
int n, m, a[N][mx], _val[SZ], val[SZ], sz, dp[SZ], _dp[SZ];

void calc_val(int col) {
	fill(val, val + sz, 0);
	fill(_val, _val + sz, 0);
	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			if ((i >> j) & 1) {
				_val[i] += a[j][col];
			}
		}
	}
	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			int new_mask = (i >> j) ^ ((i & ((1 << j) - 1)) << (n - j));
			chkmax(val[new_mask], _val[i]);
		}
	}
}

void recalc_dp() {
	fill(_dp, _dp + sz, 0);
	for (int res = 0; res < sz; ++res) {
		for (int s = res; s >= 0; s = (s - 1) & res) {
			chkmax(_dp[res], val[s] + dp[res ^ s]);
			if (s == 0) {
				break;
			}
		}
	}
	swap(dp, _dp);
}

void solve() {
	cin >> n >> m;
	sz = (1 << n);
	vector<pair<int, int> > vp;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			vp.emplace_back(a[i][j], j);
		}
	}
	/*cerr << "a" << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cerr << a[i][j] << " ";
		}
		cerr << endl;
	}*/
	sort(vp.rbegin(), vp.rend());
	set<int> useful;
	for (auto pp : vp) {
		useful.insert(pp.second);
		if (useful.size() >= n) {
			break;
		}
	}
	/*cerr << "useful" << endl;
	for (auto x : useful) {
		cerr << x << " ";
	}
	cerr << endl;*/
	fill(dp, dp + sz, 0);
	for (auto col : useful) {
		calc_val(col);
		/*cerr << "val: ";
		output(val, val + sz);*/
		recalc_dp();
	}
	cout << dp[(1 << n) - 1] << endl;
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		solve();
	}
}