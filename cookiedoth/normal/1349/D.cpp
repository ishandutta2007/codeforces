/*

Code for problem D by cookiedoth
Generated 15 May 2020 at 01.46 PM


  !











\_()_/
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

int sum(int a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
	return a;
}

int diff(int a, int b) {
	a -= b;
	if (a < 0) {
		a += MOD;
	}
	return a;
}

const int mx = 1e5 + 228;
const int MAX_S = 3e5 + 228;
int n, S, a[mx], f[MAX_S], Ep[MAX_S];

void read() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		S += a[i];
	}
}

void calc_f() {
	f[0] = n - 1;
	int chance = mul(n - 2, inverse(n - 1));
	for (int k = 1; k < S; ++k) {
		int k_by_s = mul(k, inverse(S));
		int num = sum(1, mul(k_by_s, f[k - 1]));
		int den = diff(1, sum(k_by_s, mul(diff(1, k_by_s), chance)));
		f[k] = mul(num, inverse(den));
	}
}

void calc_Ep() {
	Ep[S] = 0;
	for (int i = S - 1; i >= 0; --i) {
		Ep[i] = sum(Ep[i + 1], f[i]);
	}
}

void calc_ans() {
	int ans = 0;
	int C = Ep[0];
	for (int i = 0; i < n; ++i) {
		ans = sum(ans, Ep[a[i]]);
	}
	ans = diff(ans, mul(C, n - 1));
	ans = mul(ans, inverse(n));
	cout << ans << endl;
}

signed main() {
	fast_io();
	read();
	calc_f();
	calc_Ep();
	calc_ans();
}