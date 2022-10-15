#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

mt19937 rng_home(0);
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
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

/**
ret=f(0,1,2)-f(0,1)-f(0,2)-f(1,2)+f(0)+f(1)+f(2)

f(0,1,2)=2^n                                         to do done
f(0,1)=f(1,2)=no of indep sets                       to do
f(0,2)=2^comp conexe                                 to do done
f(0)=f(2)=2^izolat                                   to do
f(1)=0 daca nu e bip / 2^comp daca e bip             to do
**/

const int N = 40;
int n, m, edges[N];
vector<int> g[N];

int nr_componente() {
  vector<bool> vis(n, 0);
  int ret = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    ret++;
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (auto &y : g[x]) {
        if (!vis[y]) {
          q.push(y);
          vis[y] = 1;
        }
      }
    }
  }
  return ret;
}

bool bip() {
  vector<bool> vis(n, 0);
  vector<int> col(n, -1);
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    queue<int> q;
    q.push(i);
    vis[i] = 1;
    col[i] = 0;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (auto &y : g[x]) {
        if (!vis[y]) {
          q.push(y);
          vis[y] = 1;
          col[y] = col[x] ^ 1;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (auto &j : g[i]) {
      if (col[i] == col[j]) return 0;
    }
  }
  return 1;
}

int cnt[1 << (N / 2)];


signed realMain() {
  cin >> n >> m;
  if (m == 0) {
    cout << "0\n";
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    edges[x] |= (1LL << y);
    edges[y] |= (1LL << x);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int ret = (1LL << n) - (1LL << nr_componente()), izolate = 0;
  for (int i = 0; i < n; i++) if (g[i].empty()) izolate++;
  ret += 2 * (1LL << izolate);
  if (bip()) ret += (1LL << nr_componente());
  int sol = 0;
  int n1 = n / 2, n2 = n - n / 2;
  for (int mask = 0; mask < (1LL << n1); mask++) {
    bool indep = 1;
    for (int i = 0; i < n1; i++) {
      if (mask & (1 << i)) {
        if (edges[i] & mask) indep = 0;
      }
    }
    if (indep) {
      cnt[mask]++;
    }
  }
  for (int bit = 0; bit < n1; bit++) {
    for (int i = 0; i < (1 << n1); i++) {
      if (i & (1 << bit)) {
        cnt[i] += cnt[i - (1 << bit)];
      }
    }
  }
  for (int mask = 0; mask < (1LL << n2); mask++) {
    bool indep = 1;
    int nope = 0;
    for (int i = 0; i < n2; i++) {
      if (mask & (1 << i)) {
        nope |= edges[i + n1];
        if (edges[i + n1] & (mask * (1LL << n1))) indep = 0;
      }
    }
    if (indep) {
      nope &= ((1 << n1) - 1);
      nope = (1 << n1) - 1 - nope;
      sol += cnt[nope];
    }
  }
  ret -= 2 * sol;
  cout << ret << "\n";
  return 0;
}