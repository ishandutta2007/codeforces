/*

Code for problem D by cookiedoth
Generated 10 Apr 2020 at 05.54 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

-_-
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

void solve() {
	ll n, L, R;
	cin >> n >> L >> R;
	L--;
	R--;
	int flag = 0;
	if (R == n * (n - 1)) {
		flag = 1;
		R--;
	}
	ll pos = 0;
	for (ll v = 0; v < n; ++v) {
		if (L > R) {
			break;
		}
		ll rpos = pos + 2 * (n - 1 - v);
		if (L < rpos) {
			for (ll x = L; x <= min(rpos - 1, R); ++x) {
				ll delta = x - pos;
				if (delta % 2 == 0) {
					cout << v + 1 << " ";
				} else {
					cout << v + delta / 2 + 2 << " ";
				}
			}
			L = rpos;
		}
		pos = rpos;
	}
	if (flag) {
		cout << 1 << " ";
	}
	cout << "\n";
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}