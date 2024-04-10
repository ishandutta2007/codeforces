#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);

  auto max_interval = [&](vector<pair<int,int>>& ranges) {
    vector<pair<int,int>> events;
    for (int i = 0; i < ranges.size(); i++) {
      events.push_back({ranges[i].first, 1});
      events.push_back({ranges[i].second, -1});
    }
    sort(events.begin(), events.end());
    int idx = 0, amount = 0, ans = 0;
    while(idx < (int)events.size()) {
      int curr = idx;
      while(curr < events.size() && events[curr].first == events[idx].first) {
        amount += events[curr].second;
        curr++;
      }
      ans = max(ans, amount);
      idx = curr;
    }
    return ans;
  };

  int n;
  cin >> n;
  vector<pair<int,int>> ranges(n);
  for (int i = 0; i < n; i++){
    int l,r;
    cin >> l >> r;
    r++;
    ranges[i] = {l,r};
  }
  vector<int> ans(30);
  for (int bit = 0; bit < 30; bit++) {
    int k = 1<<bit;
    vector<pair<int,int>> fin_ranges;
    for (int i =0; i < n; i++) {
      auto [l,r] = ranges[i];
      if (r-l >= k) {
        fin_ranges.push_back({0,k});
      } else {
        if (l%k < r%k) {
          fin_ranges.push_back({l%k, r%k});
        } else {
          fin_ranges.push_back({0,r%k});
          fin_ranges.push_back({l%k,k});
        }
      }
    }
    ans[bit] = max(ans[bit], max_interval(fin_ranges));
  }

  int q;
  cin >> q;
  while(q--) {
    int w;
    cin >> w;
    for (int bit =0; bit < 30; bit++) {
      if (w>>bit&1) {
        cout << ans[bit] << '\n';
        break;
      }
    }
  }
}