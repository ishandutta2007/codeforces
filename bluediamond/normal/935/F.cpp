#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int ll
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

/**
mt19937 rng_home(0);
mt19937 rng_oj((long long) (new char));

int rng() {
  if (home) {
    return rng_home();
  } else{
    return rng_oj();
  }
}

ull rng_ull() {
  return (ull) rng() * rng() ^ ((ull) rng() * rng());
}

int rng_range(int l, int r) {
  return l + abs(rng()) % (r - l + 1);
}**/

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 1e5 + 7;
const int INF = (int) 1e18;
int n;
int q;
int vec[N];
int lazy[4 * N];
int base;
set<int> type[4];
int tree[4 * N];

void upd(int v, int tl, int tr, int i, int dif) {
  if (tr < i || i < tl) return;
  if (tl == tr) {tree[v] = dif; return;}
  int tm = (tl + tr) / 2;
  upd(2 * v, tl, tm, i, dif);
  upd(2 * v + 1, tm + 1, tr, i, dif);
  tree[v] = min(tree[2 * v], tree[2 * v + 1]);
}

void upd_dif(int i, int dif) {
  upd(1, 1, n, i, dif);
}

int getmin(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) return INF;
  if (l <= tl && tr <= r) return tree[v];
  int tm = (tl + tr) / 2;
  return min(getmin(2 * v, tl, tm, l, r), getmin(2 * v + 1, tm + 1, tr, l, r));
}

int getmin(int l, int r) {
  return getmin(1, 1, n, l, r);
}

void push(int v, int tl, int tr) {
  if (!lazy[v]) return;
  if (tl == tr) vec[tl] += lazy[v];
  else lazy[2 * v] += lazy[v], lazy[2 * v + 1] += lazy[v];
  lazy[v] = 0;
}

void add(int v, int tl, int tr, int l, int r, int val) {
  push(v, tl, tr);
  if (tr < l || r < tl) return;
  if (l <= tl && tr <= r) {
    lazy[v] += val;
    push(v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  add(2 * v, tl, tm, l, r, val);
  add(2 * v + 1, tm + 1, tr, l, r, val);
}

int get(int v, int tl, int tr, int i) {
  push(v, tl, tr);
  if (tr < i || i < tl) assert(0);
  if (tl == tr) return vec[tl];
  int tm = (tl + tr) / 2;
  if (i <= tm) return get(2 * v, tl, tm, i);
  else return get(2 * v + 1, tm + 1, tr, i);
}

void add(int l, int r, int x) {
  add(1, 1, n, l, r, x);
}

int get(int i) {
  return get(1, 1, n, i);
}

void upd(int i, int sgn) {
  if (i <= 1 || i >= n) return;
  upd_dif(i, INF);
  int me = get(i);
  int b = get(i - 1);
  int c = get(i + 1);
  if (b > c) swap(b, c);
  int tp = -1;
  if (me >= b && me >= c) tp = 1; else
  if (me >= b && me < c) tp = 2; else
  if (me < b && me < c) tp = 3;
  assert(tp != -1);
  if (sgn == +1) {
    type[tp].insert(i);
  } else {
    type[tp].erase(i);
  }
  if (tp == 2) upd_dif(i, c - me);
}

int get(int l, int r, int x) {
  auto it = type[1].lower_bound(l);
  if (it != type[1].end()) {
    if (*it <= r) {
      return 2 * x;
    }
  }
  int ret = -INF;
  it = type[3].lower_bound(l);
  if (it != type[3].end()) {
    if (*it <= r) {
      int p = *it, b = get(p - 1), c = get(p + 1), me = get(p);
      ret = max(ret, abs(me + x - b) + abs(me + x - c) - abs(me - c) - abs(me - b));
      it++;
    }
  }
  int mndif = getmin(l, r);
  if (mndif != INF) {
    ret = max(ret, 2 * max(0LL, x - mndif));
  }
  return ret;
}

signed realMain() {
  for (int i = 0; i < 4 * N; i++) tree[i] = INF;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> vec[i];
  for (int i = 1; i <= n; i++) upd(i, +1);
  for (int i = 1; i < n; i++) base += abs(get(i) - get(i + 1));
  int q;
  cin >> q;
  for (int it = 1; it <= q; it++) {
    int type, l, r, x;
    cin >> type >> l >> r >> x;
    if (type == 2) {
      base -= abs(get(l) - get(l - 1));
      base -= abs(get(r) - get(r + 1));
      int sgn = -1;
      upd(l - 1, sgn), upd(l, sgn), upd(l + 1, sgn);
      upd(r - 1, sgn), upd(r, sgn), upd(r + 1, sgn);
      add(l, r, x); sgn *= -1;
      upd(l - 1, sgn), upd(l, sgn), upd(l + 1, sgn);
      upd(r - 1, sgn), upd(r, sgn), upd(r + 1, sgn);
      base += abs(get(l) - get(l - 1));
      base += abs(get(r) - get(r + 1));
    } else {
      cout << get(l, r, x) + base << "\n";
    }
  }
  return 0;
}