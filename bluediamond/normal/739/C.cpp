#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroll-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
#define int ll
signed realMain();

/**
bool eprim(int x) {
  if (x <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}
**/

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
int n, initial[N];
int dif[N];
int suf[4 * N];
int pre[4 * N];
int ret[4 * N];

int sgn(int i) {
  i = dif[i];
  if (i > 0) {
    return +1;
  }
  if (i < 0) {
    return -1;
  }
  return 0;
}

void join(int v, int tl, int tr) {
  int tm = (tl + tr) / 2;
  ret[v] = max(ret[2 * v], ret[2 * v + 1]);
  pre[v] = pre[2 * v];
  suf[v] = suf[2 * v + 1];
  if (sgn(tm) != 0 && sgn(tm + 1) != 0 && sgn(tm) >= sgn(tm + 1)) {
    ret[v] = max(ret[v], suf[2 * v] + pre[2 * v + 1]);
    if (pre[v] == (tm - tl + 1)) {
      pre[v] += pre[2 * v + 1];
    }
    if (suf[v] == (tr - tm)) {
      suf[v] += suf[2 * v];
    }
  }
}

void build(int v, int tl, int tr) {
  if (tl == tr) {
    suf[v] = pre[v] = ret[v] = (sgn(tl) != 0);
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    join(v, tl, tr);
  }
}

void upd(int v, int tl, int tr, int i) {
  if (tr < i || i < tl) {
    return;
  }
  if (tl == tr) {
    suf[v] = pre[v] = ret[v] = (sgn(tl) != 0);
  } else {
    int tm = (tl + tr) / 2;
    upd(2 * v, tl, tm, i);
    upd(2 * v + 1, tm + 1, tr, i);
    join(v, tl, tr);
  }
}

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> initial[i];
  }
  n--;
  if (n == 0) {
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
      cout << "1\n";
    }
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    dif[i] = initial[i + 1] - initial[i];
  }
  build(1, 1, n);
  int q;
  cin >> q;
  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;
    if (l >= 1) {
      dif[l - 1] += x;
      upd(1, 1, n, l - 1);
    }
    if (r <= n) {
      dif[r] -= x;
      upd(1, 1, n, r);
    }
    cout << ret[1] + 1 << "\n";
  }
  return 0;
}