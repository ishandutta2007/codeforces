#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long powmod(long long base, long long pw) {
  long long ret = 1;
  while(pw) {
    if(pw & 1)
      ret = (ret * base) % mod;
    base = (base*base) % mod;
    pw >>= 1;
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  long long ans  = powmod(27, n) - powmod(7, n);
  ans %= mod;
  if(ans < 0) ans += mod;
  cout << ans << "\n";
  return 0;

}