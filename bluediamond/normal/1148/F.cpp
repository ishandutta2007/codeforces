#include <bits/stdc++.h>


using namespace std;

bool home = 1;
typedef long long ll;
typedef unsigned long long ull;

ull getlog2(ull x) {
  if (x > 1) {
    return 1 + getlog2(x / 2);
  }
  return 0;
}

const ll N = (ll)3e5 + 7;
const ll K = 60 + 7;
ll n;
ll val[N];
ll mask[N];
vector<ll> inds[N];

ll sgn(ll x) {
  if (x > 0) {
    return +1;
  }
  if (x == 0) {
    return 0;
  }
  return -1;
}

ull cntbits(ull x) {
  ll sol = 0;
  while (x) {
    x -= x & (-x);
    sol++;
  }
  return sol;
}

ll eval(ll lim, ull m) {
  ll sol = 0;
  for (ll k = 0; k <= lim; k++) {
    for (auto& i : inds[k]) {
      if (cntbits(m & mask[i]) % 2 == 1) {
        sol -= val[i];
      }
      else {
        sol += val[i];
      }
    }
  }
  return sol;
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0), cin.tie(0);
  }

  cin >> n;
  ll init = 0;
  for (ll i = 1; i <= n; i++) {
    cin >> val[i] >> mask[i];
    init += val[i];
    ll k = getlog2(mask[i]);
    inds[k].push_back(i);
  }
  ull solution = 0, c = 1;
  for (ll k = 0; k < K; k++) {
    if (k) {
      c *= 2;
    }
    if (inds[k].empty()) {
      continue;
    }
    if (sgn(eval(k, solution ^ c)) == -sgn(init)) {
      solution ^= c;
    }
  }
  cout << solution << "\n";


}