#include <bits/stdc++.h>
 
using namespace std;
using ull = unsigned long long;
 
struct SegTree {
  struct Node {
    ull h = 0; int l = 0, r = 0;
  };
  int n;
  vector<ull> rnd;
  vector<Node> T;
 
  SegTree(int n) : n(n), T(1), rnd(n) {
    mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
    for (int i = 0; i < n; ++i)
      rnd[i] = rng();
  }
 
  int add(int x, int b, int e, int pos) {
    assert(b >= 0);
    auto tmp = T[x]; T.push_back(tmp);
    x = T.size() - 1;
    // cerr << "add: " << x << " " << b << " " << e << " " << pos << endl;
    if (e - b == 1) {
      assert(pos == b);
      T[x].h ^= rnd[pos];
    } else {
      int m = (b + e) / 2;
      if (pos < m) {
        int l = add(T[x].l, b, m, pos);
        T[x].l = l;
      } else {
        int r = add(T[x].r, m, e, pos);
        T[x].r = r;
      }
      T[x].h = T[T[x].l].h ^ T[T[x].r].h;
    }
    return x;
  }
  int Add(int rt, int pos) {
    return add(rt, 0, n, pos);
  }
 
  int query(int x, int y, int req, int b, int e, int l, int r) {
    l = max(l, b); r = min(r, e);
    if (l >= r) return -1;
    if ((T[x].h ^ T[y].h) == 
        (req >= b && req < e ? rnd[req] : 0)) 
      return -1;
    //cerr << "  query: " << b + 1 << " " << e << endl;
    //cerr << "    " << (T[x].h ^ T[y].h ^ (req >= b && req < r ? rnd[req] : 0)) << endl;
 
    if (e - b == 1) return b;
    int m = (b + e) / 2;
    int ret = query(T[x].r, T[y].r, req, m, e, l, r);
    if (ret != -1) return ret;
    return query(T[x].l, T[y].l, req, b, m, l, r);
  }
 
  int Query(int a, int b, int req, int l, int r) {
    return query(a, b, req, 0, n, l, r);
  }
 
  void dump(int x, int b, int e) {
    if (T[x].h == 0) return;
    if (e - b == 1) cerr << b + 1 << " ";
    else {
      int m = (b + e) / 2;
      dump(T[x].l, b, m);
      dump(T[x].r, m, e);
    }
  }
  void Dump(int root) {
    dump(root, 0, n);
    cerr << endl;
  }
};
 
struct RMQ {
  vector<vector<int>> rmq;
 
  RMQ(const vector<int>& v) {
    int n = v.size(), depth = 1;
    while ((1 << depth) < n * 2) ++depth;
    rmq.assign(depth, v);
    for (int i = 0; i < depth - 1; ++i)
      for (int j = 0; j + (2 << i) <= n; ++j)
        rmq[i + 1][j] = min(rmq[i][j], rmq[i][j + (1 << i)]);
  }
  int Query(int a, int b) {
    assert(a < b);
    int dep = 31 - __builtin_clz(b - a); // log(b - a)
    return min(rmq[dep][a], rmq[dep][b - (1 << dep)]);
  }
};
 
 
struct LCA {
  int n, timer = 0;
  vector<int> enter, pv, pt;
  RMQ rmq;
 
  LCA(vector<vector<int>>& graph, int root = 0) : 
    n(graph.size()), enter(n, -1), 
    rmq((dfs(graph, root), pt)) {}
 
  void dfs(auto& graph, int node) {
    enter[node] = timer++;
    for (auto vec : graph[node]) {
      if (enter[vec] != -1) continue;
      pv.push_back(node), pt.push_back(enter[node]);
      dfs(graph, vec);
    }
  }
  int Query(int a, int b) {
    if (a == b) return a;
    a = enter[a], b = enter[b];
    if (a > b) swap(a, b);
    return pv[rmq.Query(a, b)];
  }
  // Distance is depth[a] + depth[b] - 2 depth[Query(a, b)]
};
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n, q; cin >> n >> q;
  vector<int> val(n);
  for (int i = 0; i < n; ++i) {
    cin >> val[i]; --val[i];
  }
  
  vector<vector<int>> graph(n);
  for (int i = 1; i < n; ++i) {
    int a, b; cin >> a >> b;
    graph[a - 1].push_back(b - 1);
    graph[b - 1].push_back(a - 1);
  }
  LCA L(graph);
  SegTree ST(n);
 
  vector<int> roots(n);
  function<void(int, int, int)> dfs = [&](int node, int par, int rt) {
    rt = ST.Add(rt, val[node]);
    roots[node] = rt;
    for (auto vec : graph[node]) {
      if (vec == par) continue;
      dfs(vec, node, rt);
    }
  };
  dfs(0, -1, 0);
  /*
  for (int i = 0; i < n; ++i) {
    ST.Dump(roots[i]);
  }
  */
  for (int i = 0; i < q; ++i) {
    int a, b, l, r; cin >> a >> b >> l >> r; --a; --b; --l;
    int ans = ST.Query(roots[a], roots[b], val[L.Query(a, b)], l, r);
    if (ans != -1) ++ans;
    cout << ans << '\n';
  }
 
  return 0;
}