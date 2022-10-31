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

long long n, m, k;
void readInput() {
	scanf("%" SCNd64, &n);
	scanf("%" SCNd64, &m);
	scanf("%" SCNd64, &k);
}

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

void tc() {
	readInput();

	// 2nm / k should be integer
	long long a = 2 * n * m;
	if (a % k) {
		printf("NO\n");
	} else {
		printf("YES\n");
		if (k % 2) {
			// odd
			ll g = gcd(n, k);
			ll other = k / g;
			ll m2 = m / other;
			ll n2 = n / g;
			if (g >= 2) {
				n2 *= 2;
			} else {
				m2 *= 2;
			}
			printf("%" PRId64 " %" PRId64 "\n", 0LL, 0LL);
			printf("%" PRId64 " %" PRId64 "\n", n2, 0LL);
			printf("%" PRId64 " %" PRId64 "\n", 0LL, m2);
		} else {
			// even
			k /= 2;
			ll g = gcd(n, k);
			m /= (k / g);
			n /= g;
			printf("%" PRId64 " %" PRId64 "\n", 0LL, 0LL);
			printf("%" PRId64 " %" PRId64 "\n", n, 0LL);
			printf("%" PRId64 " %" PRId64 "\n", 0LL, m);
		}
	}
}

int main() { tc(); }