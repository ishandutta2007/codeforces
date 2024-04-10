#include <bits/stdc++.h>


using namespace std;

const int N = (int) 4e5 + 7;
int n, a[N], lft[N], rgh[N], spawn[N];
vector<int> stk;

int tmax[4 * N];
int lazy[4 * N];

void push(int v, int tl, int tr) {
  if (lazy[v]) {
    tmax[v] += lazy[v];
    if (tl < tr) {
      lazy[2 * v] += lazy[v];
      lazy[2 * v + 1] += lazy[v];
    }
    lazy[v] = 0;
  }
}

void add(int v, int tl, int tr, int l, int r, int x) {
  push(v, tl, tr);
  if (tr < l || r < tl) return;
  if (l <= tl && tr <= r) {
    lazy[v] += x;
    push(v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  add(2 * v, tl, tm, l, r, x);
  add(2 * v + 1, tm + 1, tr, l, r, x);
  tmax[v] = max(tmax[2 * v], tmax[2 * v + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tr < l || r < tl) return 0;
  if (l <= tl && tr <= r) return tmax[v];
  int tm = (tl + tr) / 2;
  return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

void add(int l, int r, int val) {
  add(1, 1, 2 * n, l, r, val);
}

int max_dep(int l, int r) {
  return get(1, 1, 2 * n, l, r);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ///freopen ("input", "r", stdin);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  /// urmatorul mai mic la stanga
  for (int i = 1; i <= 2 * n; i++) {
    while (!stk.empty() && a[stk.back()] >= a[i]) stk.pop_back();
    lft[i] = (stk.empty() ? -1 : stk.back());
    stk.push_back(i);
    if (i <= n) {
      add(i, i, (int) stk.size());
    } else {
      spawn[i] = (int) stk.size();
    }
  }
  stk.clear();
  for (int i = 2 * n; i >= 1; i--) {
    while (!stk.empty() && a[stk.back()] >= a[i]) stk.pop_back();
    rgh[i] = (stk.empty() ? -1 : stk.back());
    stk.push_back(i);
  }
  stk.clear();
  for (int i = n; i >= 1; i--) {
    while (!stk.empty() && a[stk.back()] >= a[i]) stk.pop_back();
    add(i, i, (int) stk.size());
    stk.push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    assert((rgh[i] == -1) == (a[i] == 1));
  }
  for (int i = n + 1; i <= 2 * n; i++) {
    assert((lft[i] == -1) == (a[i] == 1));
  }
  int ret = max_dep(1, n), shift = 0;
  for (int l = 2; l <= n; l++) {
    if (a[l - 1] == 1) {
      add(l, l + n - 2, -1);
    } else {
      add(l, rgh[l - 1] - 1, -1);
    }
    int j = l + n - 1;
    add(j, j, spawn[j]);
    if (a[j] == 1) {
      add(j - n + 1, j - 1, +1);
    } else {
      add(lft[j] + 1, j - 1, +1);
    }
    int val = max_dep(l, j);
    if (val < ret) {
      ret = val;
      shift = l - 1;
    }
  }
  cout << ret << " " << shift << "\n";
}