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
int main() {
  scanf("%d", &n);
  REP(i, n) scanf("%d", &a[i]);
  int mi = *min_element(a, a + n);
  int mx = *max_element(a, a + n);
  int ans = 0;
  REP(i, n) ans += a[i] != mi && a[i] != mx;
  printf("%d\n", ans);
  return 0;
}