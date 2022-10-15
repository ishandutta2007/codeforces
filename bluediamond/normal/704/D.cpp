#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
signed realMain();


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int INF = (int) 1e9;


struct flow {
  struct edge {
    int to;
    int cap;
    int spre;
  };
  const int INF = (int) 1e9;
  int n;
  vector<int> head;
  vector<edge> edges;
  vector<int> level;
  vector<int> pt;

  void init(int nn) {
    n = nn;
    edges.clear();
    head.resize(n + 1, -1);
    pt.resize(n + 1);
    level.resize(n + 1);
  }

  void add(int a, int b, int c, int d = 0) {
    edges.push_back({b, c, head[a]});
    edges.push_back({a, d, head[b]});

    head[a] = (int) edges.size() - 2;
    head[b] = (int) edges.size() - 1;
  }

  int dfs(int a, int cap) {
    if (cap == 0 || a == n) {
      return cap;
    }
    while (pt[a] != -1) {
      int i = pt[a];
      if (edges[i].cap && level[edges[i].to] == 1 + level[a]) {
        int b = edges[i].to;
        int x = dfs(b, min(cap, edges[i].cap));
        if (x > 0) {
          edges[i].cap -= x;
          edges[i ^ 1].cap += x;
          return x;
        }
      }
      pt[a] = edges[pt[a]].spre;
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
        int ind = head[a];
        while (ind != -1) {
          if (edges[ind].cap > 0) {
            int b = edges[ind].to;
            if (level[b] == -1) {
              level[b] = 1 + level[a];
              q.push(b);
            }
          }
          ind = edges[ind].spre;
        }
      }
      if (level[n] == -1) {
        break;
      }
      pt = head;
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


struct demand_flow {
  int n;
  struct edge {
    int from;
    int to;
    int lo;
    int hi;
    int taken;
    int id;
  };
  vector<edge> edges;
  void init(int nn) {
    n = nn;
    edges.clear();
  }
  void add(int a, int b, int lo, int hi) {
    edge it;
    it.from = a;
    it.to = b;
    it.lo = lo;
    it.hi = hi;
    it.taken = 0;
    it.id = 0;
    edges.push_back(it);
  }
  int ret;
  bool good;
  void rec() {
    ret = 0;
    good = 1;
    flow gbig;
    gbig.init(n + 2);
    gbig.add(1 + n, 1 + 1, INF);
    int slo = 0;
    for (auto &it : edges) {
      if (it.lo > it.hi) {
        good = 0;
        return;
      }
      if (it.hi == 0) continue;

      slo += it.lo;
      it.taken = 0;

      it.id = (int) gbig.edges.size();
      assert(it.lo >= 0);
      gbig.add(1 + it.from, 1 + it.to, it.hi - it.lo);

      gbig.add(1, 1 + it.to, it.lo);
      gbig.add(1 + it.from, 2 + n, it.lo);
    }

    if (gbig.get() != slo) {
      good = 0;
      return;
    }


    flow rl;
    rl.init(n);
    for (auto &it : edges) {


      if (it.hi == 0) continue;

      /// momentan e efectiv cat am acum
      /// cat = cat a trecut in plus de flowmin
      int new_id = (int) rl.edges.size();

      rl.add(it.from, it.to, gbig.edges[it.id].cap, gbig.edges[it.id ^ 1].cap);

      it.id = new_id;
    }
    int val = rl.get();
    for (auto &it : edges) {


      if (it.hi == 0) continue;

      it.taken = it.lo + rl.edges[it.id ^ 1].cap;
      if (it.from == 1) {
        ret += it.taken;
      }
      if (it.to == 1) {
        ret -= it.taken;
      }
    }
  }
};

const int N = (int) 1e5 + 7;
int n, m, r, b, x[N], y[N], id[N];
int sx[N], sy[N], catex[N], catey[N];

pair<int, int> compute(int total, int cnt) {
  return {(total - cnt + 1) / 2, (total + cnt) / 2};
}

signed realMain() {
  cin >> n >> m >> r >> b;
  map<int, int> nox, noy;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    nox[x[i]] = 0;
    noy[y[i]] = 0;
    sx[i] = sy[i] = N;
  }
  int ind = 0;
  for (auto &it : nox) {
    it.second = ++ind;
  }
  ind = 0;
  for (auto &it : noy) {
    it.second = ++ind;
  }
  for (int i = 1; i <= n; i++) catex[nox[x[i]]]++;
  for (int i = 1; i <= n; i++) catey[noy[y[i]]]++;
  int cx = (int) nox.size(), cy = (int) noy.size();
  while (m--) {
    int tp, l, d;
    cin >> tp >> l >> d;
    if (tp == 1) {
      if (nox.count(l)) {
        sx[nox[l]] = min(sx[nox[l]], d);
      }
    } else {
      if (noy.count(l)) {
        sy[noy[l]] = min(sy[noy[l]], d);
      }
    }
  }
  demand_flow f;
  f.init(1 + cx + cy + 1);
  for (int i = 1; i <= cx; i++) {
    auto it = compute(catex[i], sx[i]);
    ///cout << "x " << it.first << " " << it.second << "\n";
    it.first = max(it.first, 0);
    f.add(1, 1 + i, it.first, it.second);
  }



  for (int i = 1; i <= cy; i++) {
    auto it = compute(catey[i], sy[i]);
    it.first = max(it.first, 0);
    f.add(1 + cx + i, 1 + cx + cy + 1, it.first, it.second);
  }

  for (int i = 1; i <= n; i++) {
    id[i] = (int) f.edges.size();
    f.add(1 + nox[x[i]], 1 + cx + noy[y[i]], 0, 1);
  }
  f.rec();
  if (f.good == 0) {
    cout << "-1\n";
    return 0;
  }
  string kek = "rb";
  int cnt = f.ret;
  if (r > b) {
    swap(r, b);
    kek = "br";
  }
  cout << (ll) cnt * r + (ll) (n - cnt) * b << "\n";
  for (int i = 1; i <= n; i++) {
    int val = f.edges[id[i]].taken;
    assert(val == 0 || val == 1);
    cout << kek[1 - val];
  }
  cout << "\n";
  return 0;
}