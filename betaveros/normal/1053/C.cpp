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

// const int OO  = 1000 << 20;
// const int OO2 = 2000 << 20;
// const int       M7  = 1000000007;
// const int       M9  = 1000000009;
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

int n, q;
const int N = 200008;

ll position[N];
ll weight[N];
ll wtree[N];
ll wptree[N];
ll witree[N];

long long mod(long long x, long long m) {
	long long r = x % m;
	return r < 0 ? r + m : r;
}

void readInput() {
	scan_dd(n, q);
	fori (i, 1, n+1) { scanf("%" SCNd64, &position[i]); }
	fori (i, 1, n+1) { scanf("%" SCNd64, &weight[i]); }
}

void update(int i, ll diff) {
	int ii = i;
	while (ii <= n) {
		wtree[ii] += diff;
		wptree[ii] += diff * position[i];
		wptree[ii] = mod(wptree[ii], M7L);
		witree[ii] += diff * i;
		witree[ii] = mod(witree[ii], M7L);

		ii += ii & -ii;
	}
}

ll getSum(int i) {
	ll ret = 0;
	int ii = i;
	while (ii) {
		ret += wtree[ii];

		ii -= ii & -ii;
	}
	return ret;
}

ll getWpSum(int i) {
	ll ret = 0;
	int ii = i;
	while (ii) {
		ret = mod(ret + wptree[ii], M7L);

		ii -= ii & -ii;
	}
	return ret;
}

ll getWiSum(int i) {
	ll ret = 0;
	int ii = i;
	while (ii) {
		ret = mod(ret + witree[ii], M7L);

		ii -= ii & -ii;
	}
	return ret;
}


void tc() {
	readInput();

	// build a fenwick tree so we can calculate sums of weights and sums of
	// weight*positions
	
	fori (i, 1, n+1) {
		update(i, weight[i]);
	}

	//
	repeat(q) {
		int qa, qb;
		scan_dd(qa, qb);
		debugf("doing %d %d\n", qa, qb);
		if (qa < 0) {
			// to update, update the fenwick tree
			ll newWeight = qb;
			int i = -qa;
			ll diff = newWeight - weight[i];
			weight[i] = newWeight;
			update(i, diff);
		} else {
			// do a binary search; the best place is where sum of weight on both sides is balanced.
			int lo = qa;
			int hi = qb + 1;
			ll loWs = getSum(lo - 1);
			ll hiWs = getSum(hi - 1);
			while (hi - lo > 1) {
				int mid = (lo + hi) / 2;
				ll midWs = getSum(mid - 1);
				ll left = midWs - loWs;
				ll right = hiWs - midWs;
				debugf("%lld | (%d) | %lld", left, mid, right);
				if (left > right) {
					hi = mid;
				} else {
					lo = mid;
				}
			}

			int center = lo;
			debugf("center = %d\n", center);
			ll centerPos = position[center];
			ll leftCost =
				(centerPos - center) * mod(getSum(center - 1) - getSum(qa - 1), M7L)
				+ (getWiSum(center - 1) - getWiSum(qa - 1))
				- (getWpSum(center - 1) - getWpSum(qa - 1));
			ll rightCost =
				(getWpSum(qb) - getWpSum(center))
				- (centerPos - center) * mod(getSum(qb) - getSum(center), M7L)
				- (getWiSum(qb) - getWiSum(center))
				;
			leftCost = mod(leftCost, M7L);
			rightCost = mod(rightCost, M7L);
			printf("%" PRId64 "\n", mod(leftCost + rightCost, M7L));
		}
	}
}

int main() { tc(); }