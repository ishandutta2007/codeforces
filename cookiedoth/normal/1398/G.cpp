/*

Code for problem G by cookiedoth
Generated 14 Aug 2020 at 07.45 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

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

namespace emaxx_fft {
	int root = power(3, 17 * 7);
	int root_1 = inverse(root);
	int root_pw = 1 << 23;

	void fft (vector<int> & a, bool invert) {
		int n = (int) a.size();
	 
		for (int i=1, j=0; i<n; ++i) {
			int bit = n >> 1;
			for (; j>=bit; bit>>=1)
				j -= bit;
			j += bit;
			if (i < j)
				swap (a[i], a[j]);
		}
	 
		for (int len=2; len<=n; len<<=1) {
			int wlen = invert ? root_1 : root;
			for (int i=len; i<root_pw; i<<=1)
				wlen = int (wlen * 1ll * wlen % MOD);
			for (int i=0; i<n; i+=len) {
				int w = 1;
				for (int j=0; j<len/2; ++j) {
					int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % MOD);
					a[i+j] = u+v < MOD ? u+v : u+v-MOD;
					a[i+j+len/2] = u-v >= 0 ? u-v : u-v+MOD;
					w = int (w * 1ll * wlen % MOD);
				}
			}
		}
		if (invert) {
			int nrev = inverse(n);
			for (int i=0; i<n; ++i)
				a[i] = int (a[i] * 1ll * nrev % MOD);
		}
	}

	void multiply(vector<int>& a, vector<int>& b) {
		int n = 1;
		while (n < max(a.size(), b.size())) {
			n <<= 1;
		}
		n <<= 1;
		a.resize(n);
		b.resize(n);
		fft(a, 0);
		fft(b, 0);
		for (int i = 0; i < n; ++i) {
			a[i] = mul(a[i], b[i]);
		}
		fft(a, 1);
	}
}

int n, X, Y;
vector<int> poly, _poly;

void read() {
	cin >> n >> X >> Y;
	poly.resize(X + 1);
	for (int i = 0; i <= n; ++i) {
		int val;
		cin >> val;
		poly[val] = 1;
	}
	_poly = poly;
	reverse(all(_poly));
	emaxx_fft::multiply(poly, _poly);
}

int is_difference(int d) {
	return (d > 0 && X + d < poly.size() && poly[X + d]);
}

vector<int> dv;

int solve(int x) {
	x /= 2;
	dv.clear();
	for (int i = 1; i * i <= x; ++i) {
		if (x % i == 0) {
			dv.push_back(i);
			int L = x / i;
			if (is_difference(L - Y)) {
				return 2 * L;
			}
		}
	}
	reverse(all(dv));
	for (auto L : dv) {
		if (is_difference(L - Y)) {
			return 2 * L;
		}
	}
	return -1;
}

void process_queries() {
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		int res = solve(x);
		cout << res << '\n';
	}
}

signed main() {
	fast_io();
	read();
	process_queries();
}