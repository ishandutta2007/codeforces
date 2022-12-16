#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;


namespace std {
  template<>
  struct hash<pair<ll, ll>> {
    size_t operator() (const pair<ll, ll>& pr) const {
      hash<ll> llhsh;
      return llhsh(pr.first) + llhsh(pr.second);
    }
  };
}

const int N = 100100;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
pair<ll, ll> dp[N];
unordered_map<pair<ll, ll>, pair<ll, ll>> mp;

struct truck {
  ll v, c, l, r;
};

truck t[N];
int n;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i=1; i<=n; ++i) {
    dp[i] = {-INFLL, 0};
    cin >> t[i].v >> t[i].c >> t[i].l >> t[i].r;
  }
  for (int i=1; i<=n; ++i) {
    if (t[i].l == 0) {
      dp[i] = {t[i].v, 0};
    } else {
      pair<ll, ll> idt = {t[i].l+t[i].r+t[i].c, t[i].r+t[i].c};
      if (mp.count(idt)) {
        auto [va, j] = mp[idt];
        dp[i] = max(dp[i], {va+t[i].v, j});
      }
    }

    if (dp[i].first >= 0) {
      pair<ll, ll> idx = {t[i].l+t[i].r+t[i].c, t[i].r};
      pair<ll, ll> val = {dp[i].first, i};
      //cerr << "    pre  " << mp[idx].first << ',' << mp[idx].second << endl;
      if (!mp.count(idx)) {
        mp[idx] = {-INFLL, 0};
      }
      mp[idx] = max(mp[idx], val);
      //cerr << "    post " << mp[idx].first << ',' << mp[idx].second << endl;
    }
    ////cerr << "  DP" << i << " = " << dp[i].first << "," << dp[i].second << endl;
  }

  pair<ll, ll> best = {-INFLL, 0};
  for (int i=1; i<=n; ++i) {
    if (t[i].r == 0) {
      best = max(best, {dp[i].first, i});
    }
  }
  if (best.first < 0) {
    cout << "0\n\n";
    return 0;
  }
  int q = best.second;
  vector<int> res;
  while (q) {
    res.push_back(q);
    q = dp[q].second;
  }
  cout << res.size() << endl;
  reverse(res.begin(), res.end());
  for (auto& x : res) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}