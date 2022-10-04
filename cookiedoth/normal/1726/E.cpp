/*

Code for problem E by cookiedoth
Generated 06 Sep 2022 at 11.16 AM
The Moon is Waxing Gibbous (82% of Full)


  !
 
                                    
                          
                  




















~_^
=_=
>_<

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
#include <array>
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

const int MAX_N = 3e5 + 228;
int fact[MAX_N], _fact[MAX_N];

void calc_fact(int k) {
	fact[0] = 1;
	for (int i = 1; i <= k; ++i) {
		fact[i] = mul(fact[i - 1], i);
	}
	for (int i = 0; i <= k; ++i) {
		_fact[i] = inverse(fact[i]);
	}
}

int binom(int n, int k) {
	return k > n ? 0 : mul(fact[n], mul(_fact[k], _fact[n - k]));
}

int n, f21[MAX_N], match[MAX_N];

void solve() {
	cin >> n;
	calc_fact(n);
	f21[0] = 1;
	for (int i = 1; i <= n; ++i) {
		f21[i] = f21[i - 1];
		if (i >= 2) {
			add(f21[i], mul(f21[i - 2], i - 1));
		}
	}
	match[0] = 1;
	for (int i = 1; i <= n; ++i) {
		match[i] = mul(match[i - 1], 2 * i - 1);
	}
	int ans = 0;
	for (int k = 0; 4 * k <= n; ++k) {
		int res_k = mul(binom(n - 2 * k, 2 * k), mul(match[k], mul(power(2, k), f21[n - 4 * k])));
		add(ans, res_k);
	}
	cout << ans << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}