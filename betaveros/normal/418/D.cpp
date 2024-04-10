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

const int N = 100008;
Vint graph[N];
int n;
int queries[N][2];
int nQueries;
void readInput() {
	scan_d(n);
	repeat(n-1) {
		int x, y;
		scan_dd(x, y);
		graph[x].pushb(y);
		graph[y].pushb(x);
	}
	scan_d(nQueries);
	fori (i, 0, nQueries) {
		scan_dd(queries[i][0], queries[i][1]);
	}
}

int parent[N];
int depth[N];
int maxDepth[N];
int secondMaxDepth[N];
int thirdMaxDepth[N];
int xparent[N][18];

// max distance from v,
// turning from path between v and 2^kth ancestor
// somewhere beetween v (exclusive) and ancestor (inclusive)
int maxBottomSideDistance[N][18];

// max distance from v's 2^kth ancestor,
// turning from path between v and 2^kth ancestor
// somewhere beetween v (exclusive) and ancestor (inclusive)
int maxTopSideDistance[N][18];

void dfs(int v, int p) {
	if (v != 1) {
		depth[v] = 1 + depth[p];
	}
	maxDepth[v] = depth[v];
	secondMaxDepth[v] = depth[v];
	thirdMaxDepth[v] = depth[v];
	parent[v] = p;
	foruin (i, graph[v]) {
		int w = graph[v][i];
		if (w == p) continue;
		dfs(w, v);
		if (maxDepth[w] >= maxDepth[v]) {
			thirdMaxDepth[v] = secondMaxDepth[v];
			secondMaxDepth[v] = maxDepth[v];
			maxDepth[v] = maxDepth[w];
		} else if (maxDepth[w] >= secondMaxDepth[v]) {
			thirdMaxDepth[v] = secondMaxDepth[v];
			secondMaxDepth[v] = maxDepth[w];
		} else maxify(thirdMaxDepth[v], maxDepth[w]);
	}
}
void makeXparent() {
	fori (i, 1, n+1) xparent[i][0] = parent[i];
	fori (x, 1, 18) {
		fori (i, 1, n+1) xparent[i][x] = xparent[ xparent[i][x-1] ][x-1];
	}
}
void makeSides() {
	maxBottomSideDistance[1][0] = 0;
	maxTopSideDistance[1][0] = 0;
	fori (v, 2, n+1) {
		int otherDepth =
			(maxDepth[v] == maxDepth[parent[v]]
				? secondMaxDepth[parent[v]]
				: maxDepth[parent[v]]);
		maxBottomSideDistance[v][0] = otherDepth - depth[parent[v]] + 1;
		maxTopSideDistance[v][0] = otherDepth - depth[parent[v]];
	}
	fori (x, 1, 18) {
		debugf("making sides --- x = %d\n", x);
		fori (v, 2, n+1) {
			debugf("   v=%d\n", v);
			int & b = maxBottomSideDistance[v][x];
			b = maxBottomSideDistance[v][x-1];
			if (depth[v] >= (1 << (x-1))) {
				// the ancestor exists!
				maxify(b,
					maxBottomSideDistance[ xparent[v][x-1] ][x-1]
						+ (1 << (x-1)));

				maxTopSideDistance[v][x] = max(
					maxTopSideDistance[ xparent[v][x-1] ][x-1],
					(1 << (x-1)) + maxTopSideDistance[v][x-1]);
			}
			debugf("        bottomside: %d\n", maxBottomSideDistance[v][x]);
			debugf("        topside: %d\n", maxTopSideDistance[v][x]);
		}
	}
}
int maxDepthOtherThanTwo(int v, int d1, int d2) {
	if (d1 == maxDepth[v]) {
		if (d2 == secondMaxDepth[v]) return thirdMaxDepth[v];
		return secondMaxDepth[v];
	}
	if (d2 == maxDepth[v]) {
		if (d1 == secondMaxDepth[v]) return thirdMaxDepth[v];
		return secondMaxDepth[v];
	}
	return maxDepth[v];
}
int nthParent(int a, int k) {
	fori (i, 0, 18) {
		if ((1<<i) & k) a = xparent[a][i];
	}
	return a;
}
int lcalc(int a, int b, int & da, int & db) {
	da = 0;
	db = 0;
	if (depth[a] > depth[b]) {
		da = depth[a] - depth[b];
		a = nthParent(a, da);
	}
	if (depth[b] > depth[a]) {
		db = depth[b] - depth[a];
		b = nthParent(b, db);
	}
	assert(depth[a] == depth[b]);
	if (a == b) { return a; }
	for (int i = 17; i >= 0; i--) {
		if (xparent[a][i] != xparent[b][i]) {
			a = xparent[a][i];
			b = xparent[b][i];
			da += 1 << i;
			db += 1 << i;
		}
	}
	assert(parent[a] == parent[b]);
	da += 1;
	db += 1;
	return parent[a];
}
int calcMaxBottomSideDistance(int v, int dist) {
	int res = 0;
	int s = 0;
	fori (i, 0, 18) {
		if ((1<<i) & dist) {
			maxify(res, s + maxBottomSideDistance[v][i]);
			s += (1<<i);
			v = xparent[v][i];
		}
	}
	return res;
}
int calcMaxTopSideDistance(int v, int dist) {
	int res = 0;
	int s = dist;
	fori (i, 0, 18) {
		if ((1<<i) & dist) {
			s -= (1<<i);
			debugf("  calcMaxTopSideDistance @ %d -> s = %d\n", i, s);
			maxify(res, s + maxTopSideDistance[v][i]);
			v = xparent[v][i];
		}
	}
	return res;
}
struct Maxer {
	int result;
	Maxer(): result(0) {}
	void operator()(const char * msg, int r) {
		debugf("  %s -> %d\n", msg, r);
		maxify(result, r);
	}
	int operator()() { return result; }
};
int answer(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);
	debugf("answering %d=shallow %d=deeper\n", a, b);
	int da, db;
	int lca = lcalc(a, b, da, db);
	assert(da <= db);
	int dh = (da + db) / 2;
	int midb = nthParent(b, dh);
	debugf("(lca: %d; da = %d, db = %d)\n", lca, da, db);
	debugf("dh = %d | midb = %d\n", dh, midb);
	Maxer res;
	if (lca == a) {
		res("down from b", maxDepth[b] - depth[b]);
		res("up from b"  , calcMaxBottomSideDistance(b, dh));
		res("down from a", calcMaxTopSideDistance(midb, da + db - dh));
		res("up from a"  , calcMaxBottomSideDistance(a, depth[a]));
	} else {
		res("down from a", maxDepth[a] - depth[a]);
		res("down from b", maxDepth[b] - depth[b]);
		res("up from b", calcMaxBottomSideDistance(b, (da == db ? dh - 1 : dh)));
		res("up from a before lca", calcMaxBottomSideDistance(a, da-1));
		if (da < db - 1) {
			res("up from a then down past lca into b's subtree", da + 1 + calcMaxTopSideDistance(midb, depth[midb] - depth[lca] - 1));
		}
		res("up from a then down past lca, not into b's subtree", da + maxDepthOtherThanTwo(lca, maxDepth[nthParent(a, da-1)], maxDepth[nthParent(b, db-1)]) - depth[lca]);
		res("up from a then up past lca", da + calcMaxBottomSideDistance(lca, depth[lca]));
	}
	return res();
}

void tc() {
	readInput();
	depth[1] = 0;
	dfs(1, 1);
	makeXparent();
	makeSides();
	fori (i, 0, nQueries) {
		printf("%d\n", answer(queries[i][0], queries[i][1]));
	}
}

int main() { tc(); }