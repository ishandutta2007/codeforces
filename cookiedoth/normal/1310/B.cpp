/*

Code for problem B by cookiedoth
Generated 23 Feb 2020 at 07.23 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

o_O
-_-
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
const int mx = 1e6 + 228;
int n, k, dp[mx][4], a[mx];

void calc_dp(int v, int tl, int tr) {
	for (int i = 0; i < 4; ++i) {
		dp[v][i] = -INF;
	}
	if (tl + 1 == tr) {
		int cnt = a[tl] + a[tr];
		if (cnt == 0) {
			dp[v][0] = 0;
		}
		if (cnt == 1) {
			dp[v][1] = dp[v][2] = 1;
		}
		if (cnt == 2) {
			dp[v][3] = 1;
		}
	} else {
		int tm = (tl + tr) >> 1;
		calc_dp(v * 2, tl, tm);
		calc_dp(v * 2 + 1, tm + 1, tr);
		for (int mask1 = 0; mask1 < 4; ++mask1) {
			for (int mask2 = 0; mask2 < 4; ++mask2) {
				if (dp[v * 2][mask1] == -INF || dp[v * 2 + 1][mask2] == -INF) {
					continue;
				}
				for (int gameres = 0; gameres < 8; ++gameres) {
					int f1 = ((mask1 >> 0) & 1);
					int f2 = ((mask1 >> 1) & 1);
					int s1 = ((mask2 >> 0) & 1);
					int s2 = ((mask2 >> 1) & 1);
					int add = 0;
					add += (f1 | s1);
					if ((gameres >> 0) & 1) {
						swap(f1, s1);
					}
					add += (f2 | s2);
					if ((gameres >> 1) & 1) {
						swap(f2, s2);
					}
					add += (s1 | f2);
					if ((gameres >> 2) & 1) {
						swap(s1, f2);
					}
					int mask = (f1 ^ (f2 << 1));
					chkmax(dp[v][mask], dp[v * 2][mask1] + dp[v * 2 + 1][mask2] + add);
				}
			}
		}
	}
}

signed main() {
	fast_io();
	cin >> n >> k;
	n = (1 << n);
	for (int i = 0; i < k; ++i) {
		int pos;
		cin >> pos;
		pos--;
		a[pos] = 1;
	}
	calc_dp(1, 0, n - 1);
	int ans = 0;
	for (int mask = 0; mask < 4; ++mask) {
		chkmax(ans, dp[1][mask] + (int)(mask >= 1));
	}
	cout << ans << endl;
}