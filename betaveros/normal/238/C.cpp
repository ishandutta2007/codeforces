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

int n;
vector<uint> graph[3008];
vector<uint> backgraph[3008];
void readInput() {
	scan_d(n);
	repeat(n-1) {
		int a, b;
		scan_dd(a, b);
		graph[(uint)a].pushb(b);
		backgraph[(uint)b].pushb(a);
	}
}

int
	chg[3008], // cost of ruling v's descendants from v
	chg1d[3008]; // (<=0) gain of ruling v's descendants from somewhere below v
void dfs(uint v, uint parent) {
	debugf("dfs enter: %d from %d\n", v, parent);
	chg[v] = 0;
	chg1d[v] = 0;
	foruin (i, graph[v]) {
		uint w = graph[v][i];
		if (w != parent) {
			dfs(w, v);
			chg[v] += chg[w];
			minify(chg1d[v], chg1d[w] + 1);
			debugf("  (%d -> %d saves %d)\n", v, w, chg1d[w]);
		}
	}
	foruin (i, backgraph[v]) {
		uint w = backgraph[v][i];
		if (w != parent) {
			dfs(w, v);
			chg[v] += chg[w] + 1;
			minify(chg1d[v], chg1d[w] - 1);
			debugf("  (%d -> %d saves %d)\n", v, w, chg1d[w]-1);
		}
	}
	debugf("dfs leave: %d from %d\n", v, parent);
	debugf("    chg/1d: %d %d\n", chg[v], chg1d[v]);
}

int minChangeFrom(uint v) {
	debugf("\n-- starting over! --\n\n");
	dfs(v, -1);
	int c = 0;
	fori (i, 1, n+1) {
		if (i != v) {
			minify(c, chg1d[i]);
		}
	}
	return chg[v] + c;
}

void tc() {
	readInput();
	int res = 1 << 30;
	forui (i, 1, n+1) {
		minify(res, minChangeFrom(i));
	}
	printf("%d\n", res);
}

int main() { tc(); }