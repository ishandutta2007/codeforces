#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    vector<int> a(4);
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    int sol = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = i + 1; j < 4; j++) {
        int mn1 = min(a[i], a[j]);
        int mn2 = (int) 2e9;
        for (int k = 0; k < 4; k++) {
          if (k != i && k != j) {
            mn2 = min(mn2, a[k]);
          }
        }
        sol = max(sol, mn1 * mn2);
      }
    }
    cout << sol << "\n";
  }


}