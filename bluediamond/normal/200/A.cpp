#include <bits/stdc++.h>

using namespace std;

const int N = 2000 + 7;
int n, m, q;

struct T {
  int t[N];
  int l[N];
  int r[N];
  bool act[N];
  T() {
    for (int i = 1; i <= m; i++) {
      t[i] = l[i] = r[i] = i;
      act[i] = 0;
    }
  }
  int get(int i) {
    if (t[i] == i) {
      return i;
    } else {
      return t[i] = get(t[i]);
    }
  }
  void unite(int i, int j) {
    i = get(i);
    j = get(j);
    t[j] = i;
    l[i] = min(l[i], l[j]);
    r[i] = max(r[i], r[j]);
  }
  int ant(int i) {
    if (act[i] == 0) {
      return i;
    }
    i = get(i);
    return l[i] - 1;
  }
  int nxt(int i) {
    if (act[i] == 0) {
      return i;
    }
    i = get(i);
    return r[i] + 1;
  }
  void mark(int i) {
    act[i] = 1;
    if (i - 1 >= 1 && act[i - 1]) {
      unite(i, i - 1);
    }
    if (i + 1 <= m && act[i + 1]) {
      unite(i, i + 1);
    }
  }
};

int r, c;
int sr, sc;
int it;
bool inverted;

void upd(int x, int y) {
  if (x <= 0 || y <= 0 || x > n || y > m) {
    return;
  }
  int val_new = abs(x - r) + abs(y - c);
  int val_ant = abs(r - sr) + abs(c - sc);
  if (val_new < val_ant) {
    sr = x;
    sc = y;
    return;
  }
  if (val_new > val_ant) {
    return;
  }
  if (inverted == 0) {
    if (x < sr) {
      sr = x;
      sc = y;
      return;
    }
    if (x == sr && y < sc) {
      sc = y;
    }
  } else {
    if (y < sc) {
      sr = x;
      sc = y;
      return;
    }
    if (y == sc && x < sr) {
      sr = x;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q;
  if (n > m) {
    inverted = 1;
    swap(n, m);
  }
  vector<T> a(n + 1);
  while (q--) {
    sr = (int) 1e9;
    cin >> r >> c;
    if (inverted) {
      swap(r, c);
    }
    for (int piv = 0; piv <= abs(r - sr) + abs(c - sc) && (r - piv >= 1 || r + piv <= n); piv++) {
      if (r - piv >= 1) {
        upd(r - piv, a[r - piv].ant(c));
        upd(r - piv, a[r - piv].nxt(c));
      }
      if (r + piv <= n) {
        upd(r + piv, a[r + piv].ant(c));
        upd(r + piv, a[r + piv].nxt(c));
      }
    }
    a[sr].mark(sc);
    if (inverted) {
      swap(sr, sc);
    }
    cout << sr << " " << sc << "\n";
  }
  return 0;
}