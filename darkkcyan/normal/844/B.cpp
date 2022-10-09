#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  int a[n][m];
  for (int i = -1; ++ i < n; ) for (int f = -1; ++f < m; ) cin >> a[i][f];
  long long ans = 0;
  for (int i = -1; ++ i < n; ) {
    int c[2] = {0};
    for (int f = -1; ++ f < m;) c[a[i][f]] ++;
    ans += (1LL << c[0]) + (1LL << c[1]) - 2;
  }
  for (int i = -1; ++ i < m; ) {
    int c[2] = {0};
    for (int f = -1; ++ f < n; ) c[a[f][i]] ++;
    if (c[0] > 1) ans += (1LL << c[0]) - 1 - c[0];
    if (c[1] > 1) ans += (1LL << c[1]) - 1 - c[1];
  }
  cout << ans;
  return 0;
}