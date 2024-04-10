#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> d(n);
    for (int& x: d) cin >> x;
    vector<int> a(n);
    int s = 0;
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      if (d[i] > 0 && d[i] <= s) ok = 0;
      a[i] = s += d[i];
    }
    if (!ok) cout << "-1\n";
    else {
      for (int x: a) {
        cout << x << ' ';
      }
      cout << '\n';
    }
  }
}