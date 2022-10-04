/*

Code for problem D by cookiedoth
Generated 31 Jul 2020 at 01.35 PM



10%

30%

50%

70%

100%

o_O
-_-
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

const ll INF = 1e18;

void solve() {
	ll n, k, l1, r1, l2, r2;
	cin >> n >> k >> l1 >> r1 >> l2 >> r2;
	k -= max(0LL, min(r1, r2) - max(l1, l2)) * n;
	chkmax(k, 0LL);
	ll f = 0, s = 0;
	if (l2 > r1) {
		f = l2 - r1;
	}
	if (l1 > r2) {
		f = l1 - r2;
	}
	ll L = min(l1, l2), R = max(r1, r2);
	s = 2 * (R - L) - max(R - L, r1 - l1 + r2 - l2);
	ll ans = INF;
	for (ll used = 0; used <= n; ++used) {
		ll k1 = k;
		ll pay = f * used;
		ll can1 = s * used;
		pay += min(can1, k1);
		k1 -= min(can1, k1);
		if (k1 && used == 0) {
			continue;
		}
		pay += 2 * k1;
		chkmin(ans, pay);
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