#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

struct Node {
  int val, l, r;
};

struct PSegtree {
  Node t[300300*20];
  int n,h;
  bool ready = 0;
  int zz;
  int current;
  PSegtree() {
  }
  void init(int sz) {
    ready = 1;
    h = 32 - __builtin_clz(sz);
    n = 1<<h;
    t[0] = {(int) 2e9, -1, -1};
    zz = 1;
    current = 0;
  }
  void add_children(int x) {
    if (t[x].l != -1) {
      return;
    }
    t[zz] = {(int) 2e9, -1, -1};
    t[x].l = zz++;
    t[zz] = {(int) 2e9, -1, -1};
    t[x].r = zz++;
  }
  int assign(int i, int v, int x, int lv, int rv) {
    if (i < lv || rv <= i) {
      return x;
    }
    if (lv+1 == rv) {
      int q = zz++;
      t[q] = {min(t[x].val, v), -1, -1};
      return q;
    }
    add_children(x);
    int mv = (lv+rv)/2;
    int lx = assign(i, v, t[x].l, lv, mv);
    int rx = assign(i, v, t[x].r, mv, rv);
    int q = zz++;
    t[q] = {max(t[lx].val, t[rx].val), lx, rx};
    return q;
  }

  int assign(int i, int v) {
    return current = assign(i, v, current, 0, n);
  }
  int query(int l, int r, int x, int lv, int rv) {
    if (x == -1) {
      return 0;
    }
    if (r <= lv || rv <= l) {
      return 0;
    }
    if (l <= lv && rv <= r) {
      return t[x].val;
    }
    int mv = (lv+rv)/2;
    int ans = 0;
    ans = max(ans, query(l, r, t[x].l, lv, mv));
    ans = max(ans, query(l, r, t[x].r, mv, rv));
    return ans;
  }
  int query(int l, int r, int x) {
    return query(l, r, x, 0, n);
  }
};

int n, m, k;
int cv[100100];
PSegtree st;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> k;
  st.init(n+1);
  vector<tuple<int, int, int>> vec;
  for (int i=1; i<=k; ++i) {
    int l, r, p;
    cin >> l >> r >> p;
    vec.push_back({l, r, p});
  }
  for (int i=1; i<=n; ++i) {
    cv[i] = 2e9;
  }
  map<int, int> mp;
  sort(vec.rbegin(), vec.rend());
  for (auto& [l, r, p] : vec) {
    if (cv[p] > r) {
      cv[p] = r;
      st.assign(p, r);
    }
    mp[l] = st.current;
  }
  while (m--) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    auto res = 2e9;
    auto it = mp.lower_bound(x);
    if (it != mp.end()) {
      res = st.query(a, b+1, it->second);
    }
    cout << (res <= y ? "yes" : "no") << endl;
  }
  return 0;
}