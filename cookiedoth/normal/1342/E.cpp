/*

Code for problem E by cookiedoth
Generated 26 Apr 2020 at 06.42 PM



10%

30%

50%

70%

100%

~_^
z_z
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

// each empty cell is under attack!!!!!!!!

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

int inverse(int x) {
	return power(x, MOD - 2);
}

void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

const int mx = 2e5 + 228;
int n, fact[mx];
ll k;

void calc_fact() {
	fact[0] = 1;
	for (int i = 1; i < mx; ++i) {
		fact[i] = mul(fact[i - 1], i);
	}
}

int C(int n, int k) {
	return (k > n ? 0 : mul(fact[n], inverse(mul(fact[k], fact[n - k]))));
}

signed main() {
	fast_io();
	calc_fact();
	cin >> n >> k;
	if (k >= n) {
		cout << 0 << endl;
		exit(0);
	}
	int x = n - k;
	int ans = 0;
	for (int i = 0; i <= x; ++i) {
		int sign = (i % 2 ? MOD - 1 : 1);
		add(ans, mul(sign, mul(C(x, i), power(x - i, n))));
	}
	ans = mul(ans, C(n, x));
	if (k) {
		ans = mul(ans, 2);
	}
	cout << ans << "\n";
}