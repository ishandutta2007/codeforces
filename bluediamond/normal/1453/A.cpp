#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    bitset<100> b;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      b[x - 1] = 1;
    }
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      b[x - 1] = 1;
    }
    cout << n + m - b.count() << "\n";
  }
}