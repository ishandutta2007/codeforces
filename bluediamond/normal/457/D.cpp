#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
const int N = 300 + 7;
const ld INF = 1e99;
int n, m, k;
ld comb[N][N], sol, memoi[N * N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


  for (int n = 0; n < N; n++) {
    comb[n][0] = 1;
    for (int k = 1; k <= n; k++) {
      comb[n][k] = comb[n - 1][k - 1] + comb[n - 1][k];
    }
  }



  cin >> n >> m >> k;


  memoi[0] = 1;
  for (int i = 1; i <= n * n; i++) {
    memoi[i] = memoi[i - 1] * (k + 1 - i) / (m + 1 - i);
  }


  for (int a = 0; a <= n; a++) {
    for (int b = 0; b <= n; b++) {
      int cnt = n * (a + b) - a * b;
      ld cur = comb[n][a] * comb[n][b] * memoi[cnt];
      sol += cur;
      if (sol > INF) {
        cout << "1e99\n";
        return 0;
      }
    }
    cout << "\n";
  }
  cout << fixed << setprecision(9) << sol << "\n";

  /**

  generate a random n*n matrix with values from
  generate a vector of k distinct elements at random

  E = expected value of 2^(full rows + full columns)
  E = expected value of number of ways to chose a set of rows and columns so that each of them is full
  E = sum for (r, c) of Comb(n, r) * Comb(m, c) * Prob(r, c)

  Prob(r, c) = n * (r + c) - r * c elements are chosen from the k distinct ones
               the remaining (n - r) * (n - c) are chosen from the m - (n * (r + c) - r * c) remaining elements

  Prob(r, c) = k^(n * (r + c) - r * c) *

  **/



  return 0;
}