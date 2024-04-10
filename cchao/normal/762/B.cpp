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

int main() {
  int a, b, c, n;
  vector<int> u, p;
  scanf("%d%d%d%d", &a, &b, &c, &n);
  REP(i, n) {
    int x;
    static char s[12];
    scanf("%d%s", &x, s);
    if (s[0] == 'U') u.PB(x);
    else p.PB(x);
  }
  sort(ALL(u));
  sort(ALL(p));
  vector<int> r;
  for (int i = a; i < SZ(u); ++i) r.PB(u[i]);
  for (int i = b; i < SZ(p); ++i) r.PB(p[i]);
  sort(ALL(r));
  LL ans = 0;
  int cnt = 0;
  REP(i, min(a, SZ(u))) ans += u[i], ++cnt;
  REP(i, min(b, SZ(p))) ans += p[i], ++cnt;
  REP(i, min(c, SZ(r))) ans += r[i], ++cnt;
  printf("%d %lld\n", cnt, ans);
  return 0;
}