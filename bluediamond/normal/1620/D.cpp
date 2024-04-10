#include <bits/stdc++.h>

using namespace std;

///#define int ll
typedef long long ll;
typedef long double ld;

#define int ll

const int N = 100 + 7;
int n;
int a[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

//  freopen ("input", "r", stdin);

  int t;
  cin >> t;

  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }


    int maxtake = 7;

    int sol = (int) 2e9;

    for (int t1 = 0; t1 <= maxtake; t1++) {
      for (int t2 = 0; t2 <= maxtake; t2++) {
        int cur = t1 + t2, mx = 0;
        for (int i = 1; i <= n; i++) {
          int now = (int) 2e9;
          for (int u1 = 0; u1 <= t1; u1++) {
            for (int u2 = 0; u2 <= t2; u2++) {
              int x = a[i] - u1 - 2 * u2;
              if (x >= 0 && x % 3 == 0) {
                now = min(now, x / 3);
              }
            }
          }
          mx = max(mx, now);
        }
        sol = min(sol, cur + mx);
      }
    }
    cout << sol << "\n";
  }

  return 0;
}