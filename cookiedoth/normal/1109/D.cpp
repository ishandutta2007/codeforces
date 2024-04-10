/*

Code for problem D by cookiedoth
Generated 16 Feb 2019 at 07.32 P


 ] 
 
Il] 


-_-
z_z
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

const ll MOD = 1e9 + 7;

ll power(ll a, ll deg) {
	ll res = 1;
	while (deg) {
		if ((deg & 1LL) == 0) {
			a = (a * a) % MOD;
			deg >>= 1;
		}
		else {
			res = (res * a) % MOD;
			deg -= 1;
		}
	}
	return res;
}

ll inverse(ll x) {
	return power(x, MOD - 2);
}

const int mx = 1e6 + 228;
ll fact[mx];

ll C(ll n, ll k) {
	if (k > n) {
		return 0;
	}
	return (fact[n] * inverse(((fact[k]) * fact[n - k]) % MOD)) % MOD;
}

ll n, m;
int a, b;

signed main() {
	fast_io();
	//cerr << "mem" << endl;

	fact[0] = 1;
	for (int i = 1; i < mx; ++i) {
		fact[i] = (fact[i - 1] * (ll)i) % MOD;
	}

	cin >> n >> m >> a >> b;
	ll ans = 0;
	for (ll k = 2; k <= min(n, m + 1); ++k) {
		//cerr << "k = " << k << endl;
		ll v1 = (C(m - 1, k - 2) * C(n - 2, k - 2)) % MOD;
		v1 = (v1 * fact[k - 2]) % MOD;
		ll d = 1;
		if (k < n) {
			d = (power(n, n - k - 1) * k) % MOD;
		}
		d = (d * power(m, n - k)) % MOD;
		ans = (ans + v1 * d) % MOD;
	}
	cout << ans << endl;
}