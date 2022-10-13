#include <bits/stdc++.h>
#define int long long 

using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int ans = 0;
  vector<int> fact(n + 1, 1);
  for (int i = 2; i <= n; ++i) {
    fact[i] = fact[i - 1] * i % m;
  }

  for (int len = 1; len <= n; ++len) {
    int coef = n - len + 1;
    coef = coef * coef % m;
    ans = (ans + fact[len] * fact[n - len] % m * coef) % m;
  }
  cout << ans << endl;

  return 0;
}