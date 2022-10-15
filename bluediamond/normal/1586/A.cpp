#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool isprime(int x) {
  if (x <= 1) return 0;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, sum = 0;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
      sum += x;
    }
    if (!isprime(sum)) {
      cout << n << "\n";
      for (int i = 1; i <= n; i++) {
        cout << i << " ";
      }
      cout << "\n";
      continue;
    }
    /// sum = 2 * k + 1 and prime => a contains an odd number => if we delete this number the sum of the rest is even and is also >= 1 + 2 => the left sum is composite

    for (int i = 0; i < n; i++) {
      if (a[i] & 1) {
        cout << n - 1 << "\n";
        for (int j = 0; j < n; j++) {
          if (i != j) {
            cout << j + 1 << " ";
          }
        }
        cout << "\n";
        break;
      }
    }
  }




  return 0;
}