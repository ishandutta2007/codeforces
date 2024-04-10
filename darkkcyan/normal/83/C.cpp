#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<char, char>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 52 
int n, m, k;
string a[maxn];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};
int sr, sc, tr, tc;
string ans(maxn * maxn, ' ');
bool allowed['z' + 1] = {0};
bool vis[maxn][maxn];
int d[maxn][maxn];
void bfs() {
  for (char i = 'a'; i <= 'z'; ++i)
    if (allowed[(int)i]) clog << i;
  clog << endl;
  static queue<ii> qu;
  memset(d, -1, sizeof(d));
  d[tr][tc] = 0;
  for (qu.push({tr, tc}); qu.size(); qu.pop()) {
    int r = qu.front().xx, c = qu.front().yy;
    rep(i, 4) {
      int tr = r + dr[i], tc = c + dc[i];
      if (tr < 0 or tr >= n or tc < 0 or tc >= m) continue;
      if (d[tr][tc] != -1) continue;
      if (a[tr][tc] == 'S' or allowed[(int)a[tr][tc]]) d[tr][tc] = d[r][c] + 1;
      if (!allowed[(int)a[tr][tc]]) continue;
      qu.push({tr, tc});
    }
  }
  if (d[sr][sc] == -1) return;
  static vector<ii> curlay, nxtlay;
  curlay.clear(); nxtlay.clear();
  curlay.push_back({sr, sc});
  string tans = "";
  memset(vis, 0, sizeof(vis));
  rep(i, d[sr][sc] - 1) {
    char minchar = 'z' + 1;
    for (; curlay.size(); curlay.pop_back()) {
      int r = curlay.back().xx, c = curlay.back().yy;
      // clog << r << ' ' << c << endl;
      rep(i, 4) {
        int tr = r + dr[i], tc = c + dc[i];
        if (tr < 0 or tr >= n or tc < 0 or tc >= m) continue;
        if (vis[tr][tc]) continue;
        if (a[tr][tc] != 'S' and a[tr][tc] != 'T' and !allowed[(int)a[tr][tc]]) continue;
        if (d[tr][tc] != d[r][c] - 1) continue;
        // clog << tr << ' ' << tc << endl;
        vis[tr][tc] = 1;
        if (a[tr][tc] < minchar) {
          minchar = a[tr][tc];
          nxtlay.clear(); 
        }
        if (a[tr][tc] == minchar) nxtlay.push_back({tr, tc});
      }
    }
    tans += minchar;
    curlay = nxtlay;
    nxtlay.clear();
  }
  // clog << tans << endl;
  if (len(ans) < len(tans)) return;
  if (len(ans) > len(tans) or ans > tans) ans = tans;
}

void process(int i = 'a') {
  if (k == 0) {
    bfs();
    return;
  }
  if (i > 'z') return;
  rep(t, 2) {
    k -= t;
    allowed[i] = t;
    process(i + 1);
    allowed[i] = 0;
    k += t;
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m >> k;
  rep(i, n) cin >> a[i];
  rep(i, n) rep(f, m) {
    if (a[i][f] == 'S') sr = i, sc = f;
    if (a[i][f] == 'T') tr = i, tc = f;
  }
  // clog << sr << ' ' << sc << ' ' << tr << ' ' << tc << endl;
  process();
  if (len(ans) > m * n) ans = "-1";
  cout << ans;
  
  return 0;
}