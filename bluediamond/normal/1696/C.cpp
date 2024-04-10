/// 483 -> 484
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<pair<ll, ll>> get(vector<ll> v, ll m) {
  vector<pair<ll, ll>> sol;
  for (auto &x : v) {
    ll times = 1, val = x;
    while (val % m == 0) {
      val /= m;
      times *= m;
    }
    assert(times * val == x);
    pair<ll, ll> it = {val, times};
    if (!sol.empty() && sol.back().first == val) {
      sol.back().second += it.second;
    } else {
      sol.push_back(it);
    }
  }
  return sol;
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    ll m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    cin >> k;
    vector<ll> b(k);
    for (auto &x : b) {
      cin >> x;
    }
    cout << ((get(a, m) == get(b, m)) ? ("Yes") : ("No")) << "\n";
  }
}