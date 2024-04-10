#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll

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

const int N = (int) 1e5 + 7;
int n, q, a[N];
int sum[4 * N][10];
int to[4 * N][10];

void join(int v) {
  for (int d = 0; d < 10; d++) {
    sum[v][d] = sum[2 * v][d] + sum[2 * v + 1][d];
  }
}

void build(int v, int tl, int tr) {
  for (int j = 0; j < 10; j++) {
    to[v][j] = j;
  }
  if (tl == tr) {
    vector<int> digits;
    int num = a[tl];
    while (num) {
      digits.push_back(num % 10);
      num /= 10;
    }
    int coef = 1;
    for (auto &d : digits) {
      sum[v][d] += coef;
      coef *= 10;
    }
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    join(v);
  }
}

int ff[10];
int ss[10];
int sm[10];

void push(int v, int tl, int tr) {
  if (tl < tr) {
    for (int j = 0; j < 10; j++) {
      ff[j] = to[v][to[2 * v][j]];
      ss[j] = to[v][to[2 * v + 1][j]];
    }
    for (int j = 0; j < 10; j++) {
      to[2 * v][j] = ff[j];
      to[2 * v + 1][j] = ss[j];
    }
  }
  for (int j = 0; j < 10; j++) {
    sm[to[v][j]] += sum[v][j];
  }
  for (int j = 0; j < 10; j++) {
    to[v][j] = j;
    sum[v][j] = sm[j];
    sm[j] = 0;
  }
}

void op(int v, int tl, int tr, int l, int r, int x, int y) {
  push(v, tl, tr);
  if (tr < l || r < tl) return;
  if (l <= tl && tr <= r) {
    to[v][x] = y;
    push(v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  op(2 * v, tl, tm, l, r, x, y);
  op(2 * v + 1, tm + 1, tr, l, r, x, y);
  join(v);
}

int get(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tr < l || r < tl) return 0;
  if (l <= tl && tr <= r) {
    int ret = 0;
    for (int d = 0; d < 10; d++) {
      ret += sum[v][d] * d;
    }
    return ret;
  }
  int tm = (tl + tr) / 2;
  return get(2 * v, tl, tm, l, r) + get(2 * v + 1, tm + 1, tr, l, r);
}

void op(int l, int r, int x, int y) {
  if (x == y) return;
  op(1, 1, n, l, r, x, y);
}

int get(int l, int r) {
  return get(1, 1, n, l, r);
}

signed realMain() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r, x, y;
      cin >> l >> r >> x >> y;
      op(l, r, x, y);
    } else {
      int l, r;
      cin >> l >> r;
      cout << get(l, r) << "\n";
    }
  }
  return 0;
}