/*

Code for problem D by cookiedoth
Generated 25 Aug 2020 at 05.56 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

~_^
=_=
\_()_/

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

const int mx = 3010;
int n, a[mx], cnt[2][mx], prod_sum;

void add(int r, int c, int val) {
	prod_sum -= cnt[0][c] * cnt[1][c];
	cnt[r][c] += val;
	prod_sum += cnt[0][c] * cnt[1][c];
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i]--;
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		fill(cnt[0], cnt[0] + n, 0);
		fill(cnt[1], cnt[1] + n, 0);
		prod_sum = 0;
		for (int j = i + 2; j < n; ++j) {
			add(1, a[j], 1);
		}
		for (int j = i + 2; j < n; ++j) {
			add(0, a[j - 1], 1);
			add(1, a[j], -1);
			if (a[i] == a[j]) {
				ans += prod_sum;
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