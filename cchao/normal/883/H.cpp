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

int n;
char s[500010];
int cnt[128];

int sol1() {
  int odd = 0, even = 0;
  REP(i, 128) {
    odd += cnt[i] & 1;
    even += cnt[i] >> 1;
  }
  if (odd == 0) {
    even -= 1;
    odd += 2;
  }
  for (int i = odd; even >= 0; i += 2, even -= 1) {
    if (even % i == 0) {
      return i;
    }
  }
  return INT_MAX;
}
int sol2() {
  int t = 0;
  REP(i, 128) {
    t += cnt[i] >> 1;
  }
  REPE(i, 1, n) {
    if (t % i == 0) {
      return i;
    }
  }
  return INT_MAX;
}

void f(int o, int x) {
  int len = n / x;
  printf("%d\n", x);
  while (x--) {
    char cen = 0;
    if (o == 1) {
      REP(i, 128) {
        if (cnt[i] & 1) {
          cnt[i]--;
          cen = i;
          break;
        }
      }
      if (!cen) {
        REP(i, 128) {
          if (cnt[i]) {
            cnt[i]--;
            cen = i;
            break;
          }
        }
      }
    }
    int v[128] = {}, rem = len - o;
    REP(i, 128) {
      while (rem > 0 && cnt[i] > 1) {
        rem -= 2;
        cnt[i] -= 2;
        v[i]++;
      }
    }
    REP(i, 128) REP(j, v[i]) putchar(i);
    if (cen) putchar(cen);
    for (int i = 127; i >= 0; --i) REP(j, v[i]) putchar(i);
    putchar(x == 0 ? '\n' : ' ');
  }
}

int main() {
  scanf("%d%s", &n, s);
  REP(i, n) cnt[s[i]]++;
  bool odd = false;
  REP(i, 128) {
    if (cnt[i] & 1) {
      odd = true;
    }
  }
  int t1 = sol1(), t2 = INT_MAX;
  sol1();
  if (!odd)
    t2 = sol2();
  if (t1 < t2) f(1, t1);
  else f(0, t2);
  return 0;
}