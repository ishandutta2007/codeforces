#include <bits/stdc++.h>

using namespace std;

const int INF = (int) 1e9;

struct flow {
  struct edge {
    int cap;
    int from;
    int to;
    int nxt;
  };
  int n;
  vector<int> pos;
  vector<int> level;
  vector<int> head;
  vector<edge> edges;
  void init(int nn) {
    n = nn;

    pos.clear();
    level.clear();
    edges.clear();
    head.clear();

    head.resize(n + 1, -1);
    pos.resize(n + 1);
    level.resize(n + 1);
  }
  void add(int a, int b, int c) {
    edges.push_back({c, a, b, head[a]});
    edges.push_back({0, b, a, head[b]});

    head[a] = (int) edges.size() - 2;
    head[b] = (int) edges.size() - 1;
  }
  int dfs(int a, int cap) {
    if (!cap || a == n) {
      return cap;
    }
    while (pos[a] != -1) {
      int i = pos[a];
      pos[a] = edges[i].nxt;
      if (edges[i].cap > 0 && level[edges[i].to] == 1 + level[a]) {
        int x = dfs(edges[i].to, min(cap, edges[i].cap));
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
    int sol = 0;
    while (1) {
      for (int i = 1; i <= n; i++) {
        level[i] = -1;
        pos[i] = head[i];
      }
      level[1] = 0;
      queue<int> q;
      q.push(1);
      while (!q.empty()) {
        int a = q.front();
        q.pop();
        int ind = head[a];
        while (ind != -1) {
          int b = edges[ind].to;
          if (edges[ind].cap > 0 && level[b] == -1) {
            level[b] = 1 + level[a];
            q.push(b);
          }
          ind = edges[ind].nxt;
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
        sol += x;
      }
    }
    return sol;
  }
};

struct point {
  int x, y;
};

void print(vector<vector<int>> sol) {
  cout << (int) sol.size() << "\n";
  for (auto &kek : sol) {
    for (auto &v : kek) {
      cout << v << " ";
    }
    cout << "\n";
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);


  int n;
  cin >> n;
  vector<point> points(n);
  map<int, vector<int>> lax, lay;
  map<int, vector<int>> indx, indy;

  for (auto &p : points) {
    cin >> p.x >> p.y;
    lax[p.x].push_back(p.y);
    lay[p.y].push_back(p.x);
  }
  int sa = 0, sb = 0;
  for (auto &it : lax) {
    sort(it.second.begin(), it.second.end());
    for (int i = 0; i < (int) it.second.size() - 1; i++) {
      indx[it.first].push_back(++sa);
    }
  }
  for (auto &it : lay) {
    sort(it.second.begin(), it.second.end());
    for (int i = 0; i < (int) it.second.size() - 1; i++) {
      indy[it.first].push_back(++sb);
    }
  }

  vector<pair<int, int>> edges;

  for (auto &it1 : lax) {
    int x = it1.first;
    for (int j1 = 0; j1 < (int) it1.second.size() - 1; j1++) {
      int ymin = it1.second[j1], ymax = it1.second[j1 + 1];

      for (auto &it2 : lay) {
        int y = it2.first;
        for (int j2 = 0; j2 < (int) it2.second.size() - 1; j2++) {
          int xmin = it2.second[j2], xmax = it2.second[j2 + 1];

          if (xmin < x && x < xmax && ymin < y && y < ymax) {
            edges.push_back({indx[x][j1], indy[y][j2]});
          }
        }
      }
    }
  }


  flow f;
  f.init(1 + sa + sb + 1);

  for (int i = 1; i <= sa; i++) {
    f.add(1, 1 + i, 1);
  }
  for (int i = 1; i <= sb; i++) {
    f.add(1 + sa + i, 1 + sa + sb + 1, 1);
  }

  for (auto &it : edges) {
    f.add(1 + it.first, 1 + sa + it.second, 1);
  }
  f.get();

  vector<vector<int>> gr(1 + sa + sb + 1 + 1);
  vector<bool> vis(1 + sa + sb + 1 + 1, 0);

  for (auto &it : f.edges) {
    if (it.from < it.to) {
      if (it.cap > 0) {
        gr[it.from].push_back(it.to);
      } else {
        gr[it.to].push_back(it.from);
      }
    }
  }

  function<void(int)> squid = [&] (int a) {
    vis[a] = 1;
    for (auto &b : gr[a]) {
      if (!vis[b]) {
        squid(b);
      }
    }
  };

  squid(1);

  assert(vis[1]);
  assert(!vis[1 + sa + sb + 1]);

  vector<int> a(sa + 1);
  vector<int> b(sb + 1);

  //cout << " --> ";
  for (int i = 1; i <= sa; i++) {
    a[i] = (vis[1 + i] == 1);
    //cout << a[i] << " ";
  }
  //cout << "\n";

  //cout << " --> ";
  for (int i = 1; i <= sb; i++) {
    b[i] = (vis[1 + sa + i] == 0);
    //cout << b[i] << " ";
  }
  //cout << "\n";


  { /// print y
    vector<vector<int>> sol;
    int cur = 0;
    for (auto &it : lay) {
      vector<int> all = it.second;
      int l = 0;
      while (l < (int) all.size()) {
        int r = l;
        while (r + 1 < (int) all.size() && b[++cur]) {
          r++;
        }
        sol.push_back({all[l], it.first, all[r], it.first});
        l = r + 1;
      }
    }
    print(sol);
  }

  { /// print x
    vector<vector<int>> sol;
    int cur = 0;
    for (auto &it : lax) {
      vector<int> all = it.second;
      int l = 0;
      while (l < (int) all.size()) {
        int r = l;
        while (r + 1 < (int) all.size() && a[++cur]) {
          r++;
        }
        sol.push_back({it.first, all[l], it.first, all[r]});
        l = r + 1;
      }
    }
    print(sol);
  }


  return 0;
}