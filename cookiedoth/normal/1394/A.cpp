/*

Code for problem A by cookiedoth
Generated 12 Aug 2020 at 05.34 PM


 ] 
 
Il] 


o_O
-_-
z_z

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

const int mx = 1e5 + 228;
int n, d, m, good;
ll a[mx], pref[mx];

void read() {
	cin >> n >> d >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		if (a[i] <= m) {
			good++;
		}
	}
	reverse(a, a + good);
	// cerr << "a" << endl;
	// output(a, a + n);
}

ll ans = 0;

void process() {
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = pref[i] + (i < good ? a[i] : 0);
	}
	// output(pref, pref + n + 1);
	ll sum = 0;
	for (int cnt = 0; cnt <= n - good; ++cnt) {
		ll silent = max(0LL, (ll)(cnt - 1) * (ll)d);
		if (silent > n - cnt) {
			continue;
		}
		// cerr << "cnt = " << cnt << endl;
		// cerr << "sum = " << sum << endl;
		// cerr << "pos = " << n - cnt - silent << endl;
		// cerr << sum + pref[n - cnt - silent] << endl;
		chkmax(ans, sum + pref[n - cnt - silent]);
		if (cnt < (n - good)) {
			sum += a[n - 1 - cnt];
		}
	}
	cout << ans << '\n';
}

signed main() {
	fast_io();
	read();
	process();
}