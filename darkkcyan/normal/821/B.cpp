#include<bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define sz(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )

llong m, b;

llong cal(llong x, llong y) {
  #define sum(n) (n * (n + 1) / 2)
  return sum(x) * (y + 1) + sum(y) * (x + 1);
}

llong findx(llong y) { return m * (b - y); }
llong findy(llong x) { return (-x + b * m) / m; }


int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> m >> b;
  llong ans = 0;
  rep(y, b) {
    llong x = findx(y);
    ans = max(ans, cal(x, y));
  }

  rep(x, m * b) {
    llong y = findy(x);
    ans = max(ans, cal(x, y));
  }
  cout << ans;

  return 0;
}