#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 50;
int n, m, a[N][N];

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


  cin >> n >> m;
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
  ll ret = 0;
  for (int i = 0; i < n; i++) {
    int x = 0, y = 0;
    for (int j = 0; j < m; j++) x += a[i][j], y += 1 - a[i][j];
    ret += (1LL << x) - 1 + (1LL << y) - 1;
  }
  for (int j = 0; j < m; j++) {
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) x += a[i][j], y += 1 - a[i][j];
    ret += (1LL << x) - 1 + (1LL << y) - 1;
  }
  ret -= n * m;
  cout << ret << "\n";

}