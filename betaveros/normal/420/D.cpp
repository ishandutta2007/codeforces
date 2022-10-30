// @betaveros :: vim:set fdm=marker syntax=cppc:
#define NDEBUG
// #includes, using namespace std {{{
#include <cstdio>
#include <cstdlib>
#include <ctime>
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

// const int OO  = 1000 << 10;
// const int OO2 = 2000 << 10;
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

const int T6 = 1000008;
uint rr;
struct Treap {
	Treap * lc;
	Treap * rc;
	int sz;
	int ip; // initial pos
	uint pri;
	int mark;
	Treap() {}
	Treap(int ip): lc(NULL), rc(NULL), sz(1), ip(ip), pri(rr = 0xdefaced * rr + 1), mark(-1) {}
	static Treap mem[T6], *pmem;
} Treap::mem[T6], *Treap::pmem = Treap::mem;

Treap * make (int ip) {
	return new (Treap::pmem++) Treap(ip);
}

int sz(Treap * t) { return t ? t->sz : 0; }
void pull(Treap * t) { if (t) t->sz = sz(t->lc) + sz(t->rc) + 1; }

Treap * merge(Treap * a, Treap * b) {
	if (!a) return b; if (!b) return a;
	if (a->pri < b->pri) {
		a->rc = merge(a->rc, b);
		pull(a);
		return a;
	} else {
		b->lc = merge(a, b->lc);
		pull(b);
		return b;
	}
}
void split(Treap * t, int k, Treap * & a, Treap * & b) {
	debugf("< splitting t (sz = %d) to %d >\n", sz(t), k);
	if (!t) {a = b = NULL; return;}
	if (sz(t->lc) >= k) {
		b = t;
		split(t->lc, k, a, b->lc);
	} else {
		a = t;
		split(t->rc, k - sz(t->lc) - 1, a->rc, b);
	}
	pull(a);
	pull(b);
}

int n, m;
Treap * buildTreap() {
	Treap * t = NULL;
	fori (i, 1, n+1) {
		t = merge(t, make(i));
	}
	return t;
}
int opmark[T6], oppos[T6];
void readInput() {
	scan_dd(n, m);
	fori (i, 0, m) {
		scan_dd(opmark[i], oppos[i]);
	}
}
int ans[T6];
bool seen[T6];
void store(Treap * t) {
	if (t) {
		ans[t->ip] = t->mark;
		store(t->lc);
		store(t->rc);
	}
}

void tc() {
	readInput();
	Treap * t = buildTreap();
	fori (i, 0, m) {
		debugf("i = %d\n", i);
		Treap * lf, * rt;
		split(t, oppos[i] - 1, lf, t);
		debugf("lf = %d\n", sz(lf));
		split(t, 1, t, rt);
		debugf("t = %d\n", sz(t));
		debugf("rt = %d\n", sz(rt));
		assert(sz(t) == 1);
		if (t->mark != opmark[i]) {
			if (t->mark == -1) {
				t->mark = opmark[i];
			} else {
				printf("-1\n");
				return;
			}
		}
		t = merge(t, merge(lf, rt));
	}
	store(t);
	fill(seen, seen + T6, false);
	fori (i, 1, n+1) {
		if (ans[i] != -1) {
			if (seen[ans[i]]) {
				printf("-1\n");
				return;
			}
			seen[ans[i]] = true;
		}
	}
	int si = 1;
	fori (i, 1, n+1) {
		if (ans[i] == -1) {
			while (si <= n && seen[si] == true) {si++;}
			assert(si <= n);
			ans[i] = si;
			si++;
		}
	}
	fori (i, 1, n+1) {
		if (i != 1) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}

int main() {
	rr = time(0);
	tc();
}