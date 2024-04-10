#include <bits/stdc++.h>
using namespace std;
 
const int mod = 998244353;
int n, m;
 
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    b >>= 1; a = a * a % mod;
  }
  return res;
}
 
int main() {
  scanf("%d%d", &n, &m);
  printf("%lld\n", qpow(2LL, n + m));
  return 0;
}