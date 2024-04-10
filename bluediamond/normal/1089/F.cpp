#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int ll
typedef long long ll;
///typedef long double ld;
typedef unsigned long long ull;

signed realMain();

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
} user;

int n, narnia;

bool prime(int x) {
  if (x <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}

vector<int> divis;

signed realMain() {
  cin >> n;
  narnia = n;
  vector<int> primes;
  for (int i = 2; i * i <= n; i++) {
    bool is = 0;
    while (n % i == 0) {
      n /= i;
      is = 1;
    }
    if (is) {
      primes.push_back(i);
    }
  }
  if (n > 1) {
    primes.push_back(n);
  }
  if ((int) primes.size() == 1) {
    cout << "NO\n";
    return 0;
  }
  n = narnia;
  assert((int) primes.size() >= 2);
  int p1 = primes[0], p2 = primes[1];
  auto it = user.coef(p1, p2, n - 1);
  int c1 = it.first, c2 = it.second;
  if (c1 < 0) {
    int x = (-c1 - 1) / p2 + 1;
    c1 += p2 * x;
    c2 -= p1 * x;
  }
  if (c2 < 0) {
    int x = (-c2 - 1) / p1 + 1;
    c2 += p1 * x;
    c1 -= p2 * x;
  }
  p1 = n / p1;
  p2 = n / p2;
  cout << "YES\n";
  vector<pair<int, int>> ret;
  while (c1 >= p1) {
    ret.push_back({p1 - 1, p1});
    c1 -= (p1 - 1);
  }
  while (c2 >= p2) {
    ret.push_back({p2 - 1, p2});
    c2 -= (p2 - 1);
  }
  if (c1) {
    ret.push_back({c1, p1});
  }
  if (c2) {
    ret.push_back({c2, p2});
  }

  cout << (int) ret.size() << "\n";
  for (auto &x : ret) {
    cout << x.first << " " << x.second << "\n";
  }
  cout << "\n";
  return 0;
}