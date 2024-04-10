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

LL solve() {
  LL x, y, p, q;
  scanf("%lld%lld%lld%lld", &x, &y, &p, &q);
  if (x < y && p == q) return -1;
  if (x && p == 0) return -1;
  LL l = 1, r = 2e9, ans = -1;
  while (l <= r) {
    LL m = (l + r) >> 1;
    LL a = p * m;
    LL b = q * m;
    if (a >= x && b >= y && a - x <= b - y) ans = b - y, r = m - 1;
    else l = m + 1;
  }
  return ans;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int kase = 1; kase <= T; ++kase) {
    printf("%lld\n", solve());
  }
  return 0;
}