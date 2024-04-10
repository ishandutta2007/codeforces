#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);
  int n;
  cin >> n;
  vector<int> m(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> m[i];
  }
  using ll = long long;
  auto go = [&]() -> vector<ll> {
    stack<int> S;
    vector<int> fs(n + 1);
    vector<ll> f(n + 1);
    for (int i = n; i >= 1; i--) {
      while (!S.empty() && m[i] <= m[S.top()]) {
        fs[S.top()] = i;
        S.pop();
      }
      S.push(i);
    }
    while (!S.empty()) {
      fs[S.top()] = 0;
      S.pop();
    }
    for (int i = 1; i <= n; i++) {
      f[i] = f[fs[i]] + 1LL * m[i] * (i - fs[i]);
    }
    return f;
  };
  vector<ll> f = go();
  reverse(m.begin() + 1, m.end());
  vector<ll> g = go();
  reverse(g.begin() + 1, g.end());
  reverse(m.begin() + 1, m.end());
  /*
  for (int i = 1; i <= n; i++) {
    cout << f[i] << " ";
  }
  cout << endl;
  for (int i = 1; i <= n; i++) {
    cout << g[i] << " ";
  }
  cout << endl;
  */
  ll best = -1;
  int best_cut = -1;
  for (int cut = 1; cut <= n; cut++) {
    ll cur = f[cut] + g[cut] - m[cut];
    if (cur > best) {
      best = cur;
      best_cut = cut;
    }
  }
  // cout << best_cut << endl;
  vector<int> ans(n + 1);
  int last = INT_MAX;
  for (int i = best_cut; i >= 1; i--) {
    int cur = min(last, m[i]);
    last = cur;
    ans[i] = cur;
  }
  last = INT_MAX;
  for (int i = best_cut; i <= n; i++) {
    int cur = min(last, m[i]);
    last = cur;
    ans[i] = cur;
  }
  // cerr << best << endl;
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }
  return 0;
}