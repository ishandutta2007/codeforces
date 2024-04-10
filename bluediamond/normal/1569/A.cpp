#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s, t;
    cin >> n >> s;
    t = s;
    sort(t.begin(), t.end());
    if (t[0] == t.back()) {
      cout << "-1 -1\n";
    } else {
      for (int i = 0; i + 1 < (int) s.size(); i++) {
        if (s[i] != s[i + 1]) {
          cout << i + 1 << " " << i + 2 << "\n";
          break;
        }
      }
    }
  }

}