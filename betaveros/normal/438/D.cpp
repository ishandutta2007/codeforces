// @betaveros :: vim:set fdm=marker syntax=cppc:
// #define NDEBUG
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
// const int       M9  = 1000000009;
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

int seq[100008];

int n, nOps;
void readInput() {
	scan_dd(n, nOps);
	fori (i, 0, n) {
		scan_d(seq[i]);
	}
}

ll s[400008];
int m[400008];
void pull(int ix) {
	s[ix] = s[2*ix] + s[2*ix+1];
	m[ix] = max(m[2*ix], m[2*ix+1]);
}
void makeSums(int ix, int lo, int hi) {
	if (hi - lo == 1) { m[ix] = s[ix] = seq[lo]; return; }

	int mid = (hi + lo + 1) / 2;
	makeSums(2*ix, lo, mid);
	makeSums(2*ix+1, mid, hi);
	pull(ix);
}

void init() {
	makeSums(1, 0, n);
}

ll _query(int ix, int alo, int ahi, int tlo, int thi) {
	assert(alo <= tlo);
	assert(tlo < thi);
	assert(thi <= ahi);
	if (alo == tlo && ahi == thi) return s[ix];
	int mid = (ahi + alo + 1) / 2;
	ll q = 0;
	if (tlo < mid) q += _query(2*ix  , alo, mid, tlo, min(thi, mid));
	if (thi > mid) q += _query(2*ix+1, mid, ahi, max(tlo, mid), thi);
	return q;
}

ll query(int lo, int hi) {
	return _query(1, 0, n, lo, hi);
}

void _doMod(int ix, int alo, int ahi, int tlo, int thi, int mod) {
	assert(alo <= tlo);
	assert(tlo < thi);
	assert(thi <= ahi);
	if (m[ix] < mod) return;
	if (ahi - alo == 1) {
		s[ix] = m[ix] = (s[ix] % mod);
		return;
	}
	int mid = (ahi + alo + 1) / 2;
	if (tlo < mid) _doMod(2*ix  , alo, mid, tlo, min(thi, mid), mod);
	if (thi > mid) _doMod(2*ix+1, mid, ahi, max(tlo, mid), thi, mod);
	pull(ix);
}

void doMod(int lo, int hi, int mod) {
	_doMod(1, 0, n, lo, hi, mod);
}

void _doSet(int ix, int alo, int ahi, int t, int x) {
	assert(alo <= t);
	assert(t < ahi);
	if (ahi - alo == 1) {
		s[ix] = m[ix] = x;
		return;
	}
	int mid = (ahi + alo + 1) / 2;
	if (t < mid) _doSet(2*ix  , alo, mid, t, x);
	else         _doSet(2*ix+1, mid, ahi, t, x);
	pull(ix);
}

void doSet(int k, int x) {
	_doSet(1, 0, n, k, x);
}

void tc() {
	readInput();
	init();
	repeat(nOps) {
		int op;
		scan_d(op);
		int lo, hi, mm;
		switch (op) {
			case 1:
				scan_dd(lo, hi);
				printf("%" PRId64 "\n", query(lo - 1, hi));
				break;
			case 2:
				scan_ddd(lo, hi, mm);
				doMod(lo - 1, hi, mm);
				break;
			case 3:
				int k, x;
				scan_dd(k, x);
				doSet(k - 1, x);
				break;
		}
	}
}

int main() { tc(); }