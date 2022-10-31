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

const int maxn = 1e5 + 10;
int n, l, r, a[maxn], b[maxn], c[maxn];

int main() {
  scanf("%d%d%d", &n, &l, &r);
  REP(i, n) scanf("%d", &a[i]);
  REP(i, n) scanf("%d", &c[i]);
  vector<PII> v(n);
  REP(i, n) v[i] = {c[i], i};
  sort(v.begin(), v.end());
  int cur = INT_MIN;
  for (auto it : v) {
    const int i = it.S;
    int lb = l - a[i], ub = r - a[i];
    lb = max(lb, cur + 1);
    if (lb > ub) {
      puts("-1");
      return 0;
    }
    b[i] = lb + a[i];
    cur = lb;
  }
  REP(i, n) printf("%d%c", b[i], " \n"[i == n - 1]);
  return 0;
}