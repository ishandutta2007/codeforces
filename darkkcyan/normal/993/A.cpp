#include<bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ii a[2][4];
  int minx[2], maxx[2], miny[2], maxy[2];
  rep(i, 2) {
    minx[i] = miny[i] = 1000000;
    maxx[i] = maxy[i] = -1000000;
  }
  rep(f, 2) {
    rep(i, 4) {
      cin >> a[f][i].xx >> a[f][i].yy;
      a[f][i].xx *= 2;
      a[f][i].yy *= 2;
      if (f) {
        ii t(a[f][i].xx - a[f][i].yy, a[f][i].xx + a[f][i].yy);
        a[f][i] = t;
      }
      minx[f] = min(minx[f], a[f][i].xx);
      maxx[f] = max(maxx[f], a[f][i].xx);
      maxy[f] = max(maxy[f], a[f][i].yy);
      miny[f] = min(miny[f], a[f][i].yy);
    }
  }

  for (int x = minx[0]; x <= maxx[0]; ++x)
    for (int y = miny[0]; y <= maxy[0]; ++y) {
      int u = x - y, v = x + y;
      if (minx[1] <= u and u <= maxx[1] and miny[1] <= v and v <= maxy[1]) {
        cout << "YES";
        return 0;
      }
    }
  cout << "NO";
  return 0;
}