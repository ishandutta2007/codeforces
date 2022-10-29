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


int n, c[5];


bool read() {
  if (! (cin >> n))
    return false;
  memset (c, 0, sizeof c);
  forn(i,n) {
    int x;
    scanf ("%d", &x);
    ++c[x];
  }
	return true;
}


void solve() {
  int ans = 0;

  ans += c[4];
  c[4] = 0;

  ans += c[3];
  c[1] -= min (c[3], c[1]);
  c[3] = 0;

  ans += c[2] / 2;
  c[2] %= 2;
  if (c[2]) {
    ++ans;
    c[1] -= min (c[1], 2);
    c[2] = 0;
  }

  ans += (c[1]+3) / 4;
  c[1] = 0;

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