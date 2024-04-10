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

int n, k, a[200000];

int main() {
  scanf("%d%d", &n, &k);
  REPE(i, 1, n) {
    scanf("%d", &a[i]);
    a[i] += a[i - 1];
  }
  int sum = INT_MAX, ans = 0;
  for (int i = 1; i + k - 1 <= n; ++i) {
    if (a[i + k - 1] - a[i - 1] < sum) {
      sum = a[i + k - 1] - a[i - 1];
      ans = i;
    }
  }
  printf("%d\n", ans);
  return 0;
}