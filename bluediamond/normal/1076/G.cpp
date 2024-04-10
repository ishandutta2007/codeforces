#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

bool home = 1;
const int N = (int)2e5 + 7;
const int M = 5;
int n, m, q;
int a[N];
int w[N];
int combine[2][1 << M];

int fent[N];

void upd(int i) {
  while (i <= n) {
    fent[i] ^= 1;
    i += i & (-i);
  }
}

int getfent(int i) {
  int s = 0;
  while (i) {
    s ^= fent[i];
    i -= i & (-i);
  }
  return s;
}

struct Node {
  int what[2][1 << M];
};

Node join(Node a, Node b) {
  for (int tp = 0; tp < 2; tp++) {
    for (int i = 0; i < (1 << m); i++) {
      b.what[tp][i] = a.what[tp][b.what[tp][i]];
    }
  }
  return b;
}

Node t[4 * N];
bool lazy[4 * N];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    for (int i = 0; i < (1 << m); i++) {
      t[v].what[0][i] = combine[a[tl]][i];
      t[v].what[1][i] = combine[a[tl] ^ 1][i];
    }
  }
  else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = join(t[2 * v], t[2 * v + 1]);
  }
}

void push(int v, int tl, int tr) {
  if (lazy[v]) {
    swap(t[v].what[0], t[v].what[1]);
    if (tl < tr) {
      lazy[2 * v] ^= 1;
      lazy[2 * v + 1] ^= 1;
    }
    lazy[v] = 0;
  }
}

void inv(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tr < l || r < tl) return;
  if (l <= tl && tr <= r) {
    lazy[v] ^= 1;
    push(v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  inv(2 * v, tl, tm, l, r);
  inv(2 * v + 1, tm + 1, tr, l, r);
  t[v] = join(t[2 * v], t[2 * v + 1]);
}

Node get(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (l <= tl && tr <= r) return t[v];
  int tm = (tl + tr) / 2;
  if (r <= tm) return get(2 * v, tl, tm, l, r);
  if (tm + 1 <= l) return get(2 * v + 1, tm + 1, tr, l, r);
  return join(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0), cin.tie(0);
  }

  cin >> n >> m >> q;
  for (int me = 0; me < 2; me++) {
    for (int mask = 0; mask < (1 << m); mask++) {
      bool ww = 0;
      bool has = 0;
      for (int j = 0; j < m; j++) {
        if (mask & (1 << j)) has = 1;
        else ww = 1;
      }
      if (me == 0 && has) {
        ww = 1;
      }
      int nm = ww;
      for (int j = 0; j < m - 1; j++) {
        if (mask & (1 << j)) nm += (1 << (j + 1));
      }
      combine[me][mask] = nm;
    }
  }
  for (int i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    a[i] = x % 2;
  }
  build(1, 1, n);
  while (q--) {
    int tp, l, r;
    cin >> tp >> l >> r;
    if (tp == 1) {
      ll x;
      cin >> x;
      x %= 2;
      if (x == 0) continue;
      inv(1, 1, n, l, r);
      upd(l);
      upd(r + 1);
    }
    else {

      if (!(a[r] ^ getfent(r))) w[r] = 1;
      int L2 = max(l, r - m + 1);
      for (int i = r - 1; i >= L2; i--) {

        bool has = 0;
        for (int j = i + 1; j <= min(r, i + m); j++) {
          if (w[j] == 0) w[i] = 1;
          else has = 1;
        }

        if ((a[i] ^ getfent(i)) == 0 && has) {
          w[i] = 1;
        }
      }
      if (l == L2) {
        if (w[l]) {
          cout << "1\n";
        }
        else {
          cout << "2\n";
        }
        for (int i = r; i >= L2; i--) w[i] = 0;
        continue;
      }
      int mask = 0;
      for (int j = L2; j <= r; j++) {
        if (w[j]) mask += (1 << (j - L2));
      }
      Node tr = get(1, 1, n, l, L2 - 1);
      int init = mask;
      mask = tr.what[0][init];
      if (mask & 1) {
        cout << "1\n";
      }
      else {
        cout << "2\n";
      }
      for (int i = r; i >= L2; i--) w[i] = 0;
    }
  }
}