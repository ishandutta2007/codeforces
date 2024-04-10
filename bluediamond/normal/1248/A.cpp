#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, m, f0 = 0, f1 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      f1 += x % 2;
    }
    f0 = n - f1;
    cin >> m;
    ll sol = 0;
    for (int i = 1; i <= m; i++) {
      int x;
      cin >> x;
      if (x % 2) {
        sol += f1;
      } else {
        sol += f0;
      }
    }
    cout << sol << "\n";
  }

}