#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <complex>
#include <bitset>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef double DB;

#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#define X first
#define Y second

#define Error(x) cout << #x << " = " << x << endl

template <typename T, typename U>
void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
void chkmin(T& x, U y) {
	if (y < x) x = y;
}

const int MX = 500000;
const LL INF = 1LL<<62;
LL chk[MX];
VI diag[MX], rdiag[MX];
int n, m, k;
int x[MX], y[MX];

int main() {
	
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &x[i], &y[i]);
		chk[i] = INF;
		diag[x[i] + m - y[i]].pb(i);
		rdiag[x[i] + y[i]].pb(i);
	}
	int cx = 0, cy = 0, dx = 1, dy = 1;
	LL ct = 0;
	while (true) {
		if (dx == dy) {
			int d = cx + m - cy;
			for (int i = 0; i < diag[d].size(); i++) {
				int id = diag[d][i];
				chkmin(chk[id], ct + abs(cx - x[id]));
			}
		} else {
			int rd = cx + cy;
			for (int i = 0; i < rdiag[rd].size(); i++) {
				int id = rdiag[rd][i];
				chkmin(chk[id], ct + abs(cx - x[id]));
			}
		}
		int tx = dx > 0 ? (n - cx) / dx : cx;
		int ty = dy > 0 ? (m - cy) / dy : cy;
		int t = min(tx, ty);
		ct += t;
		cx += t * dx, cy += t * dy;
		if (tx == ty) {
			break;
		}
		if (tx == t) dx = -dx;
		else dy = -dy;
	}
	for (int i = 0; i < k; i++) {
		if (chk[i] == INF) puts("-1");
		else printf("%lld\n", chk[i]);
	}
	return 0;
}