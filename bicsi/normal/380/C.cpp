#include <bits/stdc++.h>

using namespace std;

struct SegTree {
  struct Node {
    int open = 0, close = 0, dp = 0;
  };
  int n;
  vector<Node> T;
  SegTree(string s) : 
      n(s.size()), T(4 * n) {
    init(1, 0, n - 1, s);
  }

  Node combine(Node l, Node r) {
    Node ret;
    ret.open = l.open + r.open;
    ret.close = l.close + r.close;
    ret.dp = l.dp + r.dp;
    ret.dp += min(l.open - l.dp, r.close - r.dp);
    return ret;
  }

  void init(int node, int b, int e, string& s) {
    if (b == e) {
      char c = s[b];
      if (c == '(') T[node].open = 1;
      else T[node].close = 1;
      T[node].dp = 0;
    } else {
      int m = (b + e) / 2;
      init(node * 2, b, m, s);
      init(node * 2 + 1, m + 1, e, s);
      T[node] = combine(T[node * 2], T[node * 2 + 1]);
    }
  }

  Node query(int node, int b, int e, int l, int r) {
    l = max(l, b);
    r = min(r, e);
    if (l > r) return Node{};
    if (b == l && e == r) return T[node];
    int m = (b + e) / 2;
    return combine(query(node * 2, b, m, l, r),
        query(node * 2 + 1, m + 1, e, l, r));
  }

  int Query(int l, int r) {
    Node ans = query(1, 0, n - 1, l, r);
    return ans.dp;
  }
};

int main() {
  string s; cin >> s;
  SegTree st(s);
  int q; cin >> q;
  while (q--) {
    int l, r; cin >> l >> r;
    cout << 2 * st.Query(l - 1, r - 1) << '\n';
  }
  return 0;
}