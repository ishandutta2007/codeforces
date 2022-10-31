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
  LL n, k;
  cin >> n >> k;
  vector<LL> a;
  for (LL i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      a.push_back(i);
      LL j = n / i;
      if (i != j) {
        a.push_back(j);
      }
    }
  }
  sort(ALL(a));
  if (k <= SZ(a)) {
    cout << a[k - 1] << endl;
  } else cout << -1 << endl;
  return 0;
}