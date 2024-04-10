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

const LL mx = 1000000007;

int score(LL a, LL b) {
  REPE(i, 1, 5) if ((a << i) > b) return i;
  return 6;
}
int n;
LL t[120][5];
LL ac[5];
LL diff[5];

int main() {
  scanf("%d", &n);
  REP(i, n) REP(j, 5) {
    scanf("%lld", &t[i][j]);
    ac[j] += t[i][j] >= 0;
  }
  REP(i, 5) diff[i] = (t[0][i] >= 0 ? 250 - t[0][i] : 0) - (t[1][i] >= 0 ? 250 - t[1][i] : 0);
  const int la = 5000;
  REP(it, la) {
    LL sum = 0;
    REP(i, 5) {
      LL a = ac[i];
      if (diff[i] < 0 && t[0][i] > 0) a += it;
      sum += score(a, n + it) * 2 * diff[i];
    }
    if (sum > 0) {
      printf("%d\n", it);
      return 0;
    }
  }
  puts("-1");
  return 0;
}