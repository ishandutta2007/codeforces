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
int n, m, s;
vector<PII> g[maxn];
int c[maxn];
int no;
bool vis[maxn];
void dfs(int x) {
  if (vis[x]) return;
  vis[x] = true;
  for (auto e : g[x]) {
    if (e.S == -1) {
      dfs(e.F);
    } else {
      if (c[e.S] == -1) {
        c[e.S] = x;
        dfs(e.F);
      }
    }
  }
}
void dfs2(int x) {
  if (vis[x]) return;
  vis[x] = true;
  for (auto e : g[x]) {
    if (e.S == -1) {
      dfs2(e.F);
    } else {
      if (c[e.S] == -1) {
        c[e.S] = e.F;
      }
    }
  }
}

PII e[maxn];
int main() {
  scanf("%d%d%d", &n, &m, &s);
  REP(i, m) {
    int t, u, v;
    scanf("%d%d%d", &t, &u, &v);
    if (t == 1) {
      g[u].EB(v, -1);
    } else {
      g[u].EB(v, no);
      g[v].EB(u, no);
      e[no] = {u, v};
      no++;
    }
  }
  {
    memset(c, -1, sizeof c);
    memset(vis, 0, sizeof vis);
    dfs(s);
    int ans = 0;
    REPE(i, 1, n) ans += vis[i];
    printf("%d\n", ans);
    REP(i, no) putchar(e[i].F == c[i] ? '+' : '-');
    puts("");
  }
  {
    memset(c, -1, sizeof c);
    memset(vis, 0, sizeof vis);
    dfs2(s);
    int ans = 0;
    REPE(i, 1, n) ans += vis[i];
    printf("%d\n", ans);
    REP(i, no) putchar(e[i].F == c[i] ? '+' : '-');
    puts("");
  }

  return 0;
}