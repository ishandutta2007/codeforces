/*

Code for problem B by cookiedoth
Generated 13 Feb 2020 at 06.45 P


 ] 
 
Il] 


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

const int mx = 1e5 + 228;
const int C = 1e9;
int n, a[mx];

int check(int x, int &res) {
	int l = 0, r = C;
	// cerr << "check " << x << endl;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] == -1 && a[i + 1] == -1) {
			continue;
		}
		if (a[i] != -1 && a[i + 1] != -1 && abs(a[i] - a[i + 1]) > x) {
			return 0;
		}
		if (a[i] != -1 && a[i + 1] == -1) {
			chkmax(l, a[i] - x);
			chkmin(r, a[i] + x);
		}
		if (a[i] == -1 && a[i + 1] != -1) {
			chkmax(l, a[i + 1] - x);
			chkmin(r, a[i + 1] + x);
		}
	}
	if (l > r) {
		return 0;
	} else {
		res = l;
		return 1;
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int l = 0, r = C;
	int res;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid, res)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	check(l, res);
	for (int i = 0; i < n; ++i) {
		if (a[i] == -1) {
			a[i] = res;
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		assert(abs(a[i] - a[i + 1]) <= l);
	}
	cout << l << " " << res << "\n";
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}