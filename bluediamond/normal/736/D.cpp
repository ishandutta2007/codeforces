#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = 2000 + 7;
const int M = 500000 + 7;
int n, m, x[M], y[M];
bitset<2 * N> b[N];

signed realMain() {
  cin >> n >> m;
  for (int j = 1; j <= m; j++) {
    cin >> x[j] >> y[j];
    b[x[j]][y[j]] = 1;
  }
  for (int i = 1; i <= n; i++) {
    b[i][i + n] = 1;
  }
  for (int j = 1; j <= n; j++) {
    int i = j;
    while (!b[i][j]) i++;
    swap(b[i], b[j]);
    for (int i = 1; i <= n; i++) {
      if (j != i && b[i][j]) {
        b[i] ^= b[j];
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    bool is = !b[y[i]][n + x[i]];
    if (is) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}