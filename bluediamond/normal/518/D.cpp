#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
const int N = 2000 + 7;
int n, t;
ld prob, p[N][N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  cin >> n >> prob >> t;
  p[0][0] = 1;
  for (int i = 1; i <= t; i++) {
    p[i][0] = p[i - 1][0] * (1 - prob);
    for (int j = 1; j < n; j++) {
      p[i][j] = p[i - 1][j] * (1 - prob) + p[i - 1][j - 1] * prob;
    }
    p[i][n] = p[i - 1][n] + p[i - 1][n - 1] * prob;
  }
  ld e = 0, sol = 0;
  for (int j = 1; j <= n; j++) {
    sol += p[t][j] * j;
  }
  cout << fixed << setprecision(6) << sol << "\n";
}