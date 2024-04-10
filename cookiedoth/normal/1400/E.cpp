/*

Code for problem E by cookiedoth
Generated 25 Aug 2020 at 06.06 PM










(@)(@)(@)(@)(@)

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

const int mx = 5010;
int n, a[mx];

void read() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
}

ll dp[mx];
const int INF = 1e9 + 228;
const ll BINF = 1e18;

void solve() {
	fill(dp, dp + n + 2, BINF);
	dp[0] = 0;
	for (int i = 1; i <= n + 1; ++i) {
		int min_val = INF;
		for (int j = i - 1; j >= 0; --j) {
			if (min_val >= a[j]) {
				chkmin(dp[i], dp[j] + (ll)(i - j - 1) + (ll)max(0, a[i] - a[j]));
			}
			chkmin(min_val, a[j]);
		}
	}
	cout << dp[n + 1] << '\n';
}

signed main() {
	fast_io();
	read();
	solve();
}