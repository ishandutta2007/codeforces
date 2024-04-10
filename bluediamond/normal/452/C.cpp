#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int N = 1000 + 7;
int n, cnt, total;
ld p[N][N];

signed main() {

/**

prob[n][cnt]

**/
  cin >> n >> cnt;

  total = n * cnt;
  p[1][1] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= min(cnt, i); j++) {
      int same = cnt - j;
      int opts = total - i;
      ld fr = (ld) same / (ld) opts;
      p[i + 1][j + 1] += p[i][j] * fr;
      p[i + 1][j] += p[i][j] * (1 - fr);
    }
  }

  ld sol = 0;
  for (int j = 1; j <= n; j++) {
    sol += p[n][j] * (ld) (j) / (ld) n;
  }
  cout << fixed << setprecision(100) << sol << "\n";

  return 0;
}
/**



**/