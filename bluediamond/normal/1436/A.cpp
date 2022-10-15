#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, s = 0, w;
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      s += x;
    }
    if (s == w) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

}