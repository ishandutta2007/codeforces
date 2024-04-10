#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

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

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

#define job(a) a = add(a, val)

int ret;
int rows, n, a[257][257], copa[257][257];
int dp[15][1 << 15][2][2], nw[1 << 15][2][2];

signed realMain() {
  cin >> rows >> n;
  for (int i = 0; i < rows; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) {
      a[i][j] = (s[j] == 'x');
    }
  }
  if (n > rows) {
    swap(n, rows);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < n; j++) {
        copa[i][j] = a[j][i];
      }
    }
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = copa[i][j];
      }
    }
  }
  dp[0][0][0][0] = 1;
  for (int r = 0; r < rows; r++) {
    for (int i = 0; i <= n; i++) {
      for (int mask = 0; mask < (1 << n); mask++) {
        for (int sus = 0; sus <= 1; sus++) {
          for (int cnt = 0; cnt <= 1; cnt++) {
            if (!dp[i][mask][sus][cnt]) continue;
            int val = dp[i][mask][sus][cnt];
            if (i < n) { /// propagate to next row
              if (a[r][i]) {
                job(dp[i + 1][mask & ((1 << n) - 1 - (1 << i))][0][cnt]);
              } else {
                /// don't place
                int protejat = (sus || (mask & (1 << i)));
                if (!protejat + cnt <= 1) job(dp[i + 1][mask][sus][cnt + !protejat]);
                /// place
                job(dp[i + 1][mask | (1 << i)][1][cnt]);
              }
            } else { /// propagate to next col
              job(nw[mask][0][cnt]);
            }
            dp[i][mask][sus][cnt] = 0;
          }
        }
      }
    }
    ret = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
      for (int sus = 0; sus <= 1; sus++) {
        for (int cnt = 0; cnt <= 1; cnt++) {
          dp[0][mask][sus][cnt] = nw[mask][sus][cnt];
          ret = add(ret, nw[mask][sus][cnt]);
          nw[mask][sus][cnt] = 0;
        }
      }
    }
  }
  cout << ret << "\n";
  return 0;
}