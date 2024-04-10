#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

struct SegTree {
  struct Node {
    int dp, pref, suff, all;
  };

  int n;
  vector<Node> T;

  SegTree(string& s) : n(s.size()), T(2 * n) {
    init(1, 0, n, s);
    dump(1, 0, n);
  }

  void combine(Node& l, Node& r, Node& to) {
    to.dp = max(l.dp, r.dp);
    to.pref = (l.all ? l.dp + r.pref : l.pref);
    to.suff = (r.all ? r.dp + l.suff : r.suff);
    to.dp = max(to.dp, to.pref);
    to.dp = max(to.dp, to.suff);
    to.dp = max(to.dp, l.suff + r.pref);
    to.all = l.all && r.all; 
  }

  void init(int x, int b, int e, string& s) {
    if (b + 1 == e) {
      T[x].dp = T[x].pref = T[x].suff = T[x].all = s[b] - '0';
    } else {
      int m = (b + e) / 2;
      int z = x + (m - b) * 2;
      init(x + 1, b, m, s);
      init(z, m, e, s);
      combine(T[x + 1], T[z], T[x]);
    }
  }

  void dump(int x, int b, int e) {
    // cerr << "[" << b + 1 << ".." << e << "]: " << T[x].dp << endl;
    if (b + 1 == e) return;
    int m = (b + e) / 2;
    int z = x + (m - b) * 2;
    dump(x + 1, b, m);
    dump(z, m, e);
  }
  
  int query(int x, int b, int e, int l, int r, int val, Node& nn, int dir) {
    l = max(l, b); r = min(r, e);
    if (l >= r) return dir == -1 ? b : e;
    if (b == l && e == r) {
      // cerr << "Try: " << b + 1 << ".." << e << endl;
      Node nnn; 
      if (dir == 1) combine(nn, T[x], nnn);
      else combine(T[x], nn, nnn);
      // cerr << "     -> " << nnn.dp << endl;
      if (nnn.dp <= val) {
        // cerr << "Acc: " << b + 1 << ".." << e << endl;
        swap(nn, nnn);
        return dir == -1 ? b : e;
      }
    } 
    if (b + 1 == e) return -1;
    int m = (b + e) / 2;  
    int z = x + (m - b) * 2;
    if (dir == 1) {
      int ans = query(x + 1, b, m, l, r, val, nn, dir);
      if (ans != m) return ans;
      int ans2 = query(z, m, e, l, r, val, nn, dir);
      if (ans2 == -1) return ans;
      return ans2;
    } else {
      int ans = query(z, m, e, l, r, val, nn, dir);
      if (ans != m) return ans;
      int ans2 = query(x + 1, b, m, l, r, val, nn, dir);
      if (ans2 == -1) return ans;
      return ans2;
    }
  }

  int Query(int l, int r, int val, int dir) {
    Node nn{0, 0, 0, 0};
    int ret = query(1, 0, n, l, r, val, nn, dir);
    assert(nn.dp <= val);
    // cerr << "CERR: " << nn.dp << endl;
    return ret;
  } 
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n; cin >> n;
  string s; cin >> s;
  SegTree st(s);
  /*
  while (true) {
    int l, r, val, dir; cin >> l >> r >> val >> dir;
    cout << st.Query(l - 1, r, val, dir) + 1 << endl;
  }
  */
  vector<pair<int, int>> ranges;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') continue;
    if (i > 0 && s[i - 1] == '1')
      ranges.back().second = i + 1;
    else
      ranges.emplace_back(i, i + 1);
  }
  
  if (ranges.empty()) {
    cout << 0 << '\n';
    return 0;
  }


  long long total = 0;
  for (auto [b, e] : ranges) {
    // cerr << "range: " << b + 1 << " " << e << endl;
    for (int len = 1; len <= e - b - 2; ++len) {
      int cnt = e - b - len - 1;
      total += 1LL * len * cnt;
      // cerr << "  segment " << len << ": " << e - b - len - 1 << "(len: " << len << ")" << endl;
    }
    for (int i = b + 1; i < e; ++i) {
      int len = e - i;
      if (len == 0) continue;
      int until = st.Query(e, n, len, +1);
      assert(until >= e);
      total += 1LL * (until - e + 1) * len; 
      // cerr << "  suffix " << i + 1 << " " << e << ": " << until - e + 1 << "(len: " << len << ")" << endl;   
    }
    for (int i = b + 1; i < e; ++i) {
      int len = i - b;
      if (len == 0) continue;
      int until = st.Query(0, b, len - 1, -1);
      assert(until <= b);
      total += 1LL * (b - until + 1) * len; 
      // cerr << "  prefix " << b + 1 << " " << i << ": " << b - until + 1 << "(len: " << len << ")" << endl;  
    }
    {
      int len = e - b;
      int untilb = st.Query(0, b, len - 1, -1);
      int untile = st.Query(e, n, len,     +1);
      assert(untilb <= b);
      assert(untile >= e);
      // cerr << "    " << untilb + 1 << "..." << untile << endl;
      total += 1LL * len * (b - untilb + 1) * (untile - e + 1);
      // cerr << "  full " << b + 1 << " " << e << ": " << (b - untilb + 1) * (untile - e + 1) << "(len: " << len << ")" << endl;
    }
  }

  cout << total << endl;


  return 0;
}