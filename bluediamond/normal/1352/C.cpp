#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll cnt(ll x, ll n) {
  return x - x / n;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 /// freopen ("input", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    ll l = 1, r = (ll) 1e18, sol;
    while (l <= r) {
      ll m = (l + r) / 2;
      if (cnt(m, n) < k) {
        l = m + 1;
      } else {
        sol = m;
        r = m - 1;
      }
    }
    cout << sol << "\n";
  }
  return 0;
}