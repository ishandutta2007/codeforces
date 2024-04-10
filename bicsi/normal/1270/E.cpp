#include <bits/stdc++.h>
#define int long long 

using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i]; 
  }

  auto r = [&](int i) {
    int ret = x[i] + y[i];
    ret %= 2;
    if (ret < 0) ret += 2;
    return ret;
  };

  while (true) {
    vector<int> cnt(2, 0);
    for (int i = 0; i < n; ++i) {
      cnt[r(i)] += 1;
    }
    if (cnt[0] && cnt[1]) {
      vector<int> ans;
      for (int i = 0; i < n; ++i) {
        if (r(i) == 0) {
          ans.push_back(i);
        }
      }
      cout << ans.size() << '\n';
      for (auto x : ans) cout << x + 1 << " "; cout << '\n';
      break;
    } 
    if (cnt[1]) {
      for (int i = 0; i < n; ++i)
        y[i] -= 1;
    }
    for (int i = 0; i < n; ++i) {
      int xx = x[i], yy = y[i];
      x[i] = (xx + yy) / 2;
      y[i] = (xx - yy) / 2;
    }
  }
 
  return 0;
}