#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;

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

const int E = (int) 2e5 + 7;
const int N = 75000 + 7;
int n, x1[N], x2[N], y1[N], a[N], b[N], y2[N];

struct node {
  int a;
  int b;
  node* l;
  node* r;
  node() {
    a = b = 0;
    l = r = 0;
  }
  node(node* alt) {
    a = alt->a;
    b = alt->b;
    l = alt->l;
    r = alt->r;
  }
};

node* root[E];

node* add(node* vertex, int tl, int tr, int i, int to_a, int to_b) {
  node* cur = new node(vertex);
  if (home) {
    if (tr < i || i < tl) {
      assert(0);
    }
  }
  if (tl == tr) {
    node* ret = new node(cur);
    ret->a += to_a;
    ret->b += to_b;
    return ret;
  }
  int tm = (tl + tr) / 2;
  if (i <= tm) {
    if (!cur->l) {
      cur->l = new node;
    }
    cur->l = add(cur->l, tl, tm, i, to_a, to_b);
  } else {
    if (!cur->r) {
      cur->r = new node;
    }
    cur->r = add(cur->r, tm + 1, tr, i, to_a, to_b);
  }
  cur->a = 0;
  cur->b = 0;
  if (cur->l) {
    cur->a += cur->l->a;
    cur->b += cur->l->b;
  }
  if (cur->r) {
    cur->a += cur->r->a;
    cur->b += cur->r->b;
  }
  return cur;
}

pair<int, int> operator + (pair<int, int> a, pair<int, int> b) {
  return {a.first + b.first, a.second + b.second};
}

pair<int, int> operator - (pair<int, int> a, pair<int, int> b) {
  return {a.first - b.first, a.second - b.second};
}

pair<int, int> sum(node* cur, int tl, int tr, int l, int r) {
  if (home) {
    if (tr < l || r < tl) {
      assert(0);
    }
  }
  if (l <= tl && tr <= r) {
    return {cur->a, cur->b};
  }
  int tm = (tl + tr) / 2;
  pair<int, int> sol = {0, 0};
  if (l <= tm && cur->l) {
    sol = sol + sum(cur->l, tl, tm, l, r);
  }
  if (r >= tm + 1 && cur->r) {
    sol = sol + sum(cur->r, tm + 1, tr, l, r);
  }
  return sol;
}

struct Event {
  int to_a, to_b, i;
};

vector<Event> events[E];

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x1[i] >> x2[i] >> y1[i] >> a[i] >> b[i] >> y2[i];
    events[0].push_back({0, y1[i], i});
    events[x1[i] + 1].push_back({a[i], -y1[i] + b[i], i});
    events[x2[i] + 1].push_back({-a[i], -b[i] + y2[i], i});
  }
  root[0] = new node;
  for (auto &it : events[0]) {
    root[0] = add(root[0], 1, n, it.i, it.to_a, it.to_b);
  }
  for (int j = 1; j < E; j++) {
    root[j] = new node(root[j - 1]);
    for (auto &it : events[j]) {
      root[j] = add(root[j], 1, n, it.i, it.to_a, it.to_b);
    }
  }
  int q, last = 0;
  cin >> q;
  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;
    x = (x + last) % (int) 1e9;
    x = min(x, (int) 2e5 + 2);
    pair<int, int> sol = sum(root[x], 1, n, 1, r);
    if (l > 1) {
      sol = sol - sum(root[x], 1, n, 1, l - 1);
    }
    last = sol.first * x + sol.second;
    cout << last << "\n";
  }
}