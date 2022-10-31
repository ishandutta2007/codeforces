#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;
int n, q, a[110];
int main() {
  cin >> n >> q;
  while (q--) {
    int t, k, d;
    cin >> t >> k >> d;
    int avai = 0;
    REPE(i, 1, n) if (a[i] <= t) avai++;
    if (avai < k) {
      puts("-1");
      continue;
    }
    int sum = 0;
    REPE(i, 1, n) if (a[i] <= t) {
      sum += i;
      a[i] = t + d;
      if (--k == 0) break;
    }
    printf("%d\n", sum);
  }
  return 0;
}