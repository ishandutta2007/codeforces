// @betaveros :: vim:set fdm=marker syntax=cppc:
// #define NDEBUG
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


//
//
// b c       d
// d c       b
// d b       c
// c b       d

const int N = 300008;
int n;
int p[N];
int pinv[N];

void readInput() {
	scan_d(n);
	fori (i, 1, n+1) {
		scan_d(p[i]);
		pinv[p[i]] = i;
	}
}

vector<pair<int, int>> swaps;

int myabs(int a) {
	return a < 0 ? -a : a;
}

void doSwap(int i, int j) {
	assert(myabs(i - j) >= n/2);
	assert(pinv[p[i]] == i);
	assert(pinv[p[j]] == j);
	swap(p[i], p[j]);
	pinv[p[i]] = i;
	pinv[p[j]] = j;
	swaps.push_back(make_pair(i, j));
}

void doSwapStrategy(int i, int j) {
	if (myabs(i - j) >= n/2) {
		doSwap(i, j);
	} else if (i <= n/2 && j <= n/2) {
		doSwap(i, n);
		doSwap(j, n);
		doSwap(i, n);
	} else if (i > n/2 && j > n/2) {
		doSwap(i, 1);
		doSwap(j, 1);
		doSwap(i, 1);
	} else {
		if (i > j) swap(i, j);
		assert(i <= n/2);
		assert(j > n/2);
		// a     b c      d
		// c     b a      d
		// c     d a      b
		// b     d a      c
		// a     d b      c
		// a     c b      d
		doSwap(1, j);
		doSwap(i, n);
		doSwap(1, n);
		doSwap(1, j);
		doSwap(i, n);
	}
}

void tc() {
	readInput();

	fori (i, 1, n+1) {
		// make p[i] == i)
		if (p[i] != i) {
			int j = pinv[i];
			assert(j > i);
			doSwapStrategy(i, j);
		}
	}

	fori (i, 1, n+1) {
		assert(p[i] == i);
	}

	printf("%lu\n", swaps.size());
	foruin (i, swaps) {
		printf("%d %d\n", swaps[i].first, swaps[i].second);
	}
}

int main() { tc(); }