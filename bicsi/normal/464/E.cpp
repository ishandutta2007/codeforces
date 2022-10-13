#include <bits/stdc++.h>
 
using namespace std;
using ull = unsigned long long;
 
const int kMod = 1e9 + 7;
mt19937_64 rng(time(0));
 
struct SegTree {
  struct Node {
    ull dp = 0;
    int l = 0, r = 0;
    ull hash = 0;
  };
 
  int n;
  vector<Node> T;
  vector<ull> rnd;
 
  SegTree(int n) : n(n), T(1), rnd(n) {
    for (int i = 0; i < n; ++i)
      rnd[i] = rng();
  }
 
  pair<int, int> add(int node, int b, int e, int pos) {
    if (e <= pos) return {node, 0};
    if (b == pos && T[node].dp + 1 == 0)
      return {0, 1};
 
    T.emplace_back();
    int ret = T.size() - 1;
    if (e - b == 64) {
      T[ret].dp = T[node].dp;
      T[ret].dp += (1ULL << (pos - b));
      int state = 1 + (T[ret].dp > T[node].dp);
      for (int i = b; i < e; ++i)
        if (T[ret].dp & (1ULL << (i - b)))
          T[ret].hash += rnd[i];
      return {ret, state};
    }
 
    int state; int l = T[node].l, r = T[node].r;
    int m = (b + e) / 2;
    tie(l, state) = add(l, b, m, pos);
    if (state == 0)
      tie(r, state) = add(r, m, e, pos);
    else if (state == 1)
      tie(r, state) = add(r, m, e, m);
 
    T[ret].l = l; T[ret].r = r;
    T[ret].hash = T[l].hash + T[r].hash;
    T[ret].dp = min(T[l].dp, T[r].dp); 
    return {ret, state};
  }
  int Add(int node, int val) {
    auto [ret, state] = add(node, 0, n, val);
    assert(state == 2);
    return ret;
  }
 
 
  int compare(int x, int y, int b, int e) {
    if (T[x].hash == T[y].hash) return 0;
    if (e - b == 64) 
      return T[x].dp < T[y].dp ? -1 : 1;
    int m = (b + e) / 2;
    int ret = compare(T[x].r, T[y].r, m, e);
    if (ret) return ret;
    return compare(T[x].l, T[y].l, b, m);
  }
  int Compare(int a, int b) {
    return compare(a, b, 0, n);
  }
 
  void get(int node, int b, int e, int& ans) {
    if (e - b == 64) {
      for (int i = b; i < e; ++i)
        ans = (ans + ans) % kMod;
      ans = (ans + T[node].dp % kMod) % kMod;
    } else {
      int m = (b + e) / 2;
      get(T[node].r, m, e, ans);
      get(T[node].l, b, m, ans);
    }
  }
  int Get(int node) {
    int ans = 0;
    get(node, 0, n, ans);
    return ans;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
 
  int n, m; cin >> n >> m;
  vector<vector<pair<int, int>>> graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b, c; cin >> a >> b >> c; --a; --b;
    graph[a].emplace_back(c, b);
    graph[b].emplace_back(c, a);
  }
  
  SegTree st(1 << 17);
  int s, t; cin >> s >> t; --s; --t;
 
  auto cmp = [&](pair<int, int> a, pair<int, int> b) {
    return st.Compare(a.first, b.first) == 1;
  };
  priority_queue<pair<int, int>, vector<pair<int, int>>, 
    decltype(cmp)> pq(cmp);
  
  vector<int> dist(n, -1), parent(n, -1), vis(n, false);
  dist[s] = 0;
  pq.emplace(0, s);

  while (pq.size()) {
    auto [d, node] = pq.top(); pq.pop();
    if (d != dist[node]) continue;
    if (node == t) break;
    vis[node] = true;
    
    for (auto [cost, vec] : graph[node]) {
      if (vis[vec]) continue;
      int nd = st.Add(d, cost);
      if (dist[vec] == -1 || st.Compare(nd, dist[vec]) == -1) {
        dist[vec] = nd;
        parent[vec] = node;
        pq.emplace(nd, vec);
      } 
    }
  }
 
  if (dist[t] == -1) {
    cout << -1 << '\n';
  } else {
    vector<int> trace;
    for (int node = t; node != -1; node = parent[node])
      trace.push_back(node);
    reverse(trace.begin(), trace.end());
    cout << st.Get(dist[t]) << endl;
    cout << trace.size() << endl;
    for (auto x : trace) 
      cout << x + 1 << " ";
    cout << endl;
  }
 
  return 0;
}