#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 300 + 7;
int n, k, a[N][N], r[N], c[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = 0;
      }
    }
    int x = k / n, e = k % n;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < i + x; j++) {
        a[i][j % n] = 1;
      }
    }
    for (int i = 0; i < e; i++) {
      a[i][(i + x) % n] = 1;
    }
    for (int i = 0; i < n; i++) {
      r[i] = c[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        r[i] += a[i][j];
        c[j] += a[i][j];
      }
    }
    int mn = r[0], mx = r[0], sol = 0;
    for (int i = 0; i < n; i++) {
      mn = min(mn, r[i]);
      mx = max(mx, r[i]);
    }
    sol += (mx - mn) * (mx - mn);
    mn = c[0];
    mx = c[0];
    for (int i = 0; i < n; i++) {
      mn = min(mn, c[i]);
      mx = max(mx, c[i]);
    }
    sol += (mx - mn) * (mx - mn);
    cout << sol << "\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << a[i][j];
      }
      cout << "\n";
    }
  }
  return 0;
}