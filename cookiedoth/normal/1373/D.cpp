/*

Code for problem D by cookiedoth
Generated 25 Jun 2020 at 05.44 PM



10%

30%

50%

70%

100%

~_^
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

const int mx = 2e5 + 228;
int n;
ll ans, opt, a[mx], b[mx], pref[mx];

void solve() {
	cin >> n;
	ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		b[i] = a[i];
		if (i % 2 == 0) {
			b[i] = -b[i];
			ans += a[i];
		}
	}
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = pref[i] + b[i];
	}
	opt = 0;
	vector<ll> min_pref(2);
	for (int i = 1; i <= n; ++i) {
		chkmax(opt, pref[i] - min_pref[i % 2]);
		chkmin(min_pref[i % 2], pref[i]);
	}
	cout << ans + opt << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}