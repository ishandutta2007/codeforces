#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
int n, e, q, t[N], h[N], col[N];
int x[2 * N];
int y[2 * N];
int sol[N];

void init() {
  for (int i = 1; i <= n; i++) {
    t[i] = i;
    h[i] = 1;
    col[i] = 0;
  }
}

pair<int, int> get(int x) {
  if (t[x] == x) {
    return make_pair(x, col[x]);
  } else {
    auto it = get(t[x]);
    it.second ^= col[x];
    return it;
  }
}

bool is_ok(int x, int y) {
  auto itx = get(x);
  auto ity = get(y);
  if (itx.first == ity.first) {
    return (itx.second != ity.second);
  } else {
    return 1;
  }
}

struct info {
  int x, hx, colx;
  int y, hy, coly;
};

vector<info> information;

void roll_back() {
  auto it = information.back();
  if (it.x == -1) {
    information.pop_back();
    return;
  }
  t[it.x] = it.x;
  h[it.x] = it.hx;
  col[it.x] = it.colx;
  t[it.y] = it.y;
  h[it.y] = it.hy;
  col[it.y] = it.coly;
  information.pop_back();
}

void unite(int x, int y) {
  auto itx = get(x);
  auto ity = get(y);
  if (itx.first == ity.first) {
    information.push_back({-1, -1, -1, -1, -1, -1});
    return;
  }
  x = itx.first;
  y = ity.first;
  information.push_back({x, h[x], col[x], y, h[y], col[y]});
  if (h[x] > h[y]) {
    swap(x, y);
  }
  t[x] = y;
  if (itx.second == ity.second) {
    col[x] ^= 1;
  }
  if (h[x] == h[y]) {
    h[y]++;
  }
}

void solve(int l, int r, int lo, int hi) {
///  cout << "computing " << l << " " << r << " : " << lo << " " << hi << "\n";
  if (l > r) {
    cout << "I should never be here\n";
    exit(0);
  }
  int m = (l + r) / 2, steps = 0;
  if (m <= lo) {
    /// we need to insert [m, lo] and after that expand as long as I can
    if (r <= lo) {
      /// we need to insert [m, lo, r - 1] because [r, lo] already is here
      for (int i = m; i <= r - 1; i++) {
        if (!is_ok(x[i], y[i])){
          cout << "error 1\n";
          exit(0);
        }
        unite(x[i], y[i]);
        steps++;
      }
    } else {
      /// we need to insert [m, lo]
      for (int i = m; i <= lo; i++) {
        if (!is_ok(x[i], y[i])) {
          cout << "error 2\n";
          exit(0);
        }
        unite(x[i], y[i]);
        steps++;
      }
    }
    sol[m] = lo;
  } else {
    sol[m] = m;
    unite(x[m], y[m]);
    steps++;
  }
  /// expand as long as I can
  while (sol[m] + 1 <= 2 * e && is_ok(x[sol[m] + 1], y[sol[m] + 1])) {
    sol[m]++;
    unite(x[sol[m]], y[sol[m]]);
    steps++;
  }
  ///cout << "\t\t\t\t" << "sol[" << m << "] = " << sol[m] << "\n";
  while (steps > 0) {
    steps--;
    roll_back();
  }
  if (l <= m - 1) {
    /// we have info from [r, lo]
    if (r <= lo) {
      for (int j = m - 1; j < r; j++) {
        if (!is_ok(x[j], y[j])) {
          cout << "error 3\n";
          exit(0);
        }
        unite(x[j], y[j]);
        steps++;
      }
    } else {
      for (int j = m - 1; j <= lo; j++) {
        if (!is_ok(x[j], y[j])) {
          cout << "error 4\n";
          exit(0);
        }
        unite(x[j], y[j]);
        steps++;
      }
    }
    solve(l, m - 1, lo, sol[m]); /// there should be information [m-1, lo]
  }
  while (steps > 0) {
    steps--;
    roll_back();
  }
  if (m + 1 <= r) {
    /// we have info from [r, lo]
    if (r <= lo) {
      for (int j = lo + 1; j <= sol[m]; j++) {
        if (!is_ok(x[j], y[j])) {
          cout << "error 5\n";
          exit(0);
        }
        unite(x[j], y[j]);
        steps++;
      }
    } else {
      for (int j = r; j <= sol[m]; j++) {
        if (!is_ok(x[j], y[j])) {
          cout << "error 6\n";
          exit(0);
        }
        unite(x[j], y[j]);
        steps++;
      }
    }
    solve(m + 1, r, sol[m], hi); /// there should be information [r, sol[m]]
  }
  while (steps > 0) {
    steps--;
    roll_back();
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ///freopen ("input", "r", stdin);
  cin >> n >> e >> q;
  for (int i = 1; i <= e; i++) {
    cin >> x[i] >> y[i];
    x[i + e] = x[i];
    y[i + e] = y[i];
  }
  init();
  solve(1, e + 1, 1, 2 * e);
  while (q--) {
    int l, r;
    cin >> l >> r;
    swap(l, r);
    l++;
    r += e - 1;
    if (r <= sol[l]) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}