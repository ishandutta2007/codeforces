#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
const int K = 20;

struct SegTree {
  int t[4 * N];
  int lt[4 * N];
  int n;

  void clr(int v, int tl, int tr) {
    t[v] = lt[v] = 0;
    if (tl < tr) {
      int tm = (tl + tr) / 2;
      clr(2 * v, tl, tm);
      clr(2 * v + 1, tm + 1, tr);
    }
  }

  void init(int __n) {
    n = __n;
    clr(1, 1, n);
  }

  void push(int v, int tl, int tr) {
    if (lt[v]) {
      t[v] = tr - tl + 1 - t[v];
      if (tl < tr) {
        lt[2 * v] ^= 1;
        lt[2 * v + 1] ^= 1;
      }
      lt[v] ^= 1;
    }
  }

  void cor(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if (tr < l || r < tl) {
      return;
    }
    if (l <= tl && tr <= r) {
      lt[v] ^= 1;
      push(v, tl, tr);
    } else {
      int tm = (tl + tr) / 2;
      cor(2 * v, tl, tm, l, r);
      cor(2 * v + 1, tm + 1, tr, l, r);
      t[v] = t[2 * v] + t[2 * v + 1];
    }
  }

  void cor(int l, int r) {
    cor(1, 1, n, l, r);
  }

  int get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) {
      return 0;
    }
    push(v, tl, tr);
    if (l <= tl && tr <= r) {
      return t[v];
    } else {
      int tm = (tl + tr) / 2;
      int a = get(2 * v, tl, tm, l, r);
      int b = get(2 * v + 1, tm + 1, tr, l, r);
      return a + b;
    }
  }

  int get(int l, int r) {
    return get(1, 1, n, l, r);
  }

};

SegTree a[K];

void cor(int num, int l, int r) {
  for (int i = 0; (1 << i) <= num; i++) {
    if (num & (1 << i)) {
      a[i].cor(l, r);
    }
  }
}

ll get(int l, int r) {
  ll sum = 0;
  for (int i = 0; i < K; i++) {
    ll cnt = a[i].get(l, r);
    ll val = (1 << i);
    sum += cnt * val;
  }
  return sum;
}

int n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n;

  for (int i = 0; i < K; i++) {
    a[i].init(n);
  }

  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    cor(x, i, i);
  }

  int q;
  cin >> q;

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r;
      cin >> l >> r;
      cout << get(l, r) << "\n";
    } else {
      int l, r, x;
      cin >> l >> r >> x;
      cor(x, l, r);
    }
  }

  return 0;
}