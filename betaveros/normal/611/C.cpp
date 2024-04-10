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

int nRows, nCols;
char grid[888][888];
int hAcc[888][888], vAcc[888][888];

void readInput() {
	scan_dd(nRows, nCols);
	scanf(" ");
	fori (i, 0, nRows) {
		fgets(grid[i], 886, stdin);
	}
}

void tc() {
	readInput();
	fori (r, 0, nRows) {
		fori (c, 0, nCols) {
			if (r != nRows - 1) {
				// down: vertical
				vAcc[r+1][c+1] = (grid[r][c] == '.' && grid[r+1][c] == '.') ? 1 : 0;
			}
			if (c != nCols - 1) {
				// right: horizontal
				hAcc[r+1][c+1] = (grid[r][c] == '.' && grid[r][c+1] == '.') ? 1 : 0;
			}
		}
	}
	fori (r, 1, nRows+2) {
		fori (c, 0, nCols+2) {
			hAcc[r][c] += hAcc[r-1][c];
			vAcc[r][c] += vAcc[r-1][c];
		}
	}
	fori (r, 0, nRows+2) {
		fori (c, 1, nCols+2) {
			hAcc[r][c] += hAcc[r][c-1];
			vAcc[r][c] += vAcc[r][c-1];
		}
	}
	int nQ;
	scan_d(nQ);
	repeat(nQ) {
		int r1, c1, r2, c2;
		scan_dddd(r1, c1, r2, c2);
		r1--; c1--;
		debugf(">  %d\n", +hAcc[r2][c2-1]);
		debugf(">  %d\n", -hAcc[r2][c1]);
		debugf(">  %d\n", -hAcc[r1][c2-1]);
		debugf(">  %d\n", +hAcc[r1][c1]);
		debugf(">  %d\n", +vAcc[r2-1][c2]);
		debugf(">  %d\n", -vAcc[r2-1][c1]);
		debugf(">  %d\n", -vAcc[r1][c2]);
		debugf(">  %d\n", +vAcc[r1][c1]);
		printf("%d\n",
				+hAcc[r2][c2-1]
				-hAcc[r2][c1]
				-hAcc[r1][c2-1]
				+hAcc[r1][c1]
				+vAcc[r2-1][c2]
				-vAcc[r2-1][c1]
				-vAcc[r1][c2]
				+vAcc[r1][c1]
			  );
	}
}

int main() { tc(); }