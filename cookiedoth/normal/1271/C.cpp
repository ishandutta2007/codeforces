/*

Code for problem C by cookiedoth
Generated 15 Dec 2019 at 02.00 P


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

~_^
z_z
>_<

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

const int mx = 2e5 + 228;
int n, sx, sy, x[mx], y[mx], best = -1, best_x = -1, best_y = -1;

int between(int l, int r, int val) {
	if (l > r) {
		swap(l, r);
	}
	return (val >= l && val <= r);
}

void get(int px, int py) {
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (between(x[i], sx, px) && between(y[i], sy, py)) {
			cnt++;
		}
	}
	if (chkmax(best, cnt)) {
		best_x = px;
		best_y = py;
	}
}

signed main() {
	fast_io();
	cin >> n >> sx >> sy;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	get(sx + 1, sy);
	get(sx, sy + 1);
	get(sx - 1, sy);
	get(sx, sy - 1);
	cout << best << endl;
	cout << best_x << " " << best_y << endl;
}