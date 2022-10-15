#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll inf = (ll) 1e18 + 7;

ll mult(ll a, ll b) {
  if (a == 0 || b == 0) return 0;
  if (a <= inf / b) return a * b;
  return inf;
}

vector<ll> glb, sol;

void place(int i, ll x) {
  if (i >= (int) glb.size()) {if (x <= (ll) 1e18) sol.push_back(x); return;}
  place(i + 1, x);
  while (1) {
    ll nxt = mult(x, glb[i]);
    if (nxt == x) break;
    x = nxt;
    place(i + 1, x);
  }
}



vector<ll> get(vector<ll> a) {
  glb = a;
  sol.clear();
  place(0, 1);
  sort(sol.begin(), sol.end());
  for (int i = 1; i < (int) sol.size(); i++) {
    assert(sol[i] != sol[i - 1]);
  }
  return sol;
}

ll cnt(vector<ll> &x, vector<ll> &y, ll lim) {
  assert(!x.empty());
  assert(!y.empty());
  ll sol = 0;
  int p = (int) y.size() - 1;
  for (auto &num : x) {
    while (mult(num, y[p]) > lim) {
      if (!p) return sol;
      p--;
    }
    sol += p + 1;
  }
  return sol;
}

signed main() {
 /// freopen ("input", "r", stdin);

  int n;
  cin >> n;
  vector<int> p(n);
  for (auto &x : p) {
    cin >> x;
  }
  ll k;
  cin >> k;
  sort(p.begin(), p.end());
  vector<vector<ll>> a(2);
  for (int i = 0; i < n; i++) {
    a[i % 2].push_back(p[i]);
  }
  vector<ll> x, y;
  x = get(a[0]);
  y = get(a[1]);
  ll l = 0, r = (ll) 1e18, sol = -1;
  while (l <= r) {
    ll m = (l + r) / 2;
    if (cnt(x, y, m) >= k) {
      sol = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  assert(sol != -1);
  cout << sol << "\n";
  return 0;
}