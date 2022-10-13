#include <bits/stdc++.h>
 
using namespace std;
const int INF = 1e9;
const int X = 1e6;

struct DSU {
  vector<int> link;
  DSU(int n) : link(n, -1) {}
  int Find(int x) {
    if (link[x] == -1) return x;
    return link[x] = Find(link[x]);
  }
  bool Union(int a, int b) {
    a = Find(a); b = Find(b);
    if (a != b) {
      link[a] = b;
      return true;
    }
    return false;
  }
};
 
struct Tree {
  int n;
  vector<int> a, b;
  Tree(int n, vector<int> a, vector<int> b) : n(n), a(a), b(b) {}
  vector<int> Admits(vector<bool> sol) {
    DSU D(n);
    for (int i = 0; i < (int)sol.size(); ++i) {
      if (sol[i])
        D.Union(a[i], b[i]);
    }
    vector<int> ret;
    for (int i = 0; i < (int)sol.size(); ++i) {
      if (!sol[i] && D.Find(a[i]) != D.Find(b[i]))
        ret.push_back(i);
    }
    return ret;
  }
};
 
struct Color {
  vector<int> v, a, b;
  Color(vector<int> v, vector<int> a, vector<int> b) : v(v), a(a), b(b) {}
 
  vector<int> Admits(vector<bool> sol) {
    vector<int> w = v;
    for (int i = 0; i < (int)sol.size(); ++i) {
      if (sol[i])
        w[a[i]] -= 1, w[b[i]] -= 1;
    }
    vector<int> ret;
    for (int i = 0; i < (int)sol.size(); ++i) 
      if (!sol[i] && w[a[i]] > 0 && w[b[i]] > 0)
        ret.push_back(i);
    return ret;
  }
};
 

template <class M1, class M2>
pair<int, int> MatrInter(M1 m1, M2 m2, vector<int> w) {
  int n = w.size(), M = 0;
  for (int i = 0; i < n; ++i)
    M = max(M, abs(w[i]) + 1);

  vector<bool> sol(n, false);
  while (true) {
    // Build graph.
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; ++i) {
      if (!sol[i]) continue;
      sol[i] = 0; 
      for (auto j : m1.Admits(sol)) 
        graph[i].push_back(j);
      for (auto j : m2.Admits(sol)) 
        graph[j].push_back(i);
      sol[i] = 1;
    }
    // Find augmenting path.
    vector<int> inq(n, 0), parent(n, -2);
    vector<long long> dist(n);
    deque<int> q;
    auto push = [&](int v, int p, long long d) {
      if (parent[v] != -2 && dist[v] <= d) return;
      dist[v] = d; parent[v] = p; 
      if (!inq[v]) inq[v] = 1, q.push_back(v);
    };
    for (auto node : m1.Admits(sol))
      push(node, -1, 1LL * w[node] * M);
    while (q.size()) {
      int node = q.front(); q.pop_front(); inq[node] = 0;
      for (auto vec : graph[node]) 
        if (vec != node)
          push(vec, node, dist[node] + 
              (sol[vec] ? -1LL : 1LL) * w[vec] * M + 1);
    }
    int choose = -1; long long best = 1LL * M * M;
    for (auto node : m2.Admits(sol))
      if (parent[node] != -2 && dist[node] < best)
        best = dist[node], choose = node;
    if (choose == -1) break;
    // Augment.
    for (int node = choose; node != -1; node = parent[node]) 
      sol[node] = !sol[node];
  }
  
  int ans = 0, cnt = 0;
  for (int i = 0; i < n; ++i) 
    if (sol[i]) 
      ans += w[i], ++cnt;
  return make_pair(cnt, ans);
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n, k; cin >> n >> k;
  vector<int> v(n, n);
  for (int i = 0; i < k; ++i)
    cin >> v[i];
 
  vector<int> a, b, w;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int x; cin >> x;
      a.push_back(i);
      b.push_back(j);
      w.push_back(x);
    }
  }
 
  int m = a.size();
  vector<int> o(m);
  iota(o.begin(), o.end(), 0);
  sort(o.begin(), o.end(), [&](int a, int b) { return w[a] < w[b]; });
 
  vector<int> na, nb, nw, si;
  DSU D(n);
  for (auto i : o) {
    if (a[i] < k && b[i] < k) 
      si.push_back(na.size());
    if (a[i] < k || b[i] < k || D.Union(a[i], b[i])) {
      na.push_back(a[i]);
      nb.push_back(b[i]);
      nw.push_back(w[i]);
    }
 
  }
  a = na; b = nb; w = nw;
 
  int sol = INF;
  for (int msk = 0; msk < (1 << si.size()); ++msk) {
    DSU D(n);
    vector<int> now_w = w;
    vector<int> ww = v;
    int delta = 0;
    bool bad = false;
 
    for (int i = 0; i < (int)si.size(); ++i) {
      if (msk & (1 << i)) {
        if (!D.Union(a[si[i]], b[si[i]]))
          bad = true;
        if (--ww[a[si[i]]] < 0 || --ww[b[si[i]]] < 0)
          bad = true;
        
        delta += w[si[i]] + X;
        now_w[si[i]] = -X;
      } else now_w[si[i]] = X;
    }
    if (bad) continue;
    Tree T(n, a, b);
    Color C(v, a, b);
    auto [sz, wei] = MatrInter(T, C, now_w);
    if (sz == n - 1)
      sol = min(sol, wei + delta);
  }
  cout << sol << endl;
 
  return 0;
}