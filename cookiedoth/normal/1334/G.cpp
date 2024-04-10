/*

Code for problem G by cookiedoth
Generated 11 Apr 2020 at 09.10 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

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

namespace MOD_STUFF {
	const int LOW_DEG = 20;
	const int VAL = (1 << LOW_DEG);
	const int MIN_MOD = 5e8;
	const int MAX_MOD = 1e9;

	mt19937 rng(60);

	int is_prime(int x) {
		for (int i = 2; i * i <= x; ++i) {
			if (x % i == 0) {
				return 0;
			}
		}
		return 1;
	}

	int gen_mod() {
		int T_MIN = (MIN_MOD + VAL - 1) / VAL;
		int T_MAX = MAX_MOD / VAL;
		while (true) {
			int x = rng() % (T_MAX - T_MIN + 1) + T_MIN;
			if (is_prime(x * VAL + 1)) {
				return x * VAL + 1;
			}
		}
	}

	int MOD;

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

	vector<int> primes;

	void gen_primes() {
		int x = MOD - 1;
		for (int i = 2; i * i <= x; ++i) {
			if (x % i == 0) {
				primes.push_back(i);
				while (x % i == 0) {
					x /= i;
				}
			}
		}
		if (x > 1) {
			primes.push_back(x);
		}
	}

	int is_primitive_root(int x) {
		for (auto p : primes) {
			if (power(x, (MOD - 1) / p) == 1) {
				return 0;
			}
		}
		return 1;
	}

	int find_primitive_root() {
		while (true) {
			int val = rand() % MOD;
			if (val && is_primitive_root(val)) {
				return val;
			}
		}
	}

	int root;

	void go() {
		fast_io();
		MOD = gen_mod();
		// cerr << "MOD = " << MOD << endl;
		gen_primes();
		root = find_primitive_root();
		root = power(root, (MOD - 1) / VAL);
	}
}

int MOD;

int mul(int a, int b) {
	return (1LL * a * b) % MOD;
}

void add(int &a, int b) {
	a = (a + b) % MOD;
}

void subt(int &a, int b) {
	a = (a - b + MOD) % MOD;
}

int sum(int a, int b) {
	return (a + b) % MOD;
}

int power(int a, int deg) {
	int res = 1;
	while (deg) {
		if ((deg & 1) == 0) {
			a = mul(a, a);
			deg >>= 1;
		} else {
			res = mul(res, a);
			deg -= 1;
		}
	}
	return res;
}

int inverse(int a) {
	return power(a, MOD - 2);
}

int root;
int root_1;
int root_pw;

void gen() {
	MOD_STUFF::go();
	// MOD = 469762049;
	// root = 1068559;
	MOD = MOD_STUFF::MOD;
	root = MOD_STUFF::root;
	root_pw = MOD_STUFF::VAL;
	root_1 = inverse(root);
	// int val = 1;
	// for (int i = 0; i < root_pw; ++i) {
	// 	val = mul(val, root);
	// 	if (i < root_pw - 1 && val == 1) {
	// 		cerr << "i = " << i << endl;
	// 		assert(0);
	// 	}
	// }
	// cerr << "val = " << val << endl;
	// assert(val == 1);
	// cerr << MOD << " " << root << " " << root_pw << " " << root_1 << endl;
	// cerr << mul(root, root_1) << endl;
}
 
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

const int MX = 1e5;
int res[MX];

void multiply(vector<int> &a, vector<int> &b) {
	if (a.size() * b.size() < 1000) {
		int len = a.size() + b.size() + 1;
		fill(res, res + len, 0);
		for (int i = 0; i < a.size(); ++i) {
			for (int j = 0; j < b.size(); ++j) {
				add(res[i + j], mul(a[i], b[j]));
			}
		}
		a = vector<int> (res, res + a.size() + b.size() + 1);
		return;
	}

	int _n = max(a.size(), b.size());
	int n = 1;
	while (n < _n) {
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

const int K = 26;
int n, m;
vector<int> perm(K), _perm(K), char_hash(K), s, p, t;
mt19937 rng(58);

void read() {
	for (int i = 0; i < K; ++i) {
		char_hash[i] = rng() % MOD;
	}
	for (int i = 0; i < K; ++i) {
		cin >> perm[i];
		perm[i]--;
	}
	for (int i = 0; i < K; ++i) {
		_perm[perm[i]] = i;
	}
	perm = _perm;
	string _s, _t;
	cin >> _t;
	cin >> _s;
	n = _s.size();
	m = _t.size();
	s.resize(n);
	p.resize(n);
	t.resize(m);
	for (int i = 0; i < n; ++i) {
		s[i] = _s[i] - 'a';
		p[i] = perm[s[i]];
	}
	for (int i = 0; i < m; ++i) {
		t[i] = _t[i] - 'a';
	}
	for (int i = 0; i < n; ++i) {
		s[i] = char_hash[s[i]];
		p[i] = char_hash[p[i]];
	}
	for (int i = 0; i < m; ++i) {
		t[i] = char_hash[t[i]];
	}

	// cerr << "s" << endl;
	// output(all(s));
	// cerr << "p" << endl;
	// output(all(p));
	// cerr << "t" << endl;
	// output(all(t));
}

const int POLY_CNT = 5;
vector<vector<int> > polyA, polyB;

int get_s2p2(int pos) {
	return mul(mul(s[pos], s[pos]), mul(p[pos], p[pos]));
}

void calc() {
	polyA.resize(POLY_CNT, vector<int> (n));
	polyB.resize(POLY_CNT, vector<int> (m));
	for (int i = 0; i < n; ++i) {
		polyA[2][i] = sum(sum(mul(s[i], s[i]), mul(p[i], p[i])), mul(4, mul(s[i], p[i])));
		polyA[1][i] = mul(MOD - 2, sum(mul(mul(s[i], s[i]), p[i]), mul(mul(p[i], p[i]), s[i])));
		polyA[3][i] = mul(MOD - 2, sum(s[i], p[i]));
	}
	for (int i = 0; i < m; ++i) {
		polyB[0][i] = 1;
		for (int it = 1; it <= 4; ++it) {
			polyB[it][i] = mul(polyB[it - 1][i], t[i]);
		}
	}
	int sum_t4 = 0;
	for (int i = 0; i < m; ++i) {
		add(sum_t4, polyB[4][i]);
	}
	// cerr << "sum_t4 = " << sum_t4 << endl;
	int sum_s2p2 = 0;
	for (int it = 1; it <= 3; ++it) {
		reverse(all(polyB[it]));
		// cerr << "it = " << it << endl;
		// output(all(polyA[it]));
		// output(all(polyB[it]));
		multiply(polyA[it], polyB[it]);
	}
	// cerr << "sum_s2p2 = " << sum_s2p2 << endl;
	for (int i = 0; i < m; ++i) {
		add(sum_s2p2, get_s2p2(i));
	}
	for (int i = 0; i <= n - m; ++i) {
		int res = 0;
		for (int it = 1; it <= 3; ++it) {
			add(res, polyA[it][i + m - 1]);
		}
		// cerr << "_res = " << res << endl;
		add(res, sum_t4);
		add(res, sum_s2p2);
		// cerr << "res = " << res << endl;
		cout << (res == 0 ? '1' : '0');
		if (i < n - m) {
			subt(sum_s2p2, get_s2p2(i));
			add(sum_s2p2, get_s2p2(i + m));
		}
	}
	cout << endl;
}

signed main() {
	fast_io();
	gen();
	read();
	calc();
}