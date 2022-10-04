/*

Code for problem F1 by cookiedoth
Generated 20 Jul 2019 at 07.20 P


 ] 
 
Il] 


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

const int mx = 510;
const ll MOD = 998244353;
int n, m, p[mx];
ll dp[mx][mx];

signed main() {
	fast_io();
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		p[i]--;
	}
	for (int i = 0; i < n; ++i) {
		dp[i][i] = 1;
	}
	for (int len = 2; len <= n; ++len) {
		for (int l = 0; l <= n - len; ++l) {
			int r = l + len - 1;
			int pos = (min_element(p + l, p + r + 1) - p);
			//cerr << l << " " << r << " " << pos << endl;
			ll w1 = 0, w2 = 0;
			if (r == pos) {
				w1 = 1;
			}
			else {
				for (int i = pos + 1; i < r; ++i) {
					w1 = (w1 + dp[pos + 1][i] * dp[i + 1][r]) % MOD;
				}
				w1 = (w1 + 2 * dp[pos + 1][r]) % MOD;
				//cerr << "w1 = " << w1 << endl;
			}
			if (l == pos) {
				w2 = 1;
			}
			else {
				for (int i = l + 1; i < pos; ++i) {
					w2 = (w2 + dp[l][i - 1] * dp[i][pos - 1]) % MOD;
				}
				w2 = (w2 + 2 * dp[l][pos - 1]) % MOD;
			}
			dp[l][r] = (w1 * w2) % MOD;
			//cerr << "dp " << l << " " << r << " = " << dp[l][r] << endl;
		}
	}
	cout << dp[0][n - 1] << endl;
}