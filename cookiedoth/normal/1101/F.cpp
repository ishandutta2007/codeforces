/*

Code for problem F by savkinsd2089
Generated 11 Jan 2019 at 07.00 pm
The Moon is Waxing Crescent (26% of Full)


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

~_^
z_z
-_-

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

const int mx = 405;
int n, m, a[mx], dist[mx][mx], dp[mx][mx][mx];

signed main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			dp[i][j][0] = dist[i][j] = a[j] - a[i];
		}
	}

	for (int len = 1; len <= n; ++len) {
		for (int i = 0; i <= n - len; ++i) {
			int j = i + len - 1;
			int ptr = j;
			for (int k = 1; k <= len - 1; ++k) {
				while (ptr > i + 1 && max(dist[i][ptr], dp[ptr][j][k - 1]) > max(dist[i][ptr - 1], dp[ptr - 1][j][k - 1])) {
					ptr--;
				}
				dp[i][j][k] = max(dist[i][ptr], dp[ptr][j][k - 1]);
			}
		}
	}

	ll V = 0;
	for (int i = 0; i < m; ++i) {
		int s, f, c, r;
		cin >> s >> f >> c >> r;
		s--;
		f--;
		chkmin(r, f - s);
		int cnt = dp[s][f][r];
		chkmax(V, (ll)cnt * (ll)c);
	}
	cout << V << endl;
}