/*

Code for problem C by cookiedoth
Generated 15 Apr 2020 at 06.05 PM










(@)(@)(@)(@)(@)

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

const int MOD = 998244353;
const int mx = 3010;
string s, t;
int n, m, dp[2][mx], _dp[2][mx];

void add(int &a, int b) {
	a = (a + b) % MOD;
}

int can(int pos, char c) {
	return (pos >= m || t[pos] == c);
}

void go(int len, char c) {
	for (int it = 0; it < 2; ++it) {
		fill(_dp[it], _dp[it] + len + 2, 0);
	}
	for (int it = 0; it < 2; ++it) {
		for (int prev_len = 0; prev_len <= len; ++prev_len) {
			if (can(prev_len, c)) {
				add(_dp[1][prev_len + 1], dp[it][prev_len]);
			}
			int back_len = len - prev_len;
			if (can(n - 1 - back_len, c)) {
				add(_dp[1][prev_len], dp[it][prev_len]);
				if (it == 0 && n - 1 - back_len >= m) {
					add(_dp[0][prev_len], dp[it][prev_len]);
				}
			}
		}
	}
	swap(dp, _dp);
}

signed main() {
	fast_io();
	cin >> s >> t;
	n = s.size();
	m = t.size();
	dp[0][0] = 1;
	for (int i = n - 1; i >= 0; --i) {
		go(n - 1 - i, s[i]);
	}
	int ans = 0;
	for (int it = 0; it < 2; ++it) {
		for (int i = 0; i <= n; ++i) {
			add(ans, dp[it][i]);
		}
	}
	cout << ans << endl;
}