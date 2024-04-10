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

int n, a[3010];
int main() {
  cin >> n;
  REP(i, n) cin >> a[i];
  sort(a, a + n);
  LL ans = 0;
  REP(i, n) if (i) {
    if (a[i] <= a[i - 1]) {
      LL t = a[i - 1] + 1 - a[i];
      a[i] += t;
      ans += t;
    }
  }
  cout << ans << endl;
  return 0;
}