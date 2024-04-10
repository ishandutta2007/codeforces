/*

Code for problem D by cookiedoth
Generated 23 Jun 2020 at 05.54 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

o_O
-_-
~_^

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

const int mx = 2e6 + 228;
const ll MOD = 1e9 + 7;
ll dp[mx];

signed main() {
	fast_io();
	dp[3] = 1;
	dp[4] = 1;
	dp[5] = 3;
	for (int i = 6; i < mx; ++i) {
		ll v1 = 2 * dp[i - 2] + dp[i - 1];
		ll v2 = 1 + 4 * dp[i - 4] + 4 * dp[i - 3] + dp[i - 2];
		if (i % 3 == 2) {
			dp[i] = v1;
		} else {
			dp[i] = v2;
		}
		dp[i] %= MOD;
	}
	int q;
	cin >> q;
	while (q--) {
		ll pos;
		cin >> pos;
		cout << (dp[pos] * 4) % MOD << endl;
	}
}