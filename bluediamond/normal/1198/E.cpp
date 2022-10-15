#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}


struct flow {
  struct edge {
    int to;
    int cap;
  };
  const int INF = (int) 2e9;
  int n;
  vector<edge> edges;
  vector<vector<int>> g;
  vector<int> level;
  vector<int> pt;

  void init(int nn) {
    n = nn;
    edges.clear();
    pt.resize(n + 1);
    level.resize(n + 1);
    g.resize(n + 1);
  }

  void add(int a, int b, int c) {
    g[a].push_back((int) edges.size());
    g[b].push_back((int) edges.size() + 1);
    edges.push_back({b, c});
    edges.push_back({a, 0});
  }

  int dfs(int a, int cap) {
    if (cap == 0 || a == n) {
      return cap;
    }
    while (pt[a] < (int) g[a].size()) {
      int i = g[a][pt[a]++];
      if (edges[i].cap && level[edges[i].to] == 1 + level[a]) {
        int b = edges[i].to;
        int x = dfs(b, min(cap, edges[i].cap));
        if (x > 0) {
          edges[i].cap -= x;
          edges[i ^ 1].cap += x;
          return x;
        }
      }
    }
    return 0;
  }

  int get() {
    int ret = 0;
    while (1) {
      for (int i = 1; i <= n; i++) {
        level[i] = -1;
        pt[i] = 0;
      }
      level[1] = 0;
      queue<int> q;
      q.push(1);
      while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (auto &i : g[a]) {
          if (edges[i].cap > 0) {
            int b = edges[i].to;
            if (level[b] == -1) {
              level[b] = 1 + level[a];
              q.push(b);
            }
          }
        }
      }
      if (level[n] == -1) {
        break;
      }
      while (1) {
        int x = dfs(1, INF);
        if (x == 0) {
          break;
        }
        ret += x;
      }
    }
    return ret;
  }

};

struct interval {
  int l, r;
};

int len, n, x1[55], y1[55], x2[55], y2[55];
set<int> sxp, syp;
vector<int> xp, yp;
vector<interval> xi, yi;

signed realMain() {
  cin >> len >> n;
  for (int i = 1; i <= n; i++) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
  for (int i = 1; i <= n; i++) {
    sxp.insert(x1[i]), sxp.insert(x2[i] + 1);
    syp.insert(y1[i]), syp.insert(y2[i] + 1);
  }
  for (auto &it : sxp) xp.push_back(it);
  for (auto &it : syp) yp.push_back(it);
  for (int i = 0; i + 1 < (int) xp.size(); i++) {
    xi.push_back({xp[i], xp[i + 1] - 1});
  }
  for (int i = 0; i + 1 < (int) yp.size(); i++) {
    yi.push_back({yp[i], yp[i + 1] - 1});
  }
  flow f;
  f.init(1 + (int) xi.size() + (int) yi.size() + 1);
  for (int i = 1; i <= (int) xi.size(); i++) {
    f.add(1, 1 + i, xi[i - 1].r - xi[i - 1].l + 1);
  }
  for (int i = 1; i <= (int) yi.size(); i++) {
    f.add(1 + (int) xi.size() + i, 1 + (int) xi.size() + (int) yi.size() + 1, yi[i - 1].r - yi[i - 1].l + 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int a = 1; a <= (int) xi.size(); a++) {
      for (int b = 1; b <= (int) yi.size(); b++) {
        if (x1[i] <= xi[a - 1].l && xi[a - 1].r <= x2[i]) if (y1[i] <= yi[b - 1].l && yi[b - 1].r <= y2[i]) {
          f.add(1 + a, 1 + (int) xi.size() + b, (int) 2e9);
        }
      }
    }
  }
  cout << f.get() << "\n";
  return 0;
}