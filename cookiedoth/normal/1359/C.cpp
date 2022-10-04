/*

Code for problem C by cookiedoth
Generated 28 May 2020 at 05.57 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

>_<
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

const ld INF = 1e9 + 228;
ld c, h, t, best;
ll ans = -1;

ld f(ll k) {
	ll cold = k / 2;
	ll hot = k - cold;
	ld cur = ((ld)cold * c + (ld)hot * h) / (ld)k;
	ld res = abs(cur - t);
	if (chkmin(best, res)) {
		ans = k;
	}
	return res;
}

void make_odd(ll &x) {
	if (x % 2 == 0) {
		x++;
	}
}

void solve() {
	cerr << setprecision(15) << fixed;
	cin >> h >> c >> t;
	best = INF;
	f(2);
	ll l = 1, r = 1e8;
	while (r - l > 15) {
		// cerr << l << " " << r << endl;
		ll m1 = (l * 2 + r) / 3;
		ll m2 = (l + 2 * r) / 3;
		make_odd(m1);
		make_odd(m2);
		if (f(m1) < f(m2)) {
			r = m2;
		} else {
			l = m1;
		}
	}
	for (ll i = l; i <= r; ++i) {
		f(i);
	}
	cout << ans << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}