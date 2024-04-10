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

const int maxn = 2e5 + 10;
int c[maxn], t[maxn], n;

int main() {
  scanf("%d", &n);
  REP(i, n) scanf("%d%d", &c[i], &t[i]);

  LL a = LLONG_MIN;
  LL b = LLONG_MAX;
  LL d = 0;
  REP(i, n) {
    if (t[i] == 1) {
      // x+d >= 1900
      a = max(a, 1900 - d);
    } else {
      // x+d <= 1899
      b = min(b, 1899 - d);
    }
    d += c[i];
  }
  if (a > b) puts("Impossible");
  else if (b == LLONG_MAX) puts("Infinity");
  else cout << b + d << endl;
  return 0;
}