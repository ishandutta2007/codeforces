#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 5;

int x[MXN];
int y[MXN];
int d[MXN];
int xr[MXN];
int par[MXN];
int siz[MXN];
int sol[MXN];
int type[MXN];
int basis[30];

stack<pair<int*, int>> stk;
vector<array<int, 3>> st[2 << 18];

void change(int &ref, int val) {
  stk.push({&ref, ref});
  ref = val;
}

array<int, 2> get(int x) {
  int len = 0;
  while (par[x]) {
    len ^= xr[x];
    x = par[x];
  }
  return {x, len};
}

void join(int x, int y, int d) {
  auto [px, xrx] = get(x);
  auto [py, xry] = get(y);
  if (px == py) {
    int cycle = xrx ^ d ^ xry;
    for (int i = 29; i >= 0; --i) {
      if (cycle >> i & 1) {
        if (basis[i]) {
          cycle ^= basis[i];
        } else {
          change(basis[i], cycle);
          break;
        }
      }
    }
  } else {
    if (siz[px] < siz[py]) {
      swap(px, py);
    }
    change(siz[px], siz[px] + siz[py]);
    change(xr[py], xrx ^ d ^ xry);
    change(par[py], px);
  }
}

void dfs(int lo, int hi, int nd = 0) {
  int sz = stk.size();
  for (auto [x, y, d] : st[nd]) {
    join(x, y, d);
  }
  if (lo + 1 == hi) {
    sol[lo] ^= get(x[lo])[1];
    sol[lo] ^= get(y[lo])[1];
    for (int i = 29; i >= 0; --i) {
      sol[lo] = min(sol[lo], sol[lo] ^ basis[i]);
    }
  } else {
    int mid = (lo + hi) / 2;
    dfs(lo, mid, 2 * nd + 1);
    dfs(mid, hi, 2 * nd + 2);
  }
  while (sz < (int) stk.size()) {
    auto [ptr, val] = stk.top();
    *ptr = val;
    stk.pop();
  }
}

void add(int l, int r, array<int, 3> e, int lo, int hi, int nd = 0) {
  if (l <= lo && hi <= r) return st[nd].push_back(e);
  int mid = (lo + hi) / 2;
  if (l < mid) add(l, r, e, lo, mid, 2 * nd + 1);
  if (mid < r) add(l, r, e, mid, hi, 2 * nd + 2);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;
  map<array<int, 2>, array<int, 2>> mp;
  for (int i = 0; i < m; ++i) {
    int x, y, d;
    cin >> x >> y >> d;
    mp[{x, y}] = {0, d};
  }
  int q;
  cin >> q;
  int sz = 0;
  for (int i = 0; i < q; ++i) {
    cin >> type[i] >> x[i] >> y[i];
    if (type[i] == 1) cin >> d[i];
    sz += type[i] == 3;
  }
  int cq = 0;
  for (int i = 0; i < q; ++i) {
    if (type[i] == 1) {
      mp[{x[i], y[i]}] = {cq, d[i]};
    } else if (type[i] == 2) {
      auto [pq, d] = mp[{x[i], y[i]}];
      mp.erase({x[i], y[i]});
      if (pq < cq) add(pq, cq, {x[i], y[i], d}, 0, sz);
    } else {
      x[cq] = x[i];
      y[cq] = y[i];
      cq++;
    }
  }
  for (auto [a, b] : mp) {
    if (b[0] < sz) add(b[0], sz, {a[0], a[1], b[1]}, 0, sz);
  }
  for (int i = 1; i <= n; ++i) {
    siz[i] = 1;
  }
  dfs(0, sz);
  for (int i = 0; i < sz; ++i) {
    cout << sol[i] << '\n';
  }
}