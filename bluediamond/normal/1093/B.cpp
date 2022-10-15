#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (s[0] == s.back()) {
      cout << "-1\n";
    } else {
      cout << s << "\n";
    }
  }

}