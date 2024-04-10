#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int t, n, id, sum;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  cin >> t;
  while (t--) {
    cin >> n >> id;
    sum = 0;
    for (int i = 1; i < n; i++) {
      int foo;
      cin >> foo;
      sum += foo;
    }
    for (int x = 1; x <= n; x++) {
      if ((sum + id + x) % n == 0) {
        cout << x << "\n";
      }
    }
  }

  return 0;
}