#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
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

const int N = (int) 2e5 + 7;
const int B = 30;
int n, q, a[N], b[N];

int lazy[4 * N];

void push(int v, int tl, int tr) {
  if (!lazy[v]) return;
  if (tl == tr) {
    a[tl] ^= lazy[v];
  } else {
    lazy[2 * v] ^= lazy[v];
    lazy[2 * v + 1] ^= lazy[v];
  }
  lazy[v] = 0;
}

void xor_range(int v, int tl, int tr, int l, int r, int x) {
  push(v, tl, tr);
  if (tr < l || r < tl) return;
  if (l <= tl && tr <= r) {
    lazy[v] ^= x;
    push(v, tl, tr);
  } else {
    int tm = (tl + tr) / 2;
    xor_range(2 * v, tl, tm, l, r, x);
    xor_range(2 * v + 1, tm + 1, tr, l, r, x);
  }
}

void xor_range(int l, int r, int x) {
  xor_range(1, 1, n, l, r, x);
}

int get_a(int v, int tl, int tr, int i) {
  push(v, tl, tr);
  if (tl == tr) return a[tl];
  int tm = (tl + tr) / 2;
  if (i <= tm) return get_a(2 * v, tl, tm, i);
  return get_a(2 * v + 1, tm + 1, tr, i);
}

int get_a(int i) {
  return get_a(1, 1, n, i);
}

struct T {
  int val[B];
  T() {
    for (int i = 0; i < B; i++) val[i] = 0;
  }
};

T operator + (T ret, T b) {
  for (int j = 0; j < B; j++) {
    if (!b.val[j]) continue;
    int x = b.val[j];
    for (int bit = 0; bit < B; bit++) {
      if (x & (1 << bit)) x ^= ret.val[bit];
    }
    if (x) {
      for (int bit = 0; bit < B; bit++) {
        if (x & (1 << bit)) {
          assert(ret.val[bit] == 0);
          ret.val[bit] = x;
          break;
        }
      }
    }
  }
  return ret;
}

T t[4 * N];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    if (b[tl]) {
      for (int bit = 0; bit < B; bit++) {
        if (b[tl] & (1 << bit)) {
          t[v].val[bit] = b[tl];
          break;
        }
      }
    }
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = t[2 * v] + t[2 * v + 1];
  }
}

void upd(int v, int tl, int tr, int i, int x) {
  if (tr < i || i < tl) {
    assert(0);
  }
  if (tl == tr) {
    b[tl] ^= x;
    for (int bit = 0; bit < B; bit++) t[v].val[bit] = 0;
    if (b[tl]) {
      for (int bit = 0; bit < B; bit++) {
        if (b[tl] & (1 << bit)) {
          t[v].val[bit] = b[tl];
          break;
        }
      }
    }
    return;
  }
  int tm = (tl + tr) / 2;
  if (i <= tm) {
    upd(2 * v, tl, tm, i, x);
  } else {
    upd(2 * v + 1, tm + 1, tr, i, x);
  }
  t[v] = t[2 * v] + t[2 * v + 1];
}

void upd(int i, int x) {
  upd(1, 1, n, i, x);
}

T get(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) {
    assert(0);
  }
  if (l <= tl && tr <= r) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  if (r <= tm) return get(2 * v, tl, tm, l, r);
  if (tm + 1 <= l) return get(2 * v + 1, tm + 1, tr, l, r);
  return get(2 * v, tl, tm, l, r) + get(2 * v + 1, tm + 1, tr, l, r);
}

T get(int l, int r) {
  return get(1, 1, n, l, r);
}

signed realMain() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i - 1] ^ a[i];
  }
  build(1, 1, n);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      xor_range(l, r, x);
      upd(l, x);
      if (r + 1 <= n) {
        upd(r + 1, x);
      }
    } else {
      int l, r, x;
      cin >> l >> r;
      x = get_a(l);
      if (l == r) {
        if (x == 0) {
          cout << "1\n";
        } else {
          cout << "2\n";
        }
        continue;
      }
      T ret = get(l + 1, r);
      for (int bit = 0; bit < B; bit++) {
        if (x & (1 << bit)) x ^= ret.val[bit];
      }
      if (x) {
        for (int bit = 0; bit < B; bit++) {
          if (x & (1 << bit)) {
            ret.val[bit] = x;
            break;
          }
        }
      }
      int cnt = 0;
      for (int bit = 0; bit < B; bit++) {
        cnt += (ret.val[bit] > 0);
      }
      cout << (1 << cnt) << "\n";
    }
  }
  return 0;
}