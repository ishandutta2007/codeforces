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


int a[100008], b[100008];
int n, d;
//x is 64-bit variable;
ll x;
ll getNextX() {
	x = (x * 37 + 10007) % 1000000007;
	return x;
}
void initAB() {
	for(int i = 0; i < n; i = i + 1){
		a[i] = i + 1;
	}
	for(int i = 0; i < n; i = i + 1){
		swap(a[i], a[getNextX() % (i + 1)]);
	}
	for(int i = 0; i < n; i = i + 1){
		if (i < d)
			b[i] = 1;
		else
			b[i] = 0;
	}
	for(int i = 0; i < n; i = i + 1){
		swap(b[i], b[getNextX() % (i + 1)]);
	}
}

void readInput() {
	scan_dd(n, d);
	scanf("%" SCNd64, &x);
}
int ainv[100008];
void tc() {
	readInput();
	initAB();
	if (d < 300) {
		vector<int> d1;
		fori0 (i, n) if (b[i]) d1.push_back(i);
		fori0 (i, n) {
			int m = 0;
			for (int di : d1) {
				if (di > i) break;
				maxify(m, a[i - di]);
			}
			printf("%d\n", m);
		}
	} else {
		fori0 (i, n) ainv[a[i]] = i;
		fori0 (i, n) {
			bool f = false;
			for (int m = n; m >= 1; m--) {
				int bi = i - ainv[m];
				if (bi >= 0 && b[bi]) {
					printf("%d\n", m);
					f = true;
					break;
				}
			}
			if (!f) printf("0\n");
		}
	}
}

int main() { tc(); }