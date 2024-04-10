#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int n, m, q;
set<int> ds[N];
set<int> us[N];

struct T {
  int min_d;
  int max_u;
  bool ok;
};

T operator + (T a, T b) {
  int min_d = min(a.min_d, b.min_d);
  int max_u = max(a.max_u, b.max_u);
  bool ok = a.ok & b.ok & (a.min_d > b.max_u);
  return {min_d, max_u, ok};
}

T t[4 * N];

void rec(int v, int tl, int tr, int i) {
  if (tr < i || i < tl) {
    return;
  }
  if (tl == tr) {
    auto it1 = ds[tl].begin();
    t[v].min_d = *it1;
    auto it2 = us[tl].end();
    it2--;
    t[v].max_u = *it2;
    t[v].ok = (t[v].min_d > t[v].max_u);
    return;
  }
  int tm = (tl + tr) / 2;
  rec(2 * v, tl, tm, i);
  rec(2 * v + 1, tm + 1, tr, i);
  t[v] = t[2 * v] + t[2 * v + 1];
}

void ins(int r, int c) {
  int x = (r + 1) / 2, y = (c + 1) / 2;
  if (r % 2 == 1) {
    ds[x].insert(y);
  } else {
    us[x].insert(y);
  }
  rec(1, 1, n, x);
}

void del(int r, int c) {
  int x = (r + 1) / 2, y = (c + 1) / 2;
  if (r % 2 == 1) {
    ds[x].erase(y);
  } else {
    us[x].erase(y);
  }
  rec(1, 1, n, x);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    ds[i].insert((int) 1e9);
    us[i].insert(-(int) 1e9);
    rec(1, 1, n, i);
  }
  set<pair<int, int>> s;
  for (int i = 1; i <= q; i++) {
    int r, c;
    cin >> r >> c;
    if (s.count({r, c}) == 0) {
      ins(r, c);
      s.insert({r, c});
    } else {
      del(r, c);
      s.erase({r, c});
    }
    if (t[1].ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}