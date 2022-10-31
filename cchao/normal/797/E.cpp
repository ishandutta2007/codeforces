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

int n, a[100010];
const int m = 350;
int b[100010][m + 1];
int main() {
  scanf("%d", &n);
  REPE(i, 1, n) scanf("%d", &a[i]);
  for (int i = n; i >= 1; --i) {
    REPE(j, 1, m) {
      int t = i + a[i] + j;
      b[i][j] = 1 + (t > n ? 0 : b[t][j]);
    }
  }
  int q;
  scanf("%d", &q);
  while (q-- > 0) {
    int p, k;
    scanf("%d%d", &p, &k);
    if (k <= m) {
      printf("%d\n", b[p][k]);
    } else {
      int ans = 0;
      while (p <= n) {
        p = p + a[p] + k;
        ans++;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}