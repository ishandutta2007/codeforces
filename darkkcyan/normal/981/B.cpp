#include<bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )
#define xx first
#define yy second

map<int, ii> ma;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  rep(i, n) {
    int u, v; cin >> u >> v;
    ma[u].xx = v;
  }
  cin >> n;
  rep(i, n) {
    int u, v; cin >> u >> v;
    ma[u].yy = v;
  }

  llong ans = 0;
  for (auto i: ma) {
    ans += max(i.yy.xx, i.yy.yy);
    //clog <<i.xx << ' ' << max(i.yy.xx, i.yy.yy) << endl;
  }
  cout << ans;

  return 0;
}