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
    vector<string> mp(2);
    for (int i = 0; i < 2; i++) {
      cin >> mp[i];
    }
    bool ok = true;
    for (int j = 0; j < n; j++) {
      if (mp[0][j] == '1' && mp[1][j] == '1') {
        ok = false;
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