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

int s, k;

LL a[3], t[3], p[3];
LL ans = LLONG_MAX;

int main() {
  scanf("%d%d%lld", &s, &k, &t[0]);
  a[0] = s;
  REPE(i, 1, 2) scanf("%lld%lld%lld", &a[i], &t[i], &p[i]);
  if (t[1] < t[2] || (t[1] == t[2] && p[1] > p[2])) {
    swap(a[1], a[2]);
    swap(t[1], t[2]);
    swap(p[1], p[2]);
  }
  bool ok = false;
  REP(i, 3) {
    if (s * t[i] <= k) {
      ok = true;
      break;
    }
  }
  if (!ok) {
    puts("-1");
    return 0;
  }
  if (t[0] < t[2]) {
    puts("0");
    return 0;
  }
  const int ed = (s + a[2] - 1) / a[2];
  REPE(i, 0, ed) {
    LL bts = min(LL(s), i * a[2]);
    LL rt = k - t[2] * bts;
    LL rb = s - bts;
    if (t[0] < t[1]) {
      if (t[0] * rb <= rt) ans = min(ans, i * p[2]);
    } else {
      int l = 0, r = (rb + a[1] - 1) / a[1];
      while (l <= r) {
        int m = (l + r) / 2;
        LL bb = min(rb, m * a[1]);
        LL tt = rt - bb * t[1];
        LL rr = rb - bb;
        if (rr * t[0] > tt) {
          l = m + 1;
        } else {
          ans = min(ans, i * p[2] + m * p[1]);
          r = m - 1;
        }
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}