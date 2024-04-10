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

const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int n;
int t[155];
bool v[310][310];
bool d[2][310][310][8];

int main() {
  scanf("%d", &n);
  REP(i, n) scanf("%d", &t[i]);
  v[155][155] = true;
  int cur = 0;
  d[cur][155][155][0] = true;
  REP(it, n) {
    int nxt = cur ^ 1;
    memset(d[nxt], 0, sizeof(d[nxt]));
    REP(i, 310) REP(j, 310) REP(k, 8) if (d[cur][i][j][k]) {
      int x = i, y = j;
      REP(l, t[it]) {
        v[x][y] = true;
        x += dx[k];
        y += dy[k];
      }
      x -= dx[k];
      y -= dy[k];
      {
        int nd = (k + 1) & 7;
        d[nxt][x + dx[nd]][y + dy[nd]][nd] = true;
      }
      {
        int nd = (k + 7) & 7;
        d[nxt][x + dx[nd]][y + dy[nd]][nd] = true;
      }
    }
    cur = nxt;
  }
  int ans = 0;
  REP(i, 310) REP(j, 310) ans += v[i][j];
  printf("%d\n", ans);

  return 0;
}