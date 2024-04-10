/*

Code for problem E by cookiedoth
Generated 26 May 2020 at 07.03 PM


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

const int mx = 5e5 + 228;
int n, upw;
ll a[mx], x;

void read() {
	cin >> n;
	upw = (n + 1) / 2;
	for (int i = 0; i < upw; ++i) {
		cin >> a[i];
	}
	cin >> x;
	for (int i = upw; i < n; ++i) {
		a[i] = x;
	}
}

ll delta[mx], func[mx];

void calc_func() {
	for (int i = 0; i < upw; ++i) {
		delta[i] = x - a[i];
	}
	for (int i = 0; i < upw; ++i) {
		func[i + 1] = func[i] + delta[i];
	}
	for (int i = 1; i <= n - upw; ++i) {
		chkmin(func[i], func[i - 1]);
	}
}

ll pref[mx];

void solve() {
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = pref[i] + a[i];
	}
	for (int k = upw; k <= n; ++k) {
		if (pref[k] + func[n - k] > 0) {
			cout << k << endl;
			exit(0);
		}
	}
	cout << -1 << endl;
}

signed main() {
	fast_io();
	read();
	calc_func();
	solve();
}