#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repe(i, a, b) for (int i = a; i <= (int)b; ++i)
#define rii(a, b) scanf("%d%d", &a, &b)
#define riii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define PB push_back
#define MP make_pair
const int maxn = 100010;
int n, k;
vector<pii> g[maxn];
bool center[maxn] = {};
int sz[maxn] = {};
int dfs(int x, int p = 0) {
  sz[x] = 1;
  rep(i, g[x].size()) {
    int y = g[x][i].first;
    if (y == p || center[y])
      continue;
    sz[x] += dfs(y, x);
  }
  return sz[x];
}
pii find_center(int x, int p, int t) {
  pii r = MP(2147483647, -1);
  int s = 1, m = 0;
  rep(i, g[x].size()) {
    int y = g[x][i].first;
    if (y == p || center[y])
      continue;
    r = min(r, find_center(y, x, t));
    m = max(m, sz[y]);
    s += sz[y];
  }
  m = max(m, t - s);
  r = min(r, MP(m, x));
  return r;
}
typedef long long LL;
LL inv(LL a, LL n) {
  return a < 2 ? a : ((1 - n * 1LL * inv(n % a, a)) / a % n + n) % n;
}
int p[maxn], ip[maxn];

map<int, int> c;
LL r1 = 0, r2 = 0;
void dfs1(int x, int f, int w, int d) {
  r2 += w == 0;
  r1 += c[1LL * (k - w) * ip[d] % k];
  for (auto it : g[x]) {
    if (it.first == f || center[it.first]) continue;
    dfs1(it.first, x, (w * 10LL + it.second) % k, d + 1);
  }
}
void dfs2(int x, int f, int w, int d) {
  r2 += w == 0;
  c[w]++;
  for (auto it : g[x]) {
    if (it.first == f || center[it.first]) continue;
    dfs2(it.first, x, (w + 1LL * it.second * p[d]) % k, d + 1);
  }
}

void go(int x) {
  c.clear();
  for (auto it : g[x]) {
    if (center[it.first]) continue;
    dfs1(it.first, x, it.second % k, 1);
    dfs2(it.first, x, it.second % k, 1);
  }
}

void solve(int x) {
  dfs(x);
  x = find_center(x, -1, sz[x]).second;
  center[x] = true;
  rep(i, g[x].size()) if (!center[g[x][i].first]) solve(g[x][i].first);
  go(x);
  reverse(g[x].begin(), g[x].end());
  go(x);
  center[x] = false;
}
int main() {
  rii(n, k);
  int iv = inv(10, k);
  p[0] = ip[0] = 1;
  repe(i, 1, n) {
    p[i] = 10LL * p[i - 1] % k;
    ip[i] = 1LL * ip[i - 1] * iv % k;
  }
  repe(i, 1, n) g[i].clear();
  repe(i, 1, n - 1) {
    int a, b, c;
    riii(a, b, c);
    a++, b++;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
  }
  solve(1);
  printf("%lld\n", r1 + r2 / 2);
  return 0;
}