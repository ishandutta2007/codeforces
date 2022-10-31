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
int n, a[maxn], b[maxn];
bool v[maxn];
int main() {
  scanf("%d", &n);
  REPE(i, 1, n) scanf("%d", &a[i]);
  int one = 0;
  REPE(i, 1, n) {
    scanf("%d", &b[i]);
    one += b[i];
  }
  int ans = one % 2 == 0 ? 1 : 0;
  int cnt = 0;
  REPE(i, 1, n) if (!v[i]) {
    cnt++;
    int j = i;
    while (!v[j]) {
      v[j] = true;
      j = a[j];
    }
  }
  if (cnt != 1) ans += cnt;
  printf("%d\n", ans);
  return 0;
}