#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 101
char a[maxn][maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m; cin >> n >> m;
  rep(i, n) cin >> a[i];
  int lm, rm, um, dm;
  bool ok = 1;
  for (um = 0; um < n; ++um) {
    rep(i, m) if (a[um][i] == '*') ok = 0;
    if (!ok) break;
  }
  for (dm = n - 1, ok = 1; dm >= 0 and ok; --dm) {
    rep(i, m) if (a[dm][i] == '*') ok = 0;
    if (!ok) break;
  }
  for (lm = 0, ok = 1; lm < m and ok; ++lm) {
    rep(i, n) if (a[i][lm] == '*') ok = 0;
    if (!ok) break;
  }
  for (rm = m - 1, ok = 1; rm >= 0 and ok; --rm) {
    rep(i, n) if (a[i][rm] == '*') ok = 0;
    if (!ok) break;
  }
  clog << lm << ' ' << rm << ' ' << um << ' ' << dm << endl;
  for (int i = um; i <= dm; ++i) {
    for (int f = lm; f <= rm; ++f) cout << a[i][f];
    cout << '\n';
  }
  
  return 0;
}