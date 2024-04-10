#include <bits/stdc++.h>; iron man

using namespace std;

#define int ll
typedef long long ll;
typedef long double ld;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  /// freopen ("input", "r", stdin);


  int t;
  cin >> t;
  while (t--) {
    int n, m;
    string s;
    cin >> n >> m >> s;
    for (int j = 1; j <= m; j++) {
      string t = s;
      for (int i = 0; i < n; i++) {
        if (t[i] == '1') continue;
        int cnt = 0;
        if (i - 1 >= 0 && s[i - 1] == '1') cnt++;
        if (i + 1 < n && s[i + 1] == '1') cnt++;
        if (cnt == 1) t[i] = '1';
      }
      if (t == s) break;
      s = t;
    }
    cout << s << "\n";
  }

  return 0;
}