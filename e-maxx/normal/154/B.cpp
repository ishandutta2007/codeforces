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


vector<int> divs[MAXN];
int n, m;


bool read() {
	return !! (cin >> n >> m);
}


bool on[MAXN];
vector<int> used[MAXN];

inline void upd_vec (vector<int> & u) {
  while (u.size() && !on[u.back()])
    u.pop_back();
}


void solve() {
  memset (on, 0, sizeof on);
  forn(i,MAXN)
    used[i].clear();

  forn(i,m) {
    char tp;
    int x;
    scanf (" %c %d", &tp, &x);

    if (tp == '+') {

      if (on[x])
        puts ("Already on");
      else {
        bool ok = true;
        forn(j,divs[x].size()) {
          int y = divs[x][j];
          upd_vec (used[y]);
          if (used[y].size()) {
            printf ("Conflict with %d\n", used[y][0]);
            ok = false;
            break;
          }
        }
        if (ok) {
          on[x] = true;
          puts ("Success");
          forn(j,divs[x].size()) {
            int y = divs[x][j];
            used[y].pb (x);
          }
        }
      }

    }
    else {

      if (!on[x])
        puts ("Already off");
      else {
        on[x] = false;
        puts ("Success");
      }

    }
  }
}


int main() {
  fore(i,1,MAXN) {
    for (int j=1; j*j<=i; ++j)
      if (i % j == 0) {
        if (j > 1)
          divs[i].pb (j);
        if (i/j != j && i/j > 1)
          divs[i].pb (i/j);
      }
  }

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