#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll MOD = 998244353;

struct Node {
  ll a = 1, b = 0; // lazy
  ll sum = 0;  // sum of children...
  void apply(const Node& o, ll tsz) {
    a = a*o.a%MOD;
    b = (o.a*b + o.b)%MOD;
    sum = (sum*o.a + o.b*tsz)%MOD;
  }
  void pull(const Node& l, const Node& r, ll tsz) {
    sum = ((l.sum + r.sum)*a + b*tsz)%MOD;
  }
  void clear_lazy() {
    a = 1, b = 0;
  }
  bool has_lazy() {
    return (a != 1 || b != 0);
  }
};

struct Segtree {
  vector<Node> node;
  int n, h;
  Segtree (int sz) {
    h = 32 - __builtin_clz(sz);
    n = 1<<h;
    node = vector<Node>(n<<1);
  }
  ll seg_size(int x) {
    return 1LL<<(h - 31 + __builtin_clz(x));
  }
  void push(int x) {
    if (node[x].has_lazy()) {
      node[x<<1].apply(node[x], seg_size(x<<1));
      node[x<<1|1].apply(node[x], seg_size(x<<1|1));
      node[x].clear_lazy();
    }
  }
  void pull(int x) {
    node[x].pull(node[x<<1], node[x<<1|1], seg_size(x));
  }
  void update(int l, int r, const Node& v, int x, int lv, int rv) {
    if (rv <= l || r <= lv) {
      return;
    }
    if (l <= lv && rv <= r) {
      node[x].apply(v, seg_size(x));
      return;
    }
    push(x);
    int mv = (lv+rv)/2;
    update(l, r, v, x*2, lv, mv);
    update(l, r, v, x*2+1, mv, rv);
    pull(x);
  }
  void update(int l, int r, const Node& v) {
    update(l, r, v, 1, 0, n);
  }
  ll query(int l, int r, int x, int lv, int rv) {
    if (rv <= l || r <= lv) {
      return 0;
    }
    if (l <= lv && rv <= r) {
      return node[x].sum;
    }
    push(x);
    int mv = (lv+rv)/2;
    ll ans = query(l, r, x*2, lv, mv);
      ans += query(l, r, x*2+1, mv, rv);
    return ans;
  }
  ll query(int l, int r) {
    return query(l, r, 1, 0, n)%MOD;
  }
};

const int N=200200;
set<pair<int, int>> of[N];
Segtree st(1);

void perform(set<pair<int, int>>& ranges, int l, int r) {
  auto it = ranges.lower_bound({l, -10});
  if (it != ranges.begin() && prev(it)->second >= l) {
    --it;
  }
  if (it != ranges.end() && it->first < l) {
    auto seg = *it;
    ranges.erase(it);
    ranges.insert({seg.first, l-1});
    ranges.insert({l, seg.second});
    it = ranges.find({l, seg.second});
  }
  auto jt = it;
  while (jt != ranges.end() && next(jt) != ranges.end() && next(jt)->first <= r) {
    ++jt;
  }
  if (jt->first <= r && jt != ranges.end() && jt->second > r) {
    bool eq = (jt == it);
    auto seg = *jt;
    ranges.erase(jt);
    ranges.insert({seg.first, r});
    ranges.insert({r+1, seg.second});
    jt = ranges.find({seg.first, r});
    if (eq) {
      it = jt;
    }
  }
  if (jt != ranges.end() && jt->first <= r) {
    ++jt;
  }
  int rct = l;
  while (it != jt) {
    Node upd = {1, 1, 0};
    st.update(rct, it->first, upd);
    upd = {2, 0, 0};
    st.update(it->first, it->second+1, upd);
    rct = it->second+1;
    ranges.erase(prev(++it));
  }
  Node upd = {1, 1, 0};
  st.update(rct, r+1, upd);
  ranges.insert({l, r});
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, q;
  cin >> n >> q;
  st = Segtree(n+10);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      //cerr << "   :: " << of[x].size() << endl;
      perform(of[x], l, r);
      //cerr << "    :: " << of[x].size() << endl;
    } else if (type == 2) {
      int l, r;
      cin >> l >> r;
      cout << st.query(l, r+1) << "\n";
    }
  }

  return 0;
}