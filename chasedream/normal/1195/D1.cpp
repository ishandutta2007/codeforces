%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int mod = 998244353;
 
ll pw[35], ans;
int n;
 
ll f(int x) {
  ll res = 0LL;
  int pos = 0;
  while (x > 0) {
    int cur = x % 10; x /= 10;
    res = (res + cur * pw[2 * pos]) % mod;
    res = (res + cur * pw[2 * pos + 1]) % mod;
    pos++;
  }
  return res;
}
 
int main() {
  pw[0] = 1;
  for (int i = 1; i < 30; i++) {
    pw[i] = pw[i - 1] * 10LL % mod;
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x; scanf("%d", &x);
    ans = (ans + (ll)n * f(x)) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
//