#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  vector<int> v(n);
  priority_queue<tuple<int, int, int>> pq;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    pq.emplace(v[i], 0, i);
  }

  tuple<int, int, int> ans = {0, -1, -1};
  while (pq.size()) {
    auto [x, d, i] = pq.top();
    pq.pop();

    while (pq.size()) {
      auto [xp, dp, ip] = pq.top();
      if (x != xp) break;
      assert(i != ip);
      ans = max(ans, make_tuple(d + dp, i, ip));
      if (d < dp) {
        d = dp;
        i = ip;
      }
      pq.pop();
    }
    if (x == 0) continue;

    int pw = 1;
    while (pw < x) 
      pw *= 2;
    pq.emplace(pw - x, d + 1, i);
  }
  cout << get<1>(ans) + 1 << " " << get<2>(ans) + 1 << " " << get<0>(ans) << endl;
  return 0;
}