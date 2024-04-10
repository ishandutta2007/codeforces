#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = (int) 1e9;

struct flow {
  struct edge {
    int to;
    int cap;
  };
  const int INF = (int) 1e9;
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

const int E = 100 + 7;
int last[E];
int n;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  /**
  Deci,
  maxflow = mincut
  vreau:
  ret = sum b pozitive - mincut
  mincut = minim => ret = maxim
  pentru b pozitive trasez muchie de la s la i de b(i)
    deci daca i nu face parte din solutie => muchia (s, i) apare in taietura deci NU apare in ret
         daca i face parte din solutie => muchia (s, i) NU apare in taietura deci apare in ret
  pentru b negative trasez muchid de la t la i de -b(i)
    deci daca i nu face parte din solutie => s si i sunt in parti diferite => t si i sunt in parti egale => NU exista muchia (t, i)
         daca i face parte din solutie => s si i sunt in ac parte => t si i sunt in parti diferite => exista muchia (t, i) pe care trebuie sa
         o platesc in formula ret = sum b pozitive - mincut

  fac toata asta si cu (s) si cu (t) doar ptc Nu merge sa fac flux maxim cu nr negative


  **/

  flow f;
  cin >> n;
  f.init(n + 2);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for (int y = 1; y <= x; y++) {
      if (x % y == 0 && last[y]) {
        f.add(i + 1, last[y] + 1, INF);
      }
    }
    last[x] = i;
  }
  int sum_pos = 0;
  for (int i = 1; i <= n; i++) {
    int b;
    cin >> b;
    if (b >= 0) {
      sum_pos += b;
      f.add(1, i + 1, b);
    } else {
      f.add(i + 1, n + 2, -b);
    }
  }
  cout << sum_pos - f.get() << "\n";


}