#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll n, g, b;

ll cnt(ll t) {
  ll full = t / (g + b);
  ll rem = t - full * (g + b);
  if (rem > g) {
    rem = g;
  }
  return full * g + rem;

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> g >> b;
    ll a = (n + 1) / 2;
    ll l = n, r = (ll) 1e18, ans = 0;
    while (l <= r) {
      ll mid = (l + r) / 2;
      ll ff = cnt(mid);
      if (ff >= a) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << ans << "\n";
  }

}