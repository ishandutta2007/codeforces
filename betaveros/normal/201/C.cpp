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
#define debug(code)

int n;
int b[100008];

void readInput() {
	scanf("%d", &n);
	b[0] = 0;
	fori (i, 0, n-1) scanf("%d", &b[i]);
	b[n] = 0;
}
long long bestScore = 0;

// eooooooe
struct Section {
	long long oo;
	long long leb;
	long long reb;
	Section(long long oo, long long leb, long long reb): oo(oo), leb(leb), reb(reb){
	
		debug(printf("Section(%lld,%lld,%lld)\n",oo,leb,reb);)
	}
};

long long roundDownToOdd(long long x) {
	return (x % 2 == 0) ? (x - 1) : x;
}

int ix;
int ebs[100008];
int maxEbs[100008];
int minEbs[100008];
vector<Section> secs;
void readSection() {
	debug(printf("reading section... ");)
	int si = ix;
	int eb = 0; // even-bonus: # evens - # odds
	int maxEb = 0;
	int minEb = 0;
	long long total = 0;
	ebs[ix] = 0;
	while (b[ix] > 1) {
		debug(printf("%d ", b[ix]);)
		total += roundDownToOdd(b[ix]);
		eb += (b[ix] % 2 == 0) ? 1 : -1;
		ebs[ix+1] = eb;
		maxEb = max(eb, maxEb);
		minEb = min(eb, minEb);
		ix++;
	}
	int ei = ix;
	fori (i,si,ei+1) minEbs[i] -= eb;
	debug(printf("\n");)
	maxEbs[si] = 0;
	fori (i, si + 1, ei + 1) {
		maxEbs[i] = max(maxEbs[i-1], ebs[i]);
		debug(printf("maxEbs[%d] = %d\n", i, maxEbs[i]);)
	}
	minEbs[ei] = 0;
	for (int i = ei - 1; i >= si; i--) {
		minEbs[i] = min(minEbs[i+1], ebs[i] - eb);
		debug(printf("minEbs[%d] = %d\n", i, minEbs[i]);)
	}
	int bestSelf = 0;
	fori (i, si, ei + 1) {
		bestSelf = max(bestSelf, maxEbs[i] - minEbs[i]);
	}
	bestScore = max(bestScore, total + bestSelf);
	secs.push_back(Section(total, maxEb, eb-minEb));
}
long long leftGain[100008], rightGain[100008];
void checkBlock() {
	while (true) {
		readSection();
		if (b[ix] == 0) break;
		ix++;
		if (b[ix] == 0) { secs.push_back(Section(0,0,0)); break; }
	}
	if (secs.size() == 0) return;
	long long ooTotal = secs.size() - 1;
	// done reading sections
	fori (i, 0, secs.size()) {
		ooTotal += secs[i].oo;
	}
	debug(printf("ooTotal = %lld\n", ooTotal);)
	long long loot = secs[0].oo + 1;
	leftGain[0] = secs[0].leb;
	fori (i, 1, secs.size()) {
		leftGain[i] = max(leftGain[i-1], secs[i].leb - loot);
		loot += secs[i].oo + 1;
	}
	long long root = secs[secs.size() - 1].oo + 1;
	rightGain[secs.size() - 1] = secs[secs.size() - 1].reb;
	for (int i = secs.size() - 2; i >= 0; i--) {
		rightGain[i] = max(rightGain[i+1], secs[i].reb - root);
		root += secs[i].oo + 1;
	}
	fori (i, 0, secs.size() - 1) {
		bestScore = max(bestScore, ooTotal + leftGain[i] + rightGain[i+1]);
	}
}
void tc() {
	secs.reserve(100000);
	readInput();
	while (ix < n) { checkBlock(); ix++; }
	printf("%" PRId64 "\n", bestScore);
}

int main() { tc(); }