#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int fen1[200002];

void upd1(int pos, int val) {
  for ( ; pos <= 200000; pos |= (pos + 1))
    fen1[pos] += val;
}

int fnd1(int pos) {
  int ret = 0;
  for ( ; pos >= 0; pos = (pos & (pos + 1)) - 1)
    ret += fen1[pos];
  return ret;
}

int fen2[200002];

void upd2(int pos, int val) {
  for ( ; pos >= 0; pos = (pos & (pos + 1)) - 1)
    fen2[pos] += val;
}

int fnd2(int pos) {
  int ret = 0;
  for ( ; pos <= 200000; pos |= (pos + 1))
    ret += fen2[pos];
  return ret;
}

int now[200002];

int main() {
  int n, k, a, b, q;
  scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int d, aa;
      scanf("%d%d", &d, &aa); --d;

      int add = max(0, min(aa, b - now[d]));
      upd1(d, add);

      add = max(0, min(aa, a - now[d]));
      upd2(d, add);

      now[d] += aa;
    } else {
      int p;
      scanf("%d", &p); --p;
      int ans = fnd1(p - 1) + fnd2(p + k);
      printf("%d\n", ans);
    }
  }
  return 0;
}