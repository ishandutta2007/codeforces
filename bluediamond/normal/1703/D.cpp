#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<string> s(n);
    for (string& z: s) cin >> z;
    set<string> p(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
      bool found = 0;
      int k = s[i].size();
      for (int j = 1; j < k; j++) {
        if (p.count(s[i].substr(0, j)) && p.count(s[i].substr(j))) {
          found = 1;
        }
      }
      cout << found;
    }
    cout << '\n';
  }
}