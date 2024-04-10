/*

Code for problem C by cookiedoth
Generated 23 Feb 2020 at 01.18 P










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

const int mx = 5e5 + 228;
int n, a[mx], l[mx], r[mx];
ll dp_l[mx], dp_r[mx];

void calc_lr() {
	vector<int> st;
	for (int i = 0; i <= n + 1; ++i) {
		while (!st.empty() && a[i] <= a[st.back()]) {
			st.pop_back();
		}
		if (st.empty()) {
			l[i] = -1;
		} else {
			l[i] = st.back();
		}
		st.push_back(i);
	}
	st.clear();
	for (int i = n + 1; i >= 0; --i) {
		while (!st.empty() && a[i] <= a[st.back()]) {
			st.pop_back();
		}
		if (st.empty()) {
			r[i] = n + 2;
		} else {
			r[i] = st.back();
		}
		st.push_back(i);
	}
}

void calc_dp() {
	for (int i = 1; i <= n; ++i) {
		dp_l[i] = (ll)a[i] * (ll)(i - l[i]) + dp_l[l[i]];
	}
	for (int i = n; i >= 1; --i) {
		dp_r[i] = (ll)a[i] * (ll)(r[i] - i) + dp_r[r[i]];
	}
}

ll ans[mx];

void solve() {
	int best_pos = -1;
	ll best = -1;
	for (int i = 1; i <= n; ++i) {
		ll cur = dp_l[i] + dp_r[i] - a[i];
		if (chkmax(best, cur)) {
			best_pos = i;
		}
	}
	assert(best_pos != -1);
	ll val = a[best_pos];
	for (int i = best_pos; i >= 1; --i) {
		chkmin(val, (ll)a[i]);
		ans[i] = val;
	}
	val = a[best_pos];
	for (int i = best_pos; i <= n; ++i) {
		chkmin(val, (ll)a[i]);
		ans[i] = val;
	}
	output(ans + 1, ans + n + 1, cout);
}

signed main() {
	fast_io();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	calc_lr();
	calc_dp();
	solve();
}