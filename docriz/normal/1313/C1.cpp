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
  ll best = -1;
  vector<int> ans(n + 1);
  for (int cut = 1; cut <= n; cut++) {
    int last = m[cut];
    ll tot = m[cut];
    vector<int> cur_ans(n + 1);
    cur_ans[cut] = m[cut];
    for (int i = cut - 1; i >= 1; i--) {
      int cur = min(last, m[i]);
      cur_ans[i] = cur;
      last = cur;
      tot += cur;
    }
    last = m[cut];
    for (int i = cut + 1; i <= n; i++) {
      int cur = min(last, m[i]);
      cur_ans[i] = cur;
      last = cur;
      tot += cur;
    }
    if (tot > best) {
      best = tot;
      ans = cur_ans;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }
  return 0;
}