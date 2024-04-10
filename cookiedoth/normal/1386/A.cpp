/*

Code for problem A by cookiedoth
Generated 22 Jul 2020 at 03.27 PM



10%

30%

50%

70%

100%

o_O
^_^
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

ll n;
set<ll> used;

#ifndef TESTING
int ask(ll pos) {
	used.insert(pos);
	cout << "? " << pos + 1 << endl;
	int res;
	cin >> res;
	return res;
}

void guess(ll res) {
	used.clear();
	cout << "= " << res << endl;
}
#else
ll C, oldPos;

void init() {
	cin >> C;
	oldPos = 0;
}

int ask(ll pos) {
	cerr << "ask " << pos << endl;
	assert(pos >= 0 && pos < n);
	assert(used.find(pos) == used.end());
	ll res = (abs(pos - oldPos) >= C);
	oldPos = pos;
	used.insert(pos);
	return res;
}

void guess(ll res) {
	cerr << "res = " << res << endl;
	used.clear();
	assert(res == C);
}
#endif

ll get(ll x, int t) {
	if (x == 1) {
		return 0;
	}
	return (t ? (x / 2) : 0) + get((x + 1) / 2, t ^ 1);
}

void smart() {
	ll pos = get(n, 1);
	int dir = 0;
	ask(pos);
	ll l = 1, r = n;
	while (l < r) {
		ll mid = (l + r - 1) >> 1;
		// cerr << "mid = " << mid << endl;
		if (dir == 0) {
			pos -= mid;
		} else {
			pos += mid;
		}
		ll res = ask(pos);
		if (res) {
			r = mid;
		} else {
			l = mid + 1;
		}
		// cerr << "lr = " << l << " " << r << endl;
		dir ^= 1;
	}
	guess(l);
}

void solve() {
	cin >> n;
	#ifdef TESTING
	init();
	#endif
	smart();
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}