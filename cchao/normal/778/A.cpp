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

const int maxn = 2e5 + 10;

char s[maxn], t[maxn];
int n, m, a[maxn], p[maxn];

bool ok(int x) {
  int j = 0;
  REP(i, n) if (p[i] >= x && s[i] == t[j]) j++;
  return j == m;
}

int main() {
  scanf("%s%s", s, t);
  n = strlen(s);
  m = strlen(t);
  REP(i, n) {
    scanf("%d", &a[i]);
    p[a[i] - 1] = i;
  }
  int l = 1, r = n, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) ans = mid, l = mid + 1;
    else r = mid - 1;
  }
  printf("%d\n", ans);
  return 0;
}