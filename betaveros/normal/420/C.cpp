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

int n, p;
const int N = 300008;
vector<int> graph[N];
int cnt[N];
void readInput() {
	fill(cnt, cnt + N, 0);
	scan_dd(n, p);
	repeat (n) {
		int a, b;
		scan_dd(a, b);
		cnt[a]++;
		cnt[b]++;
		graph[a].pushb(b);
		graph[b].pushb(a);
	}
}

struct Fen {
	int a[N];
	Fen() {
		fill(a, a + N, 0);
	}
	void add(int ix, int d) {
		while (ix < N) {
			a[ix] += d;
			ix += ix & -ix;
		}
	}
	int get(int ix) {
		int res = 0;
		while (ix > 0) {
			res += a[ix];
			ix -= ix & -ix;
		}
		return res;
	}
} fen;

void tc() {
	readInput();
	fori (i, 1, n+1) {
		sort(allof(graph[i]));
	}
	fori (i, 1, n+1) {
		fen.add(cnt[i]+1, 1);
	}
	ll ways = 0; // !doubled!
	fori (i, 1, n+1) {
		if (cnt[i] >= p) {
			debugf("i = %d: directly, %d\n", i, n-1);
			ways += n - 1;
		} else {
			int req = p - cnt[i];
			int w = n - 1 - (fen.get(req) - (cnt[i] <= req - 1 ? 1 : 0));
			debugf("i = %d: prelim %d\n", i, w);
			uint j = 0;
			while (j < graph[i].size()) {
				int jc = 1;
				while (j < graph[i].size() - 1 && graph[i][j] == graph[i][j+1]) {
					j++; jc++;
				}
				int v = graph[i][j];
				if (cnt[v] >= req && cnt[v] - jc < req) {
					debugf("  elim %d\n", v);
					w--;
				}
				j++;
			}
			debugf("i = %d:     involve %d\n", i, w);
			ways += w;
		}
	}
	assert(ways % 2 == 0);
	printf("%" PRId64 "\n", ways / 2);
}

int main() { tc(); }