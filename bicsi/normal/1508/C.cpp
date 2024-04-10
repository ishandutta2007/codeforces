#ifdef LOCAL
#include <debug.hpp>
#else
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#define debug(...)
#endif 

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n, m; cin >> n >> m;
  vector<tuple<int, int, int>> edges;
  int xor_sum = 0;
  vector<vector<pair<int, int>>> graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b, c; cin >> a >> b >> c; --a; --b;
    if (a > b) swap(a, b);
    // cerr << "Edge: " << c << " " << a + 1 << " " << b + 1 << endl;
    edges.emplace_back(c, a, b);
    graph[a].emplace_back(b, c);
    graph[b].emplace_back(a, c);
    xor_sum ^= c;
  }
  sort(edges.begin(), edges.end());
  for (int i = 0; i < n; ++i)
    sort(graph[i].begin(), graph[i].end());

  long long tot = 1LL * n * (n - 1) / 2;
  long long extra = tot - m;

  auto check = [&]() {
    set<int> vis;
    for (int i = 0; i < n; ++i)
      vis.insert(i);
    vector<int> q;
    priority_queue<pair<int, int>> pq;
    vector<bool> proc(n, false);
    vector<int> dist(n, 2e9);
    auto relax = [&](int a, int d) {
      if (proc[a]) return false;
      if (dist[a] <= d) return false;
      if (d == 0) {
        dist[a] = 0;
        q.push_back(a);
        return true;
      }
      dist[a] = d;
      pq.emplace(-d, a);
      return true;
    };

    relax(0, 0);
    long long ans = 0;
    while (true) {
      int ch = -1;
      if (q.size()) {
        ch = q.back(); q.pop_back();
      } else if (pq.size()) {
        ch = pq.top().second; pq.pop();
      } else break;
      
      assert(ch != -1);
      if (proc[ch]) {
        continue;
      }
      
      proc[ch] = true;
      ans += dist[ch];
      
      int ptr = 0;
      for (auto it = vis.begin(); it != vis.end(); ) {
        int j = *it;
        while (ptr < (int)graph[ch].size() && graph[ch][ptr].first < j)
          ++ptr;
        if (ptr < (int)graph[ch].size() && graph[ch][ptr].first == j) 
          ++it;
        else {
          relax(j, 0);
          it = vis.erase(it);
        }
      }
      
      for (auto [a, d] : graph[ch]) {
        relax(a, d);
      }
    }
    return ans;
  };
  
  if (extra > n) {
    // cerr << "Case easy\n";
    cout << check() << endl;
  } else {
    // cerr << "Case hard\n";
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (auto [c, a, b] : edges)
      C[a][b] = C[b][a] = c;

    auto check2 = [&]() {
      vector<bool> vis(n, false);
      vector<int> dist(n, 2e9);
      dist[0] = 0;
      long long total = 0;
      for (int i = 0; i < n; ++i) {
        int ch = -1;
        for (int j = 0; j < n; ++j) {
          if (vis[j]) continue;
          if (ch == -1 || dist[ch] > dist[j])
            ch = j;
        }
        vis[ch] = true;
        total += dist[ch];
        for (int j = 0; j < n; ++j) 
          dist[j] = min(dist[j], C[ch][j]);
      }
      return total;
    };

    long long best = 2e18;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        if (C[i][j]) continue;
        C[i][j] = C[j][i] = xor_sum;
        best = min(best, check2());
        C[i][j] = C[j][i] = 0;
      }
    cout << best << endl;
  }

  return 0;
}