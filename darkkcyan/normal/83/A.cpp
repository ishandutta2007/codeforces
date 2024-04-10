#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int u; cin >> u;
  llong cnt = 1;
  llong ans = 0;
  rep1(i, n - 1) {
    int v; cin >> v;
    if (u != v) {
      ans += cnt * (cnt + 1) / 2;
      cnt = 0;
    }
    ++cnt;
    u = v;
  }
  ans += cnt * (cnt + 1) / 2;
  cout << ans;
  
  
  return 0;
}