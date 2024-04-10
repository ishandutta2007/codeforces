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

const int OO  = 1000 << 20;
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

int a, b, c;
int n;
int h[7];

void burn(int i, int cnt) {
	for (int j = i; j >= 0; j--) {
		int x = min(h[j], cnt);
		h[j] -= x;
		cnt -= x;
	}
}

int solve() {
	int ans = 0;
	vector<int> abcs;

	scan_d(n);

	repeat(3) {
		int x;
		scan_d(x);
		abcs.push_back(x);
	}
	sort(allof(abcs));
	a = abcs[0];
	b = abcs[1];
	c = abcs[2];
	vector<int> thresholds;
	thresholds.push_back(a);
	thresholds.push_back(b);
	thresholds.push_back(c);
	thresholds.push_back(a + b);
	thresholds.push_back(a + c);
	thresholds.push_back(b + c);
	thresholds.push_back(a + b + c);
	thresholds.push_back(OO);
	sort(allof(thresholds));
	repeat(n) {
		int x;
		scan_d(x);
		for(size_t i = 0; i < 8; i++) {
			if (x <= thresholds[i]) {
				if (i == 7) return -1;
				h[i]++;
				break;
			}
		}
	}
	debugf("t!S: %d %d %d %d %d %d %d\n",
			thresholds[0],
			thresholds[1],
			thresholds[2],
			thresholds[3],
			thresholds[4],
			thresholds[5],
			thresholds[6]);

	// a b c
	ans += h[6];
	h[6] = 0;

	// b c
	ans += h[5];
	burn(0, h[5]);
	h[5] = 0;

	// a c
	ans += h[4];
	burn(1, h[4]);
	h[4] = 0;

	// interesting part:
	int rans = OO;
	int w = h[0], x = h[1], y = h[2], z = h[3];
	if (a + b > c) {
		debugf("alpha\n");
		fori (s, 0, w + x + y + z + 1) {
			int t = max(z,
					max((z + y - s + 1) / 2,
						max((z + y + x - 2*s + 1) / 2,
							(z + y + x + w - 3*s + 1) / 2)));
			minify(rans, s + t);
		}
	} else {
		debugf("beta\n");
		fori (s, 0, w + x + y + z + 1) {
			int t = max(0,
					max(z - s,
						max((z + y - s + 1) / 2,
							max((z + y + x - 2*s + 1) / 2,
								(z + y + x + w - 3*s + 1) / 2))));
			minify(rans, s + t);
		}
	}
	return ans + rans;
}

void tc() {
	printf("%d\n", solve());
}

int main() { tc(); }