// betaveros
#define NDEBUG
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cinttypes>
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

#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define forui(i,s,e) for(unsigned int i = s; i < ((unsigned int)e); i++)
#define _conc(x,y) x ## y
#define _conc2(x,y) _conc(x,y)
#define repeat(n) fori(_conc2(_,__LINE__),0,n)
#define allof(s) (s).begin(), (s).end()
#define debug(code)

template <class T> void dumpBetween(const T & a, const T & b) {
	for (T it = a; it != b; it++) cout << *it << " ";
	cout << endl;
}
template <class T> void dumpAll(const T & a) { dumpBetween(allof(a)); }
template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }

struct Hill {
	long long x;
	long long y;
} hills[100008];

bool canSee(const Hill & from, const Hill & block, const Hill & to) {
	return (to.y - from.y) * (block.x - from.x)
		> (block.y - from.y) * (to.x - from.x);
}

int teams[100008][2];

int nHills, nTeams;
void readInput() {
	scanf("%d", &nHills);
	fori(i, 0, nHills) {
		scanf("%" SCNd64 "%" SCNd64, &hills[i].x, &hills[i].y);
	}
	scanf("%d", &nTeams);
	fori (i, 0, nTeams) {
		scanf("%d %d", &teams[i][0], &teams[i][1]);
	}
}

int parent[100008];
int depth[100008];
int curve[100008]; // indices of hills which form a concave frontier
int curveTop;

void findParents() {
	parent[nHills - 1] = nHills - 1;
	depth[nHills - 1] = 0;
	if (nHills == 1) return;

	curve[0] = (nHills - 1);
	curve[1] = (nHills - 2);
	curveTop = 1;
	parent[nHills - 2] = nHills - 1;
	depth[nHills - 2] = 1;

	for (int i = nHills - 3; i >= 0; i--) {
		// find the rightmost hill (lowest index) that can be seen
		int lo = -1; // not seen (index of curve!)
		int hi = curveTop; // seen
		const Hill & self = hills[i];
		while (hi - lo > 1) {
			int mid = (hi + lo) / 2;
			const Hill & tgt = hills[curve[mid]];
			const Hill & blocker = hills[curve[mid + 1]];
			if (canSee(self, blocker, tgt)) hi = mid;
			else lo = mid;
		}

		// register seen hill
		parent[i] = curve[hi];
		depth[i] = depth[ curve[hi] ] + 1;
		// "pop" all-but-one seen hills
		curveTop = hi + 1;
		curve[curveTop] = i;
	}
}
int xparent[100008][17];
void makeDoubling() {
	fori (i, 0, nHills) {
		xparent[i][0] = parent[i];
	}
	fori (x, 1, 17) {
		fori (i, 0, nHills) {
			xparent[i][x] = xparent[ xparent[i][x-1] ][x-1];
		}
	}
	// that was easy
}
int nthParent(int a, int n) {
	while (n) {
		int x = __builtin_ctz(n);
		a = xparent[a][x];
		n = n & ~(1<<x);
	}
	return a;
}
int lca(int a, int b) {
	debug(printf("lca of %d, %d\n", a, b);)
	debug(printf("depths: %d, %d\n", depth[a], depth[b]);)
	if (depth[a] < depth[b]) swap(a, b);
	if (depth[a] > depth[b]) {
		a = nthParent(a, depth[a] - depth[b]);
	}
	// now a and b are same level
	assert(depth[a] == depth[b]);
	if (a == b) return a;
	for (int x = 16; x >= 0; x--) {
		if (xparent[a][x] != xparent[b][x]) {
			a = xparent[a][x];
			b = xparent[b][x];
		}
	}
	assert(a != b);
	assert(parent[a] == parent[b]);
	return parent[a];
}
void solve() {
	fori (i, 0, nTeams) {
		// oops, we'll have to do the index adjustments here...
		if (i != 0) printf(" ");
		printf("%d", lca(teams[i][0]-1, teams[i][1]-1)+1);
	}
	printf("\n");
}

void tc() {
	readInput();
	findParents();
	makeDoubling();
	solve();
}

int main() { tc(); }