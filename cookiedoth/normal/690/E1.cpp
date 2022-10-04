/*

Code for problem B by cookiedoth
Generated 21 Jan 2021 at 09.40 AM










(@)(@)(@)(@)(@)

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

int h, w;
vector<vector<int>> pic;

ll get(int r1, int r2) {
	ll res = 0;
	for (int i = 0; i < w; ++i) {
		res += (pic[r1][i] - pic[r2][i]) * (pic[r1][i] - pic[r2][i]);
	}
	return res;
}

void solve() {
	cin >> h >> w;
	pic.assign(h, vector<int> (w));
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> pic[i][j];
		}
	}
	ll cur = get(h / 2 - 1, h / 2);
	ll other = get(0, h - 1);
	cout << (other < cur ? "YES" : "NO") << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}