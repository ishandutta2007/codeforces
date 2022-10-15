#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  if (k >= n * (n - 1) / 2) {
    cout << "no solution\n";
    return 0;
  }
  int variation = (int) 1e6;
  for (int i = 0; i < n; i++) {
    cout << i << " " << (int) 1e9 - i * variation << "\n";
  }
}