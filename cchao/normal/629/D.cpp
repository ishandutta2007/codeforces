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

int main() {
  map<LL, LL> a;
  a[0] = 0;
  int n;
  R(n);
  REP(i, n) {
    int r, h;
    R(r, h);
    LL v = 1LL * r * r * h;
    auto it = a.lower_bound(v); --it;
    LL t = a[v] = max(a[v], it->S + v);
    it = a.upper_bound(v);
    while (it != a.end() && it->S <= t) it = a.erase(it);
  }
  printf("%.12f\n", a.rbegin()->S * acos(-1));

  return 0;
}