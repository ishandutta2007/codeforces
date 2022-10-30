#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> G(n + 1);
    vector<int> deg(n + 1);
    for (int i = 1; i <= m; i++) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
      deg[x] += 1;
      deg[y] += 1;
    }
    for (int i = 1; i <= n; i++) {
      sort(G[i].begin(), G[i].end());
    }
    auto del = [&](int x, int y) -> void {
      deg[x] -= 1;
      deg[y] -= 1;
    };
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
      if (deg[i] < k - 1) {
        Q.push(i);
      }
    }
    while (!Q.empty()) {
      int cur = Q.front();
      Q.pop();
      for (auto nx: G[cur]) {
        if (deg[nx] == 0) {
          continue;
        }
        del(cur, nx);
        if (deg[nx] == k - 2) {
          Q.push(nx);
        }
      }
      assert(deg[cur] == 0);
    }
    auto go = [&]() -> void {
      for (int i = 1; i <= n; i++) {
        if (deg[i] == k - 1) {
          Q.push(i);
        }
      }
      while (!Q.empty()) {
        int cur = Q.front();
        // cout << cur << endl;
        Q.pop();
        if (deg[cur] == k - 1) {
          bool good = true;
          vector<int> vec;
          for (auto nx: G[cur]) {
            if (deg[nx]) {
              vec.push_back(nx);
            }
          }
          assert(vec.size() == k - 1);
          for (int i = 0; good && i < k - 1; i++) {
            for (int j = i + 1; good && j < k - 1; j++) {
              int x = vec[i];
              int y = vec[j];
              auto it = lower_bound(G[x].begin(), G[x].end(), y);
              if (it == G[x].end() || *it != y) {
                good = false;
              }
            }
          }
          if (good) {
            cout << "2\n";
            for (auto t: vec) {
              cout << t << " ";
            }
            cout << cur << "\n";
            return;
          }
        }
        for (auto nx: G[cur]) {
          if (deg[nx] == 0) {
            continue;
          }
          del(cur, nx);
          if (deg[nx] == k - 1) {
            Q.push(nx);
          }
        }
      }
      vector<int> ans;
      for (int i = 1; i <= n; i++) {
        if (deg[i]) {
          ans.push_back(i);
        }
      }
      if (ans.empty()) {
        cout << -1 << "\n";
      } else {
        cout << "1 " << ans.size() << "\n";
        for (auto t: ans) {
          cout << t << " ";
        }
        cout << "\n";
      }
    };
    go();
  }
  return 0;
}