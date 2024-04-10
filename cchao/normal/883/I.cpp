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

const int maxn = 3e5 + 10;
PII q[maxn];
PII r[maxn];
int front = 0, tail = 0;
int n, k, a[maxn];
int f(int v, PII x) {
  return max(v - a[x.F], x.S);
}
int main() {
  scanf("%d%d", &n, &k);
  REP(i, n) scanf("%d", &a[i]);
  sort(a, a + n);
  q[tail++] = {0, 0};
  for (int i = k; i <= n; ++i) {
    if (i - k >= k) {
      PII &x = r[i - k];
      while (tail - front > 0 && x.S <= q[tail - 1].S) tail--;
      q[tail++] = x;
    }
    while (tail - front > 1 && f(a[i - 1], q[front]) >= f(a[i - 1], q[front + 1])) {
      front++;
    }
    r[i] = {i, f(a[i - 1], q[front])};
  }
  printf("%d\n", r[n].S);
  return 0;
}