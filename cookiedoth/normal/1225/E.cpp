/*

Code for problem E by cookiedoth
Generated 26 Oct 2019 at 02.39 P



10%

30%

50%

70%

100%

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

const int mx = 2010;
int n, m, rock[mx][mx], pref1[mx][mx], pref2[mx][mx], push_right[mx][mx], push_down[mx][mx];

void read() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] == 'R') {
				rock[i][j] = 1;
			}
		}
	}
}

void calc_pref() {
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= m; ++j) {
			pref1[i][j] = pref1[i][j - 1] + rock[i][j - 1];
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 1; j <= n; ++j) {
			pref2[j][i] = pref2[j - 1][i] + rock[j - 1][i];
		}
	}
}

int r_pushable(int i, int j, int cnt) {
	return (pref1[i][j + cnt + 1] - pref1[i][j + 1] <= m - 1 - j - cnt);
}

int d_pushable(int i, int j, int cnt) {
	return (pref2[i + cnt + 1][j] - pref2[i + 1][j] <= n - 1 - i - cnt);
}

void calc_push() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			push_right[i][j] = (m - 1 - j) - (pref1[i][m] - pref1[i][j + 1]);
			push_down[i][j] = (n - 1 - i) - (pref2[n][j] - pref2[i + 1][j]);
			/*int l = 0, r = m - 1 - j;
			while (l < r) {
				int mid = (l + r) >> 1;
				if (r_pushable(i, j, mid + 1)) {
					l = mid + 1;
				}
				else {
					r = mid;
				}
			}
			push_right[i][j] = l;
			l = 0, r = n - 1 - i;
			while (l < r) {
				int mid = (l + r) >> 1;
				if (d_pushable(i, j, mid + 1)) {
					l = mid + 1;
				}
				else {
					r = mid;
				}
			}
			push_down[i][j] = l;*/
		}
	}
}

const ll MOD = 1e9 + 7;

ll right_dp[mx][mx], down_dp[mx][mx];
ll suf_right_dp[mx][mx], suf_down_dp[mx][mx];

void solve() {
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (i == n - 1 && j == m - 1) {
				right_dp[n - 1][m - 1] = 1;
				down_dp[n - 1][m - 1] = 1;
				suf_right_dp[n - 1][m - 1] = 1;
				suf_down_dp[n - 1][m - 1] = 1;
				continue;
			}
			right_dp[i][j] = (suf_down_dp[i][j + 1] - suf_down_dp[i][j + push_right[i][j] + 1] + MOD) % MOD;
			down_dp[i][j] = (suf_right_dp[i + 1][j] - suf_right_dp[i + push_down[i][j] + 1][j] + MOD) % MOD;
			suf_right_dp[i][j] = (suf_right_dp[i + 1][j] + right_dp[i][j]) % MOD;
			suf_down_dp[i][j] = (suf_down_dp[i][j + 1] + down_dp[i][j]) % MOD;
		}
	}
	ll ans = (right_dp[0][0] + down_dp[0][0]) % MOD;
	cout << ans << endl;
}

signed main() {
	fast_io();
	read();
	if (rock[0][0]) {
		cout << 0 << endl;
		exit(0);
	}
	if (n == 1 && m == 1) {
		cout << 1 << endl;
		exit(0);
	}
	calc_pref();
	calc_push();
	solve();
}