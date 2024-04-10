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


int n, m, a[MAXN];


bool read() {
  if (! (cin >> n >> m))
    return false;
  fore(i,1,n+1)
    scanf ("%d", &a[i]);
	return true;
}


int deg1[MAXN], deg2[MAXN];
bool can[MAXN];

void out (int ans) {
  puts (ans==0 ? "Not defined" : ans==+1 ? "Truth" : "Lie");
}

void solve() {
  memset (deg1, 0, sizeof deg1);
  memset (deg2, 0, sizeof deg2);
  int c1=0, c2=0;
  fore(i,1,n+1)
    if (a[i] > 0) {
      ++deg1[a[i]];
      ++c1;
    }
    else {
      ++deg2[-a[i]];
      ++c2;
    }

  int cnt = 0;
  fore(i,1,n+1) {
    int cur_m = deg1[i] + c2 - deg2[i];
    can[i] = cur_m == m;
    if (can[i])
      ++cnt;
  }

  fore(i,1,n+1) {
    if (a[i] > 0) {
      if (!can[a[i]])
        out (-1);
      else if (cnt > 1)
        out (0);
      else
        out (+1);
    }
    else {
      if (cnt == 1)
        if (can[-a[i]])
          out (-1);
        else
          out (+1);
      else
        if (can[-a[i]])
          out (0);
        else
          out (+1);
    }
  }
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