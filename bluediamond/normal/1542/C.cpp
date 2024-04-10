#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

void addup(int &a, int x) {
  a = add(a, x);
}

int f(int x) {
  int i = 1;
  while (x % i == 0) i++;
  return i;
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

int memo[100][100], kezm[100];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);
/**
  for (int i = 1; i <= 100; i++) {
    int cnt = 0;
    for (int j = 1; j <= 100; j++) cnt += (f(j) == i);
    if (!cnt) continue;
    cout << i << " : ";
    for (int j = 1; j <= 100; j++) {
      if (f(j) == i) {
        cout << j / 2 << " ";
      }
    }
    cout << "\n";
   /// cout << i << " : " << f(i) << "\n";
  }
  return 0;**/
  {

    int lcm = 1;
    for (int x = 2; x <= 43; x++) {
      int g = __gcd(x - 1, lcm);
      lcm /= g;
      lcm *= (x - 1);
      for (int r = 1; r < x; r++) {
        memo[x][r] = user.crt(lcm, x, 0, r);
      }
      kezm[x] = lcm / __gcd(lcm, x) * x;
    }
  }
  ///return 0;
  int t;

  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int lcm = 1, sol = 0;
    for (int x = 2; x <= 43; x++) {
      int g = __gcd(x - 1, lcm);
      lcm /= g;
      lcm *= (x - 1);
      for (int r = 1; r < x; r++) {
        int mod = memo[x][r];
        if (mod == -1) continue;
      ///  int yol = ;
        if (x == 43) {
          sol += x * (mod <= n);
        } else {
          /// i * kezm[x] + mod <= n
          if (mod <= n) sol += x * (1 + (n - mod) / kezm[x]);
        }
        sol %= M;
      }
    }
    cout << sol << "\n";

  }

  return 0;
}