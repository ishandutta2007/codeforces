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

LL f(LL n, LL l, LL r) {
  if (l > r) return 0;
  if (n <= 1) return n;
  LL x = 1;
  while (x <= n) x += x;
  x = (x >> 1) - 1;
  LL ret = 0;
  if (l <= x) ret += f(n >> 1, l, min(r, x));
  if (l <= x + 1 && r >= x + 1) ret += n & 1;
  if (r > x + 1) {
    ret += f(n >> 1, max(1LL, l - (x + 1)), r - (x + 1));
  }
  return ret;
}

int main() {
  LL n, l, r;
  cin >> n >> l >> r;
  cout << f(n, l, r) << endl;
  return 0;
}