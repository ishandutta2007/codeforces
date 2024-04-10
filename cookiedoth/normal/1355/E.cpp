/*

Code for problem E by cookiedoth
Generated 16 May 2020 at 03.53 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

^_^
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
const ll INF = 8e18;
int n;
ll A, R, M, h[mx], pref[mx];

ll ans = INF;

ll get(ll x) {
	// cerr << "get " << x << endl;
	ll pos = lower_bound(h, h + n, x) - h;
	ll C1 = x * pos - pref[pos];
	ll C2 = (pref[n] - pref[pos]) - (ll)(n - pos) * x;
	ll res = C1 * A + C2 * R;
	if (M <= A + R) {
		ll kek = A + R - M;
		res -= kek * min(C1, C2);
	}
	chkmin(ans, res);
	return res;
}

void search(ll l, ll r) {
	while (r - l > 5) {
		ll m1 = (2 * l + r) / 3;
		ll m2 = (l + 2 * r) / 3;
		if (get(m1) < get(m2)) {
			r = m2;
		} else {
			l = m1;
		}
	}
	for (int i = l; i <= r; ++i) {
		get(i);
	}
}

signed main() {
	fast_io();
	cin >> n >> A >> R >> M;
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	sort(h, h + n);
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = pref[i] + h[i];
	}
	// cerr << "pref" << endl;
	// output(pref, pref + n + 1);
	if (n == 1) {
		ans = 0;
	}
	for (int i = 0; i < n - 1; ++i) {
		search(h[i], h[i + 1]);
	}
	cout << ans << endl;
}