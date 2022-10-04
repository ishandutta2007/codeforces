/*

Code for problem  by cookiedoth
Generated 08 May 2022 at 09.07 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

z_z
=_=
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

const int MOD = 998244353;

int mul(int a, int b) {
	return (1LL * a * b) % MOD;
}

int diff(int a, int b) {
	a -= b;
	if (a < 0) {
		a += MOD;
	}
	return a;
}

void subt(int &a, const int &b) {
	a -= b;
	if (a < 0) {
		a += MOD;
	}
}

int sum(int a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
	return a;
}

void add(int &a, const int &b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int power(int a, int deg) {
	int res = 1;
	for (; deg; a = mul(a, a), deg >>= 1) {
		if (deg & 1) {
			res = mul(res, a);
		}
	}
	return res;
}

int inverse(int a) {
	return power(a, MOD - 2);
}

int divide(int a, int b) {
	return mul(a, inverse(b));
}


const int MAX_N = 1e6 + 228;
int T, n, k, arr[MAX_N], cnt, fact[MAX_N], _fact[MAX_N];

void calc_fact() {
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = mul(fact[i - 1], i);
	}
	for (int i = 0; i <= n; ++i) {
		_fact[i] = inverse(fact[i]);
	}
}

int C(int n, int k) {
	return k > n ? 0 : mul(fact[n], mul(_fact[k], _fact[n - k]));
}

int geom(int a, int max_deg) {
	return divide(diff(power(a, max_deg + 1), 1), diff(a, 1));
}

void solve() {
	cin >> n >> k;
	bool bad = false;
	int perm_cnt = 1;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (i >= n - k) {
			if (!(arr[i] == -1 || arr[i] == 0)) {
				bad = true;
			}
			continue;
		}
		if (arr[i] == -1) {
			perm_cnt = mul(perm_cnt, i + k + 1);
		}
		if (arr[i] == 0) {
			perm_cnt = mul(perm_cnt, k + 1);
		}
	}
	// cerr << "perm_cnt = " << perm_cnt << '\n';
	calc_fact();
	if (bad) {
		cout << 0 << '\n';
		return;
	} else {
		cout << mul(fact[k], perm_cnt) << '\n';
	}
}

const int MM = 10;
int dp[MM][MM];

void oeis() {
	n = MM;
	calc_fact();
	for (int i = 1; i < MM; ++i) {
		dp[0][i] = 1;
	}
	for (int i = 1; i < MM; ++i) {
		for (int j = 1; j < MM; ++j) {
			for (int k = 0; k <= j - i; ++k) {
				add(dp[i][j], mul(dp[i - 1][j - k], C(j - i, k)));
			}
		}
	}
	for (int k = 1; k < MM; ++k) {
		for (int cnt = k; cnt < MM; ++cnt) {
			assert(mul(fact[k], power(k + 1, cnt - k)) == dp[k][cnt]);
		}
	}
	for (int i = 0; i < MM; ++i) {
		for (int j = 0; j < MM; ++j) {
			cerr << dp[i][j] << ' ';
		}
		cerr << '\n';
	}
}

signed main() {
	fast_io();
	// oeis();
	cin >> T;
	while (T--) {
		solve();
	}
}