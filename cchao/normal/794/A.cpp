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

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  int n, x, ans = 0;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &x);
    ans += x > b && x < c;
  }
  printf("%d\n", ans);
  return 0;
}