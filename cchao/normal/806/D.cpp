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

vector<tuple<int, int, int>> a;
const int maxn = 2020;
LL d[maxn];
const LL inf = 1e18;
int main() {
  int n;
  scanf("%d", &n);
  int t = INT_MAX;
  REP(i, n) for (int j = i + 1; j < n; ++j) {
    int x;
    scanf("%d", &x);
    a.EB(x, i, j);
    t = min(t, x);
  }
  fill(d, d + n, inf);
  LL mi = inf;
  sort(a.begin(), a.end());
  for (auto &it : a) {
    int w, u, v;
    tie(w, u, v) = it;
    if (w == t) {
      d[u] = d[v] = 0;
    }
    LL val = w * 2LL - t * 2;
    LL tu = min(d[u], min(val, (LL)w + d[v] - t));
    LL tv = min(d[v], min(val, (LL)w + d[u] - t));
    d[u] = tu, d[v] = tv;
    mi = min(mi, min(d[u], d[v]));
  }
  REP(i, n) printf("%lld\n", 1LL * (n - 1) * t + d[i]);
  return 0;
}