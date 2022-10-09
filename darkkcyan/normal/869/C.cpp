#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )
#define rem ((llong) 998244353)

#define maxn 5050
llong a, b, c;
llong fac[maxn], rfac[maxn];

llong mpow(llong b, llong m) {
  llong ans = 1;
  for (; m > 0; m >>= 1, (b *= b) %= rem)
    if (m & 1) (ans *= b) %= rem;
  return ans;
}

llong comb(llong n, llong k) {
  return fac[n] * rfac[k] % rem * rfac[n - k] % rem;
}

llong pro(int l, int r) {
  return fac[r] * rfac[l - 1] % rem;
}

llong cal(llong u, llong v) {
  if (u > v) swap(u, v);
  llong ans = 1;
  rep1(i, u) {
    llong t = comb(u, i);
    (t *= pro(v - i + 1, v)) %= rem;
    (ans += t) %= rem;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  fac[0] = 1;
  rep1(i, maxn - 1) (fac[i] = fac[i - 1] * i) %= rem;
  rep(i, maxn) rfac[i] = mpow(fac[i], rem - 2);
  
  cin >> a >> b >> c;
  llong ans = cal(a, b);
  (ans *= cal(b, c)) %= rem;
  (ans *= cal(c, a)) %= rem;
  cout << ans;
  
  return 0;
}