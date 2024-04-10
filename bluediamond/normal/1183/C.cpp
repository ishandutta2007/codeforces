#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    ll k, n, a, b;
    cin >> k >> n >> a >> b;
    ll l = 0, r = n, ans = -1;
    while (l <= r) {
      ll half = (l + r) / 2;
      if (half * a + (n - half) * b < k) {
        ans = half;
        l = half + 1;
      } else r = half - 1;
    }
    cout << ans << "\n";
  }

}