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

const ll OO = 1LL << 62LL;

int nFriends, nProblems, monitorCost;
struct Friend {
	int cost;
	int mreq;
	int mask;
	bool operator<(const Friend & o) const {
		return mreq < o.mreq;
	}
} friends[108];
void readInput() {
	scan_ddd(nFriends, nProblems, monitorCost);
	fori (i, 0, nFriends) {
		int m = 0;
		int nSolves;
		scan_ddd(friends[i].cost, friends[i].mreq, nSolves);
		repeat(nSolves) {
			int x;
			scan_d(x);
			m |= (1<<(x-1));
		}
		friends[i].mask = m;
	}
}

ll pay[1100000];
void tc() {
	readInput();
	sort(friends, friends + nFriends);

	debugf("friends: %d\n", nFriends);

	// init
	pay[0] = 0;
	fori (m, 1, 1<<nProblems) {
		pay[m] = OO;
	}

	ll best = OO;
	fori (i, 0, nFriends) {
		debugf("adding friend: %d\n", i);
		ll fmreq = friends[i].mreq;
		int fm = friends[i].mask;
		ll fc = friends[i].cost;
		fori (m, 1, 1<<nProblems) {
			pay[m] = min(pay[m], pay[m&~fm] + fc);
			debugf("  m=%d, pay[m]=%" PRId64 "\n", m, pay[m]);
		}
		minify(best, pay[(1<<nProblems)-1] + fmreq * (ll)monitorCost);
	}
	if (best == OO) {
		printf("-1\n");
	} else {
		printf("%" PRId64 "\n", best);
	}
}

int main() { tc(); }