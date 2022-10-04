/*

Code for problem E by cookiedoth
Generated 11 Apr 2021 at 07.09 PM


  !











-_-
~_^
=_=

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

const int MOD = 1e9 + 7;

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

const int mx = 1e5 + 228;
int n, a[mx], fact[mx], neg, pos, zer;
map<int, int> cnt;

void read() {
	cin >> n;
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = mul(fact[i - 1], i);
	}
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum % n != 0) {
		cout << 0 << '\n';
		exit(0);
	}
	for (int i = 0; i < n; ++i) {
		a[i] -= sum / n;
		if (a[i] < 0) {
			neg++;
		}
		if (a[i] == 0) {
			zer++;
		}
		if (a[i] > 0) {
			pos++;
		}
		cnt[a[i]]++;
	}
}

void solve() {
	int ans = mul(fact[n], inverse(mul(fact[zer], fact[n - zer])));
	ans = mul(ans, fact[neg]);
	ans = mul(ans, fact[pos]);
	for (auto [x, y] : cnt) {
		if (x != 0) {
			ans = mul(ans, inverse(fact[y]));
		}
	}
	if (neg == 1 || pos == 1) {
		ans = mul(ans, neg + pos);
	} else {
		if (neg || pos) {
			ans = mul(ans, 2);
		}
	}
	cout << ans << '\n';
}

signed main() {
	fast_io();
	read();
	solve();
}