#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    int l, r;
    cin >> l >> r;

    int a = (r - 1) / 2 + 1;
    if (a < l) {
      a = l;
    }
    cout << min(a - 1, r - a) << "\n";

  }

  return 0;
}