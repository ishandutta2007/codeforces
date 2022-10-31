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

int p[maxn];

int f(int x) {
  if (x == p[x]) return x;
  return p[x] = f(p[x]);
}

void uni(int a, int b) {
  int fa = f(a), fb = f(b);
  if (fa != fb) {
    p[fa] = fb;
  }
}

int main() {
  int n; R(n);
  REP(i, n) p[i] = i;
  REP(i, n) {
    int j;
    R(j);
    --j;
    uni(i, j);
  }
  unordered_map<int, int> m;
  REP(i, n) m[f(i)]++;
  vector<int> a;
  for (const auto &it : m) a.PB(it.S);
  sort(a.begin(), a.end(), greater<int>());
  LL ans = 0;
  for (auto x : a) {
    ans += 1LL * x * x;
  }
  if (SZ(a) >= 2) {
    ans += 2LL * a[0] * a[1];
  }
  printf("%lld\n", ans);

  return 0;
}