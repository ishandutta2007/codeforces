#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


vector<ll> dpx;
ll global_a, global_border;

void dfs(int state, int sgn, ll prod) {
  if (state == (int) dpx.size()) {
    global_a += sgn * (global_border / prod);
    return;
  }
  dfs(state + 1, sgn, prod);
  if (prod <= global_border / dpx[state]) {
    dfs(state + 1, -sgn, prod * dpx[state]);
  }
}

ll cnt(ll border, ll x) {
  global_a = 0;
  global_border = border;
  dpx.clear();
  for (ll d = 2; d * d <= x; d++) {
    bool is = 0;
    while (x % d == 0) {
      x /= d;
      is = 1;
    }
    if (is) dpx.push_back(d);
  }
  if (x > 1) dpx.push_back(x);
  dfs(0, 1, 1);
  return global_a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    ll x, p, k;
    cin >> x >> p >> k;
    ll before = cnt(x, p);
    ll lo = x, hi = (ll) 1e18, ans;
    while (lo <= hi) {
      ll mid = (lo + hi) / 2;
      ll intv = cnt(mid, p) - before;
      if (intv >= k) {
        ans = mid;
        hi = mid - 1;
      } else lo = mid + 1;
    }
    cout << ans << "\n";
  }


}