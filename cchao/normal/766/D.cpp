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

int n, m, q;
const int maxn = 1e5 + 10;
char s[24], t[24];
map<string, int> mp;

int p[maxn * 2];
int f(int x) { return x == p[x] ? x : p[x] = f(p[x]); }

int main() {
  scanf("%d%d%d", &n, &m, &q);
  REP(i, n) {
    scanf("%s", s);
    mp[s] = i + i;
  }
  n += n;
  REP(i, n) p[i] = i;
  REP(i, m) {
    int r, a, b;
    scanf("%d%s%s", &r, s, t);
    a = mp[s];
    b = mp[t];
    if (r == 1) {
      if (f(a + 1) == f(b)) puts("NO");
      else {
        puts("YES");
        p[f(a)] = f(b);
        p[f(a+1)] = f(b+1);
      }
    } else {
      if (f(a) == f(b)) puts("NO");
      else {
        puts("YES");
        p[f(a + 1)] = f(b);
        p[f(b + 1)] = f(a);
      }
    }
  }
  while (q--) {
    scanf("%s%s", s, t);
    int a = mp[s];
    int b = mp[t];
    if (f(a) == f(b)) {
      puts("1");
    } else if (f(a + 1) == f(b)) {
      puts("2");
    } else puts("3");
  }
  return 0;
}