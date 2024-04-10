#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<bool> take(10, 0);
    for (int i = 9; i >= 1; i--) {
      if (i <= n) {
        n -= i;
        take[i] = 1;
      }
    }
    if (n > 0) {
      cout << "-1\n";
      continue;
    }
    for (int i = 1; i <= 9; i++) {
      if (take[i]) {
        cout << i;
      }
    }
    cout << "\n";
  }
}