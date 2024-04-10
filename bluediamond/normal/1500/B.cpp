#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;

int realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

struct math {
  ll Tgcd(ll a, ll b) {
    if (b == 0) {
      return a;
    } else {
      return Tgcd(b, a % b);
    }
  }
  ll d = 0;
  pair<ll, ll> gcd(ll a, ll b) {
    if (b == 0) {
      d = a;
      return {1, 0};
    } else {
      pair<ll, ll> it = gcd(b, a % b);
      return {it.second, it.first - a / b * it.second};
    }
  }
  pair<ll, ll> coef(ll a, ll b, ll c) {
    auto it = gcd(a, b);
    if (c % d) return {0, 0};
    it.first *= (c / d);
    it.second *= (c / d);
    return it;
  }
  ll crt(ll m1, ll m2, ll r1, ll r2) {
    pair<ll, ll> it = coef(m1, -m2, r2 - r1);
    ll t = m1 * it.first + r1, mod = m1 * m2 / abs(d);
    t %= mod;
    if (t < 0) {
      t += mod;
    }
    if (t % m1 != r1 || t % m2 != r2) {
      return -1;
    }
    return t;
  }
};

math user;

const int N = (int) 5e5 + 7;
int n, m, a[N], b[N], poz_a[2 * N];
ll k, cycle;
vector<ll> rests;

ll cnt(ll pre) {
  ll ret = 0;
  for (auto &rest : rests) {
    if (pre >= rest + 1) {
      ret += (pre - 1 - rest) / cycle + 1;
    }
  }
  return pre - ret;
}

signed realMain() {
  cin >> n >> m >> k;
  cycle = (ll) n * m / __gcd(n, m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    poz_a[a[i]] = i + 1;
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    if (poz_a[b[i]]) {
      ll rest = user.crt(n, m, poz_a[b[i]] - 1, i);
      if (rest != -1) {
        rests.push_back(rest);
      }
    }
  }
  ll l = 1, r = (ll) 1e18, ret;
  while (l <= r) {
    ll m = (l + r) / 2;
    if (cnt(m) >= k) {
      ret = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  cout << ret << "\n";
}