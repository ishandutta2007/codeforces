/*

Code for problem B by cookiedoth
Generated 12 May 2020 at 03.44 PM



10%

30%

50%

70%

100%

^_^
~_^
z_z

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

const int INF = 1e9;
const int mx = 1e5 + 228;
int n, k, a[mx], pref[mx];

void solve() {
	cin >> n >> k;
	int has_k = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] == k) {
			has_k = 1;
		}
	}
	if (!has_k) {
		cout << "no\n";
		return;
	}
	if (n == 1) {
		cout << "yes\n";
		return;
	}
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = pref[i] + (a[i] >= k ? 1 : -1);
	}
	int min_pref = INF;
	for (int i = 1; i <= n; ++i) {
		if (pref[i] > min_pref) {
			cout << "yes\n";
			return;
		}
		chkmin(min_pref, pref[i - 1]);
	}
	cout << "no\n";
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}