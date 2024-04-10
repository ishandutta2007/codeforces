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
int v[maxn] = {};

int cnt[maxn] = {};

int main() {
  for (int i = 2; i < maxn; ++i) if (!v[i]) {
    for (int j = i; j < maxn; j += i)
      v[j] = i;
  }
  int n;
  scanf("%d", &n);
  REP(i, n) {
    int x;
    scanf("%d", &x);
    while (x > 1) {
      int t = v[x];
      cnt[t]++;
      while (x % t == 0) x /= t;
    }
  }
  int ans = max(*max_element(cnt, cnt + maxn), 1);
  printf("%d\n", ans);
  return 0;
}