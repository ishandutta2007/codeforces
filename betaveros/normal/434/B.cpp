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

int n, m, q;
bool a[1008][1008];

int nl[1008][1008];
int nr[1008][1008];
int nu[1008][1008];
int nd[1008][1008];
void readInput() {
	scan_ddd(n, m, q);
	fori (i, 1, n+1) {
		fori (j, 1, m+1) {
			int x;
			scan_d(x);
			a[i][j] = x;
		}
	}
}

void makeRow(int i) {
	nl[i][1] = a[i][1];
	fori (j, 2, m+1) {
		nl[i][j] = a[i][j] ? (1 + nl[i][j-1]) : 0;
	}
	nr[i][m] = a[i][m];
	for (int j = m - 1; j >= 1; j--) {
		nr[i][j] = a[i][j] ? (1 + nr[i][j+1]) : 0;
	}
}
void makeCol(int c) {
	nu[1][c] = a[1][c];
	fori (j, 2, n+1) {
		nu[j][c] = a[j][c] ? (1 + nu[j-1][c]) : 0;
	}
	nd[n][c] = a[n][c];
	for (int j = n - 1; j >= 1; j--) {
		nd[j][c] = a[j][c] ? (1 + nd[j+1][c]) : 0;
	}
}

void make() {
	fori (i, 1, n+1) { makeRow(i); }
	fori (i, 1, m+1) { makeCol(i); }
}

void tc() {
	readInput();
	make();
	repeat (q) {
		int qt;
		scan_d(qt);
		int r, c;
		scan_dd(r, c);
		if (qt == 1) {
			a[r][c] = !a[r][c];
			makeRow(r);
			makeCol(c);
		} else {
			int best = 0;
			int lf = 1000 << 20, rt = 1000 << 20;
			for (int rr = r; rr <= n; rr++) {
				minify(lf, nl[rr][c]);
				minify(rt, nr[rr][c]);
				if (!(lf && rt)) break;
				maxify(best, (rr - r + 1) * (rt + lf - 1));
			}
			lf = 1000 << 20; rt = 1000 << 20;
			for (int rr = r; rr >= 1; rr--) {
				minify(lf, nl[rr][c]);
				minify(rt, nr[rr][c]);
				if (!(lf && rt)) break;
				maxify(best, (r - rr + 1) * (rt + lf - 1));
			}
			lf = 1000 << 20; rt = 1000 << 20;
			for (int cc = c; cc <= m; cc++) {
				minify(lf, nu[r][cc]);
				minify(rt, nd[r][cc]);
				if (!(lf && rt)) break;
				maxify(best, (cc - c + 1) * (rt + lf - 1));
			}
			lf = 1000 << 20; rt = 1000 << 20;
			for (int cc = c; cc >= 1; cc--) {
				minify(lf, nu[r][cc]);
				minify(rt, nd[r][cc]);
				if (!(lf && rt)) break;
				maxify(best, (c - cc + 1) * (rt + lf - 1));
			}
			printf("%d\n", best);
		}
	}
}

int main() { tc(); }