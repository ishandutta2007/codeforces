#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 7;
const ll INF = (ll) 1e18 + 7;
int n, a[2][N], b[2][N], oa, ob;
ll sol;

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE


  cin >> n;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      oa += a[i][j];
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cin >> b[i][j];
      ob += b[i][j];
    }
  }
  if (oa != ob) {
    cout << "-1\n";
    return 0;
  }
  ll x0 = 0, x1 = 0;
  for (int j = 0; j < n; j++) {
    x0 += a[0][j] - b[0][j];
    x1 += a[1][j] - b[1][j];
    if (x0 > 0 && x1 < 0) {
      ll take = min(x0, -x1);
      x0 -= take;
      x1 += take;
      sol += take;
    }
    if (x1 > 0 && x0 < 0) {
      ll take = min(x1, -x0);
      x1 -= take;
      x0 += take;
      sol += take;
    }
    sol += abs(x0) + abs(x1);
  }
  cout << sol << "\n";
}


/**

**/