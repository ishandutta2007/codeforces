#include <bits/stdc++.h>
using namespace std;
#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())

#define maxn 101010
int n, k, x;
int a[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> x >> k;
  rep(i, n) cin >> a[i];
  sort(a, a + n);
  llong ans = 0;
  rep(i, n) {
    llong p = a[i] / x - k;
    llong u = p * x + 1, v = min(u + x - 1, (llong)a[i]);
    //clog << a[i] << ' ' << u << ' ' << v << endl;
    ans += upper_bound(a, a + n, v) - lower_bound(a, a + n, u);
  }
  cout << ans;

  return 0;
}