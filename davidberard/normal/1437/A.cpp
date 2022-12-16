#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int TT;
  cin >> TT;
  while (TT--) {
    ll l, r;
    cin >> l >> r;
    if (r < l*2) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}