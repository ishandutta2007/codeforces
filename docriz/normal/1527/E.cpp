#include <bits/stdc++.h>

using namespace std;

const int MAXN = 35005;

struct Node {
  int v;
  int t;
  Node *ls, *rs;
  void clear() {
    v = t = 0;
    ls = rs = nullptr;
  }
  void pushUp() {
    v = min(ls->v, rs->v);
  }
  void update(int ft) {
    v += ft;
    t += ft;
  }
  void pushDown() {
    if (t) {
      ls->update(t);
      rs->update(t);
      t = 0;
    }
  }
}pool[MAXN<<2];

int node_cnt = 0;

void clear() {
  node_cnt = 0;
}

Node *newNode() {
  pool[node_cnt].clear();
  return &pool[node_cnt++];
}

void add(Node *cur, int l, int r, int a, int b, int v) {
  if (a <= l && b >= r) {
    cur->update(v);
  } else {
    cur->pushDown();
    int mid = (l + r) / 2;
    if (a <= mid) {
      add(cur->ls, l, mid, a, b, v);
    }
    if (b > mid) {
      add(cur->rs, mid + 1, r, a, b, v);
    }
    cur->pushUp();
  }
}

int query(Node *cur, int l, int r, int a, int b) {
  if (a <= l && b >= r) {
    return cur->v;
  }
  cur->pushDown();
  int mid = (l + r) / 2;
  int ret = INT_MAX / 2;
  if (a <= mid) {
    ret = min(ret, query(cur->ls, l, mid, a, b));
  }
  if (b > mid) {
    ret = min(ret, query(cur->rs, mid + 1, r, a, b));
  }
  return ret;
}

Node *build(int l, int r) {
  Node *cur = newNode();
  if (l < r) {
    int mid = (l + r) / 2;
    cur->ls = build(l, mid);
    cur->rs = build(mid + 1, r);
    cur->pushUp();
  } else {
    cur->v = cur->t = 0;
  }
  return cur;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> f(n + 1);
  vector<int> last(n + 1, -1);
  vector<int> pre(n + 1);
  for (int i = 1; i <= n; i++) {
    if (last[a[i]] == -1) {
      f[i] = f[i - 1];
    } else {
      pre[i] = last[a[i]];
      f[i] = f[i - 1] + i - last[a[i]];
    }
    last[a[i]] = i;
  }
  for (int t = 2; t <= k; t++) {
    auto g = f;
    clear();
    Node* root = build(0, n);
    for (int i = 0; i <= n; i++) {
      add(root, 0, n, i, i, g[i]);
    }
    for (int i = 0; i <= n; i++) {
      f[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      if (pre[i]) {
        add(root, 0, n, 0, pre[i] - 1, i - pre[i]);
      }
      f[i] = query(root, 0, n, 0, i - 1);
      // cerr << f[i] << " ";
    }
    // cerr << endl;
  }
  cout << f[n] << "\n";
  return 0;
}