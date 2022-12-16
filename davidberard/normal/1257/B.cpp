#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    ll x,y;
    cin >> x >> y;
    if (x == 1) {
    } else if (x == 2 || x == 3) {
      x = 3;
    } else {
      x = 2e9;
    }
    cout << (x>=y ? "YES" : "NO") << "\n";
  }
  return 0;
}