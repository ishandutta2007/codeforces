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

const int maxn = 1e5 + 10;
int n, c[2];
int b[maxn], p[maxn], t[maxn];

char s[4];

vector<PII> v[2];

int ans = 0;

void f(vector<PII> &v, int coin) {
  vector<PII> a;
  int mx = 0;
  for (auto x : v) {
    auto it = upper_bound(a.begin(), a.end(), PII(coin - x.F, INT_MAX));
    if (it != a.begin()) {
      --it;
      ans = max(ans, x.S + it->S);
    }
    mx = max(mx, x.S);
    a.EB(x.F, mx);
  }
}

int main() {
  scanf("%d%d%d", &n, &c[0], &c[1]);
  int aa[2] = {};
  REP(i, n) {
    scanf("%d%d%s", &b[i], &p[i], s);
    t[i] = s[0] == 'C' ? 0 : 1;
    if (p[i] <= c[t[i]]) {
      aa[t[i]] = max(aa[t[i]], b[i]);
      v[t[i]].EB(p[i], b[i]);
    }
  }
  if (aa[0] && aa[1]) ans = aa[0] + aa[1];
  REP(i, 2) {
    sort(ALL(v[i]));
    f(v[i], c[i]);
  }
  printf("%d\n", ans);
  return 0;
}