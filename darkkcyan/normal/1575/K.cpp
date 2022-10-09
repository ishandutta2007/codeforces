#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

template<int MOD>
struct modInt {
  int x;

  void normalize() {
    if (x < 0) x += MOD;
    else if (x >= MOD) x -= MOD;
  }

  modInt() = default;

  modInt(int x) : x(x) {
    normalize();
  }

  modInt(ll x) : x(int(x % MOD)) {
    normalize();
  }

  friend modInt operator+(const modInt &a, const modInt &b) {
    return modInt(a.x + b.x);
  }

  friend modInt operator-(const modInt &a, const modInt &b) {
    return modInt(a.x - b.x);
  }

  friend modInt operator*(const modInt &a, const modInt &b) {
    return modInt((ll) a.x * b.x);
  }

  friend modInt operator/(modInt a, modInt b) {
    int p = MOD - 2;
    while (p > 0) {
      if (p % 2) {
        a = a * b;
      }
      b = b * b;
      p /= 2;
    }
    return a;
  }

  modInt &operator+=(const modInt &b) {
    return *this = *this + b;
  }

  modInt &operator-=(const modInt &b) {
    return *this = *this - b;
  }

  modInt &operator*=(const modInt &b) {
    return *this = *this * b;
  }

  modInt &operator/=(const modInt &b) {
    return *this = *this / b;
  }

  bool operator<(const modInt &other) const {
    return x < other.x;
  }

  bool operator>(const modInt &other) const {
    return x > other.x;
  }

  bool operator<=(const modInt &other) const {
    return x <= other.x;
  }

  bool operator>=(const modInt &other) const {
    return x >= other.x;
  }

  bool operator==(const modInt &other) const {
    return x == other.x;
  }

  bool operator!=(const modInt &other) const {
    return x != other.x;
  }
};

template<int MOD>
ostream &operator<<(ostream &out, modInt<MOD> const &x) {
  out << x.x;
  return out;
}

template<int MOD>
istream &operator>>(istream &in, modInt<MOD> &x) {
  x = 0;
  int c;
  while (isdigit(c = in.get())) {
    x *= 10;
    x += c - '0';
  }
  return in;
}

using mint = modInt<1'000'000'007>;

mint fast_pow(mint x, ll p) {
  mint res = 1;
  while (p) {
    if (p % 2 == 0) {
      x *= x;
      p /= 2;
    } else {
      res *= x;
      p--;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k, r, c;
  cin >> n >> m >> k >> r >> c;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 == x2 && y1 == y2) {
    cout << fast_pow(k, n * 1ll * m);
  } else {
    cout << fast_pow(k, n * 1ll * m - c * 1ll * r);
  }
  return 0;
}