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
void R(int &x) { scanf("%d", &x); }
void R(LL &x) { scanf("%lld", &x); }
void R(double &x) { scanf("%lf", &x); }
template <typename T> void R(T &t) { cin >> t; }
template <typename T> void R(vector<T> &ar) {
  for (auto &it : ar)
    R(it);
}
template <typename T, typename... Args> void R(T &t, Args &... args) {
  R(t);
  R(args...);
}

const int p[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int n, a[77], b[77], c[77], d[100010];
const int mod = 1000000000 + 7;

int f(int x) {
  int t = 0;
  REP(j, 19) {
    while (x % p[j] == 0) {
      x /= p[j];
      t ^= (1 << j);
  }
  }
  return t;
}
LL ans = 0;
LL av = 1;

unordered_map<int, int> m;
void f(PII *a, int n, bool fg) {
  REP(i, (1 << n)) {
    LL r = 1;
    int t = 0;
    REP(j, n) {
      r = r * d[a[j].S - 1] % mod;
      if (i & (1 << j)) t ^= b[a[j].F];
    }
    if (!fg) m[t] = (m[t] + r) % mod;
    else ans = (ans + r * m[t]) % mod;
  }
}

int main() {
  d[0] = 1;
  for (int i = 1; i < 100010; ++i)
    d[i] = d[i - 1] * 2 % mod;
  REPE(i, 1, 70) {
    b[i] = f(i);
    int t = 1;
    REP(j, 19) if (b[i] & (1 << j)) t *= p[j];
    c[i] = t;
  }
  R(n);
  REP(i, n) {
    int x;
    R(x);
    x = c[x];
    if (x == 1) {
      av = av * 2 % mod;
      continue;
    }
    a[x]++;
  }
  REP(i, 19) {
    int x = p[i];
    if (a[x] && x * 2 > 70) {
      av = av * d[a[x] - 1] % mod;
      a[x] = 0;
    }
  }
  PII t[77];
  int m = 0;
  REPE(i, 1, 70) if (a[i])
    t[m++] = {i, a[i]};

  f(t, m / 2, false);
  f(t + m / 2, m - m / 2, true);

  ans = ans * av % mod;
  ans = ans == 0 ? mod - 1 : ans - 1;
  printf("%lld\n", ans);
  return 0;
}