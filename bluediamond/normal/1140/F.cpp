#include <bits/stdc++.h>

using namespace std;

bool home = 1;
///#define int ll
typedef long long ll;
///typedef long double ld;
typedef unsigned long long ull;

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

const int N = (int) 6e5 + 7;
int n;
map<pair<int, int>, int> when;
vector<pair<int, int>> vin[4 * N];

int t[N], h[N];
int a[N], b[N];
ll prod;

int root(int x) {
  if (t[x] == x) {
    return x;
  } else {
    return root(t[x]);
  }
}

struct Memory {
  int x, hx, ax, bx;
  int y, hy, ay, by;
  ll prod;
};

vector<Memory> events;

void join(int x, int y) {
  x = root(x);
  y = root(y);
  events.push_back({x, h[x], a[x], b[x], y, h[y], a[y], b[y], prod});
  if (x == y) {
    return;
  }
  prod -= (ll) a[x] * b[x];
  prod -= (ll) a[y] * b[y];
  if (h[x] > h[y]) {
    swap(x, y);
  }
  t[x] = y;
  h[y] += (h[x] == h[y]);
  a[y] += a[x];
  b[y] += b[x];
  prod += (ll) a[y] * b[y];
}

void intorc() {
  auto it = events.back();
  events.pop_back();
  prod = it.prod;
  t[it.x] = it.x;
  h[it.x] = it.hx;
  a[it.x] = it.ax;
  b[it.x] = it.bx;

  t[it.y] = it.y;
  h[it.y] = it.hy;
  a[it.y] = it.ay;
  b[it.y] = it.by;

}

void add(int v, int tl, int tr, int l, int r, pair<int, int> it) {
  if (tr < l || r < tl) {
    return;
  }
  if (l <= tl && tr <= r) {
    vin[v].push_back(it);
    return;
  }
  int tm = (tl + tr) / 2;
  add(2 * v, tl, tm, l, r, it);
  add(2 * v + 1, tm + 1, tr, l, r, it);
}

void solve(int v, int tl, int tr) {
  for (auto &it : vin[v]) {
    join(it.first, it.second);
  }
  if (tl == tr) {
    cout << prod << " ";
  } else {
    int tm = (tl + tr) / 2;
    solve(2 * v, tl, tm);
    solve(2 * v + 1, tm + 1, tr);
  }
  for (auto &it : vin[v]) {
    intorc();
  }
}

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    y += (int) 3e5;
    pair<int, int> p = {x, y};
    if (when[p] == 0) {
      when[p] = i;
    } else {
      add(1, 1, n, when[p], i - 1, p);
      when[p] = 0;
    }
  }
  for (auto &it : when) {
    if (it.second) {
      add(1, 1, n, it.second, n, it.first);
    }
  }
  for (int i = 1; i <= (int) 6e5; i++) {
    t[i] = i;
    h[i] = 1;
    a[i] = (i <= (int) 3e5);
    b[i] = 1 - a[i];
  }
  solve(1, 1, n);
  cout << "\n";
}