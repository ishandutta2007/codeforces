#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    bool ok = 0;
    cin >> n;
    set<int> s;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      if (s.count(x)) {
        ok = 1;
        for (int j = i + 1; j <= n; j++) {
          cin >> x;
        }
        break;
      } else {
        s.insert(x);
      }
    }
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}