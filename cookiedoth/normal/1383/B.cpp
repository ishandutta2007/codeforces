/*

Code for problem B by cookiedoth
Generated 27 Jul 2020 at 12.04 PM


 ] 
 
Il] 


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

// const int mx = 10;
// int dp[mx][mx][2][2];

// void calc_dp() {
// 	for (int i = 0; i < 2; ++i) {
// 		for (int j = 0; j < 2; ++j) {
// 			dp[0][0][i][j] = (i > j);
// 		}
// 	}
// 	for (int zeros = 0; zeros < mx; ++zeros) {
// 		for (int ones = 0; ones < mx; ++ones) {
// 			if (zeros == 0 && ones == 0) {
// 				continue;
// 			}
// 			for (int i = 0; i < 2; ++i) {
// 				for (int j = 0; j < 2; ++j) {
// 					if (zeros && dp[zeros - 1][ones][j][i] == 0) {
// 						dp[zeros][ones][i][j] = 1;
// 					}
// 					if (ones && dp[zeros][ones - 1][j][i ^ 1] == 0) {
// 						dp[zeros][ones][i][j] = 1;
// 					}
// 				}
// 			}
// 		}
// 	}
// 	for (int i = 0; i < mx; ++i) {
// 		for (int j = 0; j < mx; ++j) {
// 			if (j % 2 == 1) {
// 				cout << i << " " << j << " " << dp[i][j][0][0] << endl;
// 			}
// 		}
// 	}
// }

const int mx = 1e5 + 228;
int n, a[mx];

void solve() {
	cin >> n;
	int x = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		x ^= a[i];
	}
	if (x == 0) {
		cout << "DRAW\n";
		return;
	}
	int b = 31 - __builtin_clz(x);
	int zeros = 0, ones = 0;
	for (int i = 0; i < n; ++i) {
		if ((a[i] >> b) & 1) {
			ones++;
		} else {
			zeros++;
		}
	}
	cout << ((zeros % 2 == 1 || ones % 4 == 1) ? "WIN" : "LOSE") << '\n';
}

signed main() {
	fast_io();
	// calc_dp();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}