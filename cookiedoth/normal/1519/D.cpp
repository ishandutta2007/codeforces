/*

Code for problem D by cookiedoth
Generated 29 Apr 2021 at 05.53 PM


  !











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

const int mx = 5010;
int n;
ll a[mx], b[mx], pref[mx], suf[mx], dp[mx][mx];

void read() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = pref[i] + a[i] * b[i];
	}
	for (int i = 0; i < n; ++i) {
		suf[i + 1] = suf[i] + a[n - 1 - i] * b[n - 1 - i];
	}
}

void calc_dp() {
	for (int i = 0; i < n; ++i) {
		dp[i][i] = a[i] * b[i];
	}
	for (int len = 2; len <= n; ++len) {
		for (int l = 0; l <= n - len; ++l) {
			int r = l + len - 1;
			dp[l][r] = a[l] * b[r] + a[r] * b[l] + dp[l + 1][r - 1];
		}
	}
}

void calc_ans() {
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			chkmax(ans, pref[i] + suf[n - 1 - j] + dp[i][j]);
		}
	}
	cout << ans << '\n';
}

signed main() {
	fast_io();
	read();
	calc_dp();
	calc_ans();
}