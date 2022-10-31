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
const int maxn = 1e5 + 10;
int n, m, p[maxn], c[maxn];
int f(int x) { return x == p[x] ? x : p[x] = f(p[x]); }

int main() {
  R(n, m);
  REPE(i, 1, n) {
    p[i] = i;
    R(c[i]);
  }
  REP(i, m) {
    int u, v;
    R(u, v);
    p[f(u)] = f(v);
  }
  unordered_map<int, int> a;
  REPE(i, 1, n) {
    int x = f(i);
    if (!a.count(x) || c[i] < a[x])
      a[x] = c[i];
  }
  LL ans = 0;
  for (auto it : a) ans += it.S;
  printf("%lld\n", ans);
  return 0;
}