#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

llong a[14];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  rep(i, 14) cin >> a[i];
  llong ans = 0;
  rep(i, 14) {
    if (a[i] == 0) continue;
    llong b[14];
    memcpy(b, a, sizeof(b));
    llong t = a[i] / 14;
    llong s = a[i] % 14;
    b[i] = 0;
    rep(f, 14) b[f] += t;
    rep1(f, s) b[(i + f) % 14] ++;
    llong res = 0;
    rep(f, 14) res += (~b[f] & 1) * b[f];
    ans = max(ans, res);
  }
  cout << ans;

  return 0;
}