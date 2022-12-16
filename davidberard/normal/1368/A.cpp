#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    ll a, b, n;
    cin >> a >> b >> n;
    int cnt = 0;
    while (max(a, b) <= n) {
      ++cnt;
      if (a < b) {
        a += b;
      } else {
        b += a;
      }
    }
    cout << cnt << "\n";
  }
  return 0;
}