#include <bits/stdc++.h>
using namespace std;
 
const int mod = 998244353;
 
int main()
{
  int n, k, sol = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  int maxB = (a[n - 1] - a[0]) / (k - 1);
  vector<int> ble(maxB + 2);
  vector<vector<int>> b(n + 1);
  b[0] = vector<int>(k + 1);
  b[0][0] = 1;
  for (int i = 1; i <= maxB; i++) {
    int p = 0;
    for (int j = 1; j <= n; j++) {
      while (a[p] <= a[j - 1] - i) p++;
      b[j] = b[j - 1];
      for (int l = 0; l < k; l++) {
        b[j][l + 1] = (b[j][l + 1] + b[p][l]) % mod;
        if (b[j][l + 1] == 0) break;
      }
    }
    ble[i] = b[n][k];
  }
  for (int i = 0; i <= maxB; i++)
    sol = (sol + i * (long long)(ble[i] - ble[i + 1]) + mod) % mod;
  cout << sol << endl;
  return 0;
}