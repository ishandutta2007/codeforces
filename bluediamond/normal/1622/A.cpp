#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  //freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    vector<int> a(3);
    bool ok = 0;
    cin >> a[0] >> a[1] >> a[2];
    for (int i = 0; i < 3; i++) {
      for (int j = i + 1; j < 3; j++) {
        int k = 3 - i - j;
        if (a[i] + a[j] == a[k]) {
          ok = 1;
        }
        if (a[i] == a[j] && a[k] % 2 == 0) {
          ok = 1;
        }
      }
    }
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}