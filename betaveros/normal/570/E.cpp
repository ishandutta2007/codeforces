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
const int       M7  = 1000000007;
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
char grid[508][508];
int ways[2][508][508];
int wb = 0;
// i + j or n + m - i - j - 2, i, n - 1 - i

void readInput() {
	scan_dd(n, m);
	scanf(" ");
	fori (i, 0, n) {
		fgets(grid[i], 888, stdin);
	}
}

char get(int i, int j) {
	if (0 <= i && i < n && 0 <= j && j < m) {
		return grid[i][j];
	}
	return '\0';
}
bool match(int s, int ai, int aj) {
	char a = get(ai, s - ai);
	// s = n + m - i - j - 2;
	// aj = n - 1 - i
	// m - 1 - i = s - aj
	char b = get(n - 1 - aj, m - 1 - s + aj);
	return a == b && a != '\0';
}
int getWays(/*int s,*/int i, int j) {
	if (
			/*0 <= s && s < 508 &&*/
			0 <= i && i < 508
			&&
			0 <= j && j < 508
			) {
		return ways[!wb][i][j];
	}
	return 0;
}

int solve() {
	if (grid[0][0] != grid[n-1][m-1]) return 0;
	ways[wb][0][0] = 1;
	int hs = (n + m - 2) / 2;
	for (int s = 1; s <= hs; s++) {
		wb = !wb;
		for (int i = 0; i <= s; i++) {
			for (int j = 0; j <= s; j++) {
				if (match(s, i, j)) {
					int x = 0;
					for (int di = -1; di <= 0; di++) {
						for (int dj = -1; dj <= 0; dj++) {
							x += getWays(/*s-1,*/i+di, j+dj);
							x %= M7;
						}
					}
					ways[wb][i][j] = x;
					debugf("%d (%d) %d %d: %d\n", s, wb, i, j, x);
				} else {
					ways[wb][i][j] = 0;
				}
			}
		}
	}
	int res = 0;
	wb = !wb;
	if ((n + m) % 2 == 0) {
		// there is a center element
		fori (i, 0, n) {
			res += getWays(i, n-1-i);
			res %= M7;
		}
	} else {
		// there are two center elements
		fori (i, 0, n) {
			res += getWays(i, n-1-i);
			res %= M7;
			res += getWays(i, n-2-i);
			res %= M7;
		}
	}
	return res;
}

void tc() {
	readInput();
	printf("%d\n", solve());
}

int main() { tc(); }