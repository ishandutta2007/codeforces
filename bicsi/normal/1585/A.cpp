#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int last = -1;
    int bad = 0, h = 1;
    for (int i = 0; i < n; ++i) {
      int x; cin >> x;
      if (x == 0) {
        if (last == 0) {
          bad = 1;
        } 
      } else {
        if (last > 0) h += 5;
        else h += 1;
      }
      last = x;
    }
    if (bad) cout << -1 << '\n';
    else cout << h << '\n';
  }

  return 0;
}