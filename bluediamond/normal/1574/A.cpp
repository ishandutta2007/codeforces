#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  //freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int cnt = 1; cnt <= n; cnt++) {
      for (int i = 1; i <= cnt; i++) cout << "(";
      for (int i = 1; i <= cnt; i++) cout << ")";
      for (int i = cnt + 1; i <= n; i++) cout << "()";
      cout << "\n";
    }
  }

  return 0;
}