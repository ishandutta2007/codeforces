#pragma comment(linker, "/STACK:200000000")
#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

typedef long long int64;
//#define double long double
const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const double EPS = 1E-9;
const double EPS_ANG = 1E-16;
const double PI = acos((double)0) * 2;

#define forn(i, n)  for (int i = 0; i < int(n); ++i)
#define ford(i, n)  for (int i=int(n) - 1; i >= 0; --i)
#define fore(i, l, r)  for (int i = int(l); i < int(r); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define mp  make_pair
#define pb  push_back


const int MAXN = 30;
const int MAXK = 201;


int n, k, a[MAXN];


bool read() {
	if (!(cin >> n >> k))
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	return true;
}


double p[MAXK][MAXN][MAXN];

void calc_p() {
	forn(move, k) {
		forn(i, n)
			forn(j, n) {
				double& my = p[move][i][j];
				if (!my)
					continue;

				int cnt = 0;
				forn(rl, n)
					fore(rr, rl, n)
						++cnt;
				double prob = 1.0 / cnt;

				forn(rl, n)
					fore(rr, rl, n) {
						int ni = i, nj = j;
						if (rl <= i && i <= rr)
							ni = rr - (i - rl);
						if (rl <= j && j <= rr)
							nj = rr - (j - rl);
						p[move + 1][ni][nj] += my * prob;
					}
			}
	}
}

void solve() {
	double ans = 0;
	forn(si, n)
		fore(sj, si + 1, n) {
			memset(p, 0, sizeof p);
			p[0][si][sj] = 1.0;
			calc_p();

			forn(i, n)
				forn(j, n)
					if ((i < j) != (a[si] < a[sj]))
						ans += p[k][i][j];
		}

	printf("%.20lf\n", ans);
}


int main() {
#ifdef SU2_PROJ
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	while (read())
		solve();
#else
	if (!read())
		throw;
	solve();
#endif
}