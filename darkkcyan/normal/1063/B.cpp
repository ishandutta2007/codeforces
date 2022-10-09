#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())
/*{{{*/
template<class x> ostream& operator<<(ostream& cout, const vector<x>& a) {
  cout << "[";
  if (len(a)) cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i];
  return cout << "]";
}

template<class u, class v> ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}/*}}}*/

#define maxn 2020
int n, m, r, c, x, y;
char b[maxn][maxn];
int id[maxn][maxn] = {0};
vector<int> gr[maxn * maxn];
ii dis[2][maxn * maxn];
int cnt[maxn * maxn] = {0};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m >> r >> c >> x >> y;
  rep1(i, n) cin >> (b[i] + 1);
  int cur = 1;
  rep1(f, m) {
    ++cur;
    rep1(i, n) {
      if (b[i][f] == '.') {
        id[i][f] = cur;
        cnt[cur]++;
      }
      else cur++;
    }
  }

  rep1(i, cur) {
    dis[0][i] = dis[1][i] = {-1, -1};
  }

  rep1(f, m - 1) {
    ii last(-1, -1);
    rep1(i, n) {
      if (id[i][f] == 0 or id[i][f + 1] == 0) continue;
      if (last != ii(id[i][f], id[i][f + 1])) {
        last = ii(id[i][f], id[i][f + 1]);
        gr[last.xx].push_back(last.yy);
        gr[last.yy].push_back(last.xx);
      }
    }
  }

  //rep1(i, n) {
    //clog << vector<int>(id[i] + 1, id[i] + 1 + m) << endl;
  //}



  int root = id[r][c];
  queue<ii> qu;
  qu.push(ii(0, root));
  dis[0][root] = dis[1][root] = ii(x, y);
  for (; len(qu); qu.pop()) {
    bool udir = qu.front().xx;
    int u = qu.front().yy;
    //clog << qu.front() << ' ' << dis[udir][u] << endl;
    for (auto v: gr[u]) {
      bool dir = v > u;
      ii t = dis[udir][u];
      --(!dir ? t.xx : t.yy);
      if (t.xx < 0 || t.yy < 0) continue;
      if (dis[dir][v].xx != -1) continue;
      dis[dir][v] = t;
      qu.push({dir, v});
    }
  }

  int ans = 0;
  rep1(i, cur) {
    if (dis[0][i].xx != -1 || dis[1][i].xx != -1) ans += cnt[i];
  }
  cout << ans;

  return 0;

}