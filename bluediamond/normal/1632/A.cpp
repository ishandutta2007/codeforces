#include <bits/stdc++.h>


using namespace std;



signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int _; cin >> _;
    string s;
    cin >> s;
    if ((int)s.size() >= 3) {
      cout << "NO\n";
      continue;
    }
    if ((int)s.size() == 1) {
      cout << "YES\n";
    }
    else {
      if (s[0] != s[1]) {
        cout << "YES\n";
      }
      else {
        cout << "NO\n";
      }
    }
  }
}