/*

Code for problem C by cookiedoth
Generated 10 Oct 2020 at 06.06 PM










(@)(@)(@)(@)(@)

z_z
=_=
\_()_/

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
#include <random>
#include <utility>
#include <tuple>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define length(a) (int)a.size()

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

const int INF = 1e9;

struct celebrity {
	int t, x, y, dp;
};

int r, n;
vector<celebrity> a;

void read() {
	cin >> r >> n;
	a.push_back({0, 0, 0, 0});
	for (int i = 0; i < n; ++i) {
		int t, x, y;
		cin >> t >> x >> y;
		a.push_back({t, x - 1, y - 1, -INF});
	}
}

void solve() {
	int max_dp = -INF, ans = 0;
	for (int i = 1; i <= n; ++i) {
		a[i].dp = max_dp + 1;
		for (int j = max(i - 2 * r, 0); j < i; ++j) {
			if (abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y) <= a[i].t - a[j].t) {
				chkmax(a[i].dp, a[j].dp + 1);
			}
		}
		if (i >= 2 * r) {
			chkmax(max_dp, a[i - 2 * r].dp);
		}
		chkmax(ans, a[i].dp);
	}
	cout << ans << '\n';
}

signed main() {
	fast_io();
	read();
	solve();
}