#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

int g(int x) {
  return x * (x + 1) / 2;
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int ca = n - 2, cb = 2;
    for (int i = 1; i <= n; i++) {
      int sa;
      if (cb == 0) {
        ca--;
        cout << "a";
        continue;
      }
      if (cb == 1) {
        sa = ca;
      }
      if (cb == 2) {
        sa = g(ca);
      }
      if (k <= sa) {
        ca--;
        cout << "a";
      } else {
        cb--;
        k -= sa;
        cout << "b";
      }
    }
    cout << "\n";
  }
}