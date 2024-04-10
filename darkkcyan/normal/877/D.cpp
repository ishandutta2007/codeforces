#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define x1 safdasfjs
#define y1 sfasafasar
#define y2 dasgb
#define x2 fgdfsd

#define maxn 1010
int n, m, k;
bool a[maxn][maxn];
int x1, y1, x2, y2;
int d[maxn][maxn];

set<int> row[maxn], col[maxn];
bool vis[maxn][maxn];
void mark(int r, int c) {
  int td = d[r][c];
  for (auto it = row[r].lower_bound(c); it != row[r].end() and *it - c <= k; it = row[r].erase(it)) {
    // clog << *it << endl;
    if (a[r][*it] == 1) break;
    d[r][*it] = min(d[r][*it], td + 1);
  }
  // clog << (row[r].lower_bound(c) == row[r].begin()) << endl;
  for (auto it = row[r].lower_bound(c); it != row[r].begin() and c - (*--it) <= k; it = row[r].erase(it)) {
    // clog << *it << endl;
    if (a[r][*it] == 1) break;
    d[r][*it] = min(d[r][*it], td + 1);
  }
  for (auto it = col[c].lower_bound(r); it != col[c].end() and *it - r <= k; it = col[c].erase(it)) {
    // clog << *it << endl;
    if (a[*it][c] == 1) break;
    d[*it][c] = min(d[*it][c], td + 1);
  }
  for (auto it = col[c].lower_bound(r); it != col[c].begin() and r - (*--it) <= k; it = col[c].erase(it)) {
    // clog << *it << endl;

    if (a[*it][c] == 1) break;
    d[*it][c] = min(d[*it][c], td + 1);
  }

}

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};
void bfs() {
  queue<ii> qu;
  memset(d, -1, sizeof(d));
  rep(i, n) rep(f, m) {
    row[i].insert(f);
    col[f].insert(i);
    d[i][f] = INT_MAX;
    vis[i][f] = 0;
  }
  row[x1].erase(y1);
  col[y1].erase(x1);
  vis[x1][y1] = 1;
  d[x1][y1] = 0;
  for (qu.push({x1, y1}); len(qu); qu.pop()) {
    int r = qu.front().xx, c = qu.front().yy;
    // clog << r << ' ' << c << ' ' << d[r][c] << endl;
    mark(r, c);
    rep(i, 4) {
      int tr = r + dr[i], tc = c + dc[i];
      if (tr < 0 or tr >= n or tc < 0 or tc >= m) continue;
      if (vis[tr][tc] or a[tr][tc]) continue;
      vis[tr][tc] = 1;
      qu.push({tr, tc});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m >> k;
  rep(i, n) {
    string s; cin >> s;
    rep(f, m) {
      a[i][f] = s[f] == '#';
    }
  }
  cin >> x1 >> y1 >> x2 >> y2;
  --x1, --y1, --x2, --y2;
  bfs();
  if (d[x2][y2] == INT_MAX) cout << -1;
  else cout << d[x2][y2];
  
  return 0;
}