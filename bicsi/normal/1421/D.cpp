#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#define int long long 

using namespace std;
const int dx[] = {1, 0, -1, -1, 0, 1};
const int dy[] = {1, 1, 0, -1, -1, 0};

int get(int x, int y) {
  for (int i = 0; i < 6; ++i)
    if (dx[i] == x && dy[i] == y)
      return i;
  return -1;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int tx, ty; cin >> tx >> ty;
    
    vector<int> c(6);
    for (int i = 0; i < 6; ++i) {
      cin >> c[i];
    }

    int ch = 1;
    while (ch--) {
      for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 6; ++j) {
          int x = dx[i] + dx[j];
          int y = dy[i] + dy[j];
          int z = get(x, y);
          if (z != -1 && c[z] > c[i] + c[j]) {
            c[z] = c[i] + c[j];
            ch = 1;
          }
        }
    }

    if (tx == 0 && ty == 0) {
      cout << 0 << '\n';
      continue;
    }

    long long ans = 2e18;
    for (int i = 0; i < 6; ++i) {
      if ((tx == 0) != (dx[i] == 0)) continue;
      if ((ty == 0) != (dy[i] == 0)) continue;
      if (tx == 0) {
        assert(dy[i] != 0);
        assert(ty != 0);
        int a = ty / dy[i];
        if (a > 0) {
          ans = min(ans, 1LL * c[i] * a);
        }
      } else {
        int a = tx / dx[i];
        if (a > 0 && a * dy[i] == ty) {
          ans = min(ans, 1LL * c[i] * a);
        }
      }
    } 

    for (int i = 0; i < 6; ++i) {
      for (int j = i + 1; j < 6; ++j) {
        // dx[i] * a + dx[j] * b = tx
        // dy[i] * a + dy[j] * b = ty
        int A = dx[i], B = dx[j], C = dy[i], D = dy[j];
        int det = A * D - B * C;
        if (det == 0) continue;
        int a = D * tx - B * ty; 
        int b = -C * tx + A * ty;
        if (a % det || b % det) continue;
        a /= det; b /= det;
        assert(1LL * a * dx[i] + 1LL * b * dx[j] == tx);
        assert(1LL * a * dy[i] + 1LL * b * dy[j] == ty);
        if (a < 0 || b < 0) continue;
        ans = min(ans, 1LL * c[i] * a + 1LL * c[j] * b);
      }
    }

    cout << ans << '\n';
  }

  return 0;
}