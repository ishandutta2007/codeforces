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

const int N = 300008;
int n;
int initial[N];
int target[N];

typedef struct Stone {
	int i;
	int pos;
	bool operator<(const Stone & other) const {
		return pos < other.pos;
	}
} Stone;

vector<Stone> stones;

typedef struct Contraction {
	int s, t, distance;
} Contraction;

vector<Contraction> contractions;

bool solve() {
	ll displacement = 0;
	fori (i, 0, n) {
		displacement += target[i];
		displacement -= stones[i].pos;
		if (displacement < 0) return false;
	}
	if (displacement != 0) return false;

	// if we get here it's possible (i think)
	int leftPointer = 0;
	fori (i, 0, n) {
		// need to move i right?
		while (stones[i].pos < target[i]) {
			// find leftPointer so we can move leftPointer left
			while (stones[leftPointer].pos <= target[leftPointer]) {
				leftPointer++;
				if (leftPointer >= stones.size()) throw "gg";
			}
			assert(i < leftPointer);
			int amt = min(target[i] - stones[i].pos, stones[leftPointer].pos - target[leftPointer]);
			stones[i].pos += amt;
			stones[leftPointer].pos -= amt;
			assert(stones[i].pos <= stones[leftPointer].pos);
			assert(stones[i].pos <= target[i]);
			assert(stones[leftPointer].pos >= target[leftPointer]);
			contractions.push_back((Contraction) { .s = stones[i].i, .t = stones[leftPointer].i, .distance = amt });
		}
	}
	return true;
}

int main() {
	scan_d(n);
	fori (i, 0, n) {
		int pos;
		scan_d(pos);
		stones.push_back((Stone) { .i = i, .pos = pos});
	}
	sort(allof(stones));

	fori (i, 0, n) { scan_d(target[i]); }
	sort(target, target + n);

	if (solve()) {
		puts("YES");
		printf("%lu\n", contractions.size());
		for (const auto & con : contractions) {
			printf("%d %d %d\n", con.s + 1, con.t + 1, con.distance);
		}
	} else {
		puts("NO");
	}
}