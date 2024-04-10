#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
///#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

mt19937 rng_home(2);
mt19937 rng_oj((long long) (new char));

int rng() {
  if (home) {
    return rng_home();
  } else{
    return rng_oj();
  }
}

ull rng_ull() {
  return (ull) rng() * rng() ^ ((ull) rng() * rng());
}

int rng_range(int l, int r) {
  return l + abs(rng()) % (r - l + 1);
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = 300 + 7;
const int Q = (int) 2e6 + 7;
int n, m, q, a[N][N], ret[Q], k, t[N * N], comps, dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};

void clr() {
  comps = 0;
  for (int i = 1; i <= n * m; i++) {
    t[i] = 0;
  }
}

int id(int r, int c) {
  return c + (r - 1) * m;
}

int root(int i) {
  if (t[i] == i) {
    return i;
  } else {
    return t[i] = root(t[i]);
  }
}

void unite(int i, int j) {
  i = root(i);
  j = root(j);
  if (i == j) {
    return;
  }
  t[i] = j;
  comps--;
}

void activate(int r, int c) {
  int i = id(r, c);
  if (!t[i]) {
    comps++;
    t[i] = i;
  } else {
    return;
  }
  for (int dd = 0; dd < 4; dd++) {
    int rn = r + dr[dd], cn = c + dc[dd];
    if (1 <= rn && 1 <= cn && rn <= n && cn <= m) {
      int j = id(rn, cn);
      if (t[j]) {
        unite(i, j);
      }
    }
  }
}

struct event {
  int r;
  int c;
  int t;
  bool add;
};

vector<event> e[(int) 2e6 + 7];
vector<pair<int, int>> lafinal[(int) 2e6 + 7];

void add(int l, int r, int val) {
 /// cout << l << "..." << r << " -> " << val << "\n";
  ret[l] += val;
  ret[r + 1] -= val;
}

signed realMain() {
  cin >> n >> m >> q;
  for (int i = 1; i <= q; i++) {
    int r, c, x;
    cin >> r >> c >> x;
    k = x;
    if (a[r][c] == x) {
      continue;
    }
    e[a[r][c]].push_back({r, c, i, 0});
    a[r][c] = x;
    e[a[r][c]].push_back({r, c, i, 1});
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      lafinal[a[i][j]].push_back({i, j});
    }
  }
  for (int col = 0; col <= k; col++) {
    int sz = (int) e[col].size();
    if (!sz) continue;
    int split = -1;
    while (split + 1 < sz && e[col][split + 1].add) {
      split++;
    }

    clr();
    bool fin = 0;
    for (int j = 0; j <= split; j++) {
      auto it = e[col][j];
      activate(it.r, it.c);
      if (j + 1 < sz) {
        add(it.t, e[col][j + 1].t - 1, comps);
      } else {
        add(it.t, q, comps);
        fin = 1;
      }
    }

    clr();
    for (auto &it : lafinal[col]) {
      activate(it.first, it.second);
    }
    if (!fin) {
      if (sz == 0) {
        add(1, q, comps);
      } else {
        add(e[col].back().t, q, comps);
      }
    }
    for (int j = sz - 1; j >= split + 2; j--) {
      auto it = e[col][j];
      activate(it.r, it.c);
      if (j - 1 >= 0) {
        add(e[col][j - 1].t, it.t - 1, comps);
      } else {
        add(1, it.t - 1, comps);
      }
    }

    /// 0...split => add
    /// split + 1...sz - 1 => del

  }
  for (int i = 1; i <= q; i++) {
    ret[i] += ret[i - 1];
    cout << ret[i] << "\n";
  }
  return 0;
}