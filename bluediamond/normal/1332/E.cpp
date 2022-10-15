#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 998244353;

ll rep(ll a) {
  if (a >= mod) {
    a %= mod;
  }
  if (a < 0) {
    a += mod;
  }
  return a;
}

ll add(ll a, ll b) {
  return rep(a + b);
}

ll mul(ll a, ll b) {
  return rep(a * b);
}

ll pw(ll a, ll b) {
  ll r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

ll dv(ll a, ll b) {
  return mul(a, pw(b, mod - 2));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, m, l, r;
  cin >> n >> m >> l >> r;
  ll total = pw(rep(r - l + 1), n * m);
  if ((n * m) % 2 == 1) {
    cout << total << "\n";
  } else {
    if ((r - l + 1) % 2) {
      total = add(total, 1);
    }
    cout << dv(total, 2) << "\n";
  }

}