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

vector<int> a;
int h;
void readInput() {
	int n;
	scan_dd(n, h);
	repeat(n) { int x; scan_d(x); a.pushb(x); }
}

void tc() {
	readInput();
	uint mix; int miv = 1<<30;
	foruin (i, a) {
		if (a[i] < miv) { miv = a[i]; mix = i; }
	}
	sort(allof(a));
	if (a.size() == 2) {
		printf("0\n1 1\n"); return;
	} else {
		int b1 = a[a.size() - 1] + a[a.size() - 2] - (a[0] + a[1]);
		int b2 = abs(a[a.size() - 1] + max(a[a.size() - 2], a[0] + h) - (a[1] + min(a[0] + h, a[2])));
		if (b1 <= b2) {
			printf("%d\n1", b1);
			repeat(a.size()-1) { printf(" 1"); }
			printf("\n");
		} else {
			printf("%d\n", b2);
			foruin (i, a) {
				if (i) printf(" ");
				printf("%d", i == mix ? 1 : 2);
			}
			printf("\n");
		}
	}

}

int main() { tc(); }