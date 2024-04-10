#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    bool z = false;
    for (int i = 0; i + 1 < n; i++) {
      if (a[i] == 0 && a[i + 1] == 0) {
        z = true;
      }
    }
    if (z) {
      cout << "-1\n";
      continue;
    }
    int sol = 1;
    for (int i = 0; i < n; i++) {
      if (a[i]) {
        if (i > 0 && a[i - 1]) {
          sol += 5;
        } else {
          sol++;
        }
      }
    }
    cout << sol << "\n";
  }

  return 0;
}