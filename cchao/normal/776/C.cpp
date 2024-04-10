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

LL p[maxn];
int sz = 0;
LL s[maxn];
int n; LL k;

LL inf = 1e14;
vector<LL> f;

int main() {
  scanf("%d%lld", &n, &k);
  REPE(i, 1, n) {
    int x;
    scanf("%d", &x);
    s[i] = x + s[i - 1];
  }
  for (LL i = 1; llabs(i) <= inf; ) {
    f.push_back(i);
    i *= k;
    if (i == 1) break;
  }
  map<LL, int> mp;
  mp[0]++;
  LL ans = 0;
  REPE(i, 1, n) {
    for (auto &x : f) {
      LL t = s[i] - x;
      if (mp.count(t)) ans += mp[t];
    }
    mp[s[i]]++;
  }
  printf("%lld\n", ans);

  return 0;
}