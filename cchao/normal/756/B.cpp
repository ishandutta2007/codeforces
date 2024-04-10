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
int n;
int t[maxn];
LL c[maxn];
int main() {
  scanf("%d", &n);
  LL sum = 0;
  int j = 1, k = 1;
  REPE(i, 1, n) {
    scanf("%d", &t[i]);
    c[i] = c[i - 1] + 20;
    while (j < i && t[i] - t[j] >= 90) j++;
    while (k < i && t[i] - t[k] >= 1440) k++;
    c[i] = min(c[i], c[j - 1] + 50);
    c[i] = min(c[i], c[k - 1] + 120);
    printf("%lld\n", c[i] - sum);
    sum = c[i];
  }
  return 0;
}