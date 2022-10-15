#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, mx;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int mn;
    cin >> mn;
    for (int j = 1; j < m; j++) {
      int x;
      cin >> x;
      mn = min(mn, x);
    }
    mx = max(mx, mn);
  }
  cout << mx << "\n";


  return 0;
}