#include <bits/stdc++.h>

using namespace std;

#define int long long

int func(int n, int k) {
  if (k == 0 || n <= 1) return 0;
  return 2 * (n - 1) - 1 + func(n - 2, k - 1);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, k, sol = 0;
  cin >> n >> k;
  cout << func(n, k) << "\n";
  return 0;
}