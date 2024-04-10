// @betaveros :: vim:set fdm=marker syntax=cppc:
// #define NDEBUG
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
const int N = 100008;
int a[N], inv[N];
int n;
void readInput() {
	scan_d(n);
	fori1 (i, n) {
		scan_d(a[i]);
		inv[a[i]] = i;
	}
}

bool isPrime[N];
vector<int> primes;
void makePrimes() {
	fill(isPrime, isPrime + N, true);
	fori (i, 2, N) {
		if (isPrime[i]) {
			for (int m = i; i < 1000 && m * i < N; m++) isPrime[m * i] = false;
			primes.push_back(i);
		}
	}
}

vector<pair<int,int> > swaps;

void tc() {
	makePrimes();
	readInput();
	fori1 (i, n) {
		int t = inv[i];
		while (t > i) {
			int p = *(upper_bound(allof(primes), t - i + 1) - 1);
			int tt = t - p + 1;
			swaps.push_back(make_pair(tt, t));
			swap(a[t], a[tt]);
			swap(inv[a[t]], inv[a[tt]]);
			t = tt;
		}
	}
	printf("%lu\n", swaps.size());
	for (auto x : swaps) {
		printf("%d %d\n", x.first, x.second);
	}
}

int main() { tc(); }