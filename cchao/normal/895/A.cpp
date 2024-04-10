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

int n, a[1111];;

int main() {
  R(n);
  int ans = 360;
  REP(i, n) {
    R(a[i]);
    a[i + n] = a[i];
  }
  REP(i, n) {
    int s = 0;
    REP(j, n) {
      s += a[i + j];
      ans = min(ans, abs(s+s - 360));
    }
  }
  printf("%d\n", ans);
  return 0;
}