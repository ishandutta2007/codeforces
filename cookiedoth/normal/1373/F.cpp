/*

Code for problem F by cookiedoth
Generated 25 Jun 2020 at 06.40 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

>_<
o_O
-_-

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

const int mx = 1e6 + 228;
int n;
ll a[mx], b[mx], pref[4 * mx];
vector<ll> dt;

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	rotate(b, b + n - 1, b + n);
	dt.clear();
	for (int i = 0; i < n; ++i) {
		dt.push_back(-b[i]);
		dt.push_back(a[i]);
	}
	for (int i = 0; i < 2 * n; ++i) {
		dt.push_back(dt[i]);
	}
	ll sum_all = accumulate(all(dt), 0LL);
	if (sum_all > 0) {
		cout << "NO\n";
		return;
	}
	for (int i = 0; i < 4 * n; ++i) {
		pref[i + 1] = pref[i] + dt[i];
	}
	ll opt_pref = 0;
	for (int i = 1; i <= 4 * n; ++i) {
		if (i % 2 == 0) {
			chkmin(opt_pref, pref[i]);
		} else {
			if (pref[i] - opt_pref > 0) {
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}