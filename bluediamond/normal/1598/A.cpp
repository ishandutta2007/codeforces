#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll



signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
    bool ok = 1;
    ok &= (s[0] == '0');
    ok &= (t.back() == '0');
    for (int i = 0; i < (int) s.size(); i++) {
      ok &= (s[i] == '0' || t[i] == '0');
    }
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}