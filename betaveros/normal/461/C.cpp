// @betaveros :: vim:set fdm=marker syntax=cppc:
#define NDEBUG
// #includes, using namespace std {{{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
// #include <cinttypes> // C++11?
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

const int N = 100008;
int a[N];
int n, q;
int rlo, d, rlen;
const int SN = 400008;
struct Seg {
	int s[SN];
	void build(int ix, int lo, int hi) {
		assert(lo < hi);
		if (hi - lo == 1) s[ix] = 1;
		else {
			int mid = (lo + hi) / 2;
			build(2*ix  , lo, mid);
			build(2*ix+1, mid, hi);
			s[ix] = s[2*ix] + s[2*ix+1];
		}
	}
	void init(int nn) {
		build(1, 0, nn);
	}
	void _chg(int ix, int lo, int hi, int t, int val) {
		assert(lo <= t); assert(t < hi);
		if (hi - lo == 1) {
			s[ix] += val;
		} else {
			int mid = (lo + hi) / 2;
			if (t < mid) _chg(2*ix, lo, mid, t, val);
			else _chg(2*ix+1, mid, hi, t, val);
			s[ix] = s[2*ix] + s[2*ix+1];
		}
	}
	void chg(int t, int val) {
		_chg(1, 0, n, t, val);
	}
	int _get(int ix, int lo, int hi, int tlo, int thi) {
		assert(lo <= tlo); assert(tlo < thi); assert(thi <= hi);
		if (lo == tlo && hi == thi) return s[ix];

		int mid = (lo + hi) / 2;
		int ret = 0;
		if (tlo < mid) ret += _get(2*ix, lo, mid, tlo, min(thi, mid));
		if (thi > mid) ret += _get(2*ix+1, mid, hi, max(tlo, mid), thi);
		return ret;
	}
	int get(int tlo, int thi) {
		debugf("  in seg %d %d\n", tlo, thi);
		return _get(1, 0, n, tlo, thi);
	}
	int get1(int t) {
		return get(t, t + 1);
	}
} seg;

void readInput() {
	scan_dd(n, q);
	seg.init(n);
	rlo = 0;
	rlen = n;
	d = 1;
}

void tc() {
	readInput();
	repeat (q) {
		int op;
		scan_d(op);
		if (op == 1) {
			int cut;
			scan_d(cut);
			debugf("cutting %d\n", cut);
			if (2 * cut > rlen) {
				for (int i = 0; i < rlen - cut; i++) {
					seg.chg(rlo + (cut - i - 1) * d, seg.get1(rlo + (cut + i) * d));
				}
				rlen = cut;
				rlo = rlo + (rlen - 1) * d;
				d *= -1;
			} else {
				for (int i = 0; i < cut; i++) {
					seg.chg(rlo + (cut + i) * d, seg.get1(rlo + (cut - i - 1) * d));
				}
				rlen -= cut;
				rlo += cut * d;
			}
			debugf("rlo = %d, rlen = %d, d = %d\n", rlo, rlen, d);
			debug(
					fori (i, 0, n) printf("%d;", seg.get1(i));
					printf("\n");
				  )
		} else {
			assert(op == 2);
			int qlo, qhi;
			scan_dd(qlo, qhi);
			debugf("getting %d %d\n", qlo, qhi);
			if (d == 1) {
				printf("%d\n", seg.get(rlo + qlo, rlo + qhi));
			} else {
				printf("%d\n", seg.get(rlo - qhi + 1, rlo - qlo + 1));
			}
		}
	}
}

int main() { tc(); }