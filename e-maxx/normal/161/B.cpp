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


const int MAXN = 1100;


int n, k;
vector < pair<int,int> > tab, kar;


bool read() {
  if (! (cin >> n >> k))
    return false;
  tab.clear();
  kar.clear();
  forn(i,n) {
    int c, t;
    scanf ("%d%d", &c, &t);
    if (t == 1)
      tab.pb (mp (c, i));
    else
      kar.pb (mp (c, i));
  }
	return true;
}


vector < pair<int,int> > ans[MAXN];

void solve() {
  sort (all (tab));
  reverse (all (tab));
  
  forn(i,n)
    ans[i].clear();
  forn(i,tab.size()) {
    if (i < k)
      ans[i].pb (tab[i]);
    else
      ans[k-1].pb (tab[i]);
  }
  fore(i,tab.size(),k) {
    ans[i].pb (kar.back());
    kar.pop_back();
  }
  ans[k-1].insert (ans[k-1].end(), all (kar));

  int64 cans = 0;
  forn(i,k) {
    forn(j,ans[i].size())
      cans += ans[i][j].fs * 2;
    if (i < (int)tab.size())
      cans -= min_element (all (ans[i])) ->fs;
  }

  cout << cans/2 << '.' << cans%2*5 << endl;
  forn(i,k) {
    cout << ans[i].size();
    forn(j,ans[i].size())
      cout << ' ' << ans[i][j].sc+1;
    cout << '\n';
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