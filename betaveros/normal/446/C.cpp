// @betaveros :: vim:set fdm=marker syntax=cppc:
#define NDEBUG
// #includes, using namespace std {{{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <cinttypes> // C++11?
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <new>
#include <algorithm>
#include <iostream>
using namespace std;
// }}}
// #defines, typedefs, constants {{{
#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define fori0(i,e) for(int i = 0; i < ((int)e); i++)
#define fori1(i,e) for(int i = 1; i <= ((int)e); i++)
#define forui(i,s,e) for(unsigned int i = s; i < ((unsigned int)e); i++)
#define foruin(i,c) for(unsigned int i = 0; i < ((unsigned int)(c).size()); i++)
#define _conc(x,y) x ## y
#define _conc2(x,y) _conc(x,y)
#define repeat(n) fori(_conc2(_,__LINE__),0,n)
#define allof(s) (s).begin(), (s).end()
#define scan_d(x) scanf("%d",&(x))
#define scan_dd(x,y) scanf("%d%d",&(x),&(y))
#define scan_ddd(x,y,z) scanf("%d%d%d",&(x),&(y),&(z))
#define scan_dddd(x,y,z,w) scanf("%d%d%d%d",&(x),&(y),&(z),&(w))
#define pushb push_back
#define popb push_back

#ifdef NDEBUG
#define debug(code)
#define debugf(...) ((void)0)
#else
#define debug(code) code
#define debugf(...) fprintf(stderr, __VA_ARGS__)
#endif
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> Vint;
typedef vector<int>::iterator Vit;

// const int OO  = 1000 << 20;
// const int OO2 = 2000 << 20;
// const int       M7  = 1000000007;
const ll M9  = 1000000009;
// const long long M7L = 1000000007L;
// }}}
// dump, min/maxify {{{
template <class T> void dumpBetween(const T & a, const T & b) {
	for (T it = a; it != b; it++) cout << *it << " ";
	cout << endl;
}
template <class T> void dumpAll(const T & a) { dumpBetween(allof(a)); }
template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }
// }}}

const ll N = 300008;
int n, m;
ll fibo[N];
ll fibosum[N];
void makeFibo() {
	fibo[0] = 0;
	fibo[1] = 1;
	fibosum[0] = 0;
	fibosum[1] = 1;
	fori (i, 2, N) {
		fibo[i] = (fibo[i-1] + fibo[i-2]) % M9;
		fibosum[i] = (fibosum[i-1] + fibo[i]) % M9; // math is hard qq
	}
}

void skip(ll f0, ll f1, int k, ll & sf0, ll & sf1) {
	if (k == 0) {
		sf0 = f0;
		sf1 = f1;
	} else {
		sf0 = (int) ((fibo[k-1] * f0 + fibo[k] * f1) % M9);
		sf1 = (int) ((fibo[k] * f0 + fibo[k+1] * f1) % M9);
	}
}
struct Node {
	ll f0, f1, s;
} st[4*N];

ll justsum(int ix, int lo, int hi) {
	if (hi - lo == 1) return (st[ix].s + st[ix].f0) % M9;
	return (st[ix].s + fibosum[hi - lo - 1] * st[ix].f1
			+ ((1 + fibosum[hi - lo - 2]) * st[ix].f0)) % M9;
}
void put(int ix, int lo, int hi, int tgt, ll s) {
	assert(lo <= tgt);
	assert(tgt < hi);
	if (hi - lo == 1) {
		st[ix].f0 = (st[ix].f0 + s) % M9;
	} else {
		st[ix].s = (st[ix].s + s) % M9;
		int mid = (hi + lo) / 2;
		if (tgt < mid) put(2*ix, lo, mid, tgt, s);
		else put(2*ix+1, mid, hi, tgt, s);
	}
}

void readInput() {
	scan_dd(n, m);
	fori (i, 0, n) {
		int x;
		scan_d(x);
		put(1, 0, n, i, x);
	}
}


void addFibo(int ix, int lo, int hi, int tlo, int thi, ll f0, ll f1) {
	assert(lo <= tlo);
	assert(tlo < thi);
	assert(thi <= hi);
	debugf("addFibo %d: [%d,%d) > [%d,%d); z %d o %d\n", ix, lo, hi, tlo, thi, f0, f1);
	if (lo == tlo && hi == thi) {
		st[ix].f0 = (st[ix].f0 + f0) % M9;
		st[ix].f1 = (st[ix].f1 + f1) % M9;
	} else {
		int mid = (lo + hi) / 2;
		if (tlo < mid) {
			addFibo(2*ix, lo, mid, tlo, min(thi, mid), f0, f1);
		}
		if (thi > mid) {
			if (tlo >= mid) {
				addFibo(2*ix + 1, mid, hi, tlo, thi, f0, f1);
			} else {
				ll sf0, sf1;
				skip(f0, f1, mid - tlo, sf0, sf1);
				addFibo(2*ix + 1, mid, hi, mid, thi, sf0, sf1);
			}
		}
		st[ix].s = (justsum(2*ix, lo, mid) + justsum(2*ix+1, mid, hi)) % M9;
	}
}

void push(int ix, int lo, int hi) {
	assert(hi - lo >= 2);
	int mid = (lo + hi) / 2;
	ll f0 = st[ix].f0;
	ll f1 = st[ix].f1;
	if (!f0 && !f1) return;
	st[2*ix].f0 = (st[2*ix].f0 + f0) % M9;
	st[2*ix].f1 = (st[2*ix].f1 + f1) % M9;
	ll sf0, sf1;
	skip(f0, f1, mid - lo, sf0, sf1);
	st[2*ix+1].f0 = (st[2*ix+1].f0 + sf0) % M9;
	st[2*ix+1].f1 = (st[2*ix+1].f1 + sf1) % M9;
	st[ix].f0 = 0;
	st[ix].f1 = 0;
	st[ix].s = (justsum(2*ix, lo, mid) + justsum(2*ix+1, mid, hi)) % M9;
}

ll sum(int ix, int lo, int hi, int tlo, int thi) {
	debugf("sum %d: [%d,%d) > [%d,%d)\n", ix, lo, hi, tlo, thi);
	assert(lo <= tlo);
	assert(tlo < thi);
	assert(thi <= hi);
	if (lo == tlo && hi == thi) {
		ll j = justsum(ix, lo, hi);
		debugf(" %d  just %" PRId64 "\n", ix, j);
		return j;
	} else {
		push(ix, lo, hi);
		ll res = 0;
		int mid = (lo + hi) / 2;
		if (tlo < mid) {
			res += sum(2*ix, lo, mid, tlo, min(thi, mid));
		}
		if (thi > mid) {
			res += sum(2*ix + 1, mid, hi, max(tlo, mid), thi);
		}
		debugf(" %d  res %" PRId64 "\n", ix, res % M9);
		return res % M9;
	}
}

void tc() {
	readInput();
	makeFibo();
	repeat(m) {
		int q;
		scan_d(q);
		if (q == 1) {
			// add
			int lo, hi;
			scan_dd(lo, hi);
			addFibo(1, 0, n, lo - 1, hi, 1, 1);
		} else {
			// sum
			int lo, hi;
			scan_dd(lo, hi);
			printf("%" PRId64 "\n", sum(1, 0, n, lo - 1, hi));
		}
	}
}

int main() { tc(); }