// @betaveros :: vim:set fdm=marker syntax=cppc:
#define NDEBUG
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
const int       M7  = 1000000007;
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

int n, k;
void readInput() {
	scan_dd(n, k);
}

const int N = 100008;
int p[N]; bool pd[N];

int root(int a, bool & diff) {
	if (p[a] == a) {
		diff = 0;
		return a;
	}
	p[a] = root(p[a], diff);
	pd[a] ^= diff;
	diff = pd[a];
	return p[a];
}

bool link(int a, int b, bool d) {
	debugf("linking %d %d (diff %d)\n", a, b, d);
	bool da, db;
	int ra = root(a, da);
	int rb = root(b, db);
	if (ra == rb) {
		return !(da ^ db ^ d);
	} else {
		p[ra] = rb;
		pd[ra] = da ^ db ^ d;
		return true;
	}
}

char getox() {
	char c = getchar();
	while (c != 'o' && c != 'x') c = getchar();
	return c;
}

int freedom() {
	fori (i, 0, n + 2) {
		p[i] = i; pd[i] = 0;
	}
	repeat (k) {
		int x, y;
		scan_dd(x, y);
		char c = getox();
		bool diff = c == 'o';
		if (!link(abs(x - y), n + 1 - abs(x + y - n - 1), diff)) return -1;
	}
	int ret = 0;
	fori (i, 0, n + 2) {
		if (p[i] == i) ret++;
	}
	return ret - 2;
}

int p2(int x) {
	if (x == -1) return 0;
	int s = 1;
	repeat (x) {
		s = (s * 2) % M7;
	}
	return s;
}

void tc() {
	readInput();
	printf("%d\n", p2(freedom()));
}

int main() { tc(); }