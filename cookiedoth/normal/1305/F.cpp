/*

Code for problem F by cookiedoth
Generated 03 Mar 2020 at 07.02 PM


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

const ll INF = 1e18;
const int mx = 2e5 + 228;
const int C = 1e6 + 5e6 + 228;
int n;
char not_prime[C];
ll a[mx];

void sieve() {
	for (int i = 2; i * i < C; ++i) {
		if (not_prime[i] == 0) {
			for (int j = i * i; j < C; j += i) {
				not_prime[j] = 1;
			}
		}
	}
}

ll ans = INF;
set<ll> used;

void check1(ll p) {
	if (used.find(p) != used.end()) {
		return;
	}
	used.insert(p);
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		ll d = p * (a[i] / p);
		ll cur = d + p - a[i];
		if (d) {
			chkmin(cur, a[i] - d);
		}
		res += cur;
		if (res > ans) {
			break;
		}
	}
	// cerr << p << " " << res << endl;
	chkmin(ans, res);
}

mt19937 rng(time(null));

void check2(ll x) {
	for (ll i = 2; i * i <= x; ++i) {
		if (x % i == 0 && not_prime[i] == 0) {
			check1(i);
			while (x % i == 0) {
				x /= i;
			}
		}
	}
	if (x > 1) {
		check1(x);
	}
}

void process() {
	ld t1 = clock();
	check1(2);
	while (((ld)clock() - t1) / CLOCKS_PER_SEC < 2.0) {
		int pos = rng() % n;
		check2(a[pos]);
		if (a[pos] >= 1) {
			check2(a[pos] - 1);
		}
		check2(a[pos] + 1);
	}
}

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	ans = n;
	sieve();
	process();
	cout << ans << endl;
}