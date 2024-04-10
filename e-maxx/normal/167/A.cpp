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


const int MAXN = 110000;


int n, a, d, t[MAXN], v[MAXN];


bool read() {
    if (! (cin >> n >> a >> d))
        return false;
    forn(i,n)
        scanf ("%d%d", &t[i], &v[i]);
	return true;
}


double ans[MAXN];

void solve() {
    forn(i,n) {
        double tt = min (v[i] * 1.0 / a, sqrt (d * 2.0 / a));
        double ss = a * tt * tt / 2;

        double left = d - ss;
        if (left < -EPS)  throw;

        tt += left / v[i];
        ans[i] = max (t[i] + tt, i ? ans[i-1] : -1E20);
    }

    forn(i,n)
        printf ("%.20lf\n", ans[i]);
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