/*

Code for problem E by cookiedoth
Generated 15 Dec 2019 at 01.25 P










(@)(@)(@)(@)(@)

z_z
>_<
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

const ll INF = 1e18 + 228;

ll get_bits(ll x) {
	return 64 - __builtin_clzll(x);
}

ll check(ll n, ll k) {
	if (k == 0) {
		return INF;
	}
	if (k > n) {
		return 0;
	}
	k >>= 1;
	// cerr << "k = " << k << endl;
	int bits = get_bits(k);
	int bits_n = get_bits(n);
	// cerr << "bits_n bits " << bits_n << " " << bits << endl;
	ll ans = (1LL << (bits_n - bits)) - 1;
	ll _n = (n >> (bits_n - bits));
	// cerr << "ans = " << ans << endl;
	if (k == _n) {
		ans += (n & ((1LL << (bits_n - bits)) - 1)) + 1;
	}
	if (k < _n) {
		ans += (1LL << (bits_n - bits));
	}
	return ans - 1;
}

ll solve_even(ll n, ll k) {
	ll l = 0, r = n / 2 + 1;
	while (l < r) {
		ll mid = (l + r) >> 1;
		if (check(n, 2 * (mid + 1)) >= k) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return 2 * l;
}

ll n, k;

signed main() {
	fast_io();
	cin >> n >> k;
	if (k == 1) {
		cout << n << endl;
		exit(0);
	}
	ll res1 = solve_even(n, k);
	ll res2 = solve_even(n, k - 1);
	cout << max(res1, res2 / 2) << endl;
}