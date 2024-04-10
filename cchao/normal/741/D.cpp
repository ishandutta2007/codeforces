#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;
typedef long long LL;
const int maxn = 5e5 + 10;
int n;
vector<pair<int, int>> g[maxn];
int a[maxn], sz[maxn], heavy[maxn], h[maxn];
int in[maxn], out[maxn], rev[maxn], timer = 0;

int dfs(int x, int m = 0, int he = 1) {
  in[x] = timer++;
  rev[in[x]] = x;
  sz[x] = 1;
  a[x] = m;
  h[x] = he;
  for (auto it : g[x]) {
    sz[x] += dfs(it.first, m ^ it.second, he + 1);
    if (sz[it.first] > sz[heavy[x]])
      heavy[x] = it.first;
  }
  out[x] = timer - 1;
  return sz[x];
}

int c[1 << 22], ans[maxn];
int rh;
void update(int &res, int l, int r) {
  REPE(i, l, r) {
    int t = rev[i];
    int k = a[t];
    if (c[k]) res = max(res, h[t] + c[k] - rh * 2);
    for (int j = 0; j < 22; ++j) {
      int k = a[t] ^ (1 << j);
      if (c[k]) res = max(res, h[t] + c[k] - rh * 2);
    }
  }
  REPE(i, l, r) {
    int t = rev[i];
    c[a[t]] = max(c[a[t]], h[t]);
  }
}

void dfs2(int x, bool clean = true) {
  for (auto it : g[x]) if (it.first != heavy[x]) {
    dfs2(it.first);
    ans[x] = max(ans[x], ans[it.first]);
  }
  if (heavy[x]) {
    dfs2(heavy[x], false);
    ans[x] = max(ans[x], ans[heavy[x]]);
  }
  rh = h[x];
  for (auto it : g[x]) if (it.first != heavy[x]) {
    update(ans[x], in[it.first], out[it.first]);
  }
  update(ans[x], in[x], in[x]);
  if (clean) {
    REPE(i, in[x], out[x]) c[a[rev[i]]] = 0;
  }
}

int main() {
  scanf("%d", &n);
  REPE(i, 2, n) {
    int p;
    char s[4];
    scanf("%d%s", &p, s);
    g[p].emplace_back(i, 1 << (s[0] - 'a'));
  }
  dfs(1);
  dfs2(1);
  REPE(i, 1, n) printf("%d%c", ans[i], " \n"[i == n]);
  return 0;
}