#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int)1e9 + 7;


struct Flow {
  int n;

  struct Edge {
    int to, cap;
  };

  vector<Edge> edges;
  vector<vector<int>> g;
  vector<int> level, pt;

  void init(int nn) {
    n = nn;
    g.resize(n);
    level.resize(n);
    pt.resize(n);
  }

  void addEdge(int a, int b, int c) {
    a--;
    b--;
    assert(0 <= a && a < n);
    assert(0 <= b && b < n);
    g[a].push_back((int)edges.size());
    g[b].push_back((int)edges.size() + 1);
    edges.push_back({ b, c });
    edges.push_back({ a, 0 });
  }

  int dfs(int a, int cur) {
    if (a == n - 1 || cur == 0) return cur;

    while (pt[a] < (int)g[a].size()) {
      int i = g[a][pt[a]++];
      int b = edges[i].to, cap = edges[i].cap;
      if (level[b] == 1 + level[a] && cap) {
        int x = dfs(b, min(cur, cap));
        if (x) {
          pt[a]--;

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
      for (int i = 0; i < n; i++) level[i] = -1, pt[i] = 0;
      level[0] = 0;
      queue<int> q;
      q.push(0);
      while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (auto& i : g[a]) {
          if (edges[i].cap&&level[edges[i].to]==-1) {
            level[edges[i].to] = 1 + level[a];
            q.push(edges[i].to);
          }
        }
      }
      if (level[n - 1] == -1) break;
      while (1) {
        int x = dfs(0, INF);
        if (!x) break;
        sol += x;
      }
    }
    return sol;
  }

  vector<bool> get_min_cut_side() {
    vector<bool> marked(n, 0);
    queue<int> q;
    q.push(0);
    marked[0] = 1;
    while (!q.empty()) {
      int a = q.front();
      q.pop();
      for (auto &i : g[a]) {
        if (edges[i].cap && !marked[edges[i].to]) {
          marked[edges[i].to] = 1;
          q.push(edges[i].to);
        }
      }
    }
    return marked;
  }
};

struct T {
  int i, t;
};

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int n, m, cnt_males, cnt_females;
  cin >> n >> m >> cnt_males >> cnt_females;

  vector<int> is_valid(n * m, 0);




  function<int(int, int)> get_id = [&] (int r, int c) {
    assert(0 <= r && r < n);
    assert(0 <= c && c < m);
    int id = r * m + c;
    assert(0 <= id && id < n * m);
    return id;
  };

  function<T()> read = [&] () {
    int i, j, t;
    cin >> i >> j >> t;
    return T{get_id(i - 1, j - 1), t};
  };



  vector<vector<int>> dist(n * m, vector<int> (n * m, INF));

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    assert((int) s.size() == m);
    for (int j = 0; j < m; j++) {
      assert(s[j] == '.' || s[j] == '#');
      is_valid[get_id(i, j)] = (s[j] == '.');
    }
  }

  for (int i = 0; i < n * m; i++) {
    dist[i][i] = 0;
  }

  function<void(int, int, int, int)> add_edge = [&] (int r1, int c1, int r2, int c2) {
    int i1 = get_id(r1, c1);
    int i2 = get_id(r2, c2);
    dist[i1][i2] = min(dist[i1][i2], 1);
    dist[i2][i1] = min(dist[i2][i1], 1);
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (is_valid[get_id(i, j)]) {
        if (i + 1 < n && is_valid[get_id(i + 1, j)]) add_edge(i, j, i + 1, j);
        if (j + 1 < m && is_valid[get_id(i, j + 1)]) add_edge(i, j, i, j + 1);
      }
    }
  }

  for (int k = 0; k < n * m; k++) {
    for (int i = 0; i < n * m; i++) {
      for (int j = 0; j < n * m; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  vector<T> females(cnt_females), males(cnt_males);
  T special;
  special = read();
  for (auto &it : males) {
    it = read();
  }
  for (auto &it : females) {
    it = read();
  }

  if ((int) females.size() < (int) males.size()) {
    females.push_back(special);
  } else {
    males.push_back(special);
  }

  if ((int) females.size() != (int) males.size()) {
    cout << "-1\n";
    exit(0);
  }

  int k = (int) females.size();
  assert((int) females.size() == k);
  assert((int) males.size() == k);

  vector<int> cell_id(n * m, 0);
  vector<int> validCells;
  for (int i = 0; i < n * m; i++) {
    if (is_valid[i]) {
      cell_id[i] = (int) validCells.size();
      validCells.push_back(i);
    }
  }

  function<bool(ll)> is_ok = [&] (ll limit) {
    Flow net;
    net.init(1 + k + (int) validCells.size() + (int) validCells.size() + k + 1);
    int s = 1, d = 1 + k + (int) validCells.size() + (int) validCells.size() + k + 1;


    for (int st = 1; st <= (int) validCells.size(); st++) {
      int j = validCells[st - 1];
      net.addEdge(1 + k + st, 1 + k + (int) validCells.size() + st, 1);
    }

    for (int i = 1; i <= k; i++) {
      net.addEdge(s, 1 + i, 1);
      net.addEdge(1 + k + 2 * (int) validCells.size() + i, d, 1);


      auto girl = females[i - 1], boy = males[i - 1];
      for (int st = 1; st <= (int) validCells.size(); st++) {
        int j = validCells[st - 1];

        bool ok = (i == 3 && j == get_id(0, 1));

        if (dist[j][girl.i] != INF && dist[j][girl.i] * (ll) girl.t <= limit) {
          net.addEdge(1 + i, 1 + k + st, 1);

        } else {
          /**if (ok) {
            cout << " bad\n";
            cout << " girl i = " << girl.i << "\n";
          ///  cout << "bad : " << dist[j][girl.i] << " | " << j << ", " << girl.i << "\n";
          }**/
        }


        if (dist[j][boy.i] != INF && dist[j][boy.i] * (ll) boy.t <= limit) {
          net.addEdge(1 + k + (int) validCells.size() + st, 1 + k + 2 * (int) validCells.size() + i, 1);
        } else {
        }



      }
    }


    return net.get() == k;
  };


  ll low = 0, high = (ll) 1e14, sol = -1;
  while (low <= high) {
    ll mid = (low + high) / 2;
    ///cout << mid << " : " << is_ok(mid) << "\n";
    if (is_ok(mid)) {
      sol = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << sol << "\n";

}