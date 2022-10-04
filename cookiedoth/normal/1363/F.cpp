/*

Code for problem F by cookiedoth
Generated 31 May 2020 at 05.48 PM


  !











>_<
o_O
^_^

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

const int mx = 2010;
const int K = 26;
int n, dp[mx][mx], pref_s[mx][K], pref_t[mx][K], cs[K], ct[K];
string s, t;

void calc(string &str, int *val) {
	fill(val, val + K, 0);
	for (auto c : str) {
		val[c - 'a']++;
	}
}

int major(int *p1, int *p2) {
	for (int i = 0; i < K; ++i) {
		if (!(p1[i] >= p2[i])) {
			return 0;
		}
	}
	return 1;
}

void solve() {
	cin >> n;
	cin >> s >> t;
	calc(s, cs);
	calc(t, ct);
	for (int i = 0; i < K; ++i) {
		if (cs[i] != ct[i]) {
			cout << -1 << '\n';
			return;
		}
	}
	for (int i = 0; i < n; ++i) {
		copy(pref_s[i], pref_s[i] + K, pref_s[i + 1]);
		copy(pref_t[i], pref_t[i] + K, pref_t[i + 1]);
		pref_s[i + 1][s[i] - 'a']++;
		pref_t[i + 1][t[i] - 'a']++;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (s[i - 1] == t[j - 1] && major(pref_t[j], pref_s[i])) {
				chkmax(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		}
	}
	cout << n - dp[n][n] << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}