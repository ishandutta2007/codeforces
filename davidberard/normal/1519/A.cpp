#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    ll r, b, d;
    cin >> r >> b >> d;
    if (r > b) {
      swap(r, b);
    }
    cout << (b <= r*(d+1) ? "YES" : "NO") << "\n";
}
  return 0;
}