#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

const int N = (int) 2e5 + 7;
int n, m, a[N], b[N], tol[N], tor[N], stk[N], top;
map<int, vector<int>> wh;

struct T {
  int l;
  int r;
  int x;
};

bool on[4 * N];
int lazy[4 * N], sum[4 * N];

void push(int v, int tl, int tr) {
  if (on[v]) {
    sum[v] = mul(tr - tl + 1, lazy[v]);
    if (tl < tr) {
      on[2 * v] = on[2 * v + 1] = 1;
      lazy[2 * v] = lazy[2 * v + 1] = lazy[v];
    }
    on[v] = 0;
  }
}

void make(int v, int tl, int tr, int l, int r, int x) {
  push(v, tl, tr);
  if (tr < l || r < tl) {
    return;
  }
  if (l <= tl && tr <= r) {
    on[v] = 1;
    lazy[v] = x;
    push(v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  make(2 * v, tl, tm, l, r, x);
  make(2 * v + 1, tm + 1, tr, l, r, x);
  sum[v] = add(sum[2 * v], sum[2 * v + 1]);
}

int getsum(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tr < l || r < tl) {
    return 0;
  }
  if (l <= tl && tr <= r) {
    return sum[v];
  }
  int tm = (tl + tr) / 2;
  return add(getsum(2 * v, tl, tm, l, r), getsum(2 * v + 1, tm + 1, tr, l, r));
}

void make(int l, int r, int x) {
  make(1, 0, n, l, r, x);
}

int getsum(int l, int r) {
  return getsum(1, 0, n, l, r);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    wh[a[i]].push_back(i);
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  stk[0] = 0;
  top = 0;
  for (int i = 1; i <= n; i++) {
    while (top && a[stk[top]] >= a[i]) {
      top--;
    }
    tol[i] = stk[top];
    stk[++top] = i;
  }
  stk[0] = n + 1;
  top = 0;
  for (int i = n; i >= 1; i--) {
    while (top && a[stk[top]] >= a[i]) {
      top--;
    }
    tor[i] = stk[top];
    stk[++top] = i;
  }
  make(0, 0, 1);
  for (int it = 1; it <= m; it++) {
    vector<T> ops;
    ops.push_back({0, n, 0});
    int x = b[it];
    for (auto &i : wh[x]) {
      int stop = tol[i] + 1;
      int susu = getsum(stop - 1, i - 1);
      stop = tor[i] - 1;
      ops.push_back({i, stop, susu});
    }
    for (auto &it : ops) {
      make(it.l, it.r, it.x);
    }
  }
  cout << getsum(n, n) << "\n";
  return 0;
}