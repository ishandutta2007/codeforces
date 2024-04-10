#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct T {
  ll sum;
  int len;
  ll sol;
};

T unite(T a, T b) {
  ll sum = a.sum + b.sum;
  int len = a.len + b.len;
  ll sol = a.sol + b.sol + b.sum * a.len - a.sum * b.len;
  return {sum, len, sol};
}

const int N = (int) 1e5 + 7;
int n;
int a[N];
int grow[N];
int m;
map<int, int> trans;
int tp[N];
int x[N];
int y[N];
int now;
T aint[4 * N * 3];

void del(int v, int tl, int tr, int pos) {
  if (tr < pos || pos < tl) {
    return;
  }
  if (tl == tr) {
    aint[v] = {0, 0, 0};
  } else {
    int tm = (tl + tr) / 2;
    del(2 * v, tl, tm, pos);
    del(2 * v + 1, tm + 1, tr, pos);
    aint[v] = unite(aint[2 * v], aint[2 * v + 1]);
  }
}

void make(int v, int tl, int tr, int pos, ll x) {
  if (tr < pos || pos < tl) {
    return;
  }
  if (tl == tr) {
    aint[v] = {x, 1, 0};
  } else {
    int tm = (tl + tr) / 2;
    make(2 * v, tl, tm, pos, x);
    make(2 * v + 1, tm + 1, tr, pos, x);
    aint[v] = unite(aint[2 * v], aint[2 * v + 1]);
  }
}

T get(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) {
    return {0, 0, 0};
  }
  if (l <= tl && tr <= r) {
    return aint[v];
  } else {
    int tm = (tl + tr) / 2;
    return unite(get(2 * v, tl, tm, l, r), get(2 * v +1, tm + 1, tr, l, r));
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    trans[a[i]] = 0;
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> tp[i] >> x[i] >> y[i];
    if (tp[i] == 1) {
      grow[x[i]] += y[i];
      trans[a[x[i]] + grow[x[i]]] = 0;
    } else {
      trans[x[i]] = 0;
      trans[y[i]] = 0;
    }
  }
  for (auto &it : trans) {
    it.second = ++now;
  }
  for (int i = 1; i <= n; i++) {
    make(1, 1, now, trans[a[i]], a[i]);
  }
  for (int i = 1; i <= m; i++) {
    if (tp[i] == 1) {
      del(1, 1, now, trans[a[x[i]]]);
      a[x[i]] += y[i];
      make(1, 1, now, trans[a[x[i]]], a[x[i]]);
    } else {
      auto it = get(1, 1, now, trans[x[i]], trans[y[i]]);
      cout << it.sol << "\n";
    }
  }
}