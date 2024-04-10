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

const int maxn = 2e5 + 10;
int n, s[maxn], g[maxn], ans[maxn];
PII a[maxn];
int main() {
  scanf("%d", &n);
  REP(i, n) scanf("%d%d", &s[i], &g[i]);
  int l = s[0], r = s[0] + g[0];
  REP(i, n) {
    l--, r++;
    l = max(l, s[i]);
    r = min(r, s[i] + g[i]);
    a[i] = {l, r};
    if (l > r) {
      puts("-1");
      return 0;
    }
  }
  l = r;
  for (int i = n - 1; i>= 0; --i) {
    l = max(l, a[i].F);
    r = min(r, a[i].S);
    ans[i] = r;
    l = r = ans[i];
    l--, r++;
  }
  LL sum = 0;
  REP(i, n) sum += ans[i] - s[i];
  printf("%lld\n", sum);
  REP(i, n) printf("%d%c", ans[i], " \n"[i == n - 1]);
  return 0;
}