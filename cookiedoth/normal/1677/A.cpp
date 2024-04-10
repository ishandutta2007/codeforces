/*

Code for problem A by cookiedoth
Generated 08 May 2022 at 07.31 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

\_()_/
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

const int MAX_N = 5010;
int n, p[MAX_N], order[MAX_N], r_smaller[MAX_N];

void solve() {
	cin >> n;
	// cerr << "solve " << n << '\n';
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		p[i]--;
	}
	fill(order, order + n, 0);
	fill(r_smaller, r_smaller + n, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (p[j] < p[i]) {
				r_smaller[i]++;
			}
		}
	}
	ll ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (i < n - 1) {
			int rel = r_smaller[i + 1];
			order[i + 1] = rel;
			for (int j = i + 2; j < n; ++j) {
				if (order[j] >= rel) {
					order[j]++;
				}
			}
			// output(order, order + n);
		}
		ll tot_gr = 0;
		for (int j = n - 1; j >= i + 1; --j) {
			if (j < n - 1) {
				tot_gr += (n - 2 - i - order[j + 1]);
			}
			// cerr << "ij = " << i << ' ' << j << ' ' << tot_gr << '\n';
			ll cnt = n - 1 - j;
			if (p[i] < p[j]) {
				ans += tot_gr - r_smaller[j] - cnt * (cnt - 1) / 2;
				// cerr << "add " << tot_gr - r_smaller[j] - cnt * (cnt - 1) / 2 << '\n';
			}
		}
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