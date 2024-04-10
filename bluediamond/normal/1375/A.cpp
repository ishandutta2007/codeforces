#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      x = abs(x);
      if (i % 2 == 1) {
        x *= -1;
      }
      cout << x << " ";
    }
    cout << "\n";
  }
}