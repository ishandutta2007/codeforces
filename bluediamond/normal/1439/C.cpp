#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int n;
int q;
int initial[N];
ll t[4 * N];
int all[4 * N];
int first[4 * N];
int last[4 * N];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = first[v] = last[v] = initial[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = t[2 * v] + t[2 * v + 1];
    first[v] = first[2 * v];
    last[v] = last[2 * v + 1];
  }
  all[v] = -1;
}

void push(int v, int tl, int tr) {
  if (all[v] != -1) {
    first[v] = all[v];
    last[v] = all[v];
    t[v] = all[v] * (ll) (tr - tl + 1);
    if (tl < tr) {
      all[2 * v] = all[2 * v + 1] = all[v];
    }
    all[v] = -1;
  }
}

ll get(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tr < l || r < tl) {
    return 0LL;
  }
  if (l <= tl && tr <= r) {
    return t[v];
  } else {
    int tm = (tl + tr) / 2;
    return get(2 * v, tl, tm, l, r) + get(2 * v + 1, tm + 1, tr, l, r);
  }
}

ll get(int l, int r) {
  return get(1, 1, n, l, r);
}

void make(int v, int tl, int tr, int l, int r, int x) {
  push(v, tl, tr);
  if (tr < l || r < tl) {
    return;
  }
  if (l <= tl && tr <= r) {
    all[v] = x;
    push(v, tl, tr);
  } else {
    int tm = (tl + tr) / 2;
    make(2 * v, tl, tm, l, r, x);
    make(2 * v + 1, tm + 1, tr, l, r, x);
    t[v] = t[2 * v] + t[2 * v + 1];
    first[v] = first[2 * v];
    last[v] = last[2 * v + 1];
  }
}

void make(int l, int r, int x) {
  make(1, 1, n, l, r, x);
}

int first_single_value_smaller(int v, int tl, int tr, int i, int x) {
  push(v, tl, tr);
  if (tr < i) {
    return -1;
  }
  if (tl < i) {
    int tm = (tl + tr) / 2;
    int sol = first_single_value_smaller(2 * v, tl, tm, i, x);
    if (sol == -1) {
      sol = first_single_value_smaller(2 * v + 1, tm + 1, tr, i, x);
    }
    return sol;
  }
  if (last[v] > x) {
    return -1;
  }
  if (tl == tr) {
    return tl;
  }
  int tm = (tl + tr) / 2;
  int sol = first_single_value_smaller(2 * v, tl, tm, i, x);
  if (sol == -1) {
    sol = first_single_value_smaller(2 * v + 1, tm + 1, tr, i, x);
  }
  return sol;
}

int last_idx;
int want;
bool stop;

void last_interval_sum(int v, int tl, int tr, int i) {
  push(v, tl, tr);
  if (stop) {
    return;
  }
  if (tr < i) {
    return;
  }
  if (tl < i) {
    int tm = (tl + tr) / 2;
    last_interval_sum(2 * v, tl, tm, i);
    if (stop) {
      return;
    }
    last_interval_sum(2 * v + 1, tm + 1, tr, i);
    return;
  }
  if (want >= t[v]) {
    want -= t[v];
    last_idx = tr;
    return;
  }
  if (want < first[v]) {
    stop = 1;
    return;
  }
  int tm = (tl + tr) / 2;
  last_interval_sum(2 * v, tl, tm, i);
  if (stop) {
    return;
  }
  last_interval_sum(2 * v + 1, tm + 1, tr, i);
}

int solve(int pos, int x) {
  if (pos > n) {
    return 0;
  }
  if (get(pos, pos) <= x) {
    stop = 0;
    last_idx = -1;
    want = x;
    last_interval_sum(1, 1, n, pos);

    x -= get(pos, last_idx);
    assert(last_idx != -1);
    return last_idx - pos + 1 + solve(last_idx + 1, x);
  }
  int first = first_single_value_smaller(1, 1, n, pos + 1, x);
  if (first == -1) {
    return 0;
  } else {
    return solve(first, x);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> initial[i];
  }
  build(1, 1, n);
  while (q--) {
    int tp;
    cin >> tp;
    if (tp == 1) {
      int prefix, x;
      cin >> prefix >> x;
      int first = first_single_value_smaller(1, 1, n, 1, x - 1);
      if (first != -1 && first <= prefix) {
        make(first, prefix, x);
      }
    } else {
      int pos, x;
      cin >> pos >> x;
      cout << solve(pos, x) << "\n";
    }
  }
}