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

int n, m;
vector<vector<int>> a, dp;
vector<int> mx;
int main() {
  R(n, m);
  a = vector<vector<int>>(n, vector<int>(m));
  dp = vector<vector<int>>(n, vector<int>(m));
  mx = vector<int>(n);
  REP(i, n) REP(j, m) R(a[i][j]);
  REP(j, m) dp[0][j] = 1;
  mx[0] = 1;
  for (int i = 1; i < n; ++i) {
    REP(j, m) {
      dp[i][j] = a[i][j] >= a[i - 1][j] ? dp[i - 1][j] + 1 : 1;
      mx[i] = max(mx[i], dp[i][j]);
    }
  }
  int q;
  R(q);
  while (q--) {
    int l, r;
    R(l, r);
    l--, r--;
    puts(mx[r] >= r - l + 1 ? "Yes" : "No");
  }
  return 0;
}