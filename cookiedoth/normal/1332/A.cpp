/*

Code for problem A by cookiedoth
Generated 31 Mar 2020 at 06.46 PM


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

int inside(int point, int l, int r) {
	return (l <= point && point <= r);
}

void solve() {
	int a, b, c, d;
	int x, y, x1, y1, x2, y2;
	cin >> a >> b >> c >> d;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	if (a && b && x == x1 && x == x2) {
		cout << "No\n";
		return;
	}
	if (c && d && y == y1 && y == y2) {
		cout << "No\n";
		return;
	}
	cout << ((inside(x + b - a, x1, x2) && inside(y + d - c, y1, y2)) ? "Yes" : "No") << "\n";
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}