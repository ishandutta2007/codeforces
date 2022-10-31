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

char s[50008];
char r[50008][4];
int n;
int nq;
const int MAX_ROLL = 535353;
int c[MAX_ROLL];

struct Str {
	int ix;
	int len;
	int val;
	Str(int i, int nn, int v): ix(i), len(nn), val(v) {
		debugf("$[%d * %d] %d\n", ix, len, val);
	}
	bool operator<(const Str & o) const {
		if (val != o.val) return val < o.val;
		return ix < o.ix;
	}
};
vector<Str> strs;
struct Query {
	int ix;
	int v1;
	int v2;
	Query(int i, int v, int vv): ix(i), v1(v), v2(vv) {}
	bool operator<(const Query & o) const {
		if (v1 != o.v1) return v1 < o.v1;
		if (v2 != o.v2) return v2 < o.v2;
		return ix < o.ix;
	}
};
vector<Query> queries;
int roll(char cc[], int nn) {
	int x = 0;
	fori (i, 0, nn) {
		x = 27 * x + cc[i] + 1 - 'a';
	}
	assert(x < MAX_ROLL);
	return x;
}
void readInput() {
	fgets(s, 50004, stdin);
	scan_d(nq);
	char buf[10];
	fori0 (i, nq) {
		scanf("%s", buf);
		int v1 = roll(buf, (int) strlen(buf));
		scanf("%s", buf);
		int v2 = roll(buf, (int) strlen(buf));
		queries.push_back(Query(i, v1, v2));
		queries.push_back(Query(i, v2, v1));
	}
}

const int OO = 1000 << 20;
int answers[100008];
int _tdist  [100008], * tdist = _tdist + 2;
void tc() {
	readInput();
	sort(allof(queries));
	// fill(answers, answers + 100008, 0);
	n = (int) strlen(s);
	while (!isalpha(s[n-1])) --n;
	fori (i, 0, n) {
		fori (m, 1, min(5, n - i + 1)) {
			strs.push_back(Str(i, m, roll(s + i, m)));
		}
	}
	sort(allof(strs));
	// step 1: scan for frequent strs
	uint qi = 0;
	for (uint i = 0; i < strs.size(); ) {
		uint j = i;
		int cval = strs[i].val;
		while (j < strs.size() && cval == strs[j].val) j++;
		if (j - i > 222) {
			// record dists from ix.
			uint ti = i;
			for (int x = -2; x <= n + 2; x++) {
				while (ti < j - 1 && abs(x - strs[ti].ix) > abs(x - strs[ti+1].ix)) {
					ti++;
				}
				tdist[x] = abs(x - strs[ti].ix);
			}

			while (qi < queries.size() && queries[qi].v1 < cval) qi++;
			if (qi >= queries.size()) break;
			uint qj = qi;
			while (qj < queries.size() && queries[qj].v1 == cval) qj++;
			// queries[qi,qj) = queries related to cval
			uint ii = 0;
			for (uint qqi = qi; qqi < qj; ) {
				uint qqj = qqi;
				while (qqj < qj && queries[qqi].v2 == queries[qqj].v2) qqj++;
				// queries[qqi,qqj) are identical
				// strs[ii,jj) = strings relevant to second string
				while (ii < strs.size() && strs[ii].val < queries[qqi].v2) ii++;
				if (strs[ii].val > queries[qqi].v2) {
					for (uint qqq = qqi; qqq < qqj; qqq++) {
						answers[queries[qqq].ix] = -1;
					}
				} else {
					uint jj = ii;
					int ans = 1000 << 20;
					while (jj < strs.size() && strs[jj].val == queries[qqi].v2) {
						// calculate distance using tdist
						int m = (strs[jj].len - strs[i].len);
						if (m & 1) {
							minify(ans,
									(tdist[strs[jj].ix + (m - 1) / 2]
									+ tdist[strs[jj].ix + (m + 1) / 2]
									+ 1
									+ strs[i].len + strs[jj].len) / 2);
						} else {
							minify(ans, tdist[strs[jj].ix + m / 2] + (strs[i].len + strs[jj].len) / 2);
						}
						jj++;
					}
					maxify(ans, strs[i].len);
					maxify(ans, strs[ii].len);
					for (uint qqq = qqi; qqq < qqj; qqq++) {
						answers[queries[qqq].ix] = ans;
					}
					// match
					ii = jj;
				}
				qqi = qqj;
			}
		}
		i = j;
	}
	// step 2: handle remaining
	for (Query & q : queries) {
		if (!answers[q.ix]) {
			int ans = OO;
			auto s1 = lower_bound(allof(strs), Str(-1, -1, q.v1));
			auto s2 = lower_bound(allof(strs), Str(-1, -1, q.v2));
			while (s1 != strs.end() && s2 != strs.end()
					&& (*s1).val == q.v1
					&& (*s2).val == q.v2) {
				int i1 = (*s1).ix;
				int i2 = (*s2).ix;
				minify(ans, max(i1 + (*s1).len, i2 + (*s2).len) - min(i1, i2));
				if (i1 < i2) s1++; else s2++;
			}
			answers[q.ix] = ans == OO ? -1 : ans;
		}
	}
	fori (i, 0, nq) printf("%d\n", answers[i]);
}

int main() { tc(); }