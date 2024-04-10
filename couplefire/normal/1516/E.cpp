#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int inf = 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;
mt19937 myrand(chrono::steady_clock::now().time_since_epoch().count());

int n, k;

int A[405];
int rev[405], f[405];
int dp[405][405];

int binpow(int a, int b) {
  if (b == 0) return 1;
  if (b % 2) return a * 1ll * binpow(a, b - 1) % mod;
  int t = binpow(a, b / 2);
  return t * 1ll * t % mod;
}

int C(int n, int k) {
  int answ = 1;
  for (int i = 1; i <= k; i++) {
    answ = answ * 1ll * (n - i + 1) % mod;
    answ = answ * 1ll * rev[i] % mod;
  }
  return answ;
}

int main() {
  f[0] = 1;
  for (int i = 1; i <= 400; i++) {
    rev[i] = binpow(i, mod - 2);
    f[i] = f[i - 1] * 1ll * i % mod;
  }

  cin >> n >> k;

  dp[0][0] = 1;
  for (int i = 2; i <= 401; i++) {
    for (int j = 2; j <= i; j++) {
      int gorc = C(i - 1, j - 1) * 1ll * f[j - 1] % mod;
      for (int h = 1; h <= i; h++) {
        dp[i][h] += gorc * 1ll * dp[i - j][h - 1] % mod;
        dp[i][h] %= mod;
      }
    }
  }

  for (int i = 1; i <= k; i++) {
    int answ = 0;
    for (int j = 0; j <= min(n, 401); j++) {
      int t = C(n, j);
      for (int h = 0; h <= j; h++) {
        if (j - h <= i && (j - h) % 2 == i % 2) {
          answ += t * 1ll * dp[j][h] % mod;
          answ %= mod;
        }
      }
    }
    cout << answ << " ";
  }
  cout << endl;
  return 0;
}