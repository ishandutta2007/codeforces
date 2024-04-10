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


int n, a[33];
char s[1010];

const LL mod = 1000000007;
LL dp[1010];
int l[1010];

int main() {
  scanf("%d%s", &n, s);
  REP(i, 26) scanf("%d", &a[i]);
  REP(i, n) s[i] -= 'a';
  REP(i, n) {
    int j = i;
    int m = n;
    for(;j < n;) {
      m = min(a[s[j]], m);
      if (j - i + 1 <= m) ++j;
      else break;
    }
    l[i] = j - i;
  }
  int a2 = *max_element(l, l + n);
  int a3 = 0;
  for (int i = 0; i < n; i += l[i])
    a3++;
  dp[n] = 1;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 1; j <= l[i]; ++j) {
      dp[i] += dp[i + j];
    }
    dp[i] %= mod;
  }
  printf("%lld\n", dp[0]);
  printf("%d\n%d\n", a2, a3);
  return 0;
}