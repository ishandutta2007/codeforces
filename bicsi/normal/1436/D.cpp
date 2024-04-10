#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#define int long long 

using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  vector<int> parent(n, -1);
  vector<vector<int>> graph(n);
  for (int i = 1; i < n; ++i) {
    cin >> parent[i]; --parent[i];
    graph[parent[i]].push_back(i);
  }
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  vector<int> order, stop(n, -1);
  function<void(int)> dfs = [&](int node) {
    order.push_back(node);
    for (auto vec : graph[node]) {
      dfs(vec);
    }
    stop[node] = order.size();
  };
  dfs(0);


  int ans = -1;
  for (int i = 0; i < n; ++i)
    if (graph[i].empty())
      ans = max(ans, v[i] - 1);

  int adv = 1;
  for (int step = 1; step; adv ? step *= 2 : step /= 2) {
    int now = ans + step;
    vector<pair<int, int>> stk;
    for (int i = n - 1; i >= 0; --i) {
      int node = order[i];
      if (graph[node].empty()) {
        stk.emplace_back(i, now - v[node]);
      } else {
        int until = stop[node];
        int place = v[node];
        while (place > 0) {
          if (stk.empty() || stk.back().first >= until) {
            goto bad;
          }
          if (place >= stk.back().second) {
            place -= stk.back().second;
            stk.pop_back();
          } else {
            stk.back().second -= place;
            place = 0;
          }
        }
      }
    }

    adv = 0;
    continue;
    bad: ans += step;
  }
  cout << ans + 1 << '\n';

  return 0;
}