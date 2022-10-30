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

int nDays, nGadgets, reqGadgets;
ll money;
ll ac[200008], bc[200008];
struct Gadget {
	int id;
	ll cost;
	bool operator<(const Gadget & o) const {
		return cost < o.cost;
	}
};
vector<Gadget> ag, bg;

void readInput() {
	scan_ddd(nDays, nGadgets, reqGadgets);
	scanf("%" SCNd64, &money);
	fori (i, 0, nDays) { scanf("%" SCNd64, &ac[i]); }
	fori (i, 0, nDays) { scanf("%" SCNd64, &bc[i]); }
	fori (i, 0, nGadgets) {
		int typ;
		ll c;
		scan_d(typ);
		scanf("%" SCNd64, &c);
		if (typ == 1) {
			ag.push_back((Gadget) { .id = i + 1, .cost = c });
		} else {
			assert(typ == 2);
			bg.push_back((Gadget) { .id = i + 1, .cost = c });
		}
	}
}

bool test(int day) {
	ll amc = OO, bmc = OO;
	fori (i, 0, day) {
		minify(amc, ac[i]);
		minify(bmc, bc[i]);
	}
	size_t ai = 0, bi = 0;
	ll spent = 0;
	repeat (reqGadgets) {
		if (bi >= bg.size() || (ai < ag.size() && amc*ag[ai].cost < bmc*bg[bi].cost)) {
			assert(ai < ag.size());
			spent += amc * ag[ai++].cost;
		} else {
			spent += bmc * bg[bi++].cost;
		}
		debugf("Trying %d, spent %" PRId64 "\n", day, spent);
		if (spent > money) {
			debugf("%" PRId64 " > %" PRId64 " bad\n", spent, money);
			return false;
		}
	}
	return true;
}
void reconstruct(int day) {
	ll amc = OO, bmc = OO;
	int amd = -1, bmd = -1;
	fori (i, 0, day) {
		if (amc > ac[i]) {
			amc = ac[i];
			amd = i + 1;
		}
		if (bmc > bc[i]) {
			bmc = bc[i];
			bmd = i + 1;
		}
	}
	size_t ai = 0, bi = 0;
	repeat (reqGadgets) {
		if (bi >= bg.size() || (ai < ag.size() && amc*ag[ai].cost < bmc*bg[bi].cost)) {
			printf("%d %d\n", ag[ai++].id, amd);
		} else {
			printf("%d %d\n", bg[bi++].id, bmd);
		}
	}
}

void tc() {
	readInput();
	sort(allof(ag));
	sort(allof(bg));
	int lo = 0; // impossible
	int hi = nDays + 1; // possible?
	while (hi - lo > 1) {
		int mid = (hi + lo) / 2;
		if (test(mid)) hi = mid; else lo = mid;
	}
	if (hi == nDays + 1) printf("-1\n");
	else {
		printf("%d\n", hi);
		reconstruct(hi);
	}
}

int main() { tc(); }