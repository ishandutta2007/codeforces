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

int n, a[100010];

int main() {
  scanf("%d", &n);
  REP(i, n) scanf("%d", &a[i]);
  int mx = 0;
  for (int i = 0; i < n; ) {
    int j = i;
    while (j < n - 1 && a[j] < a[j + 1]) ++j;
    mx = max(mx, j - i + 1);
    i = j + 1;
  }
  printf("%d\n", mx);
  return 0;
}