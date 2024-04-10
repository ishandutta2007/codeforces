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

int ans = INT_MAX;

int n, a[maxn];

vector<PII> b;

int used[13];
int cur = 0;
int t;
void f(LL h, LL w, LL x, LL y, int p = 0) {
  if (cur >= ans || cur >= t) return;
  if (h >= x) {
    int cnt = 0;
    REP(i, SZ(b)) {
      if (w >= y) break;
      REP(j, b[i].S - used[i]) {
        w *= b[i].F;
        cnt++;
        if (w >= y) break;
      }
    }
    if (w >= y) {
      t = min(t, cnt + cur);
    }
    return;
  }
  if (p == SZ(b)) return;
  used[p] = 0;
  f(h, w, x, y, p + 1);
  int tt = cur;
  REP(i, b[p].S) {
    h *= b[p].F;
    cur++;
    used[p] = i + 1;
    f(h, w, x, y, p + 1);
    if (h >= x) break;
  }
  used[p] = 0;
  cur = tt;
}

int main() {
  int A, B, h, w;
  scanf("%d%d%d%d%d", &A, &B, &h, &w, &n);
  REP(i, n) scanf("%d", &a[i]);
  sort(a, a + n, greater<int>());
  n = min(n, 34);
  map<int, int> m;
  REP(i, n) m[a[i]]++;
  for (auto it : m) {
    b.PB(it);
  }
  reverse(b.begin(), b.end());
  if (b.size() > 13) b.resize(13);
  t = INT_MAX; f(h, w, A, B); ans = min(ans, t);
  t = INT_MAX; f(h, w, B, A); ans = min(ans, t);
  printf("%d\n", ans == INT_MAX ? -1 : ans);
  return 0;
}