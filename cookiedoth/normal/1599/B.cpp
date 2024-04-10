/*

Code for problem  by cookiedoth
Generated 09 Oct 2021 at 10.02 PM


 ] 
 
Il] 


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
#include <chrono>
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

ll border(ll pos, bool dir, ll n) {
	if (dir == true) {
		return n - 1 - pos;
	} else {
		return pos;
	}
}

void switch_if(ll& pos, bool& dir, ll n) {
	if ((pos == 0 && dir == false) || (pos == n - 1 && dir == true)) {
		dir = !dir;
	}
}

void simulate(ll& pos, bool& dir, ll steps, ll n) {
	pos += steps * (dir == true ? 1LL : (ll)(-1));
	switch_if(pos, dir, n);
}

void solve() {
	ll n, A, B;
	string _da, _db;
	bool da, db;
	cin >> n >> A >> B >> _da >> _db;
	da = (_da == "right");
	db = (_db == "right");
	while (true) {
		switch_if(A, da, n);
		switch_if(B, db, n);
		if (A < B && da == true && db == false) {
			ll delta = B - A;
			if (delta % 2 == 0) {
				ll mid = (A + B) / 2;
				A = B = mid;
			} else {
				ll mid = (A + B + 1) / 2;
				A = B = mid;
				swap(da, db);
			}
			break;
		}
		if (A > B && da == false && db == true) {
			ll delta = A - B;
			if (delta % 2 == 0) {
				ll mid = (A + B) / 2;
				A = B = mid;
			} else {
				ll mid = (A + B - 1) / 2;
				A = B = mid;
				swap(da, db);
			}
			break;
		}
		ll border_A = border(A, da, n);
		ll border_B = border(B, db, n);
		if (border_A <= border_B) {
			simulate(A, da, border_A, n);
			simulate(B, db, border_A - 1, n);
			swap(A, B);
			swap(da, db);
		} else {
			simulate(A, da, border_B, n);
			simulate(B, db, border_B, n);
		}
	}
	// cerr << A << ' ' << da << ' ' << db << '\n';
	if (da == db) {
		if (A == 0 && da == true) {
			cout << n - 1 << '\n';
		} else if (A != 0 && da == true) {
			cout << 0 << '\n';
		} else if (A == n - 1 && da == false) {
			cout << 0 << '\n';
		} else {
			cout << n - 1 << '\n';
		}
		return;
	} else {
		if (da == true && db == false) {
			if (A == n - 1) {
				cout << 0 << '\n';
			} else {
				cout << n - 1 << '\n';
			}
		} else {
			if (A == 0) {
				cout << n - 1 << '\n';
			} else {
				cout << 0 << '\n';
			}
		}
	}
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}