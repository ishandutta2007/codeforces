#include <bits/stdc++.h>
const int N = 25;
int t, n, m;
char s[N][N];
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      s[i][j] = '0';
  for (int i = 1; i <= m; i += 2) s[1][i] = s[n][i] = '1';
  for (int i = 3; i <= n - 2; i += 2) s[i][1] = s[i][m] = '1';
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) printf("%c", s[i][j]);
    puts("");  
  }
}
int main() {
  scanf("%d", &t); while (t--) solve();
  return 0;
}