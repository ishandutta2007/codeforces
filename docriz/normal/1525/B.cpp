#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<int> b = a;
    sort(b.begin() + 1, b.end());
    bool sorted = true;
    for (int i = 1; i <= n; i++) {
      if (a[i] != b[i]) {
        sorted = false;
      }
    }
    if (sorted) {
      cout << "0\n";
      continue;
    }
    if (a[1] == 1 || a[n] == n) {
      cout << "1\n";
    } else if (a[1] != n || a[n] != 1) {
      cout << "2\n";
    } else {
      cout << "3\n";
    }
  }
  return 0;
}