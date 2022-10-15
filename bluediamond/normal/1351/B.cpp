#include <bits/stdc++.h>

using namespace std;



int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int a[2], b[2];
    bool ok = 0;
    cin >> a[0] >> a[1] >> b[0] >> b[1];
    for (int i = 0; i <= 1; i++) {
      for (int j = 0; j <= 1; j++) {
        if (a[i] == b[j] && a[i ^ 1] + b[j ^ 1] == a[i]) {
          ok = 1;
        }
      }
    }
    if (ok) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}