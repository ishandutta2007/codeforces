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

int n, m;
int a[1008][1008]; ll dp[4][1008][1008];

void readInput() {
	scan_dd(n, m);
	fori0 (i, n) fori0 (j, m) scan_d(a[i][j]);
}

void go(int dpi, int is, int ie, int ib, int js, int je, int jb) {
	for (int i = is; i != ie; i += ib) {
		for (int j = js; j != je; j += jb) {
			ll t = 0;
			if (i != is) maxify(t, dp[dpi][i - ib][j]);
			if (j != js) maxify(t, dp[dpi][i][j - jb]);
			dp[dpi][i][j] = t + a[i][j];
		}
	}
}

void tc() {
	readInput();
	go(0, 0, n, 1, 0, m, 1);
	go(1, n-1, 0, -1, 0, m, 1);
	go(2, 0, n, 1, m-1, 0, -1);
	go(3, n-1, 0, -1, m-1, 0, -1);
	ll best = 0;
	fori (i, 1, n - 1) fori (j, 1, m - 1) {
		maxify(best,
				dp[0][i-1][j] + dp[3][i+1][j]
				+
				dp[1][i][j-1] + dp[2][i][j+1]);
		maxify(best,
				dp[0][i][j-1] + dp[3][i][j+1]
				+
				dp[1][i+1][j] + dp[2][i-1][j]);
	}
	printf("%" PRId64 "\n", best);
}

int main() { tc(); }