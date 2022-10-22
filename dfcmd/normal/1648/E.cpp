#include <bits/stdc++.h>

class disjoint_set {
public:
  typedef std::size_t size_type;

protected:
  std::vector<size_type> fa;

public:
  disjoint_set(size_type n = 0) : fa(n) {
    std::iota(fa.begin(), fa.end(), 0);
  }

  size_type find(size_type x) {
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
  }

  bool merge(size_type x, size_type y) {
    x = find(x), y = find(y);
    if (x == y) {
      return false;
    }
    fa[y] = x;
    return true;
  }
};

struct edge {
  int u, v, w;

  edge() {}

  edge(int t_u, int t_v, int t_w) : u(t_u), v(t_v), w(t_w) {}

  bool operator<(const edge &rhs) const {
    return w < rhs.w;
  }
};

class rmq {
  int n;
  std::vector<int> lg;
  std::vector<std::vector<int>> st;

public:
  rmq(const std::vector<int> &a) : n(a.size()), lg(n + 1) {
    lg[1] = 0;
    for (int i = 2; i <= n; ++i) {
      lg[i] = lg[i >> 1] + 1;
    }
    st.assign(lg[n] + 1, std::vector<int>(n));
    st[0] = a;
    for (int i = 1; i <= lg[n]; ++i) {
      for (int j = 0; j + (1 << i) <= n; ++j) {
        st[i][j] = std::max(st[i - 1][j], st[i - 1][j + ((1 << (i - 1)))]);
      }
    }
  }

  int query(int l, int r) const {
    int t = lg[r - l];
    return std::max(st[t][l], st[t][r - (1 << t)]);
  }
};

class graph {
  int n;
  std::vector<std::vector<int>> E;
  std::vector<int> val;
  std::vector<int> dfn;
  std::vector<int> id;
  rmq T;

  std::vector<int> init(std::vector<edge> &edges) {
    std::sort(edges.begin(), edges.end());
    disjoint_set D(2 * n - 1);
    int idx = n;
    for (const auto &e : edges) {
      if (D.find(e.u) != D.find(e.v)) {
        E[idx].push_back(D.find(e.u));
        E[idx].push_back(D.find(e.v));
        val[idx - n] = e.w;
        D.merge(idx, e.u);
        D.merge(idx, e.v);
        ++idx;
      }
    }

    std::vector<int> a;

    auto dfs = [&](auto &self, int u) -> void {
      if (E[u].empty()) {
        dfn[u] = a.size();
      } else {
        a.push_back(val[u - n]);
        for (int v : E[u]) {
          self(self, v);
          id.push_back(u);
          a.push_back(val[u - n]);
        }
      }
    };

    dfs(dfs, idx - 1);
    id.resize(a.size());
    for (int i = 0; i < n; ++i) {
      id[dfn[i]] = i;
    }
    return a;
  }

public:
  graph(int t_n, std::vector<edge> edges)
      : n(t_n), E(2 * n - 1), val(n - 1), dfn(n), id(), T(init(edges)) {}
  
  int get_dfn(int u) const {
    return dfn[u];
  }

  int get_id(int x) const {
    return id[x];
  }

  int query(int u, int v) const {
    int l = dfn[u], r = dfn[v];
    if (l > r) {
      std::swap(l, r);
    }
    return T.query(l, r);
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<edge> E1(m);
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
      std::cin >> E1[i].u >> E1[i].v >> E1[i].w;
      --E1[i].u, --E1[i].v;
      adj[E1[i].u].push_back(E1[i].v);
      adj[E1[i].v].push_back(E1[i].u);
    }

    graph G1(n, E1);
    disjoint_set C(n);
    std::vector<edge> E2;
    const int INF = 0x3f3f3f3f;
    std::set<int> S;
    for (int i = 0; i < n; ++i) {
      S.insert(G1.get_dfn(i));
    }
    while (1) {
      std::vector<std::vector<int>> cp(n);
      for (int i = 0; i < n; ++i) {
        cp[C.find(i)].push_back(i);
      }
      bool ok = false;
      for (int i = 0; i < n; ++i) {
        if (!cp[i].empty()) {
          edge min(0, 0, INF);
          for (int x : cp[i]) {
            S.erase(G1.get_dfn(x));
          }
          for (int x : cp[i]) {
            std::vector<int> tmp;
            for (int y : adj[x]) {
              if (S.erase(G1.get_dfn(y))) {
                tmp.push_back(y);
              }
            }
            int p = G1.get_dfn(x);
            auto it = S.lower_bound(p);
            if (it != S.end()) {
              int y = G1.get_id(*it);
              min = std::min(min, edge(x, y, G1.query(x, y)));
            }
            if (it != S.begin()) {
              --it;
              int y = G1.get_id(*it);
              min = std::min(min, edge(x, y, G1.query(x, y)));
            }
            for (int y : tmp) {
              S.insert(G1.get_dfn(y));
            }
          }
          if (min.w != INF && C.merge(min.u, min.v)) {
            E2.push_back(min);
            ok = true;
          }
          for (int x : cp[i]) {
            S.insert(G1.get_dfn(x));
          }
        }
      }
      if (!ok) {
        break;
      }
    }
    graph G2(n, E2);
    for (auto e : E1) {
      std::cout << G2.query(e.u, e.v) << " ";
    }
    std::cout << "\n";
  }
}