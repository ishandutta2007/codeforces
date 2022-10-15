#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, n;
  cin >> t;
  while (t--) {
    string a, b, c;
    cin >> a >> b >> c;
    n = (int) a.size();
    bool good = 1;
    for (int i = 0; i < n; i++) {
      good &= (a[i] == c[i] || b[i] == c[i]);
    }
    if (good) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}