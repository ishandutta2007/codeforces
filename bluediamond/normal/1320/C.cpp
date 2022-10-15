#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = (int) 2e5 + 7;
int n, m, p;

struct T {
  int x;
  int c;
};

struct M {
  int x;
  int y;
  int p;
};

bool operator < (T a, T b) {
  return a.x < b.x;
}

bool operator < (M a, M b) {
  return a.x < b.x;
}

T a[N], b[N];
M mon[N];

const int L = (int) 1e6 + 7;
int aint[4 * L];
int lazy[4 * L];

void push(int v, int tl, int tr) {
  if (lazy[v]) {
    aint[v] += lazy[v];
    if (tl < tr) {
      lazy[2 * v] += lazy[v];
      lazy[2 * v + 1] += lazy[v];
    }
    lazy[v] = 0;
  }
}

void add(int v, int tl, int tr, int l, int r, int x) {
  push(v, tl, tr);
  if (tr < l || r < tl) {
    return;
  }
  if (l <= tl && tr <= r) {
    lazy[v] += x;
    push(v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  add(2 * v, tl, tm, l, r, x);
  add(2 * v + 1, tm + 1, tr, l, r, x);
  aint[v] = max(aint[2 * v], aint[2 * v + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tr < l || r < tl) {
    return -(int) 1e18;
  }
  if (l <= tl && tr <= r) {
    return aint[v];
  }
  int tm = (tl + tr) / 2;
  return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

int best[L];

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> p;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].c;
  }
  for (int i = 0; i < L; i++) {
    best[i] = (int) 1e18;
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i].x >> b[i].c;
    best[b[i].x] = min(best[b[i].x], b[i].c);
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= p; i++) {
    cin >> mon[i].x >> mon[i].y >> mon[i].p;
    mon[i].x++;
    mon[i].y++;
  }
  sort(mon + 1, mon + p + 1);
  for (int i = 0; i < L; i++) {
    add(1, 1, L - 1, i, i, -best[i]);
  }
  int ans = -(int) 1e18;
  int cur_mon = 1;
  for (int i = 1; i <= n; i++) {
    while (cur_mon <= p && mon[cur_mon].x <= a[i].x) {
      add(1, 1, L - 1, mon[cur_mon].y, L - 1, mon[cur_mon].p);
      cur_mon++;
    }
    ans = max(ans, get(1, 1, L - 1, 1, L - 1) - a[i].c);
  }
  cout << ans << "\n";
}