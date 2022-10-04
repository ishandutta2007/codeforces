/*

Code for problem A by cookiedoth
Generated 23 Feb 2020 at 01.47 P



10%

30%

50%

70%

100%

=_=
\_()_/
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

int a, b, c, res, ans;

void check(int _a, int _b, int _c) {
	if (a >= _a && b >= _b && c >= _c) {
		a -= _a;
		b -= _b;
		c -= _c;
		res++;
	}
}

void solve() {
	cin >> a >> b >> c;
	int a0 = a, b0 = b, c0 = c;
	ans = 0;
	vector<int> masks = {0, 1, 2, 3, 4, 5, 6};
	while (true) {
		a = a0;
		b = b0;
		c = c0;
		res = 0;
		for (auto mask : masks) {
			mask++;
			check(mask & 1, (mask >> 1) & 1, (mask >> 2) & 1);
		}
		chkmax(ans, res);
		if (!next_permutation(all(masks))) {
			break;
		}
	}
	cout << ans << endl;
	// check(1, 0, 0);
	// check(0, 1, 0);
	// check(0, 0, 1);
	// if (a * b * c == 2) {
	// 	ans += 2;
	// 	cout << ans << endl;
	// 	return;
	// }
	// check(1, 1, 0);
	// check(1, 0, 1);
	// check(0, 1, 1);
	// check(1, 1, 1);
	// cout << ans << endl;
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}