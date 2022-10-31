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

const long long OO = 1000000000000000000LL;
const int N = 500008;
const int N2 = 2*N;

ll _rrec[N2],
	*rrec = _rrec + N,
	_crec[N2],
	*crec = _crec + N;

int n, h, w;
char pattern[N];

ll solve();
void tc() {
	scan_ddd(n, h, w);
	scanf(" ");
	fgets(pattern, N - 2, stdin);
	printf("%" PRId64 "\n", solve());
}
ll solve() {
	int r = 0, c = 0;
	fori (i, -N, N) { rrec[i] = crec[i] = OO; }

	fori (i, 0, n) {
		switch (pattern[i]) {
			case 'U':
				r--;
				minify(rrec[r], (ll)i+1);
				break;
			case 'D':
				r++;
				minify(rrec[r], (ll)i+1);
				break;
			case 'L':
				c--;
				minify(crec[c], (ll)i+1);
				break;
			case 'R':
				c++;
				minify(crec[c], (ll)i+1);
				break;
			debug(default: throw "gg";)
		}
	}
	debugf("r, c: %d %d\n", r, c);

	ll res = 0;
	int rlo = 0, rhi = h, clo = 0, chi = w;
	while (rlo < rhi && clo < chi) {
		debugf("<%d %d x %d %d>\n", rlo, rhi, clo, chi);
		ll &rlot = rrec[-rlo-1];
		if (rlot == OO && r < 0) {
			assert(-rlo-1-r < 0);
			rlot = n + rrec[-rlo-1-r];
			assert(rlot < OO);
		}
		ll &clot = crec[-clo-1];
		if (clot == OO && c < 0) {
			assert(-clo-1-c < 0);
			clot = n + crec[-clo-1-c];
			assert(clot < OO);
		}

		ll &rhit = rrec[h-rhi+1];
		if (rhit == OO && r > 0) {
			assert(h-rhi+1-r > 0);
			rhit = n + rrec[h-rhi+1-r];
			assert(rhit < OO);
		}

		ll &chit = crec[w-chi+1];
		if (chit == OO && c > 0) {
			assert(w-chi+1-c > 0);
			chit = n + crec[w-chi+1-c];
			assert(chit < OO);
		}

		ll m = min(min(rlot, clot), min(rhit, chit));
		if (m == OO) return -1;
		if (m == rlot) {
			res += rlot * (chi - clo);
			rlo++;
		} else if (m == clot) {
			res += clot * (rhi - rlo);
			clo++;
		} else if (m == rhit) {
			res += rhit * (chi - clo);
			rhi--;
		} else if (m == chit) {
			res += chit * (rhi - rlo);
			chi--;
		}
		res %= M7L;
	}
	return res;
}

int main() { tc(); }