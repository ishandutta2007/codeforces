#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 200 + 7;
int n1;
int n2;
int n3;
int a[N];
int b[N];
int c[N];
ll dp[N][N][N];

int main() {
 // ios::sync_with_stdio(0);
 // cin.tie(0);
  cin >> n1 >> n2 >> n3;
  for (int i = 1; i <= n1; i++) cin >> a[i];
  for (int i = 1; i <= n2; i++) cin >> b[i];
  for (int i = 1; i <= n3; i++) cin >> c[i];
  sort(a + 1, a + n1 + 1);
  sort(b + 1, b + n2 + 1);
  sort(c + 1, c + n3 + 1);
  ll sol = 0;
  for (int i = 0; i <= n1; i++) {
    for (int j = 0; j <= n2; j++) {
      for (int k = 0; k <= n3; k++) {
        ll x = 0;
        if (i >= 1 && j >= 1) x = max(x, dp[i - 1][j - 1][k] + a[i] * b[j]);
        if (i >= 1 && k >= 1) x = max(x, dp[i - 1][j][k - 1] + a[i] * c[k]);
        if (j >= 1 && k >= 1) x = max(x, dp[i][j - 1][k - 1] + b[j] * c[k]);
        dp[i][j][k] = x;
        sol = max(sol, x);
      }
    }
  }
  cout << sol << "\n";
  return 0;
}
/**
**/