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

const int NONE = -1337;
int n;
int mg(int a, int b) {
	if (a == NONE || b == NONE || a != b) return NONE;
	return a;
}
ll idCost(int lo, int hi, ll top) {
	// actually is lo+1 to hi, qq
	if (top >= hi) {
		return ((ll) (top - hi) + (top - (lo+1))) * (hi - lo) / 2;
	} else if (top <= lo) {
		return ((ll) (hi - top) + (lo + 1 - top)) * (hi - lo) / 2;
	} else {
		ll lf = top - lo;
		ll rt = hi - top;
		return lf * (lf - 1) / 2 + rt * (rt + 1) / 2;
	}
}
struct ST {
	ll top   [400008];
	ll bc    [400008];
	ll bot   [400008];
	bool hasId[400008];
	ll sum   [400008];
	ST() {
		top[1] = NONE;
		bot[1] = NONE;
		hasId[1] = true;
		bc[1] = 0;
		sum[1] = 0;
	}
	void fillIdCost(int ix, int lo, int hi) {
		assert(hasId[ix]);
		if (bot[ix] == NONE) sum[ix] = 0;
		else sum[ix] = idCost(lo, hi, bot[ix]) + bc[ix] * (hi - lo);
	}
	ll seekSum(int ix, int lo, int hi, ll color, bool force) {
		if (top[ix] == NONE || force) {
			if (hasId[ix]) {
				return idCost(lo, hi, color);
			} else {
				int mid = (lo + hi + 1) / 2;
				return seekSum(2*ix, lo, mid, color, false) + seekSum(2*ix+1, mid, hi, color, false);
			}
		} else {
			return sum[ix] + abs(color - top[ix]) * (hi - lo);
		}
	}
	void push(int ix, int lo, int hi) {
		debugf("    push! %d [%d,%d)\n", ix, lo, hi);
		int mid = (lo + hi + 1) / 2;
		if (hasId[ix]) {
			debugf("    > hasId\n");
			// these nodes were "pristine" before --- overwrite with impunity
			for (int c = 2*ix; c <= 2*ix+1; c++) {
				hasId[c] = true;
				top[c] = top[ix];
				bc [c] = bc [ix];
				bot[c] = bot[ix];
			}
			fillIdCost(2*ix, lo, mid);
			fillIdCost(2*ix + 1, mid, hi);
		} else {
			debugf("    > noid\n");
			if (top[ix] == NONE) {
				debugf("    > lolwat nothing to do\n");
				return;
			}
			int lf = 2*ix, rt = 2*ix + 1;
			if (top[lf] == NONE) {
				top[lf] = top[ix];
				bot[lf] = bot[ix];
				bc [lf] = bc [ix];
				if (hasId[lf]) {
					fillIdCost(lf, lo, mid);
				} else {
					sum[lf] = seekSum(lf, lo, mid, bot[lf], true) + bc[lf] * (mid - lo);
				}
			} else {
				bc [lf] += bc[ix] + abs(bot[ix] - top[lf]);
				sum[lf] += (bc[ix] + abs(bot[ix] - top[lf])) * (mid - lo);
				top[lf] = top[ix];
			}
			if (top[rt] == NONE) {
				top[rt] = top[ix];
				bot[rt] = bot[ix];
				bc [rt] = bc [ix];
				if (hasId[rt]) {
					fillIdCost(rt, mid, hi);
				} else {
					sum[rt] = seekSum(rt, mid, hi, bot[rt], true) + bc[rt] * (hi - mid);
				}
			} else {
				bc [rt] += bc[ix] + abs(bot[ix] - top[rt]);
				sum[rt] += (bc[ix] + abs(bot[ix] - top[rt])) * (hi - mid);
				top[rt] = top[ix];
			}
		}
		hasId[ix] = false;
		top[ix] = NONE;
		bot[ix] = NONE;
		bc [ix] = 0;
		sum[ix] = sum[2*ix] + sum[2*ix + 1];
		debugf("    end push: %d [%d,%d): sum = %" PRId64 "\n", ix, lo, hi, sum[ix]);
	}
	void _paint(int ix, int lo, int hi, int tlo, int thi, ll x) {
		debugf(" _paint(%d, [%d,%d) > [%d,%d) %" PRId64 " )\n", ix, lo, hi, tlo, thi, x);
		assert(lo <= tlo);
		assert(tlo < thi);
		assert(thi <= hi);
		if (lo == tlo && hi == thi) {
			debugf("  match!\n");
			if (top[ix] == NONE) {
				top[ix] = bot[ix] = x;
				bc[ix] = 0;
				sum[ix] = seekSum(ix, lo, hi, x, true);
			} else {
				bc[ix] += abs(top[ix] - x);
				sum[ix] += abs(top[ix] - x) * (hi - lo);
				top[ix] = x;
			}
			if (hasId[ix]) {
				debugf("  id!\n");
				fillIdCost(ix, lo, hi);
			}
		} else {
			assert(hi - lo >= 2);
			push(ix, lo, hi);
			int mid = (lo + hi + 1) / 2;
			if (tlo < mid) {
				_paint(2*ix, lo, mid, tlo, min(thi, mid), x);
			}
			if (thi > mid) {
				_paint(2*ix + 1, mid, hi, max(tlo, mid), thi, x);
			}
			sum[ix] = sum[2*ix] + sum[2*ix + 1];
		}
		debugf(" end_paint(%d, [%d,%d) > [%d,%d) %" PRId64 ", sum = %" PRId64 " )\n", ix, lo, hi, tlo, thi, x, sum[ix]);
	}
	void paint(int lo, int hi, int x) {
		_paint(1, 0, n, lo, hi, x);
	}
	ll _sum(int ix, int lo, int hi, int tlo, int thi) {
		assert(lo <= tlo);
		assert(tlo < thi);
		assert(thi <= hi);
		if (lo == tlo && hi == thi) return sum[ix];
		push(ix, lo, hi);
		int mid = (lo + hi + 1) / 2;
		ll res = 0;
		if (tlo < mid) {
			res += _sum(2*ix, lo, mid, tlo, min(thi, mid));
		}
		if (thi > mid) {
			res += _sum(2*ix+1, mid, hi, max(tlo, mid), thi);
		}
		return res;
	}
	ll getsum(int lo, int hi) {
		return _sum(1, 0, n, lo, hi);
	}
} st;

int m;
void tc() {
	scan_dd(n, m);
	repeat(m) {
		int x;
		scan_d(x);
		if (x == 1) {
			int lo, hi, col;
			scan_ddd(lo, hi, col);
			debugf("inputted %d %d %d\n", lo, hi, col);
			st.paint(lo - 1, hi, col);
		} else {
			assert(x == 2);
			int lo, hi;
			scan_dd(lo, hi);
			printf("%" PRId64 "\n", st.getsum(lo - 1, hi));
		}
	}

}

int main() { tc(); }