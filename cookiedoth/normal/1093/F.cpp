/*

Code for problem F by savkinsd2089
Generated 07 Jan 2019 at 08.02 pm
The Moon is Waxing Crescent (2% of Full)


 ] 
 
Il] 


-_-
>_<
\_()_/

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
#include <random>
#include <cstring>
#include <numeric>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)

#ifndef TESTING
	#define endl '\n'
#endif

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

const int mx = 1e5 + 228;
const int maxk = 110;
int n, k, len, a[mx], ok[maxk][mx];
ll dp[mx][maxk], sum_dp[mx];
const ll MOD = 998244353;

int weight(int val, int color) {
	return (val != color && val != -1);
}

signed main() {
	cin >> n >> k >> len;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] != -1) {
			a[i]--;
		}
	}

	for (int i = 0; i < k; ++i) {
		int sum = 0;
		for (int j = 0; j < len; ++j) {
			ok[i][0] += weight(a[j], i);
		}
		for (int j = 0; j < n - len; ++j) {
			ok[i][j + 1] = ok[i][j] - weight(a[j], i) + weight(a[j + len], i);
		}
	}

	/*cerr << "ok" << endl;
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j <= n - len; ++j) {
			cerr << ok[i][j] << " ";
		}
		cerr << endl;
	}*/

	sum_dp[0] = 1;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < k; ++j) {
			if (a[i - 1] != j && a[i - 1] != -1) {
				continue;
			}

			dp[i][j] = sum_dp[i - 1];
			if (i >= len && ok[j][i - len] == 0) {
				if (i == len) {
					dp[i][j] = (dp[i][j] - 1 + MOD) % MOD;
				}
				else {
					dp[i][j] = (dp[i][j] - (sum_dp[i - len] - dp[i - len][j]) + MOD) % MOD;
				}
			}
			sum_dp[i] = (sum_dp[i] + dp[i][j]) % MOD;
		}
	}

	/*cerr << "dp" << endl;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < k; ++j) {
			cerr << dp[i][j] << " ";
		}
		cerr << endl;
	}

	cerr << "sum_dp" << endl;
	for (int i = 0; i <= n; ++i) {
		cerr << sum_dp[i] << " ";
	}
	cerr << endl;*/

	cout << sum_dp[n] << endl;
}