#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 3123

array<i64, 2> item[maxN];
i64 f[maxN];
int n, k;
vector<int> b[maxN];
i64 answer;
void solve(int l, int r) {
  if (l == r) {
    i64 s = 0;
    for (int i = 0; i <= k; i++) {
      answer = max(answer, s + f[k - i]);
      if (i < b[l].size())
        s += b[l][i];
    }
  } else {
    i64 tmp[maxN];
    for (int i = 0; i <= k; i++)
      tmp[i] = f[i];
    int m = (l + r) / 2;
    for (int j = l; j <= m; j++) {
      for (int r = k; r >= item[j][0]; r--)
        f[r] = max(f[r], f[r - item[j][0]] + item[j][1]);
    }
    solve(m + 1, r);
    for (int i = 0; i <= k; i++)
      f[i] = tmp[i];
    for (int j = m + 1; j <= r; j++) {
      for (int r = k; r >= item[j][0]; r--)
        f[r] = max(f[r], f[r - item[j][0]] + item[j][1]);
    }
    solve(l, m);
  }
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    b[i] = vector<int>(t, 0);
    i64 s = 0;
    for (int j = 0; j < t; j++) {
      int x;
      scanf("%d", &x);
      b[i][j] = x;
      s += x;
    }
    item[i] = {t, s};
  }
  solve(0, n - 1);
  printf("%lld\n", answer);
}