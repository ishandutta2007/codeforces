#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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

using mint = modInt<(int) 1e9 + 7>;

const int maxn = 201010;
mint mobius[maxn];

void precal() {
  mobius[1] = 1;
  for (int i = 1; i < maxn; ++i) {
    for (int f = 2 * i; f < maxn; f += i) {
      mobius[f] -= mobius[i];
    }
  }
}

int n;
mint a[maxn];
int v[maxn];
mint dp[maxn];
mint cnt[maxn];

mint solve() {
  for (int x = n; x >= 1; --x) {
    for (int i = 2 * x; i <= n; i += x) {
      dp[x] += mobius[i / x] * dp[i];
    }
    for (int i = 2 * x; i <= n; i += x) {
      dp[x] += 2 * __gcd(a[x].x, a[i].x);
    }
    dp[x] += a[x];
    for (int i = 2 * x; i <= n; i += x) {
      dp[x] -= dp[i];
    }
  }

  mint ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += i * dp[i];
    cout << dp[i] << " ";
  }
  return ans;
}

const int A = 100'000 + 1;
const int BUBEN = 450;

mint cnt1[A + 1];
mint cnt2[A + 1];

int my_gcd(int x, int y) {
  if (x == 0) return y;
  if (y == 0) return x;

  int az = __builtin_ctz(x);
  int bz = __builtin_ctz(y);
  int shift = std::min(az, bz);
  x >>= az, y >>= bz;

  while (x != 0) {
    int diff = x - y;
    y = std::min(x, y);
    x = std::abs(diff);
    if (x != 0) {
      x >>= __builtin_ctz(x);
    }
  }

  return y << shift;
}

mint super_smart() {
  for (int i = 1; i <= A; i++) {
    for (int j = i; j <= A; j += i) {
      cnt2[i] += cnt1[j];
    }
    cnt2[i] *= cnt2[i];
  }
  mint res = 0;
  for (int i = A; i >= 1; i--) {
    for (int j = 2 * i; j <= A; j += i) {
      cnt2[i] -= cnt2[j];
    }
    res += i * cnt2[i];
  }
  return res;
}

mint stupid_solve() {
  for (int d = 1; d <= n; d++) {
    if (n / d <= BUBEN) {
      for (int i = d; i <= n; i += d) {
        for (int j = d; j <= n; j += d) {
          const mint &x = my_gcd(v[i], v[j]);
          dp[d] += x;
        }
      }
    } else {
      fill(cnt1, cnt1 + A + 1, 0);
      fill(cnt2, cnt2 + A + 1, 0);
      for (int i = d; i <= n; i += d) {
        cnt1[v[i]] += 1;
      }
      dp[d] = super_smart();
    }
  }
  for (int i = A; i >= 1; i--) {
    for (int j = 2 * i; j <= A; j += i) {
      dp[i] -= dp[j];
    }
  }
  mint res = 0;
  for (int i = 1; i <= A; i++) {
    res += dp[i] * i;
  }
  return res;
}

int main() {
  precal();
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  n = 100'000;
   cin >> n;
  for (int i = 1; i <= n; ++i) {
     cin >> v[i];
//    v[i] = rand() % 100'000 + 1;
    a[i] = v[i];
  }

//  auto const inv2 = mint(1) / 2;
//  cout << solve();
  cout << stupid_solve();


  return 0;
}