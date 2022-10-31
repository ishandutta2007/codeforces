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

const int OO  = 1000 << 20;
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

const int MAXN = 1008;
int nRows, nCols, minRun, maxRun;
char grid[MAXN][MAXN];
void readInput() {
	scanf("%d%d%d%d ", &nRows, &nCols, &minRun, &maxRun);
	for (int i = 0; i < nRows; i++) {
		fgets(grid[i], MAXN, stdin);
		// printf("read %s\n", grid[i]);
	}
}

int blackness[MAXN];

int cost(int col, int color) {
	assert(color == 0 || color == 1);
	if (color == 0) {
		// white
		return blackness[col];
	} else {
		// black
		return nRows - blackness[col];
	}
}

int dp[MAXN][MAXN][2]; // [lastpos][run][color]

int main() {
	readInput();
	for (int i = 0; i < nCols; i++) {
		for (int j = 0; j < nRows; j++) {
			// printf("%d %d %c\n", i, j, grid[i][j]);
			assert(
					grid[j][i] == '.' ||
					grid[j][i] == '#');
			blackness[i] += (grid[j][i] == '#');
		}
	}

	// initial
	for (int color = 0; color < 2; color++) {
		dp[0][1][color] = cost(0, color);
		for (int run = 2; run <= maxRun; run++) {
			dp[0][run][color] = OO;
		}
	}

	// next
	for (int col = 1; col < nCols; col++) {
		for (int color = 0; color < 2; color++) {
			// run = 1
			dp[col][1][color] = OO;
			for (int from = minRun; from <= maxRun; from++) {
				int c = dp[col-1][from][!color] + cost(col, color);
				if (c < dp[col][1][color]) dp[col][1][color] = c;
			}
			for (int run = 2; run <= maxRun; run++) {
				dp[col][run][color] =
					min(dp[col - 1][run - 1][color] + cost(col, color), OO);
			}
		}
	}
	int answer = OO;
	for (int finalRun = minRun; finalRun <= maxRun; finalRun++) {
		for (int color = 0; color < 2; color++) {
			answer = min(answer, dp[nCols - 1][finalRun][color]);
		}
	}
	printf("%d\n", answer);
}