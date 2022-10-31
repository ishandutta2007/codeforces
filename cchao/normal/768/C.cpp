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

int n, k, x, a[2][1024];
int main() {
  scanf("%d%d%d", &n, &k, &x);
  REP(i, n) {
    int t;
    scanf("%d", &t);
    a[0][t]++;
  }
  int cur = 0;
  while (k--) {
    int nxt = cur ^ 1;
    int sum = 0;
    REP(i, 1024) if (a[cur][i]) {
      int aa = a[cur][i] >> 1; // less
      int bb = a[cur][i] - aa; // more
      if (sum & 1) {
        a[nxt][i ^ x] += aa;
        a[nxt][i] += bb;
      } else {
        a[nxt][i ^ x] += bb;
        a[nxt][i] += aa;
      }
      sum += a[cur][i];
      a[cur][i] = 0;
    }
    cur = nxt;
  }
  int mi = 1023, mx = 0;
  REP(i, 1024) if (a[cur][i]) {
    mi = min(mi, i);
    mx = max(mx, i);
  }
  printf("%d %d\n", mx, mi);
  return 0;
}