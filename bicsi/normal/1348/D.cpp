#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> Solve(ll n) {
  auto lb = [&](ll cnt, ll rem) {
    return cnt * rem;
  };  
  auto ub = [&](ll cnt, ll rem) {
    ll ans = 0;
    while (rem) {
      ans += 2 * cnt;
      cnt *= 2;
      rem -= 1;
    }
    return ans;
  };

  --n;
  int seek = -1;
  for (int days = 1; days <= 40; ++days) {
    if (lb(1, days) <= n && ub(1, days) >= n) {
      seek = days;
      break;
    }
  }
  assert(seek != -1);

  ll cnt = 1;
  vector<ll> ret;
  for (int rem = seek; rem > 0; --rem) {
    ll ans = -1, adv = 1;
    bool ok = false;
    for (ll step = 1; step; adv ? step *= 2 : step /= 2) {
      if (ans + step <= cnt) {
        ll nn = n - cnt - ans - step;
        ll ncnt = cnt + ans + step;
        if (lb(ncnt, rem - 1) <= nn && ub(ncnt, rem - 1) >= nn) {
          ret.push_back(ans + step);
          cnt = ncnt; n = nn;
          ok = true;
          break;
        } else if (lb(ncnt, rem - 1) > nn) {
          adv = 0;
        } else {
          ans += step;
        }
      } else adv = 0;
    }
    assert(ok);
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    auto ans = Solve(n);
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << " ";
    cout << '\n';
  }


  return 0;
}