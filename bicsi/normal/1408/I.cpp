#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimization ("unroll-loops")
 
#include <bits/stdc++.h>
 
using namespace std;
const int kMod = 998244353;
 
int inv(int b) {
  int e = kMod - 2;
  int r = 1;
  while (e) {
    if (e % 2) r = 1LL * r * b % kMod;
    b = 1LL * b * b % kMod;
    e /= 2;
  }
  return r;
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
 
  int n, k, c; cin >> n >> k >> c;
  vector<int> a(n), mx(n, 0);
  int all = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (int j = 0; j <= k; ++j) {
      mx[i] = max(mx[i], (a[i] ^ (a[i] - j)));
    }
    all ^= a[i];
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int a, int b) {
    return mx[a] < mx[b];
  });
 
  vector<vector<int>> comb(2 * k + 1, 
    vector<int>(2 * k + 1, 0));
  for (int i = 0; i <= 2 * k; ++i) {
    comb[i][0] = comb[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      comb[i][j] = (comb[i - 1][j - 1] + 
        comb[i - 1][j]) % kMod;
    }
  }
 
  vector<vector<long long>> dp(k + 1, vector<long long>(1 << c, 0));
  dp[0][0] = 1;
  int lim = 1;
 
  for (auto it : order) {
    for (int j = k; j >= 0; --j) {
      for (int i = 1; i + j <= k; ++i) {
        int val = (a[it] ^ (a[it] - i)) / 2;
        for (int x = 0; x < lim; ++x) 
          dp[i + j][x ^ val] += comb[i + j][j] * dp[j][x];
      }
    }
    for (int j = 0; j <= k; ++j) {
      int val = (a[it] ^ (a[it] - j)) / 2;
      while (lim <= val) lim *= 2;
    }
    for (int j = 0; j <= k; ++j)
      for (int x = 0; x < lim; ++x)
        dp[j][x] %= kMod;
  }
  
  int sub = 1, invn = inv(n);
  for (int i = 0; i < k; ++i)
    sub = 1LL * sub * invn % kMod;
 
  for (int i = 0; i < (1 << c); ++i) {
    int par = (k + all + i) % 2;
    if (par) cout << 0 << " ";
    else cout << (dp[k][(i ^ all) / 2] * sub) % kMod << " ";
  }
  cout << endl;
 
  return 0;
}