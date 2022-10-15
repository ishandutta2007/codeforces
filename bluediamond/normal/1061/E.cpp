#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct MCMF {
  const long long INFLL = (long long)1e18;
  const int INFINT = (int)1e9;
  int n, s, d;

  struct Edge {
    int to, cap, cost;
  };

  vector<Edge> edges;
  vector<int> deg;
  vector<int> verts;
  vector<int> parrent;
  vector<long long> mincost;
  vector<long long> off;
  vector<vector<int>> g;

  MCMF(int n, int m, int s, int d) : n(n), s(s), d(d), deg(n, 0), g(n), mincost(n), parrent(n), off(n) {
    edges.reserve(m);
  }

  void add(int a, int b, int cap, int cost) {
    edges.push_back({ b, cap, cost });
    edges.push_back({ a, 0, -cost });
    verts.push_back(a);
    verts.push_back(b);
    deg[a]++;
    deg[b]++;
  }

  void belf() {
    queue<int> q;
    vector<bool> inq(n, 0);
    for (int i = 0; i < n; i++) mincost[i] = INFLL;
    q.push(s);
    inq[s] = 1;
    mincost[s] = 0;
    while (!q.empty()) {
      int a = q.front();
      inq[a] = 0;
      q.pop();
      for (auto& i : g[a]) {
        if (edges[i].cap) {
          int b = edges[i].to;
          long long value_b = mincost[a] + edges[i].cost;
          if (value_b < mincost[b]) {
            mincost[b] = value_b;
            if (!inq[b]) q.push(b);
            parrent[b] = i;
          }
        }
      }
    }
    for (int i = 0; i < n; i++) off[i] = mincost[i];
  }

  void dij() {
    priority_queue<pair<long long, int>> q;
    for (int i = 0; i < n; i++) mincost[i] = INFLL;
    q.push({ 0, s });
    mincost[s] = 0;
    while (!q.empty()) {
      pair<long long, int> it = q.top();
      q.pop();
      if (mincost[it.second] != -it.first) continue;
      int a = it.second;
      for (auto& i : g[a]) {
        if (edges[i].cap) {
          int b = edges[i].to;
          long long value_b = mincost[a] + (edges[i].cost + off[a] - off[b]);
          if (value_b < mincost[b]) {
            mincost[b] = value_b;
            q.push({ -mincost[b], b });
            parrent[b] = i;
          }
        }
      }
    }
    for (int i = 0; i < n; i++) mincost[i] = mincost[i] - off[s] + off[i], off[i] = mincost[i];
  }

  pair<long long, long long> get() {
    for (int i = 0; i < n; i++) g[i].reserve(deg[i]);
    for (int i = 0; i < (int)verts.size(); i++) g[verts[i]].push_back(i);

    long long flow = 0, bestcostforflow = 0;
    belf();
    while (1) {
      dij();
      if (mincost[d] >= INFLL) break;
      int mn = INFINT;
      long long sumcost = 0;
      vector<int> path;
      for (int i = d; i != s; i = edges[(parrent[i] ^ 1)].to) {
        path.push_back(parrent[i]);
        mn = min(mn, edges[parrent[i]].cap);
        sumcost += edges[parrent[i]].cost;
      }
      for (auto& i : path) {
        edges[i].cap -= mn;
        edges[i ^ 1].cap += mn;
      }
      flow += mn;
      bestcostforflow += (long long)mn * sumcost;
    }
    return { flow, bestcostforflow };
  }
};



int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input","r",stdin);

  int n, r1, r2;
  cin >> n >> r1 >> r2;
  r1--;
  r2--;
  vector<int> cost_vert(n);
  for (auto& x : cost_vert) cin >> x;
  vector<int> need1(n, -1), need2(n, -1);
  vector<vector<int>> g1(n), g2(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g1[a].push_back(b);
    g1[b].push_back(a);
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g2[a].push_back(b);
    g2[b].push_back(a);
  }
  MCMF flow(2 * n + 2, 0, 0, 2 * n + 1);
  int cnt1, cnt2;
  cin >> cnt1;
  for (int i = 0; i < cnt1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    assert(need1[a] == -1);
    need1[a] = b;
  }
  cin >> cnt2;
  for (int i = 0; i < cnt2; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    assert(need2[a] == -1);
    need2[a] = b;
  }

  ///  return 0;
  vector<int> sum1 = need1;
  vector<int> sum2 = need2;
  vector<int> what1(n), what2(n);
  vector<int> par1(n, -1);
  vector<int> par2(n, -1);

  function<void(int, int, vector<vector<int>>&, vector<int>&, vector<int>&, vector<int>&)>dfs = [&](int a, int p, vector<vector<int>>& g, vector<int>& sum, vector<int>& par, vector<int>& what) {
    par[a] = p;
    if (sum[a] == -1)sum[a] = 0;
    int init = sum[a];
    for (auto& b : g[a]) {
      if (b == p) continue;
      dfs(b, a, g, sum, par, what);
      sum[a] += sum[b];
    }
    if (init) {
      what[a] = init - (sum[a] - init);
      sum[a] = init;
    }
  };


  dfs(r1, -1, g1, sum1, par1, what1);
  dfs(r2, -1, g2, sum2, par2, what2);

  for (int i = 0; i < n; i++) {
    int cap = what1[i], cost = 0;
    if (cap >= 0) {
      flow.add(0, i + 1, cap, cost);
    }
    else {
      cout << "-1\n";
      exit(0);
    }
  }

  for (int i = 0; i < n; i++) {
    int cap = what2[i], cost = 0;
    if (cap >= 0) {
      flow.add(1 + n + i, 2 * n + 1, cap, cost);
    }
    else {
      cout << "-1\n";
      exit(0);
    }
  }

  for (int i = 0; i < n; i++) {
    int a = i, b = i;
    while (need1[a] == -1) {
      a = par1[a];
      assert(a != -1);
    }
    while (need2[b] == -1) {
      b = par2[b];
      assert(b != -1);
    }
    int cap = 1;
    int cost = -cost_vert[i];
    flow.add(1 + a, 1 + n + b, cap, cost);
  }
  auto it = flow.get();
  if (it.first != max(sum1[r1], sum2[r2])) {
    cout << "-1\n";
    exit(0);
  }
  cout << -it.second << "\n";
}