/*

Code for problem B by cookiedoth
Generated 25 Aug 2020 at 05.39 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

z_z
>_<
o_O

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

ll p, f, cnt_s, cnt_w, s, w;

int can(ll x) {
	ll s1 = min(x, cnt_s);
	ll w1 = max(0LL, x - cnt_s);
	for (ll s1_p = 0; s1_p <= s1; ++s1_p) {
		ll we = s1_p * s;
		if (we > p) {
			break;
		}
		ll rem = min((p - we) / w, w1);
		if ((s1 - s1_p) * s + (w1 - rem) * w <= f) {
			return 1;
		}
	}
	return 0;
}

void solve() {
	cin >> p >> f;
	cin >> cnt_s >> cnt_w;
	cin >> s >> w;
	if (s > w) {
		swap(s, w);
		swap(cnt_s, cnt_w);
	}
	int l = 0, r = cnt_s + cnt_w;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (can(mid + 1)) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	cout << l << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}