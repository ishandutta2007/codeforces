#include <bits/stdc++.h>

using namespace std;
const int kMod = 1e9 + 7;

struct ModInt {
  long long n;

  ModInt(long long n = 0) : n(n % kMod) {}
  ModInt operator+(const ModInt& oth) { return n + oth.n; }
  ModInt operator-(const ModInt& oth) { return n - oth.n; }
  ModInt operator*(const ModInt& oth) { return n * oth.n; }
  long long get() { return n < 0 ? n + kMod : n; }
};

ModInt lgpow(ModInt b, int e) {
  ModInt r;
  for (r = 1; e; e /= 2, b = b * b)
    if (e % 2) r = r * b;
  return r;
}
ModInt inv(ModInt x) { return lgpow(x, kMod - 2); }

int main() {
  int n, m; cin >> n >> m;
  vector<ModInt> fact(n + 1, 1);
  for (int i = 1; i <= n; ++i) {
    fact[i] = fact[i - 1] * i;
  }
  vector<ModInt> invfact(n + 1, 1);
  invfact[n] = inv(fact[n]);
  for (int i = n - 1; i >= 1; --i) {
    invfact[i] = invfact[i + 1] * (i + 1);
  }

  auto choose = [&](int n, int k) {
    return fact[n] * invfact[k] * invfact[n - k];
  };
  
  ModInt invm = inv(m);
  ModInt mm = invm * (m - 1);
  ModInt pw = 1;

  ModInt ans = 1;
  for (int d = 0; d < n; ++d) {
    ModInt res = choose(n, n - d - 1);
    res = res * pw;
    pw = pw * mm;
    ans = ans + res;
  }

  for (int i = 0; i < n; ++i)
    ans = ans * m;
  cout << ans.get() << endl;

  return 0;
}