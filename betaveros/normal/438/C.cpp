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

int mx(int a, int b) {
	return (int) (((ll)a) * ((ll)b) % M7L);
}

struct Pt {
	int x;
	int y;
	Pt() {}
	Pt(int x, int y): x(x), y(y) {}
	Pt operator-(const Pt & o) const {
		return Pt(x - o.x, y - o.y);
	}
	ll operator*(const Pt & o) const {
		return ((ll)x) * o.x + ((ll)y) * o.y;
	}
	ll operator^(const Pt & o) const {
		return ((ll)x) * o.y - ((ll)y) * o.x;
	}
	Pt operator|(const Pt & o) const {
		return Pt((x + o.x) / 2, (y + o.y) / 2);
	}
	Pt prime() const {
		return Pt(x + 0xdefaced, y + 1);
	}
} pts[208];

int dp[208][208];

int n;
void readInput() {
	scan_d(n);
	fori (i, 0, n) {
		scan_dd(pts[i].x, pts[i].y);
		pts[i].x *= 2; pts[i].y *= 2;
	}
}

int ori(const Pt & a, const Pt & b, const Pt & c) {
	ll r = (b - a) ^ (c - a);
	if (r == 0) return 0;
	if (r < 0) return -1;
	return 1;
}
int oriv(int a, int b, int c) { return ori(pts[a], pts[b], pts[c]); }

bool btwn(const Pt & p, const Pt & q, const Pt & c) {
	return (c - p) * (c - q) < 0;
}

bool intersects(const Pt & a1, const Pt & a2, const Pt & b1, const Pt & b2) {
	int o1 = ori(a1, a2, b1);
	int o2 = ori(a1, a2, b2);

	int q1 = ori(b1, b2, a1);
	int q2 = ori(b1, b2, a2);

	if (o1 * o2 == -1 && q1 * q2 == -1) return true;
	if (q1 == 0) {
		if (btwn(b1, b2, a1)) return true;
	}
	if (q2 == 0) {
		if (btwn(b1, b2, a2)) return true;
	}
	if ((o1 == 0 && o2 == 0) || (q1 == 0 && q2 == 0)) {
		return btwn(a1, a2, b1) || btwn(a1, a2, b2) || btwn(b1, b2, a1) || btwn(b1, b2, a2);
	}
	return false;
}

bool ok(int v, int w) {
	if (w - v == 1 || (v == 0 && w == (n - 1))) return true;

	fori (i, 0, n) {
		if (intersects(pts[i], pts[(i+1)%n], pts[v], pts[w])) return false;
	}

	Pt mid = pts[v] | pts[w];
	Pt mp = mid.prime();

	bool inside = false;
	fori (i, 0, n) {
		inside ^= intersects(pts[i], pts[(i+1)%n], mid, mp);
	}

	return inside;
}

void goDP() {
	fori (ln, 1, n) {
		fori (i, 0, n - ln) {
			debugf("[%d %d]\n", i, i + ln);
			// j = i + ln
			if (ln == 1) dp[i][i+ln] = 1;
			else if (!ok(i, i + ln)) {
				dp[i][i+ln] = 0;
			} else {
				int x = 0;
				fori (k, i + 1, i + ln) {
					x = (x + mx(dp[i][k], dp[k][i+ln])) % M7;
				}
				dp[i][i+ln] = x;
			}
			debugf("--[%d %d] = %d\n", i, i + ln, dp[i][i+ln]);
		}
	}
}

void tc() {
	readInput();
	goDP();
	printf("%d\n", dp[0][n-1]);
}

int main() { tc(); }