#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, l, r, c = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      l = ((c += x) == 1 && x) ? i : l;
      r = x ? i : r;
    }
    cout << r - l + 1 - c << "\n";
  }
}