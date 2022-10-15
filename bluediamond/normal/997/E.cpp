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

const int N = 120000 + 7;
int n, a[N], q, ret[N], ql[N], qr[N];
vector<pair<int, int>> ask[N];

int sol[4 * N];
int mn[4 * N];
int lazy[4 * N];
int cnt[4 * N];
int coef[4 * N];

void build(int v, int tl, int tr) {
  mn[v] = tl;
  cnt[v] = 1;
  if (tl < tr) {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
  }
}

void join(int v) {
  sol[v] = sol[2 * v] + sol[2 * v + 1];
  mn[v] = min(mn[2 * v], mn[2 * v + 1]);
  cnt[v] = cnt[2 * v] * (mn[2 * v] == mn[v]) + cnt[2 * v + 1] * (mn[2 * v + 1] == mn[v]);
}

void push(int v, int tl, int tr) {
  assert(tl < tr);
  if (lazy[v]) {
    if (tl < tr) {
      mn[2 * v] += lazy[v];
      mn[2 * v + 1] += lazy[v];
      lazy[2 * v] += lazy[v];
      lazy[2 * v + 1] += lazy[v];
    }
    lazy[v] = 0;
  }
  if (coef[v]) {
    if (tl < tr) {
      if (mn[2 * v] == mn[v]) {
        sol[2 * v] += coef[v] * cnt[2 * v];
        coef[2 * v] += coef[v];
      }
      if (mn[2 * v + 1] == mn[v]) {
        sol[2 * v + 1] += coef[v] * cnt[2 * v + 1];
        coef[2 * v + 1] += coef[v];
      }
    }
    coef[v] = 0;
  }
}

void add(int v, int tl, int tr, int l, int r, int val) {
  if (tr < l || r < tl) return;
  if (l <= tl && tr <= r) {
    mn[v] += val;
    lazy[v] += val;
    return;
  }
  push(v, tl, tr);
  int tm = (tl + tr) / 2;
  add(2 * v, tl, tm, l, r, val);
  add(2 * v + 1, tm + 1, tr, l, r, val);
  join(v);
}

void add(int l, int r, int val) {
  add(1, 1, n, l, r, val);
}

int solve(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) {
    return 0;
  }
  if (l <= tl && tr <= r) {
    return sol[v];
  }
  push(v, tl, tr);
  int tm = (tl + tr) / 2;
  return solve(2 * v, tl, tm, l, r) + solve(2 * v + 1, tm + 1, tr, l, r);
}

int solve(int l, int r) {
  return solve(1, 1, n, l, r);
}

signed realMain() {
  cin >> n;
  build(1, 1, n);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    ql[i] = l;
    qr[i] = r;
    ask[r].push_back({l, i});
    ret[i] = -1;
  }
  vector<int> smx, smn;
  smx.push_back(0);
  smn.push_back(0);
  add(1, n, -1);
  for (int i = 1; i <= n; i++) {
    add(1, n, -1);
    while ((int) smx.size() >= 2 && a[i] > a[smx.back()]) {
      int first = smx[(int) smx.size() - 2] + 1;
      int last = smx[(int) smx.size() - 1];
      add(first, last, a[i] - a[smx.back()]);
      smx.pop_back();
    }
    smx.push_back(i);
    while ((int) smn.size() >= 2 && a[i] < a[smn.back()]) {
      int first = smn[(int) smn.size() - 2] + 1;
      int last = smn[(int) smn.size() - 1];
      add(first, last, a[smn.back()] - a[i]);
      smn.pop_back();
    }
    smn.push_back(i);
    coef[1]++;
    sol[1] += cnt[1];
    for (auto &it : ask[i]) {
      int j = it.first, id = it.second;
      ret[id] = solve(j, i);
    }
  }
  for (int i = 1; i <= q; i++) {
    cout << ret[i] << "\n";
  }
  return 0;
}