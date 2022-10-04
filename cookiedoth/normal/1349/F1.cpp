/*

Code for problem F by cookiedoth
Generated 21 May 2020 at 06.33 PM










(@)(@)(@)(@)(@)

=_=
\_()_/
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

const int MOD = 998244353;

int mul(int a, int b) {
	return (1LL * a * b) % MOD;
}

void add(int &a, int b) {
	a = (a + b) % MOD;
	if (a >= MOD) {
		a -= MOD;
	}
}

int power(int a, int deg) {
	int res = 1;
	for (; deg; deg >>= 1, a = mul(a, a)) {
		if (deg & 1) {
			res = mul(res, a);
		}
	}
	return res;
}

int inverse(int a) {
	return power(a, MOD - 2);
}

const int mx = 5010;
int n, dp[mx][mx];

void calc_dp() {
	dp[1][0] = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			add(dp[i + 1][j], mul(dp[i][j], j + 1));
			add(dp[i + 1][j + 1], mul(dp[i][j], i - j));
		}
	}

	// cerr << "dp" << endl;
	// for (int i = 1; i <= n; ++i) {
	// 	for (int j = 0; j < i; ++j) {
	// 		cerr << dp[i][j] << " ";
	// 	}
	// 	cerr << endl;
	// }
}

int fact[mx], _fact[mx];

void calc_fact() {
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = mul(fact[i - 1], i);
	}
	for (int i = 0; i <= n; ++i) {
		_fact[i] = inverse(fact[i]);
	}
}

int ans[mx];

void calc_ans() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			add(ans[j], mul(dp[i + 1][j], mul(fact[n], _fact[i + 1])));
		}
	}
}

signed main() {
	fast_io();
	cin >> n;
	calc_dp();
	calc_fact();
	calc_ans();
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}