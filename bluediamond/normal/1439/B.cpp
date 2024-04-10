#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
int n;
int m;
int k;
int deg[N];
bool active[N];
vector<int> g[N];

bool e(int x, int y) {
  if ((int) g[x].size() > (int) g[y].size()) {
    swap(x, y);
  }
  int l = 0, r = (int) g[x].size() - 1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (g[x][m] == y) {
      return 1;
    }
    if (g[x][m] > y) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
      g[i].clear();
    }
    for (int i = 1; i <= m; i++) {
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
      sort(g[i].begin(), g[i].end());
    }
    set<pair<int, int>> s;
    for (int i = 1; i <= n; i++) {
      active[i] = 1;
      deg[i] = (int) g[i].size();
      s.insert({deg[i], i});
    }
    bool ok = 0;

    while (!s.empty()) {
      auto it = s.begin();
      if (it->first < k - 1) {
        int i = it->second;
        active[i] = 0;
        for (auto &j : g[i]) {
          if (active[j]) {
            s.erase({deg[j], j});
            deg[j]--;
            s.insert({deg[j], j});
          }
        }
        s.erase(it);
        continue;
      }
      if (it->first >= k) {
        ok = 1;
        cout << "1 " << (int) s.size() << "\n";
        for (auto &x : s) {
          cout << x.second << " ";
        }
        cout << "\n";
        break;
      }
      int i = it->second;
      vector<int> nodes;
      nodes.push_back(i);
      bool clica = 1;
      for (auto &x : g[i]) {
        if (active[x]) {
          for (auto &y : nodes) {
            if (!e(x, y)) {
              clica = 0;
              break;
            }
          }
          if (!clica) {
            break;
          }
          nodes.push_back(x);
        }
      }
      if (!clica) {
        int i = it->second;
        active[i] = 0;
        for (auto &j : g[i]) {
          if (active[j]) {
            s.erase({deg[j], j});
            deg[j]--;
            s.insert({deg[j], j});
          }
        }
        s.erase(it);
        continue;
      }
      ok = 1;
      cout << "2\n";
      for (auto &x : nodes) {
        cout << x << " ";
      }
      cout << "\n";
      break;
    }
    if (!ok) {
      cout << "-1\n";
    }
  }
}