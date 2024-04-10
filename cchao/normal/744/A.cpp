#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;

int n, m, k;
int p[1010], s[1010];

bool special[1010];

int f(int x) { return x == p[x] ? x : p[x] = f(p[x]); }

void join(int a, int b) {
  if (special[b]) swap(a, b);
  s[a] += s[b];
  p[b] = a;
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  REPE(i, 1, n) p[i] = i, s[i] = 1;
  REP(i, k) {
    int x;
    scanf("%d", &x);
    special[x] = true;
  }
  REP(i, m) {
    int u, v;
    scanf("%d%d", &u, &v);
    int fa = f(u);
    int fb = f(v);
    if (fa != fb) join(fa, fb);
  }
  int mx = 0, core = 0;
  REPE(i, 1, n) {
    if (i == f(i)) {
      if (special[i] && s[i] > mx) {
        mx = s[i];
        core = i;
      }
    }
  }
  REPE(i, 1, n) {
    if (i == f(i) && !special[i])
      join(core, i);
  }
  LL sum = 0;
  REPE(i, 1, n) if (i == f(i)) {
    sum += 1LL * s[i] * (s[i] - 1) / 2;
  }
  printf("%lld\n", sum - m);
  return 0;
}