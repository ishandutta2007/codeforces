/*

Code for problem A by cookiedoth
Generated 31 May 2020 at 07.11 PM










(@)(@)(@)(@)(@)

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
	int sum_all = 0, is_even = 0, is_odd = 0;
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; ++i) {
		int cur;
		cin >> cur;
		sum_all += (cur % 2);
		if (cur % 2 == 0) {
			is_even = 1;
		}
		if (cur % 2 == 1) {
			is_odd = 1;
		}
	}
	sum_all %= 2;
	if (n == x) {
		cout << (sum_all ? "Yes" : "No") << '\n';
	} else {
		if (is_odd == 0) {
			cout << "No\n";
		} else {
			if (is_even == 0) {
				cout << (x % 2 ? "Yes" : "No") << '\n';
			} else {
				cout << "Yes\n";
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