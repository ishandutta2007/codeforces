// @betaveros :: vim:set fdm=marker:
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
const long long M7L = 1000000007L;
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

const int N = 222228;
ll fact[N], invfact[N];

long long mod(long long x) {
	ll y = x % M7L;
	return y < 0 ? y + M7L : y;
}
long long inv(long long a) {
	return a == 1 ? 1 : mod(inv(M7L % a) * (M7L - M7L/a));
}
void prep() {
	fact[0] = 1;
	invfact[0] = 1;
	fori (i, 1, N) {
		fact[i] = mod(fact[i-1] * i);
		invfact[i] = inv(fact[i]);
	}
}
ll walk(int rs, int cs) {
	return mod(mod(fact[rs + cs] * invfact[rs]) * invfact[cs]);
}
int h, w, n;
struct Pt {
	int r; int c;
	bool operator<(const Pt & o) const {
		if (r != o.r) return r < o.r;
		return c < o.c;
	}
};
vector<Pt> pts;
void readInput() {
	scan_ddd(h, w, n);
	repeat(n) {
		int r, c;
		scan_dd(r, c);
		pts.push_back((Pt){ .r = r - 1, .c = c - 1 });
	}
}
ll ssol[N];

void tc() {
	prep();
	readInput();
	sort(allof(pts));
	pts.push_back((Pt){ .r = h - 1, .c = w - 1 });
	for (size_t i = 0; i < pts.size(); i++) {
		const Pt & pt = pts[i];
		ll acc = walk(pt.r, pt.c);
		for (size_t j = 0; j < i; j++) {
			const Pt & ot = pts[j];
			if (ot.r <= pt.r && ot.c <= pt.c) {
				acc = mod(acc - mod(ssol[j] * walk(pt.r - ot.r, pt.c - ot.c)));
			}
		}
		ssol[i] = acc;
	}
	/*
	for (Pt & p : pts) {
		fprintf(stderr, "%d,%d\n", p.r, p.c);
	}
	*/
	printf("%" PRId64 "\n", ssol[n]);
}

int main() { tc(); }