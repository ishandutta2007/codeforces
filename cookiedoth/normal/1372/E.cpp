/*

Code for problem E by cookiedoth
Generated 11 Jul 2020 at 07.50 PM


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

const int mx = 110;
int n, m, dp[mx][mx], L[mx][mx], R[mx][mx];

signed main() {
	fast_io();
	cin >> n >> m;
	for (int it = 0; it < n; ++it) {
		int k;
		cin >> k;
		for (int i = 0; i < k; ++i) {
			int l, r;
			cin >> l >> r;
			for (int j = l; j <= r; ++j) {
				L[it][j] = l;
				R[it][j] = r;
			}
		}
	}
	for (int diff = 2; diff <= m + 1; ++diff) {
		for (int l = 0; l <= m + 1 - diff; ++l) {
			int r = l + diff;
			for (int t = l + 1; t < r; ++t) {
				int score = 0;
				for (int i = 0; i < n; ++i) {
					if (L[i][t] > l && R[i][t] < r) {
						score++;
					}
				}
				chkmax(dp[l][r], dp[l][t] + dp[t][r] + score * score);
			}
		}
	}
	cout << dp[0][m + 1] << '\n';
}