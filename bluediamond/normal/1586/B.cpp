#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    unordered_set<int> s;
    for (int i = 1; i <= m; i++) {
      int _, foo;
      cin >> _ >> foo >> _;
      s.insert(foo);
    }
    int foo = 1;
    while (s.count(foo)) {
      foo++;
    }
    for (int i = 1; i <= n; i++) {
      if (i != foo) {
        cout << foo << " " << i << "\n";
      }
    }
  }




  return 0;
}