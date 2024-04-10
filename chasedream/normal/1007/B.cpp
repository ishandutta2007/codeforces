%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 100005;
ll f[N], a, b, c;

void pre(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i)
      f[j]++;
  }
}

ll gcd(ll a, ll b) {
  return b ? gcd(b, a % b) : a;
}

int main() {
  pre(1e5);
  int T; scanf("%d", &T);
  while (T--) {
    scanf("%lld%lld%lld", &a, &b, &c);
    ll ab, bc, ac;
    ab = gcd(a, b); bc = gcd(b, c); ac = gcd(a, c);
    
    ll fy = gcd(ab, c);
    ll ans1 = f[a] * f[b] * f[c];
    ll ans2 = f[ab] * (f[ab] - 1) / 2LL * f[c];
    ll ans3 = f[bc] * (f[bc] - 1) / 2LL * f[a];
    ll ans4 = f[ac] * (f[ac] - 1) / 2LL * f[b];
    ll ans5 = f[fy] * (f[fy] - 1) + f[fy] * (f[fy] - 1) * (f[fy] - 2) / 6LL * 4LL;
    ll ans6 = f[fy] * (f[fy] - 1) / 2LL * (f[ab] - f[fy]);
    ll ans7 = f[fy] * (f[fy] - 1) / 2LL * (f[bc] - f[fy]);
    ll ans8 = f[fy] * (f[fy] - 1) / 2LL * (f[ac] - f[fy]);
    ll ans9 = (f[ab] - f[fy]) * (f[bc] - f[fy]) * (f[ac] - f[fy]);
    printf("%lld\n", ans1 - ans2 - ans3 - ans4 + ans5 + ans6 + ans7 + ans8 - ans9);
  }
  return 0;
}