/*
   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
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
#define ll long long
#define null NULL
#define all(a) a.begin(), a.end()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

const ll MOD = 1e9 + 7;

const int mx = 5050;
int n, a[mx], val[mx][mx], dp[mx][mx];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		val[i][i] = a[i];
		dp[i][i] = a[i];
	}
	for (int len = 2; len <= n; ++len) {
		for (int i = 0; i <= n - len; ++i) {
			int j = i + len - 1;
			val[i][j] = val[i][j - 1] ^ val[i + 1][j];
			dp[i][j] = max(max(dp[i][j - 1], dp[i + 1][j]), val[i][j]);
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		cout << dp[l][r] << '\n';
	}
}