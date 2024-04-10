#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

const int N = 1000 + 7;
int n, a[N][5];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> a[i][j];
      }
    }
    bool ok = 0;
    for (int x = 0; x < 5; x++) {
      for (int y = 0; y < x; y++) {
        int both = 0, fx = 0, fy = 0, bad = 0;
        for (int i = 1; i <= n; i++) {
          bad += (a[i][x] == 0 && a[i][y] == 0);
          both += (a[i][x] == 1 && a[i][y] == 1);
          fx += (a[i][x] == 1 && a[i][y] == 0);
          fy += (a[i][x] == 0 && a[i][y] == 1);
        }
        if (bad) continue;
        if (fx > n / 2 || fy > n / 2) continue;
        ok = 1;
        break;
      }
      if (ok) {
        break;
      }
    }
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}