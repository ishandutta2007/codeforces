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

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m;
char g[1010][1010];

bool ans = false;
bool v[1010][1010][4][3];

void dfs(int x, int y, int d, int s) {
  if (s > 2) return;
  if (v[x][y][d][s] || ans) return;
  if (g[x][y] == 'T') { ans = true; return; }
  v[x][y][d][s] = true;
  REP(t, 4) {
    int ns = s + (d != t);
    int tx = x + dx[t];
    int ty = y + dy[t];
    if (tx < 0 || ty < 0 || tx == n || ty == m || g[tx][ty] == '*') continue;
    dfs(tx, ty, t, ns);
  }
}

int main() {
  scanf("%d%d", &n, &m);
  REP(i, n) scanf("%s", g[i]);
  REP(i, n) REP(j, m) if (g[i][j] == 'S') {
    REP(d, 4) dfs(i, j, d, 0);
    puts(ans ? "YES" : "NO");
    return 0;
  }
  return 0;
}