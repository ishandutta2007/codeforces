/*

Code for problem C by cookiedoth
Generated 11 Apr 2021 at 05.45 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

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
#include <random>
#include <utility>
#include <tuple>
#include <chrono>
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

const int MOD = 1e9 + 7;
const int mx = 2e5 + 228;
const int D = 10;
int dp[mx][D];

void init() {
	fill(dp[0], dp[0] + D, 1);
	for (int i = 1; i < mx; ++i) {
		for (int j = 0; j < D - 1; ++j) {
			dp[i][j] = dp[i - 1][j + 1];
		}
		dp[i][D - 1] = (dp[i - 1][1] + dp[i - 1][0]) % MOD;
	}
}

void solve() {
	string s;
	int m;
	cin >> s >> m;
	int ans = 0;
	for (auto c : s) {
		int d = c - '0';
		ans = (ans + dp[m][d]) % MOD;
	}
	cout << ans << '\n';
}

signed main() {
	fast_io();
	init();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}