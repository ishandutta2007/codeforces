// @betaveros :: vim:set fdm=marker:
#define NDEBUG
// #includes, using namespace std {{{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
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
#define pushb push_back
#define popb push_back

#ifdef NDEBUG
#define debug(code)
#else
#define debug(code) code
#endif
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> Vint;
typedef vector<int>::iterator Vit;

// const int OO  = 1000 << 10;
// const int OO2 = 2000 << 10;
const int       T5  = 100008;
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

Vint graph[T5];

int n, m;
void readInput() {
	scanf("%d%d", &n, &m);
	repeat(m) {
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].pushb(b);
		graph[b].pushb(a);
	}
}

bool vis[T5];
int dfn[T5];
int dfnt = 0;
int dfsDegree(int v) {
	if (vis[v]) return 0;
	vis[v] = true;
	int ret = (int) graph[v].size();
	foruin (i,graph[v]) {
		ret += dfsDegree(graph[v][i]);
	}
	return ret;
}
Vint sol[T5];
bool dfsSolve(int v, int parent) {
	// return true if we want our parent to take care of the parent edge
	if (dfn[v] != -1) return parent == -1 ? false : dfn[parent] < dfn[v];
	dfn[v] = dfnt++;
	foruin (i,graph[v]) {
		if (graph[v][i] == parent) continue;
		if (dfsSolve(graph[v][i], v)) {
			sol[v].push_back(graph[v][i]);
		}
	}
	if (sol[v].size() % 2 != 0) {
		assert(parent != -1);
		sol[v].push_back(parent);
		return false;
	}
	return true;
}

void solve() {
	fill(vis, vis + T5, false);
	fori (i, 1, n+1) {
		int d = dfsDegree(i);
		if (d % 4 != 0) {
			printf("No solution\n");
			return;
		}
	}
	fill(dfn, dfn + T5, -1);
	fori (i, 1, n+1) {
		dfsSolve(i, -1);
		uint sn = (uint)(sol[i].size());
		assert(sn % 2 == 0);
		forui (j, 0, sn/2) {
			printf("%d %d %d\n", sol[i][2*j], i, sol[i][2*j+1]);
		}
	}
}

void tc() {
	readInput(); solve();
}

int main() { tc(); }