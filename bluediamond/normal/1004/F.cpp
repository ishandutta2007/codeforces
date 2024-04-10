#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;

int realMain();


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 1e5 + 7; /// change later to (int) 1e5
const int INF = (int) 1e9;
int n, m, x, ce[N];

struct node {
  int l;
  int r;
  ll ret;
  vector<pair<int, int>> suf, pre;
  node() {
    l = r = 0;
    suf.clear();
    pre.clear();
    ret = 0;
  }
  void baga() {
    l = r = 0;
    suf.clear();
    pre.clear();
    ret = 0;
  }
};

node d;
node operator + (node a, node b) {
  if (a.l == -1) return b;
  if (b.l == -1) return a;
  a.ret += b.ret;

  int pos = (int) b.pre.size() - 1;
  for (int j = 0; j < (int) a.suf.size(); j++) {
    if (a.suf[j].second >= x) {
      a.ret += (ll) (a.suf[j].first - a.l + 1) * (b.r - b.l + 1);
      break;
    }
    if (pos == -1) continue;
    int times = (j + 1 < (int) a.suf.size()) ? (a.suf[j].first - a.suf[j + 1].first) : (a.suf[j].first - a.l + 1);
    while (pos - 1 >= 0 && (a.suf[j].second | b.pre[pos - 1].second) >= x) pos--;
    if ((a.suf[j].second | b.pre[pos].second) >= x) {
      int times_right = b.r - b.pre[pos].first + 1;
      a.ret += times * (ll) times_right;
    }
  }
  int cur = a.pre.empty() ? 0 : a.pre.back().second;
  for (auto &it : b.pre) {
    if ((cur | it.second) > cur) {
      cur |= it.second;
      it.second = cur;
      a.pre.push_back(it);
    }
  }
  cur = b.suf.empty() ? 0 : b.suf.back().second;
  for (auto &it : a.suf) {
    if ((cur | it.second) > cur) {
      cur |= it.second;
      it.second = cur;
      b.suf.push_back(it);
    }
  }
  swap(a.suf, b.suf);
  a.r = b.r;
  return a;
}

node t[4 * N];
vector<int> bits;

void baga(int num) {
  bits.clear();
  for (int j = 0; j < 20; j++) {
    if (num & (1 << j)) bits.push_back(j);
  }
}

void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v].l = t[v].r = tl;
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v].l = tl;
    t[v].r = tr;
  }
}

void upd(int v, int tl, int tr, int i, int val) {
  if (tr < i || i < tl) {
    return;
  }
  if (tl == tr) {
    t[v].baga();
    t[v].l = t[v].r = tl;
    t[v].pre.push_back({tl, val});
    t[v].suf.push_back({tl, val});
    t[v].ret = (val >= x);
    return;
  }
  int tm = (tl + tr) / 2;
  upd(2 * v, tl, tm, i, val);
  upd(2 * v + 1, tm + 1, tr, i, val);
  t[v] = t[2 * v] + t[2 * v + 1];
}

node get(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) {
    return d;
  }
  if (l <= tl && tr <= r) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  node first = get(2 * v, tl, tm, l, r);
  node last = get(2 * v + 1, tm + 1, tr, l, r);
  return first + last;
}

void print(int num) {
  if ((1 << 7) <= num) assert(0);
  for (int j = 7; j >= 0; j--) {
    if (num & (1 << j)) cout << 1;
    else cout << 0;
  }
  cout << "\n";
}

signed realMain() {
  d.l = -1;
  cin >> n >> m >> x;
  build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    int val;
    cin >> val;
    ce[i] = val;
    baga(val);
    upd(1, 1, n, i, val);
  }

  while (m--) {
    int type;
    cin >> type;
    if (type == 1) {
      int i, val;
      cin >> i >> val;
      baga(val);
      upd(1, 1, n, i, val);
    } else {
      int l, r;
      cin >> l >> r;
      node it = get(1, 1, n, l, r);
      cout << it.ret << "\n";
    }
  }
}