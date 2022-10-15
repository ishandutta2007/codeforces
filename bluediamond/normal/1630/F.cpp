#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;



class MaxFlow {
  struct edge {
    int to;
    int cap;
    int nxt;
  };

  int n;
  vector<edge> edges;
  vector<int> level, pos, head;

public:


  MaxFlow(int nn) : n(nn), level(n + 1), pos(n + 1), head(nn + 1, -1) {}

  void add(int a, int b, int c) {
    assert(1 <= a && a <= n);
    assert(1 <= b && b <= n);
    edges.push_back({ b, c, head[a] });
    edges.push_back({ a, 0, head[b] });



    head[a] = (int)edges.size() - 2;
    head[b] = (int)edges.size() - 1;
  }

  int dfs(int a, int cur) {
    if (a == n || !cur) return cur;
    while (pos[a] != -1) {
      int i = pos[a];
      pos[a] = edges[i].nxt;
      int b = edges[i].to, cap = edges[i].cap;
      if (level[b] == 1 + level[a] && cap > 0) {
        int x = dfs(b, min(cur, cap));
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
        for (int i = head[a]; i != -1; i = edges[i].nxt) {
          int b = edges[i].to;
          if (edges[i].cap && level[b] == -1) {
            level[b] = 1 + level[a];
            q.push(b);
          }
        }
      }

      if (level[n] == -1) break;

      while (1) {
        int nw = dfs(1, (int)1e9);

        if (nw == 0) break;
        sol += nw;
      }
    }

    return sol;
  }
};


class MaxAntichain {
private:
  MaxFlow flow;
  int n;
  const int INF = (int)1e9 + 7;
public:

  MaxAntichain(int n) : n(n), flow(2 * n + 2) {
    for (int i = 1; i <= n; i++) {
      flow.add(1 + i, 1 + n + i, INF);
      flow.add(1, 1 + n + i, 1);
      flow.add(1 + i, 2 * n + 2, 1);
    }
  }

  void add(int a, int b) {
    assert(1 <= a && a <= n);
    assert(1 <= b && b <= n);
    flow.add(1 + n + a, 1 + b, INF);
  }

  int get() {
    return n - flow.get();
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);


  const int N = (int) 5e4 + 7;
  vector<vector<int>> d(N);
  vector<int> p(N, 0);
  for (int i = 1; i < N; i++) {
    for (int j = 2 * i; j < N; j += i) {
      d[j].push_back(i);
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      p[a[i]] = i + 1;
    }
    MaxAntichain antichain(2 * n);
    for (int i = 1; i <= n; i++) {
      antichain.add(i, i + n);
    }
    for (int i = 1; i <= n; i++) {
      for (auto& y : d[a[i - 1]]) {
        if (int j = p[y]) {
          antichain.add(i, j);
          antichain.add(i + n, j + n);
        }
      }
    }
    for (auto& x : a) {
      p[x] = 0;
    }
    cout << n - antichain.get() << "\n";
  }
  return 0;
}