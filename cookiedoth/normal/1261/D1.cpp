/*

Code for problem D by cookiedoth
Generated 27 Nov 2019 at 02.52 P


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

z_z
>_<
o_O

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

const int mx = 2e5 + 228;
const ll MOD = 998244353;
int n, a[mx], cnt;
ll k, fact[mx], _fact[mx];

ll power(ll a, ll deg) {
	ll res = 1;
	while (deg) {
		if ((deg & 1LL) == 0) {
			a = (a * a) % MOD;
			deg >>= 1;
		} else {
			res = (res * a) % MOD;
			deg -= 1;
		}
	}
	return res;
}

ll inverse(ll a) {
	return power(a, MOD - 2);
}

void calc_fact() {
	fact[0] = 1;
	for (int i = 1; i < mx; ++i) {
		fact[i] = (fact[i - 1] * (ll)i) % MOD;
	}
	for (int i = 0; i < mx; ++i) {
		_fact[i] = inverse(fact[i]);
	}
}

ll C(ll n, ll k) {
	if (k > n) {
		return 0;
	}
	return (fact[n] * _fact[k] % MOD * _fact[n - k] % MOD);
}

signed main() {
	fast_io();
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] != a[(i + 1) % n]) {
			cnt++;
		}
	}
	if (k == 1) {
		cout << 0 << endl;
		exit(0);
	}
	calc_fact();
	// cerr << "cnt = " << cnt << endl;
	ll mult = power(k, n - cnt);
	// cerr << "mult = " << mult << endl;
	ll all = power(k, cnt);
	// cerr << "all = " << all << endl;
	for (int c = 0; 2 * c <= cnt; ++c) {
		ll cur = (C(cnt, c) * C(cnt - c, c) % MOD * power(k - 2, cnt - 2 * c)) % MOD;
		all = (all - cur + MOD) % MOD;
	}
	// cerr << "_all = " << all << endl;
	all = (all * inverse(2)) % MOD;
	mult = (mult * all) % MOD;
	cout << mult << endl;
}