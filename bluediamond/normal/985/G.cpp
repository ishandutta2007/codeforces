#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef unsigned long long ll;

signed realMain();

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


const int N = (int) 2e5 + 7;
int n, m;
vector<int> g[N], p1[N], p2[N];
ll a, b, c;

struct T {
  int x;
  int y;
};

bool operator < (T a, T b) {
  return a.x > b.x;
}

ll f(ll i, ll j, ll k) {
  return a * i + b * j + c * k;
}

bool ok[N];

mt19937 rng(0);

void gen() {
  int n = 100, m = 3000;
  int a = rng(), b = rng(), c = rng();
  a = abs(a);
  b = abs(b);
  c = abs(c);
  freopen ("input", "w", stdout);
  cout << n << " " << m << " " << a << " " << b << " " << c << "\n";
  vector<pair<int, int>> gg;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      gg.push_back({i - 1, j - 1});
    }
  }
  shuffle(gg.begin(), gg.end(), rng);
  assert((int) gg.size() >= m);
  for (int j = 0; j < m; j++) {
    cout << gg[j].first << " " << gg[j].second << "\n";
  }
  exit(0);
}

ll gauss(ll x) {
  assert(n < N);
  return x * (x + 1) / 2;
}

ll gauss(ll x, ll y) {
  assert(x - 1 <= y);
  return gauss(y) - gauss(x - 1);
}

vector<int> v[N];

ll t1[N];
ll t2[N];
ll t3[N];
ll t4[N];
ll sx;
ll sy;

const int M = 400;
bool act[N];
int lim;
int id[N];
bitset<N> bb[M];

signed realMain() {
 // gen();
  cin >> n >> m >> a >> b >> c;
  vector<T> e;
  vector<pair<int, int>> all;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    g[x].push_back(y);
    e.push_back({x, y});
    all.push_back({x, y});
  }
  sort(e.begin(), e.end());
  for (int j1 = n - 1; j1 >= 0; j1--) {
    t1[j1] = t1[j1 + 1] + gauss(j1 + 1, n - 1);
    t2[j1] = t2[j1 + 1] + (ll) j1 * (n - (j1 + 1));
  }
  for (int i = 0; i < n; i++) sort(g[i].begin(), g[i].end());
  int p = 0;
  ll ret = 0;
  for (int i = n - 1; i >= 0; i--) {
    while (p < m && e[p].x > i) {
      t4[e[p].y] += b * e[p].x;
      sx += e[p].x;
      sy += e[p].y;
      p1[e[p].x].push_back(e[p].y);
      p2[e[p].y].push_back(e[p].x);
      t3[e[p].x] += c * e[p].y;
      p++;
    }
    for (auto &j : g[i]) {
      ok[j] = 0;
    }
    ll rem = n - (i + 1);
    if (rem >= 2) {
      ll g = rem * (rem - 1) / 2;
      ret += g * (ll) a * i;
    }
    ret += c * t1[i + 1];
    ret += b * t2[i + 1];
    for (auto &j1 : g[i]) {
      ret -= a * i * (n - (j1 + 1));
      ret -= b * j1 * (n - (j1 + 1));
      ret -= c * gauss(j1 + 1, n - 1);
      ret -= a * i * (j1 - (i + 1));
      ret -= b * gauss(i + 1, j1 - 1);
      ret -= c * j1 * (j1 - (i + 1));
      ret += (a * i + b * j1) * (int) p1[j1].size() + t3[j1];
      ret += (a * i + c * j1) * (int) p2[j1].size() + t4[j1];
    }
    int sz = (int) g[i].size();
    if (sz >= 2) {
      ret += i * a * gauss(sz - 1);
    }
    for (int k = 0; k < sz; k++) {
      ret += c * g[i][k] * k;
      ret += b * g[i][k] * (sz - (k + 1));
    }
    ret -= a * i * p;
    ret -= b * sx;
    ret -= c * sy;
  }
  for (int j = 0; j < n; j++) act[j] = 0;
  lim = sqrt(m);
  if (!lim) lim = 1;
  int y = 0;
  for (int i = 0; i < n; i++) {
    if ((int) g[i].size() >= lim) {
      id[i] = ++y;
      for (auto &j : g[i]) {
        bb[y][j] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (id[i]) {
      int now = id[i];
      for (auto &it : all) {
        if (bb[now][it.first] && bb[now][it.second]) {
          ret -= f(i, it.first, it.second);
        }
      }
      continue;
    }
    for (int p = 0; p < (int) g[i].size(); p++) {
      int x = g[i][p], y;
      if (id[x]) {
        for (int p2 = p + 1; p2 < (int) g[i].size(); p2++) {
          y = g[i][p2];
          if (bb[id[x]][y]) {
            ret -= f(i, x, y);
          }
        }
      } else {
        for (auto &j : g[x]) act[j] = 1;
        for (int p2 = p + 1; p2 < (int) g[i].size(); p2++) {
          y = g[i][p2];
          if (act[y]) {
            ret -= f(i, x, y);
          }
        }
        for (auto &j : g[x]) act[j] = 0;
      }
    }
  }
  if (home && n == 100) {
    assert(ret == 2186354564277272);
  }
  cout << ret << "\n";
  return 0;
}