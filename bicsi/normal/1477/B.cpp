#ifdef LOCAL
#include <debug.hpp>
#else
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#define debug(...)
#endif 

#include <bits/stdc++.h>

using namespace std;

struct SegTree {
  int n;
  vector<int> sum, lazy;
  SegTree(int n) : n(n), sum(4 * n, 0), lazy(4 * n, -1) {}

  void push(int node, int b, int e) {
    int l = lazy[node];
    if (l == -1) return;
    if (l == 1) sum[node] = (e - b + 1);
    else sum[node] = 0;
    if (b != e) 
      lazy[node * 2] = lazy[node * 2 + 1] = l;
    lazy[node] = -1;
  }
  void update(int node, int b, int e, int l, int r, int val) {
    push(node, b, e);
    l = max(l, b); r = min(r, e);
    if (l > r) return;
    if (b == l && e == r) {
      lazy[node] = val;
      push(node, b, e);
      return;
    }

    int m = (b + e) / 2;
    update(node * 2, b, m, l, r, val);
    update(node * 2 + 1, m + 1, e, l, r, val);
    sum[node] = sum[node * 2] + sum[node * 2 + 1];
  };

  int query(int node, int b, int e, int l, int r) {
    push(node, b, e);
    l = max(l, b); r = min(e, r);
    if (l > r) return 0;
    if (b == l && e == r) return sum[node];
    int m = (b + e) / 2;
    return query(node * 2, b, m, l, r) + query(node * 2 + 1, m + 1, e, l, r);
  }

  void Update(int l, int r, int x) { 
    //cerr << "Update: " << l << " " << r << " " << x << endl;
    update(1, 0, n - 1, l, r, x); 
  }
  int Query(int l, int r) { 
    //cerr << "Query: " << l << " " << r << endl;
    return query(1, 0, n - 1, l, r); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--) {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    string t; cin >> t;
    SegTree st(n);
    for (int i = 0; i < n; ++i)
      st.Update(i, i, t[i] - '0');
    
    vector<int> l(q), r(q);
    for (int i = 0; i < q; ++i) {
      cin >> l[i] >> r[i]; --l[i]; --r[i];
    }

    bool bad = false;
    for (int i = q - 1; i >= 0; --i) {
      int sum = st.Query(l[i], r[i]);
      int len = r[i] - l[i] + 1;
      if (sum * 2 == len) { bad = true; break; }
      int tg = 1; if (sum * 2 < len) tg = 0;
      st.Update(l[i], r[i], tg);
    }

    for (int i = 0; i < n; ++i) 
      if (st.Query(i, i) != s[i] - '0')
        bad = true;
    
    if (bad) cout << "NO\n";
    else cout << "YES\n";
  }

  return 0;
}