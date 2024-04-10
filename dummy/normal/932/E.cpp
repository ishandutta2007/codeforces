#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

const int N = 5050;

long long C[N][N];

long long powmod(long long b, long long p) {
  long long r= 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  C[1][1] = n;
  for (int i = 1; i < k; ++i) {
    for (int j = 1; j <= i; ++j) {
      C[i+1][j] = (C[i+1][j] + C[i][j] * j) % mod;
      C[i+1][j+1] = (C[i+1][j+1] + C[i][j] * (n-j)) % mod; 
    }
  }
  long long ans = 0;
  for (int i = 1; i <= min(k, n); ++i) {
    ans = (ans + C[k][i] * powmod(2, n-i)) % mod;
  }
  ans %= mod;
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}