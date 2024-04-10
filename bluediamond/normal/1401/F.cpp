#include <bits/stdc++.h>

using namespace std;

#define int long long

struct segt {
  vector<int> t;
  int n;
  void upd(int v, int tl, int tr, int i, int x) {
    if (tr < i || i < tl) {
      return;
    }
    if (tl == tr) {
      t[v] = x;
      return;
    }
    int tm = (tl + tr) / 2;
    upd(2 * v, tl, tm, i, x);
    upd(2 * v + 1, tm + 1, tr, i, x);
    t[v] = t[2 * v] + t[2 * v + 1];
  }
  int get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) {
      return 0;
    }
    if (l <= tl && tr <= r) {
      return t[v];
    }
    int tm = (tl + tr) / 2;
    return get(2 * v, tl, tm, l, r) + get(2 * v + 1, tm + 1, tr, l, r);
  }
  void upd(int i, int x) {
    upd(1, 1, n, i, x);
  }
  int get(int l, int r) {
    return get(1, 1, n, l, r);
  }
  void init(int nn, int a[]) {
    n = nn;
    t.resize(4 * n + 7, 0);
    for (int i = 1; i <= n; i++) {
      upd(i, a[i]);
    }
  }
};

const int N = (1 << 18) + 7;
int n;
int q;
int a[N];
int one;

int rl(int n, int i, int one) {
  if (i < 1 || i > n || one < 1 || one > n) {
    cout << "error on function rl!!!\n";
    exit(0);
  }
  if (n == 1) {
    return n;
  }
  if (i <= n / 2) {
    if (one <= n / 2) {
      return rl(n / 2, i, one);
    } else {
      return n / 2 + rl(n / 2, i, one - n / 2);
    }
  } else {
    if (one <= n / 2) {
      return n / 2 + rl(n / 2, i - n / 2, one);
    } else {
      return rl(n / 2, i - n / 2, one - n / 2);
    }
  }
}

vector<pair<int, int>> lol;

void put(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) {
    return;
  }
  if (l <= tl && tr <= r) {
    lol.push_back({tl, tr});
    return;
  }
  int tm = (tl + tr) / 2;
  put(2 * v, tl, tm, l, r);
  put(2 * v + 1, tm + 1, tr, l, r);
}

void put(int l, int r) {
  lol.clear();
  put(1, 1, n, l, r);
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


  cin >> n >> q;
  n = (1 << n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  segt t;
  t.init(n, a);
  one = 1;
  while (q--) {
    int tp;
    cin >> tp;
    if (tp == 1) { /// replace
      int i, x;
      cin >> i >> x;
      t.upd(rl(n, i, one), x);
    }
    if (tp == 2) { /// reverse
      int k;
      cin >> k;
      int i = (one - 1) / ((1 << k)) + 1;
      int l = (i - 1) * (1 << k) + 1, r = l + (1 << k) - 1;
      one = r - (one - l);
    }
    if (tp == 3) { /// swap
      int k;
      cin >> k;
      int i = (one - 1) / ((1 << (k + 1))) + 1;
      int l1 = (2 * i - 2) * (1 << k) + 1, r1 = l1 + (1 << k) - 1;
      int l2 = r1 + 1, r2 = l2 + (1 << k) - 1;
      if (l1 <= one && one <= r1) {
        one += (1 << k);
        continue;
      }
      if (l2 <= one && one <= r2) {
        one -= (1 << k);
        continue;
      }
      cout << "what are you doing here bro?\n";
      return 0;
    }
    if (tp == 4) { /// sum
      int l, r;
      cin >> l >> r;
      put(l, r);
      int sol = 0;
      for (auto &it : lol) {
        int f = it.first;
        int s = it.second;
        int k2 = s - f + 1;
        int yolo = (rl(n, f, one) - 1) / k2;
        f = yolo * k2 + 1;
        s = f + k2 - 1;
        sol += t.get(f, s);
      }
      cout << sol << "\n";
    }
  }
  return 0;
}