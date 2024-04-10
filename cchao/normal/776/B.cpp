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
int v[maxn], a[maxn];

int main() {
  for (int i = 2; i < maxn; ++i) if (!v[i])
    for (int j = i + i; j < maxn; j += i)
      v[j] = i;
  int n;
  scanf("%d", &n);
  int mx = 1;
  for (int i = 2; i <= n + 1; ++i) {
    a[i] = v[i] ? 2 : 1;
    mx = max(mx, a[i]);
  }
  printf("%d\n", mx);
  for (int i = 2; i <= n + 1; ++i)
    printf("%d%c", a[i], " \n"[i == n + 1]);
  return 0;
}