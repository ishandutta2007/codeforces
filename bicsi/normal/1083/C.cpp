#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

template <class T>
struct RMQ {
    const T kInf = numeric_limits<T>::max();
    vector<vector<T>> rmq;

    void Build(const vector<T>& V) {
        int n = V.size(), on = 1, depth = 1;
        while (on < n) on *= 2, ++depth;
        rmq.assign(depth, V);

        for (int i = 0; i < depth - 1; ++i)
            for (int j = 0; j < n; ++j) {
                rmq[i + 1][j] = min(rmq[i][j],
                        rmq[i][min(n - 1, j + (1 << i))]);
            }
    }

    T Query(int a, int b) {
        if (b <= a) return kInf;
        int dep = 31 - __builtin_clz(b - a); // log(b - a)
        return min(rmq[dep][a], rmq[dep][b - (1 << dep)]);
    }
};

struct LCA {
    vector<int> enter, depth;
    vector<vector<int>> G;
    vector<pair<int, int>> linear;
    RMQ<pair<int, int>> rmq;
    int timer = 0;

    LCA(int n) : enter(n, -1), depth(n), G(n), linear(2 * n) {}

    void dfs(int node, int dep) {
        linear[timer] = {dep, node};
        enter[node] = timer++;
        depth[node] = dep;

        for (auto vec : G[node])
            if (enter[vec] == -1) {
                dfs(vec, dep + 1);
                linear[timer++] = {dep, node};
            }
    }

    void AddEdge(int a, int b) {
        G[a].push_back(b);
        G[b].push_back(a);
    }

    void Build(int root) {
        dfs(root, 0);
        rmq.Build(linear);
    }

    int Query(int a, int b) {
        a = enter[a], b = enter[b];
        return rmq.Query(min(a, b), max(a, b) + 1).second;
    }

    int Distance(int a, int b) {
        return depth[a] + depth[b] - 2 * depth[Query(a, b)];
    }
};

struct SegTree {
  struct Node {
    int s, e; 
  };
  int n; 
  vector<Node> data;
  vector<int> v;
  LCA lca;


  SegTree(vector<int> v, LCA lca) : n(v.size()), data(4 * n), v(v), lca(lca) {
    build(1, 0, n - 1);
  }

  Node combine(Node a, Node b) {
    vector<int> nodes = {a.s, a.e, b.s, b.e};
    if (find(nodes.begin(), nodes.end(), -1) != nodes.end()) {
      return {-1, -1};
    }

    tuple<int, int, int> choose;
    for (auto x : nodes)
    for (auto y : nodes) {
      choose = max(choose, make_tuple(lca.Distance(x, y), x, y));
    }

    int x, y; tie(ignore, x, y) = choose;
    for (auto z : nodes) {
      if (lca.Distance(x, z) + lca.Distance(z, y) != lca.Distance(x, y)) {
        return {-1, -1};
      }
    }

    return {x, y};
  }

  void build(int node, int b, int e) {
    if (b == e) {
      data[node] = {v[b], v[b]};
    } else {
      int m = (b + e) / 2;
      build(node * 2, b, m);
      build(node * 2 + 1, m + 1, e);
      data[node] = combine(data[node * 2], data[node * 2 + 1]);
    }
  }

  void update(int node, int b, int e, int l, int r) {
    if (e < l) return;
    if (b > r) return;
    if (b > l && e < r) return;

    if (b == e) {
      data[node] = {v[b], v[b]};
    } else {
      int m = (b + e) / 2;
      update(node * 2, b, m, l, r);
      update(node * 2 + 1, m + 1, e, l, r);
      data[node] = combine(data[node * 2], data[node * 2 + 1]);
    }
  }
  void Update(int a, int b) {
    swap(v[a], v[b]);
    if (a > b) swap(a, b);
    update(1, 0, n - 1, a, b);
  }

  pair<int, Node> query(int node, int b, int e, pair<int, Node> acc) {
    auto chk = combine(acc.second, data[node]);
    if (chk.s != -1) {
//        cerr << "QUERY: " << b << " " << e << " -> " << 
//            acc.first + e - b + 1 << endl;
        return {acc.first + (e - b + 1), chk};
    }

    if (b == e) {
      return acc;
    }

    int m = (b + e) / 2;
    pair<int, Node> ret = query(node * 2, b, m, acc);
    if (ret.first != acc.first + (m - b + 1)) {
//      cerr << "QUERY: " << b << " " << e << " -> " << ret.first << endl;
        return ret;
    }
    

    ret = query(node * 2 + 1, m + 1, e, ret);
//    cerr << "QEURY: " << b << " " << e << " -> " << ret.first << endl;
    return ret;
  }
  int Query() { 
    return query(1, 0, n - 1, make_pair(0, Node{v[0], v[0]})).first;
  }

  void dump(int node, int b, int e) {
    cout << node << "[" << b << " " << e << "] ->";
    cout << data[node].s + 1 << " " << data[node].e + 1 << endl;
    if (b == e) return;
    int m = (b + e) / 2;
    dump(node * 2, b, m);
    dump(node * 2 + 1, m + 1, e);
  }
  void Dump() {
//      cout << "V: ";
//      for (int i = 0; i < n; ++i) cout << v[i] << " "; cout << endl;
//      dump(1, 0, n - 1);
  }


};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    LCA lca(n);

    vector<int> node_of(n), perm(n);
    for (int i = 0; i < n; ++i) {
        int now; cin >> now;
        perm[i] = now;
        node_of[now] = i;
    }

//    for (auto x : node_of) cerr << x + 1 << " "; cerr << endl;

    for (int i = 1; i < n; ++i) {
        int par; cin >> par; --par;
        lca.AddEdge(par, i);
    }
    lca.Build(0);

    SegTree st(node_of, lca);
    int m; cin >> m;
    while (m--) {
      st.Dump();
      int t; cin >> t;
      if (t == 2) {
        cout << st.Query() << '\n';
      } else {
        int a, b; cin >> a >> b; a--; b--;
        swap(perm[a], perm[b]);
        st.Update(perm[a], perm[b]);
      }
    }




    return 0;
}