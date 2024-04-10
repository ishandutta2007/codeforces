/*

Code for problem E by cookiedoth
Generated 10 Apr 2020 at 06.19 PM



10%

30%

50%

70%

100%

~_^
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

ll D;
int ps;
vector<ll> divisors, primes;
vector<vector<int> > factor;

void div_work() {
	for (ll i = 1; i * i <= D; ++i) {
		if (D % i == 0) {
			divisors.push_back(i);
			if (i != D / i) {
				divisors.push_back(D / i);
			}
		}
	}
	sort(all(divisors));
	ll _D = D;
	for (auto d : divisors) {
		if (d > 1 && _D % d == 0) {
			primes.push_back(d);
			while (_D % d == 0) {
				_D /= d;
			}
		}
	}
	int ds = divisors.size();
	ps = primes.size();
	factor.resize(ds, vector<int> ());
	factor[0].resize(ps);
	for (int i = 1; i < divisors.size(); ++i) {
		int ok = 0;
		for (int j = 0; j < primes.size(); ++j) {
			ll p = primes[j];
			if (divisors[i] % p == 0) {
				int pos = lower_bound(all(divisors), divisors[i] / p) - divisors.begin();
				factor[i] = factor[pos];
				factor[i][j]++;
				ok = 1;
				break;
			}
		}
		assert(ok);
	}
}

const int MOD = 998244353;
const int mx = 200;

int mul(int a, int b) {
	return (1LL * a * b) % MOD;
}

int fact[mx], inv[mx], _fact[mx];

void calc_fact() {
	inv[1] = 1;
	for (int i = 2; i < mx; ++i) {
		inv[i] = mul(MOD - MOD / i, inv[MOD % i]);
	}
	// cerr << "control " << mul(inv[10], 10) << endl;
	_fact[0] = fact[0] = 1;
	for (int i = 1; i < mx; ++i) {
		fact[i] = mul(fact[i - 1], i);
		_fact[i] = mul(_fact[i - 1], inv[i]);
	}
}

int query(ll u, ll v) {
	int res_down = 1, res_up = 1;
	int s_down = 0, s_up = 0;
	int pos_u = lower_bound(all(divisors), u) - divisors.begin();
	int pos_v = lower_bound(all(divisors), v) - divisors.begin();
	for (int i = 0; i < ps; ++i) {
		int delta = abs(factor[pos_u][i] - factor[pos_v][i]);
		if (factor[pos_u][i] > factor[pos_v][i]) {
			res_down = mul(res_down, _fact[delta]);
			s_down += delta;
		} else {
			res_up = mul(res_up, _fact[delta]);
			s_up += delta;
		}
	}
	res_down = mul(res_down, fact[s_down]);
	res_up = mul(res_up, fact[s_up]);
	return mul(res_down, res_up);
}

void process() {
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		ll u, v;
		cin >> u >> v;
		int res = query(u, v);
		cout << res << "\n";
	}
}

signed main() {
	fast_io();
	cin >> D;
	div_work();
	calc_fact();
	process();
}