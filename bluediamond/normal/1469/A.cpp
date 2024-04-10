#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = (int) s.size();
    bool ok = (n % 2 == 0);
    if (s[0] == ')') ok = 0;
    if (s.back() == '(') ok = 0;
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

}