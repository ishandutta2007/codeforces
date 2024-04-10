#include <bits/stdc++.h>
using namespace std;

int a[4];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int x, p0 = 0;
    cin >> x;
    for (int i = 1; i <= 3; i++) {
      cin >> a[i];
      if (a[i] == 0) {
        p0 = i;
      }
    }
    if (x == p0) {
      cout << "NO\n";
      continue;
    }
    if (p0 == a[x]) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";

  }
}