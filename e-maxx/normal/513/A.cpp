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


const int MAXN = 100;


int n1, n2, k1, k2;


bool read() {
	return !!(cin >> n1 >> n2 >> k1 >> k2);
}


bool d[MAXN][MAXN][2];

void solve() {
	forn(i, n1 + 1)
		forn(j, n2 + 1)
			forn(tp, 2) {
				d[i][j][tp] = false;
				int lim = tp==0 ? k1 : k2;
				fore(move, 1, lim + 1) {
					int ni = tp==0 ? i - move : i;
					int nj = tp==1 ? j - move : j;
					if (ni < 0 || nj < 0)
						continue;
					d[i][j][tp] |= !d[ni][nj][1 - tp];
				}
			}

	puts(d[n1][n2][0] ? "First" : "Second");
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