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

const int maxn = 5e5 + 10;
int n, a[maxn];
LL sum;
map<LL, int> m;

int main() {
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  if (sum % 3) {
    puts("0");
    return 0;
  }
  sum /= 3;
  LL tmp = 0, ans = 0;
  REP(i, n - 1) {
    tmp += a[i];
    if (tmp == sum * 2)
      ans += m[sum];
    m[tmp]++;
  }
  printf("%lld\n", ans);
  return 0;
}