#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 500000 + 7;
int n;
int q;
int x[N];
int y[N];
int t[N];

struct solver {
  vector<vector<int>> g;
  vector<bool> vis;
  vector<int> l;
  vector<int> r;
  vector<int> dep;
  vector<int> who;
  vector<vector<int>> tree;
  vector<int> inv;
  vector<int> node;
  int top;
  void dfs(int a) {
    l[a] = ++top;
    node[top] = a;
    vis[a] = 1;
    vector<int> use;
    for (auto &i : g[a]) {
      int b = x[i] + y[i] - a;
      if (vis[b] == 0) {
        use.push_back(i);
        who[i] = b;
        dep[b] = 1 + dep[a];
        dfs(b);
      }
    }
    g[a] = use;
    r[a] = top;
  }
  void join(int v, int tl, int tr) {
    tree[v][0] = max(tree[2 * v][0], tree[2 * v + 1][0]);
    tree[v][1] = max(tree[2 * v][1], tree[2 * v + 1][1]);
  }
  void push(int v, int tl, int tr) {
    if (inv[v]) {
      swap(tree[v][0], tree[v][1]);
      if (tl < tr) {
        inv[2 * v] ^= 1;
        inv[2 * v + 1] ^= 1;
      }
      inv[v] = 0;
    }
  }
  void init(int v, int tl, int tr) {
    inv[v] = 0;
    if (tl == tr) {
      tree[v][0] = dep[node[tl]];
      tree[v][1] = -(int) 1e9;
    } else {
      int tm = (tl + tr) / 2;
      init(2 * v, tl, tm);
      init(2 * v + 1, tm + 1, tr);
      join(v, tl, tr);
    }
  }
  void invert(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if (tr < l || r < tl) {
      return;
    }
    if (l <= tl && tr <= r) {
      inv[v] ^= 1;
      push(v, tl, tr);
      return;
    }
    int tm = (tl + tr) / 2;
    invert(2 * v, tl, tm, l, r);
    invert(2 * v + 1, tm + 1, tr, l, r);
    join(v, tl, tr);
  }
  void init(int root) {
    g.resize(n + 1);
    vis.resize(n + 1, 0);
    l.resize(n + 1, 0);
    r.resize(n + 1, 0);
    dep.resize(n + 1, 0);
    who.resize(n + 1, 0);
    tree.resize(4 * n + 7, vector<int> (2, 0));
    inv.resize(4 * n + 7, 0);
    node.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      g[x[i]].push_back(i);
      g[y[i]].push_back(i);
    }
    dep[root] = 0;
    top = 0;
    dfs(root);
    init(1, 1, n);
  }
  void change(int i) {
    i = who[i];
    invert(1, 1, n, l[i], r[i]);
  }
  int get() {
    push(1, 1, n);
    return tree[1][0];
  }
};



vector<int> g[N];
int dist[N];

int fmax(int a) {
  for (int i = 1; i <= n; i++) {
    dist[i] = -1;
  }
  dist[a] = 0;
  queue<int> q;
  q.push(a);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (auto &y : g[x]) {
      if (dist[y] == -1) {
        dist[y] = 1 + dist[x];
        q.push(y);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (dist[i] > dist[a]) {
      a = i;
    }
  }
  return a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> x[i] >> y[i] >> t[i];
    g[x[i]].push_back(y[i]);
    g[y[i]].push_back(x[i]);
  }
  solver f, s;
  f.init(fmax(1));
  s.init(fmax(fmax(1)));
  for (int i = 1; i < n; i++) {
    if (t[i]) {
      f.change(i);
      s.change(i);
    }
  }
  cin >> q;
  while (q--) {
    int i;
    cin >> i;
    t[i] ^= 1;
    f.change(i);
    s.change(i);
    cout << max(f.get(), s.get()) << "\n";
  }
}