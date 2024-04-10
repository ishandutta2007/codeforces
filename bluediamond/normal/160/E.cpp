#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;
int n;
int m;
int len;
int sol[N];

struct T {
  int l;
  int r;
  int val;
  int tp;
  int i;
};

bool operator < (T a, T b) {
  if (a.l == b.l) {
    return a.tp < b.tp;
  } else {
    return a.l < b.l;
  }
}

pair<int, int> mx[8 * N];

void upd(int v, int tl, int tr, int i, int x, int id) {
  if (tr < i || i < tl) {
    return;
  }
  if (tl == tr) {
    mx[v] = max(mx[v], {x, id});
    return;
  }
  int tm = (tl + tr) / 2;
  upd(2 * v, tl, tm, i, x, id);
  upd(2 * v + 1, tm + 1, tr, i, x, id);
  mx[v] = max(mx[2 * v], mx[2 * v + 1]);
}

pair<int, int> get(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) {
    return {0, 0};
  }
  if (l <= tl && tr <= r) {
    return mx[v];
  }
  int tm = (tl + tr) / 2;
  return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

void upd(int i, int x, int id) {
  upd(1, 1, len, i, x, id);
}

pair<int, int> get(int l, int r) {
  return get(1, 1, len, l, r);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  vector<T> a(n + m);
  map<int, int> t;
  for (int i = 0; i < n + m; i++) {
    cin >> a[i].l >> a[i].r >> a[i].val;
    t[a[i].val] = 0;
    if (i < n) {
      a[i].tp = 1;
      a[i].i = i + 1;
    } else {
      a[i].tp = 2;
      a[i].i = i - n + 1;
    }
  }
  for (auto &it : t) {
    it.second = ++len;
  }
  for (auto &it : a) {
    it.val = t[it.val];
  }
  sort(a.begin(), a.end());
  for (auto &it : a) {
    if (it.tp == 1) {
      upd(it.val, it.r, it.i);
    } else {
      if (get(it.val, len).first < it.r) {
        sol[it.i] = -1;
        continue;
      }
      int l = it.val, r = len, fi = -1;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (get(it.val, mid).first >= it.r) {
          fi = mid;
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      if (fi == -1) {
        cout << "error\n";
        exit(0);
      }
      sol[it.i] = get(it.val, fi).second;
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << sol[i] << " ";
  }
  cout << "\n";
  return 0;
}

/**
**/