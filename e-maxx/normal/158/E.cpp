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


const int MAXN = 4100;
const int MAXT = 86400;


int n, k, start[MAXN], len[MAXN];


bool read() {
  if (! (cin >> n >> k))
    return false;
  forn(i,n)
    cin >> start[i] >> len[i];
	return true;
}



int idx, d[2][3*MAXT];


void solve() {
  idx = 0;
  fore(t,1,MAXT+10)
    d[idx][t] = 0;

  int ans = 0;
  forn(i,n+1) {

    {
      int *dd = d[idx];
      fore(t,1,MAXT+10)
        if (dd[t] <= k) {
          int next = i + (k - dd[t]);
          int next_t = next<n ? start[next] : MAXT+1;
          ans = max (ans, next_t - t);
        }
    }

    if (i == n)  break;
    idx ^= 1;
    
    int *dd = d[idx];
    fore(t,1,MAXT+10)
      dd[t] = INF;
    
    int *prevd = d[idx^1];
    fore(t,1,MAXT+10) {
      int val = prevd[t];
      if (val == INF)  continue;

      int end = max (t, start[i]) + len[i];
      dd[end] = min (dd[end], val);

      dd[t] = min (dd[t], val + 1);
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