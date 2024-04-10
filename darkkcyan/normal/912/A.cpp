#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define ii pair<int, int>

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  llong a, b, x, y, z; cin >> a >> b >> x >> y >> z;
  llong u = x * 2 + y, v = y + z * 3;
  llong ans = max(0LL, u - a) + max(0LL, v - b);
  cout << ans;

  return 0;
}