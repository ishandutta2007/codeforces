#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

// # matches < x, including 0 i.e. [0, x)
ll match(ll a, ll b, ll x) {
  ll p = a*b/__gcd(a, b);
  ll m = max(a, b);
  ll ans = (x/p)*m;
  ans += min(x-(x/p)*p, m);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    ll a, b, q;
    cin >> a >> b >> q;
    for (int i=0; i<q; ++i) {
      ll l, r;
      cin >> l >> r;
      ll bad = match(a, b, r+1) - match(a, b, l);
      cout << r+1-l-bad << " ";
    }
    cout << "\n";
  }
  return 0;
}