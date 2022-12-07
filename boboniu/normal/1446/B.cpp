#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 5123

int chose[maxN][maxN], ans;
char s[maxN], t[maxN];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  scanf("%s%s", s + 1, t + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      chose[i][j] = max({max(0, chose[i - 1][j - 1]) + 4 * (s[i] == t[j]) - 2,
                         chose[i - 1][j] - 1, chose[i][j - 1] - 1});
      ans = max(ans, chose[i][j]);
    }
  }
  printf("%d\n", ans);
}