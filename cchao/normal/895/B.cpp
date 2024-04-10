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
int n, x, k;
int v[100010];
unordered_map<int, int> m;
int main() {
  R(n, x, k);
  LL ans = 0;
  REP(i, n) R(v[i]);
  sort(v, v + n);
  int t = v[0], cnt = 0;
  REP(i, n) {
    int a = v[i];
    if (a == t) cnt++;
    else cnt = 1, t = a;
    int l = a / x;
    int r = (a + x - 1) / x;
    ans += m[l + 1 - k];
    m[r]++;
    if (k == (a % x == 0)) ans += cnt;
  }
  printf("%lld\n", ans);
  return 0;
}