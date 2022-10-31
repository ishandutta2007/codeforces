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

int n, a[2222];

int main() {
  R(n);
  REP(i, n) R(a[i]);
  int ans = INT_MAX;
  int m = 0;
  REP(i, n) m += a[i] > 1;
  if (m < n) {
    printf("%d\n", m);
    return 0;
  }
  REP(i, n) {
    int g = 0;
    for (int j = i; j <= n; ++j) {
      g = __gcd(a[j], g);
      if (g == 1) {
        ans = min(ans, (j - i) + n - 1);
        break;
      }
    }
  }
  printf("%d\n", ans == INT_MAX ? -1 : ans);

  return 0;
}