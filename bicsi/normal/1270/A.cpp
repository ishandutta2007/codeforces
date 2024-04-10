#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n, a, b; cin >> n >> a >> b;
    int max1 = -1, max2 = -1;
    for (int i = 0; i < a; ++i) {
      int x; cin >> x; max1 = max(max1, x);
    }
    for (int i = 0; i < b; ++i) {
      int x; cin >> x; max2 = max(max2, x);
    }
    if (max1 > max2) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}