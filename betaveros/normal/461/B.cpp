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

int n;
const int N = 100008;
int p[N];
int x[N];
ll dp0[N], dp1[N];
vector<int> children[N];
void readInput() {
	scan_d(n);
	fori (i, 1, n) {
		scan_d(p[i]);
		children[p[i]].push_back(i);
	}
	fori (i, 0, n) scan_d(x[i]);
}

void go(int v) {
	if (x[v]) {
		// black
		dp0[v] = 0;
		ll t0 = 1;
		for (int w : children[(uint)v]) {
			t0 = t0 * (dp0[w] + dp1[w]) % M7L;
		}
		dp1[v] = t0;
	} else {
		// white
		ll t0 = 1;
		ll t1 = 0;
		for (int w : children[(uint)v]) {
			t1 = (t1 * (dp0[w] + dp1[w]) + t0 * dp1[w]) % M7L;
			t0 = t0 * (dp0[w] + dp1[w]) % M7L;
		}
		dp0[v] = t0;
		dp1[v] = t1;
	}
	debugf("%d [0] %" PRId64 " [1] %" PRId64 "\n", v, dp0[v], dp1[v]);
}

void tc() {
	readInput();
	for (int i = n - 1; i >= 0; i--) go(i);
	printf("%" PRId64 "\n", dp1[0]);
}

int main() { tc(); }