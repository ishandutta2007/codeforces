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


int n, m, x, y;
pair<int,int> a[MAXN], b[MAXN];


bool read() {
  if (! (cin >> n >> m >> x >> y))
    return false;
  forn(i,n) {
    scanf ("%d", &a[i].fs);
    a[i].sc = i;
  }
  forn(i,m) {
    scanf ("%d", &b[i].fs);
    b[i].sc = i;
  }
	return true;
}


void solve() {
  sort (a, a+n);
  sort (b, b+m);
  int j = 0;
  vector < pair<int,int> > ans;
  forn(i,n) {
    while (j<m && b[j].fs < a[i].fs-x)
      ++j;
    if (j<m && b[j].fs <= a[i].fs+y) {
      ans.pb (mp (a[i].sc, b[j].sc));
      ++j;
    }
  }
  
  cout << ans.size() << endl;
  forn(i,ans.size())
    printf ("%d %d\n", ans[i].fs+1, ans[i].sc+1);
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