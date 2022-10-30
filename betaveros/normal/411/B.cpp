// @betaveros :: vim:set fdm=marker:
// #define NDEBUG
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

const int OO  = 1000 << 10;
const int OO2 = 2000 << 10;
const int       M7  = 1000000007;
const int       M9  = 1000000009;
const long long M7L = 1000000007L;
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

int nCores, nTicks, nMemories;
int insts[108][108];
void readInput() {
	scanf("%d%d%d", &nCores, &nTicks, &nMemories);
	fori (i, 1, nCores+1) {
		fori (j, 1, nTicks+1) {
			scanf("%d", &insts[i][j]);
		}
	}
}

int memLock[108];
int memWrites[108];
int coreLock[108];
void tc() {
	readInput();
	fill(memLock, memLock + 108, 0);
	fill(coreLock, coreLock + 108, 0);
	fori (i, 1, nTicks+1) {
		fill(memWrites, memWrites + 108, 0);
		fori (j, 1, nCores+1) {
			if (insts[j][i] == 0) continue;
			if (coreLock[j]) continue;
			if (memLock[insts[j][i]]) {
				coreLock[j] = i;
			}
			if (coreLock[j]) continue;
			memWrites[insts[j][i]]++;
		}
		fori (j, 1, nCores+1) {
			if (insts[j][i] == 0) continue;
			if (coreLock[j]) continue;
			if (memWrites[insts[j][i]] > 1) {
				memLock[insts[j][i]] = i;
				coreLock[j] = i;
			}
		}
	}
	fori (j, 1, nCores+1) printf("%d\n", coreLock[j]);
}

int main() { tc(); }