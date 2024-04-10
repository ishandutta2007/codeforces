#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N = (ll) 1e5 + 7;
ll mx[2][4 * N]; /// maximum (in llerval)
ll cmx[2][4 * N]; /// number of maximums (in llerval)
ll mx2[2][4 * N]; /// second maximum (in llerval)
ll len[4 * N]; /// length (of the llerval)
ll sum[4 * N]; /// the sum of active numbers (in llerval)
ll cntmx[2][4 * N]; /// number of maximums of certain type that are active (in llerval)
ll active[2][4 * N]; /// number of numbers that are active

ll addmx[2][4 * N]; /// lazy add to maximums (in llerval)

ll getmax(int type, int v) {
  return mx[type][v] + addmx[type][v];
}

void push(ll v) {
  for (ll type = 0; type <= 1; type++) {
    if (addmx[type][v] == 0) {
      continue;
    }
    if (len[v] > 1) {
      ll valmax = max(getmax(type, 2 * v), getmax(type, 2 * v + 1));
      for (int v2 = 2 * v; v2 <= 2 * v + 1; v2++) {
        if (getmax(type, v2) == valmax) {
          addmx[type][v2] += addmx[type][v];
        }
      }
    }
    mx[type][v] += addmx[type][v];
    sum[v] += (ll) cntmx[type][v] * addmx[type][v];
    addmx[type][v] = 0;
  }
}

void join(ll v) {
  for (ll type = 0; type <= 1; type++) {
    mx[type][v] = max(mx[type][2 * v], mx[type][2 * v + 1]);
    cmx[type][v] = cmx[type][2 * v] * (mx[type][v] == mx[type][2 * v]) + cmx[type][2 * v + 1] * (mx[type][v] == mx[type][2 * v + 1]);
    if (cmx[type][v] < len[v]) {
      mx2[type][v] = 0;
      for (ll v2 = 2 * v; v2 <= 2 * v + 1; v2++) {
        if (mx[type][v2] < mx[type][v]) {
          mx2[type][v] = max(mx2[type][v], mx[type][v2]);
          continue;
        }
        if (cmx[type][v2] == len[v2]) {
          continue;
        }
        mx2[type][v] = max(mx2[type][v], mx2[type][v2]);
      }
    }
    cntmx[type][v] = cntmx[type][2 * v] * (mx[type][v] == mx[type][2 * v]) + cntmx[type][2 * v + 1] * (mx[type][v] == mx[type][2 * v + 1]);
    active[type][v] = active[type][2 * v] + active[type][2 * v + 1];
  }
  sum[v] = sum[2 * v] + sum[2 * v + 1];
}

void init(ll v, ll tl, ll tr) {
  if (tl == tr) {
    len[v] = 1;
  } else {
    ll tm = (tl + tr) / 2;
    init(2 * v, tl, tm);
    init(2 * v + 1, tm + 1, tr);
    len[v] = len[2 * v] + len[2 * v + 1];
  }
}

void upd(ll type, ll v, ll tl, ll tr, ll l, ll r, ll x) {
  push(v);
  if (tr < l || r < tl) {
    return;
  }
  if (tl == tr) {
    if (active[type][v] == 0) {
      active[type][v] = 1;
      mx[type][v] = x;
      cmx[type][v] = 1;
      active[type][v] = 1;
      if (active[type ^ 1][v]) {
        sum[v] = mx[0][v] + mx[1][v];
        cntmx[0][v] = 1;
        cntmx[1][v] = 1;
      }
    } else {
      if (active[type ^ 1][v] && x < mx[type][v]) {
        sum[v] += x - mx[type][v];
        mx[type][v] = x;
      } else {
        if (x < mx[type][v]) {
          mx[type][v] = x;
        }
      }
    }
    return;
  }
  ll tm = (tl + tr) / 2;
  if (active[type][v] < tr - tl + 1) {
    upd(type, 2 * v, tl, tm, l, r, x);
    upd(type, 2 * v + 1, tm + 1, tr, l, r, x);
    join(v);
    return;
  }

  if (mx[type][v] <= x) {
    return;
  }
  if (l <= tl && tr <= r && (cmx[type][v] == tr - tl + 1 || mx2[type][v] < x)) {
    addmx[type][v] += x - mx[type][v];
    push(v);
    return;
  }
  upd(type, 2 * v, tl, tm, l, r, x);
  upd(type, 2 * v + 1, tm + 1, tr, l, r, x);
  join(v);
}


ll get(ll v, ll tl, ll tr, ll l, ll r) {
  push(v);
  if (tr < l || r < tl) {
    return 0LL;
  }
  if (l <= tl && tr <= r) {
    return sum[v];
  }
  ll tm = (tl + tr) / 2;
  return get(2 * v, tl, tm, l, r) + get(2 * v + 1, tm + 1, tr, l, r);
}

int sz = N - 7;

void init() {
  init(1, 1, sz);
}

void upd(ll type, ll l, ll r, ll x) {
  upd(type, 1, 1, sz, l, r, x);
}

ll get(ll l, ll r) {
  return get(1, 1, sz, l, r);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll tests;
  cin >> tests;
  init();
  while (tests--) {
    ll tp, l, r;
    cin >> tp >> l >> r;
    r--;
    if (tp == 1) {
      ll x;
      cin >> x;
      if (x > 0) {
        upd(0, l, r, x);
      } else {
        upd(1, l, r, -x);
      }
    } else {
      cout << get(l, r) << "\n";
    }
  }
  return 0;
}