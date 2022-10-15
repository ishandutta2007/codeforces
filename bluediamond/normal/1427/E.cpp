#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rng((long long) (new char));

struct T {
  ll x;
  ll y;
  bool type;
  /// type = 0 => +
  /// type = 1 => ^
};

ll L = (ll) 5e18;
set<ll> s;
vector<ll> vec;
vector<T> sol;

bool ins(ll x) {
  if (x > L || s.count(x)) {
    return 0;
  }
  s.insert(x);
  vec.push_back(x);
  return 1;
}

bool sum(ll x, ll y) {
  if (ins(x + y)) {
    sol.push_back({x, y, 0});
    return 1;
  }
  return 0;
}

bool xo(ll x, ll y) {
  if (ins(x ^ y)) {
    sol.push_back({x, y, 1});
    return 1;
  }
  return 0;
}

pair<ll, ll> gcd(ll a, ll b) {
  if (b == 0) {
    return {1, 0};
  } else {
    pair<ll, ll> it = gcd(b, a % b);
    return {it.second, it.first - (a / b) * it.second};
  }
}

void form(ll x, ll t) {
  /// x * t
  if (s.count(x * t)) {
    return;
  }
  if (t & 1) {
    form(x, t - 1);
    sum(x * (t - 1), x);
  } else {
    form(x, t / 2);
    sum(x * (t / 2), x * (t / 2));
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll x;
  cin >> x;
  ins(x);
  ll k = log2(x);
  k = 1 << k;
  form(x, k);
  xo(x * k, x);
  pair<ll, ll> p = {x, (x * k) ^ x};
  x = p.first;
  ll y = p.second;
  p = gcd(x, y);
  ll a = p.first;
  ll b = p.second;
  /// a * x + b * y = 1
  b *= -1;
  /// a * x - b * y = 1
  if (a < 0) {
    a *= -1;
    b *= -1;
    swap(a, b);
    swap(x, y);
  }
  if (b & 1) {
    b += x;
    a += y;
  }
  form(x, a);
  form(y, b);
  ll f = a * x;
  ll s = b * y;
  xo(f, s);
  cout << (int) sol.size() << "\n";
  for (auto &it : sol) {
    if (it.type == 0) {
      cout << it.x << " + " << it.y << "\n";
    } else {
      cout << it.x << " ^ " << it.y << "\n";
    }
  }
}