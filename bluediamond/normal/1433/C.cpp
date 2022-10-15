#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, m, M, p, y;
    cin >> n >> y;
    M = m = y;
    for (int i = 1; i < n; i++) {
      int x;
      cin >> x;
      m = min(m, x);
      M = max(M, x);
      p = (x == M && y != M) ? i : p;
      p = (y == M && x != M) ? (i - 1) : p;
      y = x;
    }
    cout << ((m == M) ? -1 : (p + 1)) << "\n";
  }
}