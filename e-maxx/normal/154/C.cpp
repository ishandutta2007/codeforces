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


const int MAXN = 1100*1000;


int n, m;
vector<int> g[MAXN];


bool read() {
  if (! (cin >> n >> m))
    return false;
  forn(i,n)
    g[i].clear();
  forn(i,m) {
    int a, b;
    scanf ("%d%d", &a, &b);
    --a, --b;
    g[a].pb (b);
    g[b].pb (a);
  }
	return true;
}


int64 h[MAXN], pw[MAXN], v[MAXN];


void solve() {
  forn(i,n) {
    h[i] = 0;
    forn(j,g[i].size())
      h[i] += pw[g[i][j]];
    v[i] = h[i];
  }
  sort (v, v+n);

  int64 ans = 0;
  forn(i,n) {
    int j = i;
    while (j+1 < n && v[i] == v[j+1])
      ++j;

    int len = j-i+1;
    ans += len * 1ll * (len - 1) / 2;

    i = j;
  }

  forn(v,n)
    forn(j,g[v].size()) {
      int to = g[v][j];
      if (to < v)  continue;
      
      int64 h1 = h[v] - pw[to];
      int64 h2 = h[to] - pw[v];
      if (h1 == h2)
        ++ans;
    }

  cout << ans << endl;
}


int main() {
  forn(i,MAXN)
    pw[i] = i ? pw[i-1] * 97 : 1;

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