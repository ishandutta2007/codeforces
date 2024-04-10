#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

struct DSU {
  vector<int> link, sz, dp;
  DSU(int n) : link(n, -1), sz(n, 1), dp(n, 0) {}

  pair<int, int> Find(int x) {
    int label = dp[x];
    while (link[x] != -1) {
      x = link[x];
      label += dp[x];
    }
    return {x, label};
  }

  void Union(int a, int b) {
    a = Find(a).first;
    b = Find(b).first;
    if (a == b) return;
    if (sz[a] < sz[b]) 
      swap(a, b);
    dp[b] += sz[a];
    sz[a] += sz[b];
    link[b] = a;
  }
};

struct DSU2 {
  int n;
  vector<int> link, minn, maxx;
  DSU2(vector<int> label) : 
    n(label.size()), link(n, -1), 
    minn(label), maxx(label) {}

  pair<int, int> Get(int x) {
    x = find(x);
    return {minn[x], maxx[x]};
  }

  void Union(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    minn[a] = min(minn[a], minn[b]);
    maxx[a] = max(maxx[a], maxx[b]);
    link[b] = a;
  }

  int find(int x) {
    if (link[x] == -1) return x;
    return link[x] = find(link[x]);
  }
};

struct SegTree {
  int n;
  vector<int> T;
  SegTree(vector<int> v) : n(v.size()), T(4 * n) {
    init(1, 0, n - 1, v);
  }
  void init(int node, int b, int e, vector<int>& v) {
    if (b == e) {
      T[node] = v[b];
      return;
    }
    int m = (b + e) / 2;
    init(node * 2, b, m, v);
    init(node * 2 + 1, m + 1, e, v);
    T[node] = max(T[node * 2], T[node * 2 + 1]);
  }

  int get(int node, int b, int e, int l, int r) {
    l = max(l, b); r = min(r, e);
    if (l > r) return 0;
    if (b == l && e == r) return T[node];
    int m = (b + e) / 2;
    return max(get(node * 2, b, m, l, r), get(node * 2 + 1, m + 1, e, l, r));
  }

  bool pop(int node, int b, int e, int l, int r, int x) {
    l = max(l, b); r = min(r, e);
    if (l > r || T[node] < x) return 0;
    if (b == e) {
      T[node] = 0;
      return 1;
    }
    int m = (b + e) / 2;
    int ret = pop(node * 2, b, m, l, r, x);
    if (!ret) ret = pop(node * 2 + 1, m + 1, e, l, r, x);
    T[node] = max(T[node * 2], T[node * 2 + 1]);
    return ret;
  }

  int Pop(int l, int r) {
    int ret = get(1, 0, n - 1, l, r);
    assert(pop(1, 0, n - 1, l, r, ret));
    return ret;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m, q; cin >> n >> m >> q;
  vector<int> v(n);
  for (int i = 0; i < n; ++i)
    cin >> v[i];

  vector<array<int, 2>> e(m);
  for (int i = 0; i < m; ++i) {
    cin >> e[i][0] >> e[i][1];
    --e[i][0]; --e[i][1];
  }

  vector<int> ins_time(m, q);
  vector<pair<int, int>> ops(q);
  for (int i = 0; i < q; ++i) {
    cin >> ops[i].first >> ops[i].second;
    --ops[i].second;
    if (ops[i].first == 2) 
      ins_time[ops[i].second] = i;
  }

  vector<vector<int>> ins_at_time(q + 1);
  for (int i = 0; i < m; ++i)
    ins_at_time[ins_time[i]].push_back(i);

  DSU dsu(n);
  for (int i = q; i >= 0; --i) {
    for (auto ei : ins_at_time[i]) {
      dsu.Union(e[ei][0], e[ei][1]);
    }
  }
  for (int i = 1; i < n; ++i)
    dsu.Union(0, i);

  vector<int> label(n);
  for (int i = 0; i < n; ++i) 
    label[i] = dsu.Find(i).second;

  DSU2 dsu2(label);
  vector<pair<int, int>> ranges(q);
  for (int i = q; i >= 0; --i) {
    if (i < q && ops[i].first == 1) {
      ranges[i] = dsu2.Get(ops[i].second);
    }
    for (auto ei : ins_at_time[i]) {
      dsu2.Union(e[ei][0], e[ei][1]);
    }
  }

  //cerr << "DONE DSU2" << endl;
  
  vector<int> w(n);
  for (int i = 0; i < n; ++i)
    w[label[i]] = v[i];
  /*
  for (int i = 0; i < n; ++i) {
    cerr << i + 1 << " -> " << label[i] + 1 << endl;
  }
  */
  SegTree st(w);
  for (int i = 0; i < q; ++i) {
    if (ops[i].first == 1) {
      //cerr << "range: " << ranges[i].first << " " << ranges[i].second << endl;
      cout << st.Pop(ranges[i].first, ranges[i].second) << '\n';
    }
  }

  return 0;
}