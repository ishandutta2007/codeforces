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


int n, ax[10], ay[10], bx[10], by[10];


bool read() {
    if (!(cin >> n))
        return false;
    forn(i, n)
        cin >> ax[i] >> ay[i] >> bx[i] >> by[i];
	return true;
}


void solve() {
    int lx = INF, ly = INF, rx = -INF, ry = -INF;
    forn(i, n) {
        lx = min(lx, min(ax[i], bx[i]));
        ly = min(ly, min(ay[i], by[i]));
        rx = max(rx, max(ax[i], bx[i]));
        ry = max(ry, max(ay[i], by[i]));
    }

    int64 s = 0;
    forn(i, n)
        s += abs(ax[i] - bx[i]) * 1ll * abs(ay[i] - by[i]);

    puts((rx - lx) == (ry - ly) && s == (rx - lx) * 1ll * (ry - ly) ? "YES" : "NO");
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