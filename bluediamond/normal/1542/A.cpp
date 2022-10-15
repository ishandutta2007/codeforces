#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    int n, c[2];
    cin >> n;
    c[0] = c[1] = 0;
    for (int i = 1; i <= 2 * n; i++) {
      int x;
      cin >> x;
      c[x % 2]++;
    }
    cout << ((c[0] == n) ? "Yes" : "No") << "\n";
  }

  return 0;
}