#include <bits/stdc++.h>

using namespace std;
const int N = 3e5 + 6;
long long powmod(long long b, long long p, long long m) {
  long long r = 1;
  for (; p; p >>= 1, b = b*b % m)
    if (p & 1) r = r * b % m;
  return r;
}
long long pr[] = {31, 23};
long long md[] = { (long long)(1e9 + 7), (long long)(1e9 + 9) };

vector< int > g[N];
long long h[N][2];
int p[N], c[N];

bool dfs(int v, int par = -1, int cc = 1) {
  if (c[v] != 0)
    return false;
  c[v] = cc;
  int cnt = 0;
  for (int u : g[v]) if (p[u] == -1 && u != v && u != par) {
    cnt++;
    if (!dfs(u, v, cc+1)) return false;
  }
  return cnt <= 1;
}

int main() {
  memset(p, -1, sizeof p);
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  map< pair< long long, long long> , int > mp;
  for (int i = 1; i <= n; ++i) {
    g[i].push_back(i);
    sort(g[i].begin(), g[i].end());
    g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
    for (int j = 0; j < 2; ++j) {
      long long res = 0, cur = 1;
      for (int v : g[i]) {
        res = (res + cur * v) % md[j];
        cur = (cur * pr[j]) % md[j];
      }
      if (res < 0)
        res += md[j];
      h[i][j] = res;
    }
    pair< long long, long long > hs = {h[i][0], h[i][1]};
    if (mp.count(hs)) {
      p[i] = mp[hs];
    }
    else
      mp[hs] = i;
  }
  int r = 0;
  for (int i = 1; i <= n; ++i) if (p[i] == -1) {
    int k = 0;
    for (int v : g[i]) if (v != i && p[v] == -1) {
      k++;
    }
    if (k <= 1) {
      r = i;
      break;
    }
  }
  if (!r || !dfs(r))
    puts("NO");
  else {
    puts("YES");
    for (int i = 1; i <= n; ++i) {
      if (p[i] != -1) c[i] = c[p[i]];
      printf("%d ", c[i]);
    }
    printf("\n");
  }
  return 0;
}