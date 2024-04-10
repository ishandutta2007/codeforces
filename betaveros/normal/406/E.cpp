// betaveros
#include <cstdio>
#include <cstdlib>
#include <cinttypes>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <new>
#include <algorithm>
using namespace std;

#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define forui(i,s,e) for(unsigned int i = s; i < ((unsigned int)e); i++)
#define _conc(x,y) x ## y
#define _conc2(x,y) _conc(x,y)
#define repeat(n) fori(_conc2(_,__LINE__),0,n)
#define allof(s) (s).begin(), (s).end()
//#define debug(code) code
#define debug(code)

vector<int> s[2];
int fix[2][2];
int len, m;
bool allEqual;
void readInput() {
	scanf("%d%d", &len, &m);
	allEqual = true;

	int bit0, start0;
	scanf("%d%d", &bit0, &start0);
	s[bit0].push_back(start0);
	repeat(m-1) {
		int bit, start;
		scanf("%d%d", &bit, &start);
		s[bit].push_back(start);
		if (bit != bit0 || start != start0) allEqual = false;
	}
}

long long total = 0;
long long lmul(long long a, long long b) { return a * b; }

void accumTriples(vector<int> & a, vector<int> & b) {
	int ai = 0, blo = 0, bhi = 0;
	while (ai < (int) a.size()) {
		while (blo < ((int)b.size()) && b[blo] < a[ai]) blo++;
		while (bhi < ((int)b.size()) && b[bhi] <= a[ai]) bhi++;
		// [blo, bhi) = a[ai]
		int btwn = bhi - blo;
		total += lmul(bhi, (int) b.size() - blo) - lmul(btwn, btwn + 1) / 2;

		ai++;
	}
}

void cutPrefix(int bit) {
	if (s[bit^1].empty()) {
		debug(printf("cutPrefix %d\n", bit);)
		// nothing starting with other bit
		// cut this
		int ix = 0;
		int minb = s[bit][0];
		while (ix < ((int)s[bit].size()) && s[bit][ix] == minb) ix++;
		s[bit].erase(s[bit].begin(), s[bit].begin() + ix);
		repeat(ix) s[bit^1].push_back(len);
	}
}
void cutSuffix(int bit) {
	if (
			(s[bit].empty() || s[bit].front() == len)
			// all (if any) strings starting with this bit are complete
			&&
			!s[bit^1].empty()
			&&
			s[bit^1].back() < len
			// all strings starting with the other are not complete
			// and they exist (because they're the only strings that need
			// be adjusted)
		) {
		debug(printf("cutSuffix %d\n", bit);)
		int maxb = s[bit^1].back();
		int ix = (int) (s[bit^1].size() - 1);
		while (ix >= 0 && s[bit^1][ix] == maxb) { s[bit^1][ix--] = len; }
	}
}
void cutCenter(int bit) {
	if (
			!s[bit].empty()
			&&
			!s[bit^1].empty()
			&&
			s[bit][0] > s[bit^1].back()
	   ) {
		int minb = s[bit][0];
		int ix = 0;
		while (ix < s[bit].size() && s[bit][ix] == minb) {
			s[bit][ix++] = s[bit^1].back();
		}
	}
}
void tc() {
	readInput();
	sort(allof(s[0]));
	sort(allof(s[1]));

	if (allEqual) {
		total = lmul(lmul(m, m-1), m-2) / 6;
	} else {
		cutPrefix(0);
		cutPrefix(1);
		cutSuffix(0);
		cutSuffix(1);
		cutCenter(0);
		cutCenter(1);
		accumTriples(s[0], s[1]);
		accumTriples(s[1], s[0]);
	}

	printf("%" PRId64 "\n", total);
}

int main() { tc(); }