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
LL f(LL n) {
  LL ans = n;
  for (LL i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      ans = ans / i * (i - 1);
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) ans = ans / n * (n - 1);
  return ans;
}

int main() {
  LL n, k;
  cin >> n >> k;
  k = (k + 1) / 2;
  while (k-- && n > 1) {
    n = f(n);
  }
  cout << n % 1000000007 << endl;
  return 0;
}