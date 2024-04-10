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

map<LL, int> m;
int a[40];
vector<LL> b;

int c[55];
int main() {
  for (int i = 0; i < 40; ++i)
    m[1LL << i] = i;
  int n;
  scanf("%d", &n);
  REP(i, n) {
    LL x;
    scanf("%lld", &x);
    if (m.count(x)) a[m[x]]++;
    else b.PB(x);
  }
  while (a[0]) {
    int s = 0;
    for (int i = 0; i < 40 && a[i] > 0; ++i) {
      a[i]--, s++;
    }
    c[s]++;
  }
  REP(i, 40) REP(j, a[i]) b.PB(1LL << i);
  int used = 0;
  sort(b.begin(), b.end(), greater<LL>());
  for (auto x : b) {
    bool ok = false;
    for (int i = 41; i >= 0; --i) if (c[i] && x < (1LL << i)) {
      c[i]--;
      used++;
      ok = true;
      break;
    }
    if (!ok) {
      puts("-1");
      return 0;
    }
  }
  int sum = 0;
  REP(i, 42) sum += c[i];
  int to = used + sum;

  int from = to;

  while (from > 1) {
    int x = from - 1;
    int d = to - x;
    int dd = d;
    LL gg = 0;
    REP(i, 42) {
      int take = min(d, c[i]);
      gg += 1LL * take * i;
      d -= take;
    }
    if (sum - dd >= gg) from--;
    else break;
  }
  REPE(i, from, to) printf("%d%c", i, " \n"[i == to]);
  return 0;
}