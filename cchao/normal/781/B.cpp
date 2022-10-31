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

const int maxn = 2010;
struct SCC {
  int n;
  vector<int> g[maxn];
  int pre[maxn], low[maxn], timer;
  int sccno[maxn], scc_cnt;
  stack<int> S;
  int dfs(int x) {
    pre[x] = low[x] = ++timer;
    S.push(x);
    for (int y : g[x]) {
      if (!pre[y])
        low[x] = min(low[x], dfs(y));
      else if (!sccno[y])
        low[x] = min(low[x], pre[y]);
    }
    if (low[x] == pre[x]) {
      scc_cnt++;
      for (;;) {
        int t = S.top();
        S.pop();
        sccno[t] = scc_cnt;
        if (t == x)
          break;
      }
    }
    return low[x];
  }
  void solve() {
    memset(pre, 0, sizeof pre);
    memset(sccno, 0, sizeof sccno);
    timer = scc_cnt = 0;
    for (int i = 0; i < n; ++i)
      if (!pre[i])
        dfs(i);
  }
  void init(int n) {
    this->n = n;
    for (int i = 0; i < n; ++i)
      g[i].clear();
  }
};

struct TwoSAT {
  int n, sol[maxn];
  SCC scc;
  bool solve() {
    scc.solve();
    for (int i = 0; i < n; ++i) {
      int no0 = scc.sccno[i * 2];
      int no1 = scc.sccno[i * 2 + 1];
      if (no0 == no1) return false;
      sol[i] = no0 > no1;
    }
    return true;
  }
  void init(int n) {
    this->n = n;
    scc.init(n * 2);
  }
  void add_or(int x, int xval, int y, int yval) {
    x = x * 2 + xval;
    y = y * 2 + yval;
    scc.g[x ^ 1].push_back(y);
    scc.g[y ^ 1].push_back(x);
  }
} sol;

char a[22], b[22];

int n;
char s[1010][2][4];

int main() {
  scanf("%d", &n);
  REP(i, n) {
    scanf("%s%s", a, b);
    s[i][0][0] = s[i][1][0] = a[0];
    s[i][0][1] = s[i][1][1] = a[1];
    s[i][0][2] = a[2];
    s[i][1][2] = b[0];
  }
  sol.init(n);
  REP(i, n) REP(j, i) {
    REP(k, 2) REP(l, 2) if (strcmp(s[i][k], s[j][l]) == 0) {
      sol.add_or(i, k ^ 1, j, l ^ 1);
    }
  }
  REP(i, n) REP(j, n) if (i != j) {
    if (strcmp(s[i][0], s[j][0]) == 0) {
      sol.scc.g[i * 2 + 1].push_back(j * 2 + 1);
    }
  }
  if (!sol.solve()) {
    puts("NO");
  } else {
    puts("YES");
    REP(i, n)
      puts(sol.sol[i] == 0 ? s[i][0] : s[i][1]);
  }
  return 0;
}