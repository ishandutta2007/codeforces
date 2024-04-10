#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N = 999999 + 7;
const ll INF = (ll) 1e18;
ll n;
ll k;
ll q;
ll sum;
ll f[100];
ll val[100];
ll best[N];

ll get(ll x) {
  ll p = 0, sol = 0;
  while (x) {
    ll cif = x % 10;
    if (cif % 3 == 0) {
      sol += (cif / 3) * f[p];
    }
    x /= 10;
    p++;
  }
  return sol;
}

struct T {
  ll profit;
  ll ocup;
};

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


  cin >> k >> f[0] >> f[1] >> f[2] >> f[3] >> f[4] >> f[5] >> q;
  ll lim = log2(3 * (k - 1));
  for (ll i = 0; i < lim; i++) {
    val[i] = (1 << i);
  }
  val[lim] = 3 * (k - 1);
  for (ll i = 0; i < lim; i++) {
    val[lim] -= val[i];
  }
  for (ll i = 1; i < N; i++) {
    best[i] = get(i);
  }
  for (ll j = 0; j <= lim; j++) {
    ll ocup = 3 * val[j];
    for (ll ob = 0; ob <= 5; ob++) {
      ll profit = (ll) val[j] * f[ob];
      for (ll i = N - ocup - 1; i >= 0; i--) {
        best[i + ocup] = max(best[i + ocup], best[i] + profit);
      }
      ocup *= 10;
    }
  }
  for (ll i = 1; i <= q; i++) {
    cin >> sum;
    cout << best[sum] << "\n";
  }


}