#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = (ll) 1e9 + 7;

ll add(ll a, ll b) {
  a += b;
  a %= mod;
  a += mod;
  a %= mod;
  return a;
}

ll mul(ll a, ll b) {
  return a *  b % mod;
}

const ll N = (ll) 1e6 + 7;
const ll K = 21;
ll n, k;
ll ret[K][N], lg[N];

ll get(ll l, ll r) {
  ll k = lg[r - l + 1];
  return max(ret[k][l], ret[k][r - (1 << k) + 1]);
}

ll buga[N], mx[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n >> k;
  for (ll i = 1; i <= n; i++) {
    cin >> ret[0][i];
  }

  for (ll i = 2; i <= n; i++) {
    lg[i] = 1 + lg[i / 2];
  }

  for (ll j = 1; (1 << j) <= n; j++) {
    for (ll i = 1; i + (1 << j) - 1 <= n; i++) {
      ret[j][i] = max(ret[j - 1][i], ret[j - 1][i + (1 << (j - 1))]);
    }
  }

  for (ll i = n; i >= 1; i--) {
    ll len = k - 1;
    ll j = i + len - 1;
    if (j <= n) {
      ll x = get(i, i + len - 1);
      ll l = 1, r = n, ans = -1;
      while (l <= r) {
        ll j = (l + r) / 2;
        ll pos = i + j * (k - 1) - 1;
        if (pos <= n && x == get(i, pos)) {
          ans = j;
          l = j + 1;
        } else {
          r = j - 1;
        }
      }
      ll pos = i + ans * (k - 1) - 1;
      buga[i] = add(buga[pos + 1], mul(ans, x));
    }
  }

  ll sol = 0;
  for (ll i = 1; i + k - 1 <= n; i++) {
    ll l = 0, r = n, ans = -1;
    while (l <= r) {
      ll j = (l + r) / 2;
      ll pos = i + k + j * (k - 1) - 1;
      if (pos <= n && get(i, pos) == get(i, i + k - 1)) {
        ans = j;
        l = j + 1;
      } else {
        r = j - 1;
      }
    }
    sol = add(sol, mul(ans + 1, get(i, i + k - 1)));
    ll pos = i + k + ans * (k - 1);
    sol = add(sol, buga[pos]);
  }
  cout << sol << "\n";

  return 0;
}