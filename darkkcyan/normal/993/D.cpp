#include<bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())

#define maxn 60
#define maxp 110
llong dp[maxn][maxn][maxp * maxn];
int n;

int a[maxn];
map<int, vector<int>> ma;

void mini(llong& u, llong v) {
  u = min(u, v);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
  cin >> n;
  rep1(i, n) {
    cin >> a[i];
  }
  rep1(i, n) {
    int u; cin >> u;
    ma[a[i]].push_back(u);
  }
  rep(g, len(ma) + 1) rep(i, n + 1) rep(f, maxp * n) dp[g][i][f] = LLONG_MAX;
  dp[0][0][0] = 0;
  int x = 0;
  for (auto i: vector<pair<int, vector<int>>>(ma.rbegin(), ma.rend())) {
    ++x;
    sort(i.yy.rbegin(), i.yy.rend());
    rep1(f, len(i.yy) - 1) i.yy[f] += i.yy[f - 1];

    rep(f, len(i.yy) + 1) {
      rep(g, n + 1) rep(h, n * maxn) {
        if (g < f) continue;
        if (dp[x - 1][g][h] == LLONG_MAX) continue;
        llong open = len(i.yy) - f;
        int inc = open ? i.yy[open - 1] : 0;
        //clog << i.yy[0] << ' ' << i.yy[1] << endl;
        //clog << "UP " << i.xx << ' ' << g-f + open << ' ' << h + inc << ' ' << f << ' ' << inc << endl;
        mini(dp[x][g - f + open][h + inc], dp[x - 1][g][h] + i.xx * open);
      }
    }
  }
  llong ans = LLONG_MAX;
  rep(f, n + 1)
  rep(i, n * maxp) {
    if (dp[len(ma)][f][i] == LLONG_MAX) continue;
    ans = min(ans, (llong)(ceil((double)dp[len(ma)][f][i] * 1000.0 / i)));
  }
  cout << ans;
  return 0;
}