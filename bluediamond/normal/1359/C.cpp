#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

ll h, c, t;

ld get(ll n) {
  ll cold = n / 2;
  ll hot = n - cold;
  ll sum = h * hot + c * cold;
  return sum / (ld) n;
}

/// hot = cold + 1
/// (h * hot + c * cold) / (hot + cold)
/// (h * (cold + 1) + c * cold) / (2 * cold + 1)
/// ((h + c) * cold + h) / (2 * cold + 1)


ll best;

void upd(ll val) {
  ld dBest = fabs(get(best) - (ld) t);
  ld dVal = fabs(get(val) - (ld) t);
  if (dBest == dVal) {
    if (val < best) {
      best = val;
      return;
    }
  }
  if (dVal < dBest) {
    best = val;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tsts;
  cin >> tsts;
  while (tsts--) {
    cin >> h >> c >> t;
    best = 1;
    upd(2);
    ll l = 0, r = (ll) 1e9, ans;
    while (l <= r) {
      ll m = (l + r) / 2;
      if (get(2 * m + 1) >= (ld) t) {
        ans = 2 * m + 1;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    upd(ans);
    upd(ans + 2);
    cout << best << "\n";
  }
  return 0;
}