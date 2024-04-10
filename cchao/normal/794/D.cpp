#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
using LL = long long;
using PII = pair<int, int>;
#define F first
#define S second

const int maxn = 3e5 + 10;

using ULL = uint64_t;

ULL zh[maxn], h[maxn];
vector<int> g[maxn];
int n, m;
map<ULL, int> ans;
vector<bool> used(maxn * 2);
void dfs(int x, int val) {
  ans[h[x]] = val;
  used[val] = true;
  set<ULL> s;
  for (int y : g[x]) {
    if (ans.count(h[y])) {
      if (abs(ans[h[y]] - val) > 1) {
        puts("NO");
        exit(0);
      }
      continue;
    }
    s.insert(h[y]);
    if (s.size() > 2) {
      puts("NO");
      exit(0);
    }
  }
  for (int y : g[x]) {
    if (ans.count(h[y])) continue;
    int nv;
    if (!used[val + 1]) {
      nv = val + 1;
    } else if (!used[val - 1]) {
      nv = val - 1;
    } else {
      puts("NO");
      exit(0);
    }
    dfs(y, nv);
  }
}

int main() {
  scanf("%d%d", &n, &m);
  REPE(i, 1, n) {
    zh[i] = rand();
    zh[i] = (zh[i] << 20) ^ rand();
    zh[i] = (zh[i] << 20) ^ rand();
    h[i] = zh[i];
  }
  REP(i, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    h[u] ^= zh[v];
    h[v] ^= zh[u];
    g[u].PB(v);
    g[v].PB(u);
  }
  dfs(1, maxn);
  puts("YES");
  REPE(i, 1, n) printf("%d%c", ans[h[i]], " \n"[i == n]);
  return 0;
}