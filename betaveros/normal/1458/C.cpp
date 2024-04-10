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

// If a[i,j] = k, after R, a[i,j+1] = k
// If a[i,j] = k, after L, a[i,j-1] = k
// If a[i,j] = k, after D, a[i+1,j] = k
// If a[i,j] = k, after U, a[i-1,j] = k
// If a[i,j] = k, after I, a[k,j] = i
// If a[i,j] = k, after C, a[i,k] = j

struct Coord {
	int sourceIndex; // 0|1|2
	int increment;
	Coord(int si, int inc): sourceIndex(si), increment(inc) {}

	int operator()(int i, int j, int k) {
		if (sourceIndex == 0) return i + increment;
		if (sourceIndex == 1) return j + increment;
		if (sourceIndex == 2) return k + increment;
		throw runtime_error("wtf");
	}
};

const int N = 1008;
int n, nOperations;
int input[N][N];
int output[N][N];
char operations[100008];

void readInput() {
	scan_dd(n, nOperations);
	fori (i, 0, n) {
		fori (j, 0, n) {
			int x;
			scan_d(x);
			input[i][j] = x - 1;
		}
	}
	scanf(" ");
	fgets(operations, 100008, stdin);

	debugf("ops: %s\n", operations);

	Coord ic(0, 0), jc(1, 0), kc(2, 0);
	fori (i, 0, nOperations) {
		switch (operations[i]) {
			case 'R': jc.increment++; break;
			case 'L': jc.increment--; break;
			case 'D': ic.increment++; break;
			case 'U': ic.increment--; break;
			case 'I': swap(jc, kc); break;
			case 'C': swap(ic, kc); break;
		}
	}
	debugf("%d %d, %d %d, %d %d\n",
		ic.sourceIndex, ic.increment,
		jc.sourceIndex, jc.increment,
		kc.sourceIndex, kc.increment);
	fori (i, 0, n) {
		fori (j, 0, n) {
			int ir = ic(i, j, input[i][j]);
			int jr = jc(i, j, input[i][j]);
			int kr = kc(i, j, input[i][j]);

			ir = ((ir % n) + n) % n;
			jr = ((jr % n) + n) % n;
			kr = ((kr % n) + n) % n;

			output[ir][jr] = kr;
		}
	}
	fori (i, 0, n) {
		fori (j, 0, n) {
			if (j) putchar(' ');
			printf("%d", output[i][j] + 1);
		}
		puts("");
	}
	puts("");
}

void tc() {
	readInput();

}

// int main() { tc(); }
int main() {
	int tcn;
	scanf("%d", &tcn);
	repeat (tcn) tc();
}