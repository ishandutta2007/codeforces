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


const int MAXN = 50010;
const int MAXK = 505;


int n, k;
vector<int> g[MAXN];


bool read() {
  if (! (cin >> n >> k))
    return false;
  forn(i,n)
    g[i].clear();
  forn(i,n-1) {
    int a, b;
    scanf ("%d%d", &a, &b);
    --a, --b;
    g[a].pb (b);
    g[b].pb (a);
  }
	return true;
}


int64 ans;
unsigned short c[MAXN][MAXK];

void dfs (int v, int par = -1) {
  ++c[v][0];
  forn(i,g[v].size()) {
    int to = g[v][i];
    if (to == par)  continue;
    dfs (to, v);

    forn(j,k)
      ans += int64(c[v][k-j-1]) * int64(c[to][j]);
    forn(j,k)
      c[v][j+1] += c[to][j];
  }
}


void solve() {
  memset (c, 0, sizeof c);
  ans = 0;
  dfs (0);
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