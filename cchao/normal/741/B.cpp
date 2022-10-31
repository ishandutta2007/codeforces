#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;
typedef long long LL;

int p[1010];
int f(int x) { return x == p[x] ? x : p[x] = f(p[x]); }
LL w[1010], v[1010];
int n, m; LL s;
vector<int> l[1010];
LL dp[1010], t[1010][1010];

void f(vector<int> &l) {
  vector<pair<LL, LL>> b;
  LL sw = 0, sv = 0;
  for (auto x : l) {
    sw += w[x];
    sv += v[x];
    b.emplace_back(w[x], v[x]);
  }
  b.emplace_back(sw, sv);
  int sz = 0;
  for (auto x : b) {
    if (x.first > s) continue;
    for (int i = s; i >= 0; --i) {
      t[sz][i] = dp[i];
      if (i >= x.first) t[sz][i] = max(t[sz][i], dp[i - x.first] + x.second);
    }
    sz++;
  }
  REP(i, sz) REPE(j, 0, s) dp[j] = max(dp[j], t[i][j]);
}

int main() {
  scanf("%d%d%lld", &n, &m, &s);
  REP(i, n) p[i] = i;
  REP(i, n) scanf("%lld", &w[i]);
  REP(i, n) scanf("%lld", &v[i]);
  REP(i, m) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x, --y;
    int fa = f(x);
    int fb = f(y);
    if (fa == fb) continue;
    p[fb] = fa;
  }
  REP(i, n) {
    l[f(i)].push_back(i);
  }
  REP(i, n) if (l[i].size())
    f(l[i]);
  cout << dp[s] << endl;
  return 0;
}