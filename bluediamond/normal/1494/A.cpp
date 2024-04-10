#include <bits/stdc++.h>

using namespace std;

#define int ll
typedef long long ll;
typedef long double ld;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s[0] == s.back()) {
      cout << "NO\n";
      continue;
    }
    int n = (int) s.size();
    vector<int> t;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == s[0]) {
        t.push_back(+1);
        sum++;
      }
      if (s[i] == s.back()) {
        t.push_back(-1);
        sum--;
      }
      if (s[i] != s[0] && s[i] != s.back()) {
        t.push_back(0);
      }
    }
    if (sum < 0) {
      for (int i = 0; i < n; i++) {
        if (t[i] == 0) {
          t[i] = +1;
        }
      }
    } else {
      for (int i = 0; i < n; i++) {
        if (t[i] == 0) {
          t[i] = -1;
        }
      }
    }
    bool ok = 1;
    sum = 0;
    for (int i = 0; i < n; i++) {
      sum += t[i];
      if (sum < 0) {
        ok = 0;
      }
    }
    ok &= (sum == 0);
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}