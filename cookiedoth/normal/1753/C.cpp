/*

Code for problem C by cookiedoth
Generated 23 Oct 2022 at 09.13 AM
The Moon is Waning Crescent (5% of Full)


       .
      ":"
    ___:____     |"\/"|
  ,'        `.    \  /
  |  O        \___/  |
~^~^~^~^~^~^~^~^~^~^~^~^~

o_O
^_^
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


int n;
vector<int> a, dp;

void solve() {
	cin >> n;
	a.resize(n);
	int cnt_1 = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		cnt_1 += a[i];
	}
	int sw = 0;
	for (int i = n - cnt_1; i < n; ++i) {
		sw += (a[i] == 0);
	}
	dp.resize(sw + 1);
	int pairs = divide(mul(n, n - 1), 2);
	for (int i = 1; i <= sw; ++i) {
		int frac = divide(pairs, mul(i, i));
		dp[i] = sum(dp[i - 1], frac);
	}
	cout << dp[sw] << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}