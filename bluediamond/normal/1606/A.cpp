#include <bits/stdc++.h>

using namespace std;

bool home = 1;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("input", "r", stdin);
  }

  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    if (s[0] != s.back()) s.back() = s[0];
    cout << s << "\n";
  }

  return 0;
}