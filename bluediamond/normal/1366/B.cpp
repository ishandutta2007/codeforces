#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, l, r, m;
    cin >> n >> l >> m;
    r = l;
    while (m--) {
      int l2, r2;
      cin >> l2 >> r2;
      if (r2 < l || r < l2) {
        continue;
      }
      l = min(l, l2);
      r = max(r, r2);
    }
    cout << r - l + 1 << "\n";
  }
  return 0;
}