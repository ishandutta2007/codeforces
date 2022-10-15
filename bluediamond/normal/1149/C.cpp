#include <bits/stdc++.h>

using namespace std;

bool home = 1;

const int N = (int)2e5 + 7;
const int INF = (int)1e7 + 7;

int n;



struct T {
  int mx[3][3];
};

T t[4 * N];

T operator + (T a, T b) {
  T c;
  for (int l = 0; l < 3; l++) {
    for (int r = l; r < 3; r++) {
      c.mx[l][r] = max(a.mx[l][r], b.mx[l][r]);
      /// [l,r]
      for (int ant = l; ant < r; ant++) {
        c.mx[l][r] = max(c.mx[l][r], a.mx[l][ant] + b.mx[ant + 1][r]);
      }
    }
  }
  return c;
}

int lazy[4 * N];
int coef[3][3];

void push(int v, int tl, int tr) {
  if (lazy[v]) {
    for (int l = 0; l < 3; l++) {
      for (int r = 0; r < 3; r++) {
        t[v].mx[l][r] += coef[l][r] * lazy[v];
      }
    }
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
  t[v] = t[2 * v] + t[2 * v + 1];
}

void add(int l, int r, int x) {
  add(1, 0, n - 1, l, r, x);
}

int get() {
  return t[1].mx[0][2];
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  {
    vector<int> la = { +1, -2, +1 };
    for (int l = 0; l < 3; l++) {
      int cur = 0;
      for (int r = l; r < 3; r++) {
        cur += la[r];
        coef[l][r] = cur;
      }
    }
  }

  int q;
  string str;
  cin >> n >> q >> str;
  n--;
  n *= 2;
  for (int i = 0; i < n; i++) {
    if (str[i] == '(') {
      add(i, n - 1, +1);
    }
    else {
      add(i, n - 1, -1);
    }
  }

  cout << get() << "\n";
  while (q--) {
    int i, j;
    cin >> i >> j;
    i--;
    j--;
    if (str[i] != str[j]) {
      if (str[i] == '(') add(i, n - 1, -2); else add(i, n - 1, +2);
      if (str[j] == '(') add(j, n - 1, -2); else add(j, n - 1, +2);
      swap(str[i], str[j]);
    }
    cout << get() << "\n";
  }


  return 0;
}