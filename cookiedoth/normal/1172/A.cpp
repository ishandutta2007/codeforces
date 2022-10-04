/*

Code for problem A by cookiedoth
Generated 07 Jun 2019 at 03.05 P


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

~_^
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

int n, ans = 1e9;
vector<int> a, _a;

void check_shit() {
	int cnt = a[2 * n - 1] + 1, i0 = 2 * n - cnt;
	for (int i = i0; i < 2 * n; ++i) {
		if (a[i] != i - i0) {
			return;
		}
	}
	int rpos = n - 1;
	for (int i = cnt; i < n; ++i) {
		if (_a[i] > rpos) {
			return;
		}
		rpos++;
	}
	ans = n - cnt;
}

signed main() {
	fast_io();
	cin >> n;
	a.resize(2 * n);
	_a.resize(n);
	for (int i = 0; i < 2 * n; ++i) {
		cin >> a[i];
		a[i]--;
		if (a[i] >= 0) {
			_a[a[i]] = i;
		}
	}
	check_shit();
	int pos = n - 1;
	for (int i = 0; i < n; ++i) {
		if (pos >= _a[i]) {
			pos++;
		}
		else {
			pos = _a[i] + 1;
		}
	}
	chkmin(ans, pos - (n - 1));
	cout << ans << endl;
}