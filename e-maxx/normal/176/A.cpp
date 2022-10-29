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
#include <stack>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


typedef long long int64;
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double PI = acos(0.0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define mp  make_pair
#define pb  push_back


const int MAXN = 110;


int n, m, k, a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN];


bool read() {
	if (! (cin >> n >> m >> k))
		return false;
	forn(i,n) {
		char buf[1000];
		scanf (" %s", buf);
		forn(j,m)
			scanf ("%d%d%d", &a[i][j], &b[i][j], &c[i][j]);
	}
	return true;
}


void solve() {
	int ans = 0;
	forn(from,n)
		forn(to,n) {
			if (from == to)  continue;

			vector < pair<int,int> > v (m);
			forn(i,m) {
				v[i].fs = -a[from][i] + b[to][i];
				v[i].sc = c[from][i];
			}

			sort (all (v));
			reverse (all (v));

			int kk = k,  cans = 0;
			forn(i,m) {
				if (v[i].fs < 0)  break;
				int cur = min (kk, v[i].sc);
				kk -= cur;
				cans += cur * v[i].fs;
			}
			ans = max (ans, cans);
		}
	cout << ans << endl;
}


int main() {
#ifdef SU2_PROJ
	cerr << "A" << endl;
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	while (read())
		solve();

}