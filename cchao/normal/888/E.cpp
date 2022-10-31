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

int m;

int a[55];
int ans;
set<int> s;
void f(int n, bool fg) {
  REP(i, n) {
    R(a[i]);
    a[i] %= m;
  }
  REP(i, (1 << n)) {
    int sum = 0;
    REP(j, n) {
      if (i & (1 << j)) {
        sum += a[j];
        if (sum >= m) sum -= m;
      }
    }
    ans = max(ans, sum);
    if (!fg) s.insert(sum);
    else {
      assert(sum < m);
      auto it = s.lower_bound(m - sum);
      if (it != s.begin()) {
        --it;
        ans = max(ans, sum + *it);
      }
    }
  }
}


int main() {
  int n;
  R(n, m);
  f(n / 2, false);
  f(n - n / 2, true);
  printf("%d\n", ans);
  return 0;
}