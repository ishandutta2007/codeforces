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
  int n, k;
  cin >> n >> k;
  int ans = 0;
  REPE(i, 1, n) {
    if (k + 5 * i > 240) break;
    k += 5 * i;
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}