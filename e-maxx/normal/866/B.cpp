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
#include <string>
#include <vector>
using namespace std;


typedef long long int64;
#define double long double
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double EPS_ANG = 1E-16;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define mp  make_pair
#define pb  push_back


const int MAXN = 110000;

int n, npieces, eat[MAXN], a[MAXN], b[MAXN];


bool read() {
	if (!(cin >> n >> npieces))
		return false;
	forn(i, n)
		scanf("%d%d%d", &eat[i], &a[i], &b[i]);
	return true;
}


void solve() {
	int64 sumeat = 0;
	forn(i, n)
		sumeat += eat[i];

	int64 anscnt = INF64, anssum = 0;
	int64 dbganscnt = INF64, dbganssum = 0;
	for (int it=0; it<16; ++it) {
		if (it && it % 4 == 0) {
			forn(i, n)
				swap(a[i], b[i]);
		}

		vector<pair<int64,int>> order(n);
		forn(i, n)
			order[i] = mp((it < 8 ? eat[i] : 1) * 1LL * (a[i] - b[i]), i);
		sort(all(order));

		int64 sumb = 0;
		forn(i, n)
			sumb += eat[i] * 1LL * b[i];

		int64 cursuma = 0,  cureata = 0,  cursumb = sumb,  cureatb = sumeat;
		for (int j=0; j<=n; ++j) {
			int64 canscnt = (cureata + npieces - 1) / npieces + (cureatb + npieces - 1) / npieces;
			int64 canssum = cursuma + cursumb;
			if (canscnt < anscnt || canscnt == anscnt && canssum > anssum) {
				anscnt = canscnt;
				anssum = canssum;
			}
			if (j < n) {
				int i = order[it%2 == 0 ? j : n-1-j].sc;

				forn(tp, 4) {
					int64 trycnt = 0;
					if (tp == 0)
						trycnt = eat[i] - (cureata + eat[i]) % npieces;
					else if (tp == 1)
						trycnt = (npieces - cureata % npieces) % npieces;
					else if (tp == 2)
						trycnt = cureatb % npieces;
					else if (tp == 3)
						trycnt = eat[i] - (npieces - (cureatb - eat[i]) % npieces) % npieces;
					if (trycnt > 0 && trycnt < eat[i]) {
						int64 neata = cureata + trycnt;
						int64 nsuma = cursuma + trycnt * 1LL * a[i];
						int64 neatb = cureatb - trycnt;
						int64 nsumb = cursumb - trycnt * 1LL * b[i];
						int64 nanscnt = (neata + npieces - 1) / npieces + (neatb + npieces - 1) / npieces;
						int64 nanssum = nsuma + nsumb;
						if (nanscnt < anscnt || nanscnt == anscnt && nanssum > anssum) {
							anscnt = nanscnt;
							anssum = nanssum;
						}
					}
				}

				cursuma += eat[i] * 1LL * a[i];
				cureata += eat[i];
				cursumb -= eat[i] * 1LL * b[i];
				cureatb -= eat[i];
			}
		}
		if (cursumb || cureatb || cureata != sumeat)
			throw;

#ifdef EMAXX_PROJ
		cursuma = 0,  cureata = 0,  cursumb = sumb,  cureatb = sumeat;
		for (int j=0; j<=n; ++j) {
			for (int c=0; ; ++c) {
				int64 canscnt = (cureata + npieces - 1) / npieces + (cureatb + npieces - 1) / npieces;
				int64 canssum = cursuma + cursumb;
				if (canscnt < dbganscnt || canscnt == dbganscnt && canssum > dbganssum) {
					dbganscnt = canscnt;
					dbganssum = canssum;
				}
				if (j == n)
					break;
				int i = order[it%2 == 0 ? j : n - 1 - j].sc;
				if (c >= eat[i])
					break;
				cursuma += a[i];
				cureata++;
				cursumb -= b[i];
				cureatb--;
			}
		}
		if (cursumb || cureatb || cureata != sumeat)
			throw;
#endif

		if (it >= 4 && clock() >= 1.8 * CLOCKS_PER_SEC)
			break;
	}

	if (anscnt == INF64)
		throw;
	cout << anssum;
	if (dbganssum) {
		cout << " dbg=" << dbganssum;
		if (dbganssum != anssum) {
			forn(i, n) {
				cerr << eat[i] << ' ' << a[i] << ' ' << b[i] << endl;
			}
			throw;
		}
	}
	cout << endl;
}


int main() {
#ifdef EMAXX_PROJ
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

//	forn(iter, 1000000) {
//		srand(time(0));
//		n = rand() % 10 + 1;
//		npieces = rand() % 10 + 1;
//		forn(i, n) {
//			eat[i] = rand() % 10 + 1;
//			a[i] = rand() % 10 + 1;
//			b[i] = rand() % 10 + 1;
//		}
//		solve();
//	}
//	return 0;

	int tt = 0;
	while (read()) {
		cerr << "Case " << ++tt << ": starting..." << endl;
		solve();
	}
    cerr << "Finished.";

	return 0;
}