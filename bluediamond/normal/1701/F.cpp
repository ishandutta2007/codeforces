#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int limit = (int) 2e5;
int q, d;
bool is_active[N];
ll cnt[N];

struct T {
  /// do something bro
  ll cnt_active;
  ll s1;
  ll s2;
  ll sum_cnt;

};

T operator + (T a, T b) {
  /// do something bro

  ll cnt_active = a.cnt_active + b.cnt_active;
  ll s1 = a.s1 + b.s1;
  ll s2 = a.s2 + b.s2;
  ll sum_cnt = a.sum_cnt + b.sum_cnt;

  return {cnt_active, s1, s2, sum_cnt};
}

ll lazy[4 * N];
T t[4 * N];

void push(int v, int tl, int tr) {
  /// do something bro

  ///  (cnt[i]^2) -> (cnt[i]+lazy[v])^2 = cnt[i]^2 + lazy[v]^2 + 2 * cnt[i] * lazy[v]

  if (lazy[v]) {
    t[v].s2 += 2 * t[v].s1 * lazy[v];
    t[v].s2 += t[v].cnt_active * lazy[v] * lazy[v];

    t[v].s1 += t[v].cnt_active * lazy[v];
    t[v].sum_cnt += lazy[v] * (tr - tl + 1);



    if (tl < tr) {
      lazy[2 * v] += lazy[v];
      lazy[2 * v + 1] += lazy[v];
    }

    lazy[v] = 0;
  }
}

void add(int v, int tl, int tr, int l, int r, ll value) {
  push(v, tl, tr);
  if (tr < l || r < tl) {
    return;
  }
  if (l <= tl && tr <= r) {
    lazy[v] += value;
    push(v, tl, tr);

    return;
  }

  int tm = (tl + tr) / 2;
  add(2 * v, tl, tm, l, r, value);
  add(2 * v + 1, tm + 1, tr, l, r, value);
  t[v] = t[2 * v] + t[2 * v + 1];
}

void change(int v, int tl, int tr, int i) {
  push(v, tl, tr);
  if (tr < i || i < tl) {
    return;
  }
  if (tl == tr) {
    assert(tl == i);
    assert(tr == i);
    /// do something bro
    t[v].cnt_active = is_active[i];
    t[v].s1 = t[v].sum_cnt * t[v].cnt_active;
    t[v].s2 = t[v].sum_cnt * t[v].sum_cnt * t[v].cnt_active;

    return;
  }
  int tm = (tl + tr) / 2;
  change(2 * v, tl, tm, i);
  change(2 * v + 1, tm + 1, tr, i);
  t[v] = t[2 * v] + t[2 * v + 1];
}

void add(int l, int r, ll value) {
  if (l > r) {
    return;
  }
  assert(1 <= l && l <= r && r <= limit);
  add(1, 1, limit, l, r, value);
}

void change(int i) {
  assert(1 <= i && i <= limit);
  change(1, 1, limit, i);
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE



  cin >> q >> d;
  for (int iq = 1; iq <= q; iq++) {
    int x;
    cin >> x;
    is_active[x] ^= 1;
    int low = max(1, x - d), high = x - 1, sgn = ((is_active[x]) ? (+1) : (-1));
    add(low, high, sgn);
    change(x);
    ll sol;
    push(1, 1, limit);
    sol = t[1].s2 - t[1].s1;
    assert(sol % 2 == 0);



    sol /= 2;
    cout << sol << "\n";
   /// cout << "\t\t\t -----> " << s2 << " " << t[1].s2  << "\n";
  }

}


/**

 (cnt[i]^2) -> (cnt[i]+lazy[v])^2 = cnt[i]^2 + lazy[v]^2 + 2 * cnt[i] * lazy[v]

**/


/**
(cnt[i]^2) -> (cnt[i]+1)^2 = cnt[i]^2 + 2*cnt[i] + 1



**/