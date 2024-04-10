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


int l1, r1, l2, r2;


bool read() {
	return !! (cin >> l1 >> r1 >> l2 >> r2);
}


void upd (pair<int,int> & p, int l, int r) {
  if (p == mp(-1,-1) || r-l > p.sc-p.fs)
    p = mp(l,r);
}


struct item {
  pair<int,int> pref, suf, mid;

  item (int l, int r) {
    pref = mp(-1,-1);
    suf = mp(-1,-1);
    mid = mp(l,r);
  }

  item cut (int k) const {
    item res(-1,-1);

    int len = (1<<k)-1,
      nlen = (1<<(k-1))-1;

    forn(i,3) {
      pair<int,int> p = get(i);
      if (p == mp(-1,-1)) continue;

      int l1 = p.fs,
        r1 = min(p.sc,nlen-1);
      if (l1 <= r1) {
        if (l1 == 0)
          upd (res.pref, l1, r1);
        else if (r1 == nlen-1)
          upd (res.suf, l1, r1);
        else
          upd (res.mid, l1, r1);
      }

      int l2 = max(nlen+1,p.fs)-nlen-1,
        r2 = p.sc-nlen-1;
      if (l2 <= r2) {
        if (l2 == 0)
          upd (res.pref, l2, r2);
        else if (r2 == nlen-1)
          upd (res.suf, l2, r2);
        else
          upd (res.mid, l2, r2);
      }
    }

    return res;
  }

  pair<int,int> get (int idx) const {
    return idx==0 ? pref : idx==1 ? suf : mid;
  }
};

int intersect (pair<int,int> a, pair<int,int> b) {
  if (a.fs<0 || b.fs<0)  return 0;
  int l = max (a.fs, b.fs),
    r = min (a.sc, b.sc);
  return r-l+1;
}


void solve() {
  item a (l1-1, r1-1),
    b (l2-1, r2-1);

  int ans = 0;
  for (int k=30; k>=1; --k) {
    forn(i,3)
      forn(j,3) {
        int cans = intersect (a.get(i), b.get(j));
        ans = max (ans, cans);
      }

    a = a.cut (k);
    b = b.cut (k);
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