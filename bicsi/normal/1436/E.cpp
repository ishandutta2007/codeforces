#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

struct SegTree {
  int n;
  vector<int> T;

  SegTree(int n) : n(n), T(2 * n) { 
    init(1, 0, n); 
  }
  
  void init(int x, int b, int e) {
    if (b + 1 == e) {
      T[x] = b;
    } else {
      int m = (b + e) / 2;
      init(x + 1, b, m);
      init(x + 2 * (m - b), m, e);
    }
  }

  void update(int x, int b, int e, int l, int r, int v) {
    l = max(l, b); r = min(r, e);
    if (l >= r) return;
    if (b == l && e == r) {
      T[x] = max(T[x], v);
      return;
    }
    int m = (b + e) / 2;
    int z = x + (m - b) * 2;
    update(x + 1, b, m, l, r, v);
    update(z, m, e, l, r, v);
  }

  int query(int x, int b, int e, int pos) {
    if (b + 1 == e) {
      assert(b == pos);
      return T[x];
    } else {
      int m = (b + e) / 2;
      if (pos >= m)
        return max(T[x], query(x + 2 * (m - b), m, e, pos));
      return max(T[x], query(x + 1, b, m, pos));
    }
  }

  void Update(int l, int r, int x) {
    // cerr << "Update: " << l << " " << r << " " << x << endl;
    update(1, 0, n, l, r, x);
  }

  int Query(int pos) {
    int ret = query(1, 0, n, pos);
    // cerr << "Query: " << pos << " -> " << ret << endl;
    return ret;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i]; --v[i];
  }

  vector<bool> found(n + 2, false);
  for (int it = 0; it < 2; ++it) {
    vector<vector<int>> pos(n + 1);
    for (int i = 0; i <= n; ++i)
      pos[i].push_back(-1);
    for (int i = 0; i < n; ++i)
      pos[v[i]].push_back(i);
    
    SegTree st(n + 1);
    for (int val = 0; val <= n; ++val) {
      // any subsequences not containing val?
      for (int i = 0; i < (int)pos[val].size(); ++i) {
        int lim = (i + 1 < (int)pos[val].size() ? pos[val][i + 1] : n);
        if (!found[val] && st.Query(pos[val][i] + 1) < lim) {
          // cerr << "found: " << val + 1 << "(limit was " << lim << ")" << endl;
          found[val] = true;
        }
      }
      for (int i = 0; i < (int)pos[val].size(); ++i) {
        int lim = (i + 1 < (int)pos[val].size() ? pos[val][i + 1] : n);
        st.Update(pos[val][i] + 1, lim, lim);
      }
    }
    reverse(v.begin(), v.end());
  }
  
  // for (int i = 0; i <= n; ++i)
    // cerr << found[i];
  // cerr << endl;

  int ans = 0;
  while (found[ans]) ++ans;
  cout << ans + 1 << endl; 

  return 0;
}