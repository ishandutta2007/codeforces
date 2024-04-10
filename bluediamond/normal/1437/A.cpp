#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    if (r >= 2 * l) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }

}