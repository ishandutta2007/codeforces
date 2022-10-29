#pragma comment (linker, "/STACK:200000000")
#define _CRT_SECURE_NO_DEPRECATE
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


const int MAXN = 1100*1000;


int n, m, a[MAXN], b[MAXN];


bool read() {
    if (! (cin >> n >> m))
        return false;
    forn(i,n)
        scanf ("%d", &a[i]);
    forn(j,m)
        scanf ("%d", &b[j]);
    return true;
}


int bpos[MAXN], q[MAXN*3], qh, qt;


void solve() {
    memset (bpos, -1, sizeof bpos);
    forn(i,m)
        bpos[b[i]] = i;

    int r = -1,  len = 0,  ans = 0;
    qh = qt = 0;
    bool overlap = false;
    forn(l,n) {
        if (len == 0)
            r = (l-1+n)%n;
        while (len < n) {
            int ch = a[(r+1)%n];
            if (bpos[ch] == -1)  break;

            if (len > 0 && bpos[ch] < q[qt-1]) {
                if (overlap)  break;
                if (bpos[ch] > q[qh])  break;
                overlap = true;
            }
            if (len > 0 && overlap && bpos[ch] > q[qh])  break;

            q[qt++] = bpos[ch];
            r = (r+1)%n;
            ++len;
        }

        ans = max (ans, len);

        if (len > 0) {
            if (len>=2 && q[qh] > q[qh+1])
                overlap = false;
            --len,  ++qh;
            if (len <= 1)
                overlap = false;
        }
    }
    cout << ans << endl;
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