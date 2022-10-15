#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
///#define int ll
signed realMain();

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


const int X = (int) 1e5;
const ll INF = (ll) 1e18;

struct line {
  ll a, b;
  int i;
  ll eval(ll x) {
    if (i == -1) return INF;
    return a * x + b;
  }
};

  /// min Chao

struct node {
  node* l;
  node* r;
  line here;
  node() {
    l = 0;
    r = 0;
    here.i = -1;
  }
};

void add(node* a, int lo, int hi, line l2) {
  line l1 = a->here;
  if (l2.eval(lo) <= l1.eval(lo) && l2.eval(hi) <= l1.eval(hi)) {
    a->here = l2;
    return;
  }
  if (l2.eval(lo) >= l1.eval(lo) && l2.eval(hi) >= l1.eval(hi)) {
    return;
  }
  int mid = (lo + hi) / 2;
  if (l1.eval(lo) > l2.eval(lo)) {
    line l3 = l1;
    l1 = l2;
    l2 = l3;
    /// swap(l1, l2); /// don't know why it doesn't let me swap here, but no big deal :)
  }
  /// l1 is better than l2 at point lo
  if (l1.eval(mid) < l2.eval(mid)) { /// l1 is better than l2 at point mid
    a->here = l1;
    if (!a->r) a->r = new node;
    add(a->r, mid + 1, hi, l2);
  } else { /// l2 is better than l1 at point mid
    a->here = l2;
    if (!a->l) a->l = new node;
    add(a->l, lo, mid, l1);
  }
}



  void add(node* root, line l) {
    add(root, -X, +X, l);
  }

  line best(line a, line b, ll x) {
    if (a.i == -1) return b;
    if (b.i == -1) return a;
    if (a.eval(x) < b.eval(x)) return a;
    else return b;
  }

  line get(node* a, int lo, int hi, int x) { /// x should be ll, some small inconsistency...
    assert(lo <= x && x <= hi);
    if (lo == hi) return a->here;
    line ret = a->here;
    int mid = (lo + hi) / 2;
    if (x <= mid) {
      if (!a->l) return ret;
      return best(ret, get(a->l, lo, mid, x), x);
    } else {
      if (!a->r) return ret;
      return best(ret, get(a->r, mid + 1, hi, x), x);
    }
  }

  line get(node* root, int x) { /// again, a small inconsistency when coming to the data type of x
    return get(root, -X, +X, x);
  }

const int N = (int) 1e5 + 7;
int n, a[N], b[N], lo[N], hi[N], tp, guy[N];
vector<int> g[N];
ll dp[N];
line ln[N];
node* c[N];

void build(int x, int p = -1) {
  tp++;
  guy[tp] = x;
  lo[x] = tp;
  vector<int> kids;
  for (auto &y : g[x]) {
    if (y == p) continue;
    build(y, x);
    kids.push_back(y);
  }
  g[x] = kids;
  hi[x] = tp;
}

void dfs(int x) {
  if (g[x].empty()) {
    ln[x] = {b[x], 0, x};
    c[x] = new node;
    add(c[x], ln[x]);
    return;
  }
  int ms = 0, who = -1;
  for (auto &y : g[x]) {
    dfs(y);
    ms = max(ms, hi[y] - lo[y]);
    if (hi[y] - lo[y] == ms) who = y;
  }
  swap(c[x], c[who]);
  for (auto &y : g[x]) {
    if (y == who) continue;
    for (int j = lo[y]; j <= hi[y]; j++) {
      add(c[x], ln[guy[j]]);
    }
  }
  auto it = get(c[x], a[x]);
  dp[x] = it.eval(a[x]);
  ln[x] = {b[x], dp[x], x};
  add(c[x], ln[x]);
}

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  build(1);
  dfs(1);
  for (int i = 1; i <= n; i++) {
    cout << dp[i] << " ";
  }
  cout << "\n";
  return 0;
}