#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    bool ok = 1;
    map<int, int> f;
    for (int i = 0; i < n; i++) {
      ll x;
      cin >> x;
      int cur = 0;
      while (x) {
        int y = x % k;
        f[cur] += y;
        ok &= (f[cur] <= 1);
        cur++;
        x /= k;
      }
    }
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}