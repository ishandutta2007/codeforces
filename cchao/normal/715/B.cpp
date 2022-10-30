#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int maxn = 1010, maxm = 10010;

int n, m, L, s, t;
vector<pair<int, LL&>> g[maxn];
vector<LL*> zero;
int u[maxm], v[maxm];
LL w[maxm];

LL f(LL v) {
  const int Z = zero.size();
  for (int i = 0; i < Z; ++i) {
    *zero[i] = v / Z + (i < v % Z);
  }
  static int inq[maxn] = {};
  static LL d[maxn] = {};
  static queue<int> q;
  fill(d, d + n, 1LL << 55);
  d[s] = 0;
  q.push(s);
  while (q.size()) {
    int x = q.front(); q.pop(); inq[x] = false;
    for (auto it : g[x]) {
      int y = it.first;
      LL w = it.second;
      if (d[x] + w < d[y]) {
        d[y] = d[x] + w;
        if (!inq[y]) {
          inq[y] = true;
          q.push(y);
        }
      }
    }
  }
  return d[t];
}

int main() {
  scanf("%d%d%d%d%d", &n, &m, &L, &s, &t);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%lld", &u[i], &v[i], &w[i]);
    g[u[i]].emplace_back(v[i], w[i]);
    g[v[i]].emplace_back(u[i], w[i]);
    if (w[i] == 0) {
      zero.push_back(&w[i]);
    }
  }
  if (f(zero.size()) > L || f(1LL << 55) < L) {
    puts("NO");
    return 0;
  }
  LL ans = zero.size();
  for (LL t = 1LL << 50; t; t >>= 1)
    if (f(ans + t) <= L)
      ans += t;
  f(ans);
  puts("YES");
  for (int i = 0; i < m; ++i)
    printf("%d %d %lld\n", u[i], v[i], w[i]);
  return 0;
}