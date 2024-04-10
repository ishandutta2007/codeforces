#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 // freopen ("input", "r", stdin);

  int tt;
  cin >> tt;

  while (tt--) {
    int n;
    cin >> n;
    bool bad = 0;
    for (int i = 1; i <= n; i++) {
      int a;
      cin >> a;
      bool currentbad = 1;
      for (int j = 2; j <= i + 1; j++) {
        if (a % j) {
          currentbad = 0;
          break;
        }
      }
      if (currentbad) {
        bad = 1;
      }
    }
    if (bad) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }

  return 0;
}