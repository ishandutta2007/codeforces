#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define rem ((llong)1e9+7)
llong mpow(llong b, llong m) {
  llong ans = 1; for (; m; m >>= 1, (b *= b) %= rem)
    if (m & 1) (ans *= b) %= rem;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  llong n;
  cin >> n;
  llong ans = mpow(3, 3 * n) - mpow(7, n);
  if (ans < 0) ans += rem;
  cout << ans;
  
  return 0;
}