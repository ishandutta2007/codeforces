#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

struct Solver {
  int n;
  vector<int> data, bias;

  Solver(vector<int> v) : n(v.size()), data(4 * n), bias(4 * n, 0) {
    init(1, 0, n - 1, v);
  }

  void init(int node, int b, int e, vector<int>& v) {
    if (b == e) {
      data[node] = v[b];
    } else {
      int m = (b + e) / 2;
      init(node * 2, b, m, v);
      init(node * 2 + 1, m + 1, e, v);
      data[node] = min(data[node * 2], data[node * 2 + 1]);
    }
  }

  int pop(int node, int b, int e) {
    int ret;
    if (b == e) {
      ret = data[node];
      data[node] = 1e9;
    } else {
      int m = (b + e) / 2;
      if (data[node * 2 + 1] + bias[node * 2 + 1] == data[node]) 
        ret = pop(node * 2 + 1, m + 1, e);
      else {
        ret = pop(node * 2, b, m);
        bias[node * 2 + 1] -= 1;
      }
      data[node] = min(data[node * 2] + bias[node * 2], 
        data[node * 2 + 1] + bias[node * 2 + 1]);
    }
    return ret + bias[node];
  }

  vector<int> Solve() {
    vector<int> ans;
    for (int i = 0; i < n; ++i)
      ans.push_back(pop(1, 0, n - 1));
    sort(ans.begin(), ans.end());
    return ans;
  }
};

struct SegTree {
  int n;
  vector<vector<int>> vals, look;
  vector<int> data;

  SegTree(vector<int> v) : n(v.size()), vals(4 * n), look(4 * n), data(4 * n) {
    for (int i = 0; i < n; ++i)
      v[i] = i + 1 - v[i];
    // for (int i = 0; i < n; ++i)
    //   cerr << v[i] << " ";
    // cerr << endl;
    init(1, 0, n - 1, v);
  }

  int combine(int x, int node) {
    auto it = upper_bound(look[node].begin(), look[node].end(), x);
    int delta = it - look[node].begin();
    // cerr << "look: ";
    // for (auto x : look[node]) cerr << x << " "; cerr << endl;
    // cerr << "delta: " << delta << endl;
    return x + data[node] + delta;
  }

  void init(int node, int b, int e, vector<int>& v) {
    if (b == e) {
      data[node] = (v[b] == 0);
      if (v[b] > 0) {
        vals[node].push_back(v[b]);
        look[node].push_back(v[b]);
      }
    } else {
      int m = (b + e) / 2;
      init(2 * node, b, m, v);
      init(2 * node + 1, m + 1, e, v);
      for (auto x : vals[2 * node])
        vals[node].push_back(x);
      data[node] = data[2 * node];
      for (auto x : vals[2 * node + 1]) 
        if (x > data[node]) {
          vals[node].push_back(x - data[node]);
        } else ++data[node];
      data[node] += data[2 * node + 1];
      if (vals[node].size()) {
        look[node] = Solver(vals[node]).Solve();
      }
      // cerr << node << " " << b << " " << e << endl;
      // cerr << data[node] << " " << data[node * 2] << " " << combine(data[node * 2], node * 2 + 1) << endl;
      // cerr << "!!!" << endl;
      assert(data[node] == combine(data[node * 2], node * 2 + 1));
    }
  }

  void query(int node, int b, int e, int l, int r, int& ret) {
    l = max(l, b); r = min(r, e);
    if (l > r) return;
    if (b == l && e == r) {
      // cerr << "query combine: " << b << " " << e << endl;
      ret = combine(ret, node);
      // cerr << ret << endl;
      return;
    }
    int m = (b + e) / 2;
    query(node * 2, b, m, l, r, ret);
    query(node * 2 + 1, m + 1, e, l, r, ret);
  }

  int Query(int l, int r) {
    int ret = 0;
    query(1, 0, n - 1, l, r, ret);
    return ret;
  }

  void dump(int node, int b, int e) {
    // cerr << "[" << b << " " << e << "]: " << data[node] << "(";
    // for (auto x : vals[node]) cerr << x << " ";
    //   cerr << ") [";
    // for (auto x : look[node]) cerr << x << " ";
    //   cerr << "]" << endl;
    if (b == e) return;
    int m = (b + e) / 2;
    dump(node * 2, b, m);
    dump(2 * node + 1, m + 1, e);
  }
  void Dump() {
    dump(1, 0, n - 1);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m; cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; ++i)
    cin >> v[i];
  SegTree st(v);
  // st.Dump();
  for (int i = 0; i < m; ++i) {
    int x, y; cin >> x >> y;
    int l = x, r = n - y - 1;
    // cerr << l << ".." << r << endl;
    cout << st.Query(l, r) << '\n';
  }
  return 0;
}