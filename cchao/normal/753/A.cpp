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
  int n;
  scanf("%d", &n);
  vector<int> a;
  for (int i = 1; i <= n; ++i) {
    n -= i;
    a.push_back(i);
  }
  a.back() += n;
  printf("%d\n", SZ(a));
  REP(i, SZ(a))
    printf("%d%c", a[i], " \n"[i + 1 == SZ(a)]);
  return 0;
}