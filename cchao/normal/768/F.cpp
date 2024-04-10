#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
using LL = long long;
using PII = pair<int, int>;
#define F first
#define S second
const LL mod = 1000000007;
LL inv(LL a, LL n = mod) {
  return a < 2 ? a : ((1 - n * 1LL * inv(n % a, a)) / a % n + n) % n;
}

const int maxn = 1e5 + 10;
LL fac[maxn], iv[maxn];
LL C(LL a, LL b) {
  return fac[a] * (iv[b] * iv[a - b] % mod) % mod;
}

LL way(LL a, LL b) {
  if (b < 0) return 0;
  return C(a + b - 1, b);
}

int main() {
  fac[0] = iv[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    fac[i] = fac[i - 1] * i % mod;
    iv[i] = inv(fac[i]);
  }
  LL f, w, h;
  cin >> f >> w >> h;
  if (f == 0) {
    puts(w > h ? "1" : "0");
    return 0;
  }
  if (w == 0) {
    puts("1");
    return 0;
  }
  LL all = 0;
  LL good = 0;
  REPE(i, 1, w) {
    LL t = (way(i, f - i) * 2 + way(i + 1, f - (i + 1))) % mod;
    if (i > 1) t = (t + way(i - 1, f - (i - 1))) % mod;
    all += way(i, w - i) * t;
    good += way(i, w - h * i - i) * t;
    all %= mod;
    good %= mod;
    // cout << i << ": " << good << ' ' << all << endl;
  }
  cout << good * inv(all) % mod << endl;
  return 0;
}