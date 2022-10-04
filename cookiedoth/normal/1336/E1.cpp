/*

Code for problem E1 by cookiedoth
Generated 15 Apr 2020 at 06.33 PM


 ] 
 
Il] 


\_()_/
o_O
-_-

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
#define ll __int128
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()
#define int long long

using namespace std;

istream& operator >> (istream &is, __int128 &x) {
	long long a;
	is >> a;
	x = (__int128)a;
	return is;
}

ostream& operator << (ostream &os, const __int128 &x) {
	os << (long long)x;
	return os;
}

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
const int M = 55;
const int MAX_LO = 15;
const int MAX_HI = M - MAX_LO;
int n, m, LO, dummies;
ll basis[mx];

void read() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		int is_dummy = 1;
		for (int j = m - 1; j >= 0; --j) {
			if ((x >> j) & 1) {
				if (basis[j] == 0) {
					basis[j] = x;
					is_dummy = 0;
					break;
				} else {
					x ^= basis[j];
				}
			}
		}
		dummies += is_dummy;
	}
}

ll ways[MAX_HI][1 << MAX_LO], lo_ways[1 << MAX_LO];

void xor_convolution(ll *a, int B, int inverse) {
	int start = (inverse ? B - 1 : 0), step = (inverse ? -1 : 1);
	for (int b = start; b < B && b >= 0; b += step) {
		for (int i = 0; i < (1 << B); i++) {
			if (((i >> b) & 1) == 0) {
				ll u = a[i], v = a[i ^ (1 << b)];
				a[i] = u + v;
				a[i ^ (1 << b)] = u - v;
			}
		}
		if (inverse) {
			for (int i = 0; i < (1 << B); ++i) {
				a[i] /= 2;
			}
		}
	}
}

void calc() {
	// cerr << "LO = " << LO << endl;
	vector<ll> high;
	for (int i = LO; i < m; ++i) {
		if (basis[i]) {
			high.push_back(basis[i]);
		}
	}
	// output(all(high));
	ll LO_MASK = (1LL << LO) - 1;
	ll HI_MASK = (~LO_MASK);
	for (int sub = 0; sub < (1 << high.size()); ++sub) {
		ll val = 0;
		for (int i = 0; i < high.size(); ++i) {
			if ((sub >> i) & 1) {
				val ^= high[i];
			}
		}
		// cerr << "ways " << __builtin_popcountll(val & HI_MASK) << " " << (val & LO_MASK) << endl;
		ways[__builtin_popcountll(val & HI_MASK)][val & LO_MASK]++;
	}
	vector<ll> low;
	for (int i = 0; i < LO; ++i) {
		if (basis[i]) {
			low.push_back(basis[i]);
		}
	}
	for (int sub = 0; sub < (1 << low.size()); ++sub) {
		ll val = 0;
		for (int i = 0; i < low.size(); ++i) {
			if ((sub >> i) & 1) {
				val ^= low[i];
			}
		}
		// cerr << "lo_ways " << val << endl;
		lo_ways[val]++;
	}
}

ll ans[M];

void multiply() {
	for (int i = 0; i <= m - LO; ++i) {
		// cerr << "ways " << i << endl;
		// output(ways[i],  ways[i] + (1 << LO));
		xor_convolution(ways[i], LO, 0);
		// output(ways[i],  ways[i] + (1 << LO));
	}
	// cerr << "lo_ways" << endl;
	// output(lo_ways, lo_ways + (1 << LO));
	xor_convolution(lo_ways, LO, 0);
	// output(lo_ways, lo_ways + (1 << LO));
	for (int i = 0; i <= m - LO; ++i) {
		for (int j = 0; j < (1 << LO); ++j) {
			ways[i][j] *= lo_ways[j];
		}
		// cerr << "=============ways " << i << endl;
		// output(ways[i],  ways[i] + (1 << LO));
		xor_convolution(ways[i], LO, 1);
		// output(ways[i],  ways[i] + (1 << LO));
		for (int j = 0; j < (1 << LO); ++j) {
			ans[i + __builtin_popcountll(j)] += ways[i][j];
		}
	}
}

void process() {
	LO = min(MAX_LO, m / 2);
	calc();
}

const int MOD = 998244353;

int mul(int a, int b) {
	return (1LL * a * b) % MOD;
}

void finalize() {
	int multiplier = 1;
	for (int i = 0; i < dummies; ++i) {
		multiplier = mul(multiplier, 2);
	}
	for (int i = 0; i <= m; ++i) {
		ans[i] %= MOD;
		ans[i] = mul(ans[i], multiplier);
	}
	int sum = 0;
	int pw2n = 1;
	for (int i = 0; i < n; ++i) {
		pw2n = mul(pw2n, 2);
	}
	for (int i = 0; i <= m; ++i) {
		sum = (sum + ans[i]) % MOD;
	}
	assert(sum == pw2n);
	output(ans, ans + m + 1, cout);
}

signed main() {
	fast_io();
	read();

	// cerr << "val" << endl;
	// output(basis, basis + m);
	// cerr << "dummies = " << dummies << endl;

	process();
	multiply();
	finalize();
}