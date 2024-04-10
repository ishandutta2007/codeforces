/*

Code for problem  by cookiedoth
Generated 11 Jun 2020 at 11.31 PM



10%

30%

50%

70%

100%

z_z
>_<
\_()_/

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

const int mx = 1e4 + 228;
int n, m, br[mx];
string s, t;
vector<int> st;

void read() {
	cin >> s;
	cin >> t;
	n = s.size();
	m = t.size();
}

void calc_br() {
	fill(br, br + n, -1);
	vector<int> st;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '.') {
			if (!st.empty()) {
				br[st.back()] = i;
				st.pop_back();
			}
		} else {
			st.push_back(i);
		}
	}
}

const int INF = 1e9;
int dp[mx][mx];

void calc_dp() {
	for (int i = 0; i <= n; ++i) {
		fill(dp[i], dp[i] + m + 1, INF);
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (j < m && s[i] == t[j]) {
				chkmin(dp[i + 1][j + 1], dp[i][j]);
			}
			chkmin(dp[i + 1][j], dp[i][j] + 1);
			if (br[i] != -1) {
				chkmin(dp[br[i] + 1][j], dp[i][j]);
			}
		}
	}
	cout << dp[n][m] << '\n';
}

signed main() {
	fast_io();
	read();
	calc_br();
	calc_dp();
}