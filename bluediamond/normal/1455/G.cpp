#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
/// #define int long long

const ll INF = (ll) 2e14 + 77777;


struct DP {
  ll lazy = 0;
  map<int, ll> dp;
  set<pair<ll, int>> s;

  void addToAll(ll value) {
    lazy += value;
  }

  void update(int x, ll value) {
    value -= lazy;
    if (dp.count(x)) {
      s.erase({dp[x], x});
      dp[x] = min(dp[x], value);
    } else {
      dp[x] = value;
    }
    s.insert({dp[x], x});
  }

  ll get(int x) {
    if (dp.count(x)) {
      return dp[x] + lazy;
    } else {
      return INF;
    }
  }

  void del(int x) {
    if (dp.count(x)) {
      s.erase({dp[x], x});
      dp.erase(x);
    }
  }

  ll getMin() {
    return s.begin()->first + lazy;
  }
};

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  vector<DP> stk;
  stk.push_back({});
  stk[0].update(0, 0);

  int ops, bad;
  cin >> ops >> bad;
  for (int iter = 1; iter <= ops; iter++) {
    string s;
    cin >> s;
    if (s == "set") {
      int x, y;
      cin >> x >> y;
      ll mn = stk.back().getMin();
      stk.back().addToAll(y);
      if (x != bad) {
        stk.back().update(x, mn);
      }
      continue;
    }
    if (s == "if") {
      int x;
      cin >> x;
      stk.push_back({});
      stk.back().update(x, stk[(int) stk.size() - 2].get(x));
      stk[(int) stk.size() - 2].del(x);
      continue;
    }
    if (s == "end") {
      if ((int) stk.back().dp.size() > (int) stk[(int) stk.size() - 2].dp.size()) {
        swap(stk.back(), stk[(int) stk.size() - 2]);
      }
      for (auto &it : stk.back().dp) {
        stk[(int) stk.size() - 2].update(it.first, it.second + stk.back().lazy);
      }
      stk.pop_back();
      continue;
    }
  }
  cout << stk[0].getMin() << "\n";

}