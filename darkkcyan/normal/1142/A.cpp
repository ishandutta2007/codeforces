#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

llong n, k, a, b;

llong cal(llong x) {
  x %= k * n;
  if (x < k * n) x += k * n;
  return n * k / __gcd(n * k, x);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k >> a >> b;
    llong min_ans = LLONG_MAX, max_ans = -1;
    rep(i, 2 * n) {
      llong u = cal(b - a + i * k);
      llong v = cal(b + a + i * k);
      min_ans = min(min_ans, min(u, v));
      max_ans = max(max_ans, max(u, v));
    }
    cout << min_ans << ' ' << max_ans;

    return 0;
}