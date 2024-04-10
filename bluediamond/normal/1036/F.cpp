#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
const ll inf = (ll) 2e18;

ll rad(ll n) {
  ll l = 1, r = (ll) 1e9 + 1245, sol = 0;
  while (l <= r) {
    ll m = (l + r) / 2;
    if (m <= n / m) sol = m, l = m + 1;
    else r = m - 1;
  }
  return sol;
}

bool check(ll a, ll b, ll limit) {
  ll sol = 1;
  for (ll j = 1; j <= b; j++) {
    if (sol > limit / a) return 0;
    sol *= a;
  }
  return sol <= limit;
}

const ll N = (ll) 1e5 + 7;
const ll K = 65;

ll n, lim[K], mob[K];
ll sol[N];
pair<ll, ll> q[N];


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for (ll i = 1; i <= n; i++) {cin >> q[i].first; q[i].second = i;}
  sort(q + 1, q + n + 1);

  vector<ll> primes;
  mob[1] = 1;

  for (ll i = 2; i < K; i++) {
    ll cnt = 0;
    mob[i] = 1;
    for (auto &p : primes) {
      if (i % p == 0) mob[i] *= -1, cnt++;
      if (i % (p * p) == 0) {mob[i] = 0; break;}
    }
    if (!cnt) primes.push_back(i), mob[i] *= -1;
  }
  for (ll i = 1; i <= n; i++) {
    ll x = q[i].first;
    ll ind = q[i].second;
    sol[ind] += x - rad(x);
    for (ll j = 3; j < K; j++) {
      while (check(lim[j] + 1, j, x)) lim[j]++;
      sol[ind] += lim[j] * mob[j];
    }
  }
  for (ll i = 1; i <= n; i++) {
    cout << sol[i] + 1 << "\n";
  }
  return 0;
}