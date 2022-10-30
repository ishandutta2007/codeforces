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
#define debug(code) code

int a[1008][1008];
int n, m;

void readInput() {
	scanf("%d%d", &n, &m);
	fori (i, 1, n+1) fori (j, 1, m+1) scanf("%d", &a[i][j]);
}
int row[1008];
int col[1008];
void getSums() {
	fori (i, 1, n+1) {
		row[i] = 0;
		fori (j, 1, m+1) row[i] += a[i][j];
	}
	fori (j, 1, m+1) {
		col[j] = 0;
		fori (i, 1, n+1) col[j] += a[i][j];
	}
}
inline long long sq(long long x) { return x * x; }
long long badRow(int r) {
	long long ret = 0;
	fori (i, 1, n+1) {
		ret += (long long) sq(r * 4 - i * 4 + 2) * (long long) (row[i]);
	}
	return ret;
}
long long badCol(int c) {
	long long ret = 0;
	fori (i, 1, m+1) {
		ret += (long long) sq(c * 4 - i * 4 + 2) * (long long) (col[i]);
	}
	return ret;
}
long long bestRowBad = 1LL << 62;
int bestRow = -1;
void scanRow() {
	fori (r, 0, n+1) {
		long long bad = badRow(r);
		if (bad < bestRowBad) {
			bestRowBad = bad;
			bestRow = r;
		}
	}
}
long long bestColBad = 1LL << 62;
int bestCol = -1;
void scanCol() {
	fori (c, 0, m+1) {
		long long bad = badCol(c);
		if (bad < bestColBad) {
			bestColBad = bad;
			bestCol = c;
		}
	}
}

void tc() {
	readInput();
	getSums();
	scanRow();
	scanCol();
	printf("%" PRId64 "\n%d %d\n", bestRowBad + bestColBad,
			bestRow, bestCol);
}

int main() { tc(); }