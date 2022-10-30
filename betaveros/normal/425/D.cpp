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

int n;
vector<int> xofy[100008], yofx[100008];
vector<pair<int,int> > pts;
void readInput() {
	scan_d(n);
	repeat (n) {
		int x, y;
		scan_dd(x, y);
		xofy[y].push_back(x);
		yofx[x].push_back(y);
		pts.push_back(make_pair(x, y));
	}
}
bool in(int needle, const vector<int> & haystack) {
	const vector<int>::const_iterator it = lower_bound(allof(haystack), needle);
	return it != haystack.end() && *it == needle;
}

void tc() {
	readInput();
	sort(allof(pts));
	fori (i, 0, 100001) {
		sort(allof(xofy[i]));
		sort(allof(yofx[i]));
	}
	ll sqs = 0;
	while (!pts.empty()) {
		int x = pts.back().first;
		int y = pts.back().second;
		pts.pop_back();
		assert(yofx[x].back() == y);
		assert(xofy[y].back() == x);
		yofx[x].pop_back();
		xofy[y].pop_back();
		int eqxs = (int) yofx[x].size();
		int eqys = (int) xofy[y].size();
		if (eqxs < eqys) {
			fori0 (i, eqxs) {
				int oy = yofx[x][(unsigned)i];
				int ox = x - (y - oy);
				if (in(ox, xofy[y]) && in(ox, xofy[oy])) {
					sqs++;
				}
			}
		} else {
			fori0 (i, eqys) {
				int ox = xofy[y][(unsigned)i];
				int oy = y - (x - ox);
				if (in(oy, yofx[x]) && in(oy, yofx[ox])) {
					sqs++;
				}
			}
		}
	}
	printf("%" PRId64 "\n", sqs);
}

int main() { tc(); }