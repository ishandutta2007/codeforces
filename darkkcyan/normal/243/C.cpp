#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

#define maxn 2010
#define cen ((llong)5e9)
#define maxval (cen * 2)

int n;
pair<llong, llong> pos[maxn];
map<char, pair<int, int>> dir = {
  {'L', {-1, 0}},
  {'R', {1, 0}},
  {'U', {0, -1}},
  {'D', {0, 1}}
};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool blocked[maxn][maxn] = {0}, vis[maxn][maxn] = {0};

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    pos[0] = {cen, cen};
    vector<llong> xvals, yvals;
    rep1(i, n) {
      char d;
      llong dis;
      cin >> d >> dis;
      pos[i].xx = pos[i - 1].xx + dir[d].xx * dis;
      pos[i].yy = pos[i - 1].yy + dir[d].yy * dis;
    }
    rep(i, n + 1) {
      rep(f, 2) {
        xvals.push_back(pos[i].xx + f);
        yvals.push_back(pos[i].yy + f);
      }
    }

    xvals.push_back(-1);
    yvals.push_back(-1);
    xvals.push_back(maxval + 1);
    yvals.push_back(maxval + 1);
    sort(all(xvals));
    sort(all(yvals));
    xvals.resize(unique(all(xvals)) - xvals.begin());
    yvals.resize(unique(all(yvals)) - yvals.begin());


    rep(i, n + 1) {
      pos[i].xx = lower_bound(all(xvals), pos[i].xx) - xvals.begin();
      pos[i].yy = lower_bound(all(yvals), pos[i].yy) - yvals.begin();
    }

    rep1(i, n) {
      llong from_x = min(pos[i - 1].xx, pos[i].xx), to_x = max(pos[i - 1].xx, pos[i].xx);
      llong from_y = min(pos[i - 1].yy, pos[i].yy), to_y = max(pos[i - 1].yy, pos[i].yy);
      for (llong u = from_x; u <= to_x; ++u) 
        for (llong v = from_y; v <= to_y; ++v) 
          blocked[u][v] = 1;
    }

    queue<tuple<int, int>> qu;
    vis[0][0] = 1;
    for (qu.push({0, 0}); len(qu); qu.pop()) {
      int x, y; tie(x, y) = qu.front();
      rep(i, 4) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= maxn || ny >= maxn) continue;
        if (vis[nx][ny] || blocked[nx][ny]) continue;
        vis[nx][ny] = 1;
        qu.push({nx, ny});
      }
    }

    llong ans = 0;
    rep(i, maxn) rep(f, maxn) {
      if (vis[i][f]) continue;
      ans += 1ll * (xvals[i + 1] - xvals[i]) * (yvals[f + 1] - yvals[f]);
    }
    cout << ans;


    return 0;
}