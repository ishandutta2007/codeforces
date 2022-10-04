/*

Code for problem C by cookiedoth
Generated 25 Aug 2020 at 05.52 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

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

const int mx = 1e5 + 228;
string s;
int n, x, ans[mx];

void solve() {
	cin >> s;
	cin >> x;
	n = s.size();
	fill(ans, ans + n, 1);
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			if (i + x < n) {
				ans[i + x] = 0;
			}
			if (i - x >= 0) {
				ans[i - x] = 0;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		int target = 0;
		if (i + x < n && ans[i + x]) {
			target = 1;
		}
		if (i - x >= 0 && ans[i - x]) {
			target = 1;
		}
		if (target != (s[i] - '0')) {
			cout << -1 << '\n';
			return;
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i];
	}
	cout << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}