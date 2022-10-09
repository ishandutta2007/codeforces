#include<bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

vector<vector<char>> ans;

void process(int u, int v, char cu, char cv) {
  if (u > v) swap(u, v), swap(cu, cv);
  if (u == 1) {
    vector<vector<char>> res(3, vector<char>(50, cu));
    rep(i, v) {
      if (i & 1) res[0][i] = cv;
      else res[2][i] = cv;
    }
    ans.insert(ans.end(), res.begin(), res.end());
    return ;
  }
  vector<vector<char>> res(6, vector<char>(50));
  rep(i, 50) {
    rep(f, 3) res[f][i] = cu;
    rep(f, 3) res[f + 3][i] = cv;
    swap(cu, cv);
  }
  rep(i, 50 - u) {
    if (i & 1) res[2][i] = cu;
    else res[3][i] = cu;
  }
  rep1(i, 50 - v) {
    if (i & 1) res[5][i] = cv;
    else res[0][i] = cv;
  }
  ans.insert(ans.end(), res.begin(), res.end());
}


int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  pair<int, char> a[4];
  rep(i, 4) {
    cin >> a[i].xx;
    a[i].yy = char('A' + i);
  }
  sort(a, a + 4);
  if (a[0].xx == 1) {
    ans.resize(24, vector<char>(50, a[0].yy));
    rep1(i, 3) {
      rep(f, a[i].xx) {
        int x = f % 50;
        int y = (i - 1) * 8 + (f / 50) * 4 + (f & 1) * 2;
        ans[y][x] = a[i].yy;
      }
    }
  } else {
    process(a[0].xx / 2, a[1].xx/2, a[0].yy, a[1].yy);
    process(a[2].xx / 2, a[3].xx / 2, a[2].yy, a[3].yy);
    process(a[0].xx - a[0].xx / 2, a[1].xx - a[1].xx / 2, a[0].yy, a[1].yy);
    process(a[2].xx - a[2].xx / 2, a[3].xx - a[3].xx / 2, a[2].yy, a[3].yy);
  }
  cout << len(ans) << ' ' << 50 << '\n';
  for (auto i: ans) {
    for (auto f: i) cout << f;
    cout << '\n';
  }

  return 0;
}