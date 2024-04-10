#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n;)
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())
#define ii pair<int, int>

#define maxn 31
int n; llong l;
llong a[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> l;
  rep(i, n) cin >> a[i];
  for (int i = n; i < maxn; ++i) a[i] = LLONG_MAX;
  rep1(i, maxn  - 1) {
    a[i] = min(a[i], a[i - 1] * 2);
  }
  llong s = 0;
  llong ans = LLONG_MAX;
  for (int i = maxn; i --;) {
    if ((~l >> i) & 1) ans = min(ans, s + a[i]);
    else s += a[i];
  }
  ans = min(ans, s);
  cout << ans;

  return 0;
}