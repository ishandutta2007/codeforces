#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N = (int) 5e5 + 7;
int n, m[3], mx[N][3][3], tab[N][3], ac[N], bc[N], go[N];
ll sol, pref[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  cin >> n >> m[0] >> m[1] >> m[2];
  for (int i = 1; i <= n; i++) {
    cin >> tab[i][0] >> tab[i][1] >> tab[i][2];
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (j != k) {
          mx[tab[i][j]][j][k] = max(mx[tab[i][j]][j][k], tab[i][k]);
        }
      }
    }
  }
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      if (x != y) {
        for (int i = N - 2; i >= 0; i--) {
          mx[i][x][y] = max(mx[i][x][y], mx[i + 1][x][y]);
        }
        for (int i = 0; i < N; i++) {
          mx[i][x][y]++;
        }
      }
    }
  }

  for (int a = 1; a <= m[0]; a++) {
    ac[a] = (int) 1e9;
    int l = 1, r = m[2];
    while (l <= r) {
      int c = (l + r) / 2;
      if (a >= mx[c][2][0]) {
        ac[a] = c;
        r = c - 1;
      } else {
        l = c + 1;
      }
    }
  }

  for (int b = 1; b <= m[1]; b++) {
    bc[b] = (int) 1e9;
    int l = 1, r = m[2];
    while (l <= r) {
      int c = (l + r) / 2;
      if (b >= mx[c][2][1]) {
        bc[b] = c;
        r = c - 1;
      } else {
        l = c + 1;
      }
    }
  }
  for (int a = 1; a <= m[0]; a++) {
    ac[a] = max(ac[a], mx[a][0][2]);
  }
  for (int b = 1; b <= m[1]; b++) {
    bc[b] = max(bc[b], mx[b][1][2]);
  }

  int p0 = 1, p1 = 1;
  while (ac[p0] > m[2]) p0++;
  while (bc[p1] > m[2]) p1++;


  for (int a = 0; a <= m[0]; a++) {
    mx[a][0][1] = max(mx[a][0][1], p1);
  }


  m[0] = m[0] - p0 + 1;
  for (int i = 1; i <= m[0]; i++) {
    ac[i] = ac[i + p0 - 1];
    mx[i][0][1] = mx[i + p0 - 1][0][1];
  }

  for (int i = 1; i <= m[0]; i++) {
    go[i] = mx[i][0][1];
  }

  for (int i = 1; i < N; i++) {
    pref[i] = pref[i - 1] + bc[i];
  }
  for (int a = 1; a <= m[0]; a++) {
    int l = go[a], r = m[1], first = m[1] + 1;
    while (l <= r) {
      int b = (l + r) / 2;
      int lv = max(ac[a], bc[b]);
      if (lv == ac[a]) {
        first = b;
        r = b - 1;
      } else {
        l = b + 1;
      }
    }
    ll val = 0;
    if (go[a] < first) {
      val += pref[first - 1] - pref[go[a] - 1];
    }
    if (first <= m[1]) {
      val += ac[a] * (m[1] - first + 1);
    }
    sol += (ll) (m[2] + 1) * (m[1] - go[a] + 1) - val;
  }
  cout << sol << "\n";
  return 0;
}