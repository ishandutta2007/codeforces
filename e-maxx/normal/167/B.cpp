#pragma comment (linker, "/STACK:200000000")
#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

typedef long long int64;
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define fore(i,l,n)  for (int i=int(l); i<int(n); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define pb  push_back
#define mp  make_pair


const int MAXN = 210;


int n, l, k, per[MAXN], a[MAXN];


bool read() {
    if (! (cin >> n >> l >> k))
        return false;
    forn(i,n)
        cin >> per[i];
    forn(i,n)
        cin >> a[i];
	return true;
}


double d[MAXN][MAXN][MAXN*2];
bool u[MAXN][MAXN][MAXN*2];

double get_d (int cur, int won, int left) {
    left = min (left, n);
    if (cur == n)
        return won>=l && left>=0 ? 1 : 0;

    double & my = d[cur][won][left+MAXN];
    bool & myu = u[cur][won][left+MAXN];
    if (myu)  return my;
    myu = true;
    my = 0;

    double p = per[cur] / 100.0;

    my += get_d (cur+1, won+1, left + a[cur]) * p;
    my += get_d (cur+1, won, left) * (1 - p);

    return my;
}


void solve() {
    memset (u, 0, sizeof u);
    double ans = get_d (0, 0, k);
    printf ("%.20lf\n", ans);
}


int main() {
#ifdef SU2_PROJ
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
	while (read())
		solve();
#else
	if (!read())  throw;
	solve();
#endif
}