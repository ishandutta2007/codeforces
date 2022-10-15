#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e6 + 7;
ll n, sol, rad;
bool e[N];
int cnt[2 * N];

vector<ll> keks;

int getid(ll x) {
  if (x <= rad) {
    return (int) keks.size() - x;
  } else {
    return n / x - 1;
  }
}

ll solve() {
  rad = sqrt(n);
  assert(rad * rad <= n && (rad + 1) * (rad + 1) > n);

  ll l = 1;
  while (l <= n) {
    ll r = n / (n / l);
    keks.push_back(n / l);
    l = r + 1;
  }

  for (auto &it : keks) {
    cnt[getid(it)] = it - 1;
  }

  for (int p = 2; p <= rad; p++) {
    if (!e[p]) continue;

    for (auto &x : keks) {
      if ((ll) p * p > x) break;
      cnt[getid(x)] -= cnt[getid(x / p)] - cnt[getid(p)] + 1;
    }
  }

  ll sol = 0;
  for (int psmall = 1; psmall <= rad; psmall++) {
    if (e[psmall]) {
      sol += cnt[getid(n / psmall)] - cnt[getid(psmall)];
    }
  }
  return sol;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  e[2] = 1;
  for (int i = 3; i < N; i += 2) {
    e[i] = 1;
  }
  for (int i = 3; i * i < N; i += 2) {
    if (e[i]) {
      for (int j = i * i; j < N; j += 2 * i) {
        e[j] = 0;
      }
    }
  }

  cin >> n;

  for (ll i = 1; i * i * i <= n; i++) {
    if (e[i]) sol++;
  }

  cout << sol + solve() << "\n";


  return 0;
}