#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    int n = s.size();
    vector<int> ans;
    vector<bool> rem(n, false);
    for (int i = 2; i < n; ++i) {
      if (s[i] == 'o' && s[i - 1] == 'w' && s[i - 2] == 't') {
        if (i + 1 < n && s[i + 1] == 'o') {
          ans.push_back(i);
          rem[i - 1] = true;
        } else {
          ans.push_back(i + 1);
          rem[i] = true;
        }
      }
      if (s[i] == 'e' && s[i - 1] == 'n' && s[i - 2] == 'o') {
        if (rem[i - 2]) continue;
        if (i + 1 < n && s[i + 1] == 'e') {
          ans.push_back(i);
          rem[i - 1] = true;
        } else {
          ans.push_back(i + 1);
          rem[i] = true;
        }
      }
    }
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << " "; 
    cout << '\n';
  }
  return 0;
}