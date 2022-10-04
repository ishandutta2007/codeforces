/*

Code for problem B by cookiedoth
Generated 31 Jul 2020 at 01.00 PM



10%

30%

50%

70%

100%

z_z
>_<
o_O

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

const ll INF = 1e18;
const int mx = 1e5 + 228;
const int Z = 5;
int n, k, z;
ll dp[mx][Z + 1][2], a[mx];

void solve() {
	cin >> n >> k >> z;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i <= k; ++i) {
		for (int j = 0; j <= z; ++j) {
			for (int it = 0; it < 2; ++it) {
				dp[i][j][it] = -INF;
			}
		}
	}
	dp[0][0][0] = 0;
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j <= z; ++j) {
			for (int it = 0; it < 2; ++it) {
				if (dp[i][j][it] == -INF) {
					continue;
				}
				int coord = i - 2 * j;
				if (coord < n - 1) {
					chkmax(dp[i + 1][j][0], dp[i][j][it] + a[coord + 1]);
				}
				if (coord > 0 && it == 0 && j < z) {
					chkmax(dp[i + 1][j + 1][1], dp[i][j][it] + a[coord - 1]);
				}
			}
		}
	}
	ll ans = -INF;
	for (int i = 0; i <= z; ++i) {
		for (int j = 0; j < 2; ++j) {
			chkmax(ans, dp[k][i][j]);
		}
	}
	cout << ans + a[0] << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}