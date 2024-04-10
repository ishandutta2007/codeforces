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

const int maxn = 1e6 + 10;
int n, m;
vector<LL> l[maxn], s[maxn];
int t[maxn];

LL query(int x, LL h) {
  if (h <= 0) return 0;
  int p = upper_bound(ALL(l[x]), h) - l[x].begin() - 1;
  return (p + 1) * h - s[x][p];
}

int main() {
  R(n, m);
  REPE(i, 2, n) R(t[i]);
  for (int i = n; i >= 1; --i) {
    l[i].PB(0);
    vector<int> b = {i * 2, i * 2 + 1};
    for (int x : b) {
      if (x > n) continue;
      for (int y : l[x]) l[i].PB(y + t[x]);
    }
    sort(ALL(l[i]));
    s[i].resize(SZ(l[i]));
    for (int j = 1; j < SZ(l[i]); ++j)
      s[i][j] = s[i][j - 1] + l[i][j];
  }

  REP(it, m) {
    int a, h;
    R(a, h);
    LL ans = query(a, h);
    while (a > 1) {
      int b = a;
      h -= t[a];
      a >>= 1;
      if (h <= 0) break;
      ans += h;
      int x = a * 2 == b ? a * 2 + 1 : a * 2;
      if (x <= n)
        ans += query(x, h - t[x]);
    }
    printf("%lld\n", ans);
  }

  return 0;
}