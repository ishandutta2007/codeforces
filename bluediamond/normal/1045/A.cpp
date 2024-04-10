#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = (int) 1e9;

struct flow {
  struct E {
    int to;
    int cap;
    int from;
    int go;
  };

  int n;
  vector<vector<int>> g;
  vector<E> edges;
  vector<int> level;
  vector<int> pos;
  void init(int nn) {
    n = nn;
    g.clear();
    edges.clear();
    level.clear();
    pos.clear();
    level.resize(n + 1);
    g.resize(n + 1);
    pos.resize(n + 1);
  }
  void add(int a, int b, int c) {
    g[a].push_back((int) edges.size());
    g[b].push_back((int) edges.size() + 1);
    edges.push_back({b, c, a, 0});
    edges.push_back({a, 0, b, 0});
  }
  int dfs(int a, int cap) {
    if (a == n || cap == 0) {
      return cap;
    }
    while (pos[a] < (int) g[a].size()) {
      int i = g[a][pos[a]++];
      int b = edges[i].to;
      int c = edges[i].cap;
      if (c == 0 || level[b] != level[a] + 1) {
        continue;
      }
      int x = dfs(b, min(cap, c));
      if (x == 0) {
        continue;
      }
      if (i % 2 == 0) {
        edges[i].go += x;
      } else {
        edges[i ^ 1].go -= x;
      }
      edges[i].cap -= x;
      edges[i ^ 1].cap += x;
      return x;
    }
    return 0;
  }
  int get() {
    int ret = 0;
    while (1) {
      level[1] = pos[1] = 0;
      for (int i = 2; i <= n; i++) {
        level[i] = -1;
        pos[i] = 0;
      }
      queue<int> q;
      q.push(1);
      while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (auto &i : g[a]) {
          int b = edges[i].to;
          int c = edges[i].cap;
          if (c > 0 && level[b] == -1) {
            level[b] = 1 + level[a];
            q.push(b);
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
  vector<int> path;
  bool remedy(int a) {
    if (a == n) {
      path.push_back(a);
      return 1;
    }
    while (pos[a] < (int) g[a].size()) {
      int i = g[a][pos[a]++];
      if (edges[i].go == 0) {
        continue;
      }
      if (remedy(edges[i].to) == 0) {
        continue;
      }
      path.push_back(a);
      edges[i].go--;
      pos[a]--;
      return 1;
    }
    return 0;
  }
  vector<pair<int, int>> solve(int q, int who[]) {
    vector<pair<int, int>> ret;
    int sz = get();
    int cnt = 0;
    while (1) {
      path.clear();
      if (remedy(1)) {
        reverse(path.begin(), path.end());
        int i = path[1] - 1;
        int j = who[path[(int) path.size() - 2] - q - 1];
        ret.push_back({i, j});
        cnt++;
      } else {
        break;
      }
    }
    assert(cnt == sz);
    return ret;
  }
};

flow f;

const int N = 5000 + 7;
int n;
int q;
int mx;
int whoo[4 * N];

void fmax(int v, int tl, int tr) {
  mx = max(mx, v);
  if (tl < tr) {
    int tm = (tl + tr) / 2;
    fmax(2 * v, tl, tm);
    fmax(2 * v + 1, tm + 1, tr);
  } else {
    whoo[v] = tl;
  }
}

void build(int v, int tl, int tr) {
  if (tl == tr) {
    f.add(1 + q + v, 1 + q + mx + 1, 1);
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    f.add(1 + q + v, 1 + q + 2 * v, INF);
    f.add(1 + q + v, 1 + q + 2 * v + 1, INF);
  }
}

void unite(int v, int tl, int tr, int l, int r, int i) {
  if (tr < l || r < tl) {
    return;
  }
  if (l <= tl && tr <= r) {
    f.add(1 + i, 1 + q + v, 1);
    return;
  }
  int tm = (tl + tr) / 2;
  unite(2 * v, tl, tm, l, r, i);
  unite(2 * v + 1, tm + 1, tr, l, r, i);
}

int m1[N];
int m2[N];
int m3[N];
int fr[N];
int who[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> q >> n;
  fmax(1, 1, n);
  f.init(1 + q + mx + 1);
  build(1, 1, n);
  for (int i = 1; i <= q; i++) {
    int t;
    cin >> t;
    if (t == 0) {
      int k;
      cin >> k;
      for (int j = 1; j <= k; j++) {
        int x;
        cin >> x;
        unite(1, 1, n, x, x, i);
      }
    }
    if (t == 1) {
      int l, r;
      cin >> l >> r;
      unite(1, 1, n, l, r, i);
    }
    if (t == 2) {
      int k1, k2, k3;
      cin >> k1 >> k2 >> k3;
      m1[i] = k1;
      m2[i] = k2;
      m3[i] = k3;
      f.add(1, 1 + i, 2);
      unite(1, 1, n, k1, k1, i);
      unite(1, 1, n, k2, k2, i);
      unite(1, 1, n, k3, k3, i);
    } else {
      f.add(1, 1 + i, 1);
    }
  }
  vector<pair<int, int>> it = f.solve(q, whoo);
  for (auto &x : it) {
    fr[x.first]++;
    who[x.second] = x.first;
  }
  int sol = (int) it.size();
  for (int i = 1; i <= q; i++) {
    if (m1[i]) {
      assert(0 <= fr[i] && fr[i] <= 2);
      if (fr[i] == 1) {
        if (who[m1[i]] > 0 && who[m1[i]] != i) {
          who[m1[i]] = i;
          it.push_back({i, m1[i]});
          continue;
        }
        if (who[m2[i]] > 0 && who[m2[i]] != i) {
          who[m2[i]] = i;
          it.push_back({i, m2[i]});
          continue;
        }
        if (who[m3[i]] > 0 && who[m3[i]] != i) {
          who[m3[i]] = i;
          it.push_back({i, m3[i]});
          continue;
        }
      }
    }
  }
  cout << sol << "\n";
  for (auto &x : it) {
    if (who[x.second] != x.first) {
      continue;
    }
    cout << x.first << " " << x.second << "\n";
  }
}