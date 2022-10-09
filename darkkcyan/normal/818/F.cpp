#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++i < n;)
#define sz(v) ((int)v.size())


llong edgecnt(llong n, llong m) {
  if (m <= n - 1) return m;
  if (m == n) return n - 3;
  if (m > n * (n - 1) / 2) return 0;
  m -= n - 1;
  llong t = (1 + sqrt(1 + 8 * m)) / 2 - 5;
  for (; t * (t + 1) / 2 < m; ++t);
  //clog << l << ' ' << m + n << ' ' << m << endl;
  return n - 2 - t;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int q; cin >> q;
  while (q--) {
    llong n; cin >> n;
    if (n == 1) {
      cout << 0 << '\n';
      continue;
    }
    llong l = n - 1, r = n * (n - 1) / 2;
    while (l < r) {
      llong mid = l + (r - l + 1) / 2;
      llong s = edgecnt(n, mid);
      if (s * 2 < mid) r = mid - 1;
      else l = mid;
    }
    //clog << edgecnt(n, l) << endl;
    cout << l << '\n';
  }
  return 0;
}