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

const int maxn = 1e6 + 10;
struct Segment {
  int n;
  LL t[maxn * 2];
  LL query(int p) {
    LL sum = 0;
    for (p += n; p > 1; p >>= 1)
      sum += t[p];
    return sum;
  }
  void modify(int l, int r) {
    r++;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) {
        t[l]++;
        l++;
      }
      if (r&1) {
        r--;
        t[r]++;
      }
    }
  }
} seg;
int n, k;

void update(int l, int r) {
  if (l < 0) {
    update(l + n, n - 1);
    update(0, r);
    return;
  }
  if (r >= n) {
    update(l, n - 1);
    update(0, r - n);
    return;
  }
  seg.modify(l, r);
}

int main() {
  scanf("%d%d", &n, &k);
  k = min(k, n - k);
  seg.n = n;
  int cur = 0;
  LL tot = 1;
  REP(it, n) {
    tot += 1 + seg.query(cur);
    printf("%lld%c", tot, " \n"[it == n - 1]);
    update(cur - k + 1, cur + k - 1);
    cur += k;
    if (cur >= n) cur -= n;
  }
  return 0;
}