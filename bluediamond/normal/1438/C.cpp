#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int x;
        cin >> x;
        if (x % 2 != (i + j) % 2) {
          x++;
        }
        cout << x << " ";
      }
      cout << "\n";
    }
  }
}