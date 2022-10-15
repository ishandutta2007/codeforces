#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef long double ld;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

ll bigNum() {
  return rng() * rng() + rng();
}

const int N = (int) 1e5 + 7;
int n, m, k, a[N];
string s;
ll p[10][N], pcoef[N];

struct Node {
  ll h;
  int cnt;
};


Node operator + (Node a, Node b) {
  ll h = a.h * pcoef[b.cnt] + b.h;
  return {h, a.cnt + b.cnt};
}

int force[4 * N];
Node t[4 * N];

void push(int v, int tl, int tr) {
  if (force[v] == -1) return;

  t[v].h = p[force[v]][tr - tl + 1];

  if (tl < tr) {
    force[2 * v] = force[2 * v + 1] = force[v];
  }

  force[v] = -1;
}

void upd(int v, int tl, int tr, int l, int r, int x) {
  t[v].cnt = tr - tl + 1;
  push(v, tl, tr);

  if (tr < l || r < tl) return;
  if (l <= tl && tr <= r) {
    force[v] = x;
    push(v, tl, tr);
  } else {
    int tm = (tl + tr) / 2;
    upd(2 * v, tl, tm, l, r, x);
    upd(2 * v + 1, tm + 1, tr, l, r, x);
    t[v] = t[2 * v] + t[2 * v + 1];
  }
}

Node get(int v, int tl, int tr, int l, int r) {
  t[v].cnt = tr - tl + 1;
  push(v, tl, tr);

  if (tr < l || r < tl) return {0, 0};

  if (l <= tl && tr <= r) {
    return t[v];
  } else {
    int tm = (tl + tr) / 2;
    return get(2 * v, tl, tm, l, r) + get(2 * v + 1, tm + 1, tr, l, r);
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  for (int i = 0; i < 4 * N; i++) force[i] = -1;

  ll coef;
  int cnt = 0;

  while (1) {
    cnt++;
    for (int i = 0; i <= 9; i++) {
      p[i][1] = bigNum();
    }
    coef = bigNum();
    for (int x = 0; x <= 9; x++) {
      for (int i = 2; i < N; i++) {
        p[x][i] = p[x][i - 1] * coef + p[x][1];
      }
    }
    set<ll> st;
    bool ok = 1;
    for (int x = 0; x <= 9 && ok; x++) {
      for (int i = 1; i < 10000 && ok; i++) {
        if (st.count(p[x][i])) {
          ok = 0;
          break;
        }

        st.insert(p[x][i]);
      }
    }
    if (!ok) continue;
    break;
  }
  pcoef[0] = 1;
  for (int i = 1; i < N; i++) {
    pcoef[i] = pcoef[i - 1] * coef;
  }

  cin >> n >> m >> k >> s;
  assert((int) s.size() == n);
  for (int i = 1; i <= n; i++) {
    a[i] = s[i - 1] - '0';
    upd(1, 1, n, i, i, a[i]);
  }

  int qq = m + k;
  while (qq--) {
    int type, l, r;
    cin >> type >> l >> r;
    if (type == 1) {
      int digit;
      cin >> digit;
      upd(1, 1, n, l, r, digit);
    } else {
      int period;
      cin >> period;
      Node aa = get(1, 1, n, l, r - period);
      Node bb = get(1, 1, n, l + period, r);
      bool ok = (aa.h == bb.h);
      if (l <= r - period - 1) {
        ok &= (get(1, 1, n, l, r - period - 1).h == get(1, 1, n, l + period, r - 1).h);
      }
      if (ok) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }


  return 0;
}