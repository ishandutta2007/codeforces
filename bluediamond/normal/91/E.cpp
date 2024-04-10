#include <bits/stdc++.h>

using namespace std;

#define int long long

/// a + b * x

struct line {
  int a, b, id;
};

/**
at -INF, the largest one is the one with b = max, if they have the same b, it's the one with a bigger a
**/

/**

a1 + b1 * x = a2 + b2 * x

(a1 - a2) = x * (b2 - b1)
x = (a1 - a2) / (b2 - b1)

**/

bool bad(line l1, line l2, line l3) {
  return (l2.b - l1.b) * (l1.a - l3.a)  < (l1.a - l2.a) * (l3.b - l1.b);
}

bool operator < (line f, line s) {
  if (f.b != s.b) return f.b < s.b;
  return f.a > s.a;
}

struct lineContainer {
  vector<line> hull;
  int pt;
};

struct Query {
  int l, r, t, id;
};

const int N = (int) 1e5 + 7;
int n, q, a[N], b[N], ans[N];
lineContainer t[4 * N];

void buildTree(int v, int tl, int tr) {
  if (tl < tr) {
    int tm = (tl + tr) / 2;
    buildTree(2 * v, tl, tm);
    buildTree(2 * v + 1, tm + 1, tr);
  }
  vector<line> lines;
  for (int j = tl; j <= tr; j++) {
    lines.push_back({a[j], b[j], j});
  }
  sort(lines.begin(), lines.end());
  {
    vector<line> lines2;
    for (auto &it : lines) {
      if (lines2.empty() || it.b != lines2.back().b) {
        lines2.push_back(it);
      }
    }
    lines = lines2;
  }
  for (auto &ln : lines) {
    while ((int) t[v].hull.size() >= 2 && bad(t[v].hull[(int) t[v].hull.size() - 2], t[v].hull[(int) t[v].hull.size() - 1], ln)) {
      t[v].hull.pop_back();
    }
    t[v].hull.push_back(ln);
  }
}

bool operator < (Query a, Query b) {
  return a.t < b.t;
}

line sol;
int T;

int eval(line f, int x = T) {
  return f.a + f.b * x;
}

void relax(line ln) {
  if (eval(ln) > eval(sol)) {
    sol = ln;
  }
}

void rec(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) {
    return;
  }
  if (l <= tl && tr <= r) {
    while (1) {
      assert(0 <= t[v].pt && t[v].pt < (int) t[v].hull.size());
      relax(t[v].hull[t[v].pt]);
      if (t[v].pt + 1 < (int) t[v].hull.size() && eval(t[v].hull[t[v].pt + 1]) > eval(t[v].hull[t[v].pt])) {
        t[v].pt++;
        continue;
      }
      break;
    }
    return;
  }
  int tm = (tl + tr) / 2;
  rec(2 * v, tl, tm, l, r);
  rec(2 * v + 1, tm + 1, tr, l, r);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];

  }

  buildTree(1, 1, n);

  vector<Query> qs(q);
  int spacex = 0;
  for (auto &it : qs) {
    cin >> it.l >> it.r >> it.t;
    it.id = ++spacex;
    ans[spacex] = -1;
  }
  sort(qs.begin(), qs.end());

  for (auto &it : qs) {
    T = it.t;
    sol = {0, 0, 0};
    rec(1, 1, n, it.l, it.r);
    ans[it.id] = sol.id;
  }

  for (int i = 1; i <= q; i++) {
    cout << ans[i] << "\n";
  }

  return 0;
}