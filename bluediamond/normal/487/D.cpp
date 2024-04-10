/// 484 -> 485
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void myass(bool ok) {
  if (!ok) {
    exit(0);
  }
}

const int M = 10 + 3;

struct T {
  pair<int, int> go[M];
};

const int N = (int) 1e5 + 7;
pair<int, int> bad = {-1, -1};
int n, m, q;
T t[4 * N];
string s[N];

bool is_valid(pair<int, int> it) {
  return 1 <= it.first && it.first <= n && 1 <= it.second && it.second <= m;
}

pair<int, int> get_next(pair<int, int> it) {
  if (!is_valid(it)) {
    return it;
  }
  assert(1 <= it.first && it.first <= n);
  assert(1 <= it.second && it.second <= m);
  int x = it.first, y = it.second;
  char ch = s[x][y - 1];
  if (ch == '^') {
    return {x - 1, y};
  }
  if (ch == '<') {
    if (y >= 2 && s[x][y - 2] == '>') {
      return bad;
    }
    return {x, y - 1};
  }
  assert(ch == '>');
  if (y + 1 <= m && s[x][y] == '<') {
    return bad;
  }
  return {x, y + 1};
}

T join(T a, T b, int l1, int r1, int l2, int r2) {
  assert(1 <= l1 && l1 <= r1 && r1 == l2 - 1 && l2 <= r2 && r2 <= n);
  T sol;
  for (int j = 1; j <= m; j++) {
    sol.go[j] = b.go[j];
    while (is_valid(sol.go[j]) && sol.go[j].first >= l2) {
      sol.go[j] = get_next(sol.go[j]);
    }
    if (is_valid(sol.go[j])) {
      assert(sol.go[j].first == r1);
      assert(sol.go[j].first == l2 - 1);

      sol.go[j] = a.go[sol.go[j].second];

      if (is_valid(sol.go[j])) {
        ///myass(sol.go[j].first == l1);
      }
    }
  }
  return sol;
}

void build(int v, int tl, int tr) {
  if (tl == tr) {
    for (int j = 1; j <= m; j++) {
      t[v].go[j] = {tl, j};
    }
    return;
  }
  int tm = (tl + tr) / 2;
  build(2 * v, tl, tm);
  build(2 * v + 1, tm + 1, tr);
  t[v] = join(t[2 * v], t[2 * v + 1], tl, tm, tm + 1, tr);
}

void update(int v, int tl, int tr, int i) {
  if (tr < i || i < tl) {
    return;
  }
  if (tl == tr) {
    myass(tl == i);
    myass(tr == i);
    for (int j = 1; j <= m; j++) {
      t[v].go[j] = {tl, j};
    }
    return;
  }
  int tm = (tl + tr) / 2;
  update(2 * v, tl, tm, i);
  update(2 * v + 1, tm + 1, tr, i);
  t[v] = join(t[2 * v], t[2 * v + 1], tl, tm, tm + 1, tr);
}

T get(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) {
    assert(0);
  }
  if (l <= tl && tr <= r) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  if (r <= tm) {
    return get(2 * v, tl, tm, l, r);
  }
  if (tm + 1 <= l) {
    return get(2 * v + 1, tm + 1, tr, l, r);
  }
  return join(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r), l, tm, tm + 1, r);
}


signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE

  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    assert((int) s[i].size() == m);
  }
  build(1, 1, n);
  for (int iq = 1; iq <= q; iq++) {
    string type;
    cin >> type;
    assert(type == "A" || type == "C");
    if (type == "A") {
      int x, y;
      cin >> x >> y;
      auto it = get(1, 1, n, 1, x).go[y];

      while (is_valid(it)) {
        it = get_next(it);
      }

      cout << it.first << " " << it.second << "\n";
    } else {
      myass(type == "C");
      int i, j;
      string what;
      cin >> i >> j >> what;
      assert(1 <= i && i <= n);
      assert(1 <= j && j <= m);
      assert((int) what.size() == 1);
      assert(what[0] == '<' || what[0] == '>' || what[0] == '^');
      s[i][j - 1] = what[0];
      update(1, 1, n, i);
    }
  }

}