#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

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
}

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


const int N = (int) 3e5 + 7;
const int INF = (int) 1e9;
const int K = 20;
int sz;

struct T {
  int l;
  int r;
} cop[N];

T operator + (T a, T b) {
  return {min(a.l, b.l), max(a.r, b.r)};
}

T rep(T a) {
  if (a.l < 1) a.l = 1;
  if (a.r > sz) a.r = sz;
  return a;
}

struct segt {
  T t[4 * N];
  /**segt() {
    for (int i = 0; i < 4 * N; i++) tree[i] = {INF, -INF};
  }**/
  void build(int v, int tl, int tr) {
    if (tl == tr) {
      t[v] = cop[tl];
    } else {
      int tm = (tl + tr) / 2;
      build(2 * v, tl, tm);
      build(2 * v + 1, tm + 1, tr);
      t[v] = t[2 * v] + t[2 * v + 1];
    }
  }
  T get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) {
      cout << l << " " << r << "\n";
      cout << " : " << tl << " " << tr << "\n";
      assert(0);
    }
    if (l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) / 2;
    if (r <= tm) return get(2 * v, tl, tm, l, r);
    if (tm + 1 <= l) return get(2 * v + 1, tm + 1, tr, l, r);
    return get(2 * v, tl, tm, l, r) + get(2 * v + 1, tm + 1, tr, l, r);
  }
  T get(int l, int r) {
    return get(1, 1, sz, l, r);
  }
  void build(T a[N]) {
    for (int i = 1; i <= sz; i++) cop[i] = a[i];
    build(1, 1, sz);
  }
};

int n, respect[N];
T tab[K][N];
segt seg[K];

signed realMain() {
  cin >> n;
  if (n == 1) {
    cout << "0\n";
    return 0;
  }
  sz = 3 * n;
  for (int i = 1; i <= n; i++) {
    cin >> respect[i];
    respect[i + n] = respect[i + 2 * n] = respect[i];
  }
  for (int i = 1; i <= sz; i++) {
    tab[0][i] = {i - respect[i], i + respect[i]};
    tab[0][i] = rep(tab[0][i]);
  }
  seg[0].build(tab[0]);
  int last_k = 0;
  for (int k = 1; (1 << k) <= sz; k++) {
    last_k = k;
    for (int i = 1; i <= sz; i++) {
      int l = tab[k - 1][i].l, r = tab[k - 1][i].r;
      T it = seg[k - 1].get(l, r);
      tab[k][i] = it;
    }
    seg[k].build(tab[k]);
  }
  for (int i = n + 1; i <= 2 * n; i++) {
    T it = {i, i};
    int cur = 0;
    for (int k = last_k; k >= 0; k--) {
      int step = (1 << k);
      T pot = seg[k].get(it.l, it.r);
      if (pot.r - pot.l + 1 < n) {
        it = pot;
        cur += step;
      }
    }
    cout << cur + 1 << " ";
  }
  cout << "\n";
  return 0;
}