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
int n, k;
LL a[maxn];

int main() {
  scanf("%d%d", &n, &k);
  REP(i, n) scanf("%lld", &a[i]);
  sort(a, a + n);
  LL ans = 0;
  for (int i = 1; i < n; ++i) {
    LL d = a[i] - a[0];
    if (d % k) {
      puts("-1");
      return 0;
    }
    ans += d / k;
  }
  printf("%lld\n", ans);
  return 0;
}