#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

llong solve(llong curans, llong remain, llong x) {
  llong t = min(remain, x / 2);
  curans += t;
  x -= 2 * t;
  return curans + x / 3;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    llong s = 0, ans = 0;
    rep(i, n) {
      llong a; cin >> a;
      tie(s, ans) = make_tuple(s + a, solve(ans, s - ans * 3, a));
    }
    cout << ans;

    return 0;
}