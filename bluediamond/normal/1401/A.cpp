#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k, init;
    cin >> n >> k;
    init = n;
    if (n % 2 != k % 2) {
      n++;
    }
    if (n < k) {
      n = k;
    }
    cout << n - init << "\n";
  }
  return 0;
}