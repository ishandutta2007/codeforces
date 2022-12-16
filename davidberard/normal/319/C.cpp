#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

struct Line {
  mutable ll k, m, p;
  bool operator<(const Line& o) const { return k < o.k; }
  bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
  const ll inf = LLONG_MAX;
  ll div(ll a, ll b) {
    return a / b - ((a ^ b) < 0 && a % b); }
  bool isect(iterator x, iterator y) {
    if (y == end()) { x->p = inf; return false; }
    if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
    else x->p = div(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
  }
  void add(ll k, ll m) {
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p)
      isect(x, erase(y));
  }
  ll query(ll x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return l.k * x + l.m;
  }
};

const int N = 100100;
ll a[N], b[N];

ll dp[N];
int n;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  for (int i=1; i<=n; ++i) {
    cin >> b[i];
  }
  LineContainer lc;
  lc.add(-b[1], 0);
  dp[1] = 0;
  for (int i=2; i<=n; ++i) {
    dp[i] = -lc.query(a[i]);
    lc.add(-b[i], -dp[i]);
  }
  cout << dp[n] << endl;
  return 0;
}