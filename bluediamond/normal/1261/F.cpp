#include <bits/stdc++.h>

using namespace std;

bool home = 1;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0);
    cin.tie(0);
  }
  realMain();
}

typedef long long ll;
const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

struct seg {
  ll l;
  int free;
};

vector<seg> ret_split;

void rec(ll tl, ll tr, ll l, ll r, int cfree = 60) {
  if (tr < l || r < tl) {
    return;
  }
  if (l <= tl && tr <= r) {
    ret_split.push_back({tl, cfree});
    return;
  }
  ll tm = (tl + tr) / 2;
  rec(tl, tm, l, r, cfree - 1);
  rec(tm + 1, tr, l, r, cfree - 1);
}

vector<seg> split(ll l, ll r) {
  ret_split.clear();
  rec(0, (1LL << 60) - 1, l, r);
  return ret_split;
}

seg operator + (seg a, seg b) {
  ll pre1 = a.l, pre2 = b.l;
  int len = max(a.free, b.free);
  ll pre = (pre1 ^ pre2) / (1LL << len) * (1LL << len);
  return {pre, len};
}

const int N = 100 + 7;
const int i2 = dv(1, 2);
int n, m;
ll l1[N], r1[N], l2[N], r2[N];
vector<seg> unu[65], doi[65];

struct node {
  node* l;
  node* r;
  bool tot;
  node() {
    tot = 0;
    l = r = 0;
  }
};

node* root = new node;
int type;
vector<ll> la[3][100];

void baga2(node* now, ll tl, ll tr, ll l, ll r, int kek = 60) {
  if (now->tot) {
    return;
  }
  if (l <= tl && tr <= r) {
    now->tot = 1;
    return;
  }
  ll tm = (tl + tr) / 2;
  if (l <= tm) {
    if (!now->l) {
      now->l = new node;
      la[type][kek - 1].push_back(tl);
    }
    baga2(now->l, tl, tm, l, r, kek - 1);
  }
  if (tm + 1 <= r) {
    if (!now->r) {
      now->r = new node;
      la[type][kek - 1].push_back(tm + 1);
    }
    baga2(now->r, tm + 1, tr, l, r, kek - 1);
  }
}

void baga(node* now, ll tl, ll tr, ll l, ll r) {
  if (now->tot) {
    return;
  }
  if (l <= tl && tr <= r) {
    now->tot = 1;
    return;
  }
  ll tm = (tl + tr) / 2;
  if (l <= tm) {
    if (!now->l) now->l = new node;
    baga(now->l, tl, tm, l, r);
  }
  if (tm + 1 <= r) {
    if (!now->r) now->r = new node;
    baga(now->r, tm + 1, tr, l, r);
  }
}

int gauss(ll x) {
  x %= M;
  return mul(i2, mul(x, x + 1));
}

ll gauss(ll x, ll y) {
  return add(gauss(y), -gauss(x - 1));
}


int scoate(node* now, ll tl, ll tr) {
  if (now->tot) {
    return gauss(tl, tr);
  }
  ll tm = (tl + tr) / 2;
  int ret = 0;
  if (now->l) ret = add(ret, scoate(now->l, tl, tm));
  if (now->r) ret = add(ret, scoate(now->r, tm + 1, tr));
  return ret;
}

signed realMain() {
  cin >> n;
  vector<seg> segs1, segs2;
  for (int i = 1; i <= n; i++) {
    cin >> l1[i] >> r1[i];
    auto vec = split(l1[i], r1[i]);
    for (auto &s : vec) {
      segs1.push_back(s);
    }
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> l2[i] >> r2[i];
    auto vec = split(l2[i], r2[i]);
    for (auto &s : vec) {
      segs2.push_back(s);
    }
  }
  node* root1 = new node;
  node* root2 = new node;
  type = 1;
  la[type][60].push_back(0);
  for (auto &x : segs1) {
    baga2(root1, 0, (1LL << 60) - 1, x.l, x.l + (1LL << x.free) - 1);
  }
  type = 2;
  la[type][60].push_back(0);
  for (auto &y : segs2) {
    baga2(root2, 0, (1LL << 60) - 1, y.l, y.l + (1LL << y.free) - 1);
  }
  for (auto &x : segs1) {
    for (auto &val : la[2][x.free]) {
      seg y = {val, x.free};
      auto z = x + y;
      baga(root, 0, (1LL << 60) - 1, z.l, z.l + (1LL << z.free) - 1);
    }
  }
  for (auto &x : segs2) {
    for (auto &val : la[1][x.free]) {
      seg y = {val, x.free};
      auto z = x + y;
      baga(root, 0, (1LL << 60) - 1, z.l, z.l + (1LL << z.free) - 1);
    }
  }
  cout << scoate(root, 0, (1LL << 60) - 1) << "\n";
  return 0;
}