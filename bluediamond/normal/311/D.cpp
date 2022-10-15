#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
const int M = 95542721;
int n;
int q;
int a[N];

int tnext(int x) {
  int y = (ll) x * x % M;
  return (ll) x * y % M;
}

struct Node {
  int v[48];
};

Node shift(Node a, int k) {
  k %= 48;
  Node b;
  for (int i = 0; i < 48; i++) {
    b.v[i] = a.v[k];
    k++;
    if (k == 48) {
      k = 0;
    }
  }
  return b;
}

Node operator + (Node a, Node b) {
  for (int i = 0; i < 48; i++) {
    a.v[i] += b.v[i];
    if (a.v[i] >= M) {
      a.v[i] -= M;
    }
  }
  return a;
}

Node t[4 * N];
int add[4 * N];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v].v[0] = a[tl];
    for (int i = 1; i < 48; i++) {
      t[v].v[i] = tnext(t[v].v[i - 1]);
    }
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = t[2 * v] + t[2 * v + 1];
  }
}

void push(int v, int tl, int tr) {
  if (add[v]) {
    t[v] = shift(t[v], add[v]);
    if (tl < tr) {
      add[2 * v] += add[v];
      add[2 * v + 1] += add[v];
    }
    add[v] = 0;
  }
}

void shift(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tr < l || r < tl) {
    return;
  }
  if (l <= tl && tr <= r) {
    add[v] = 1;
    push(v, tl, tr);
  } else {
    int tm = (tl + tr) / 2;
    shift(2 * v, tl, tm, l, r);
    shift(2 * v + 1, tm + 1, tr, l, r);
    t[v] = t[2 * v] + t[2 * v + 1];
  }
}

int get(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tr < l || r < tl) {
    return 0;
  }
  if (l <= tl && tr <= r) {
    return t[v].v[0];
  } else {
    int tm = (tl + tr) / 2;
    int x = get(2 * v, tl, tm, l, r);
    x += get(2 * v + 1, tm + 1, tr, l, r);
    if (x >= M) {
      x -= M;
    }
    return x;
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] %= M;
  }
  build(1, 1, n);
  cin >> q;
  while (q--) {
    int type, l, r;
    cin >> type >> l >> r;
    if (type == 1) {
      cout << get(1, 1, n, l, r) << "\n";
    } else {
      shift(1, 1, n, l, r);
    }
  }
}