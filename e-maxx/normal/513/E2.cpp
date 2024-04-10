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


const int MAXN = 30010;
const int MAXK = 202;


int n, k, a[MAXN];


bool read() {
	if (!(cin >> n >> k))
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	return true;
}


int64 d[MAXN][MAXK][3][3];


void solve() {
	forn(i, n + 1)
		forn(j, k + 1)
			forn(tp, 3)
				forn(ltp, 3)
					d[i][j][tp][ltp] = -INF64;
	d[0][0][1][1] = 0;

	forn(i, n)
		forn(j, k + 1)
			forn(tp, 3)
				forn(ltp, 3) {
					int64& my = d[i][j][tp][ltp];
					if (my == -INF64)
						continue;
					my = my;

					for (int ntp = 0; ntp < 3; ntp += 2) {
						if (ntp != tp && ntp == ltp)
							continue;
						int nj = j + (ntp != tp);
						int coeff = (nj == 1 || nj == k ? 1 : 2) * (ntp - 1);
						d[i + 1][nj][ntp][ntp] = max(d[i + 1][nj][ntp][ntp], my + coeff * a[i]);
					}

					if (j > 0 && j < k - 1) {
						d[i + 1][j + 1][1][ltp] = max(d[i + 1][j + 1][1][ltp], my);
					}
					
					d[i + 1][j][1][ltp] = max(d[i + 1][j][1][ltp], my);
				}

	int64 ans = -INF64;
	forn(tp, 3)
		forn(ltp, 3)
			if (ltp != 1) {
				ans = max(ans, d[n][k][tp][ltp]);
				ans = ans;
			}
	cout << ans << endl;
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