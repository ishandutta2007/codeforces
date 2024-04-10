#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  long long sum = 0;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  long long x = sum - 1LL * n * (n - 1) / 2;
  if (x % n == 0) {
    x /= n;
    for (int i = 0; i < n; i++) {
      cout << x + i << " ";
    }
    cout << "\n";
  } else {
    for (int i = 1; i < n; i++) {
      if ((x + i) % n == 0) {
        x = (x + i) / n;
        for (int j = 0; j < n; j++) {
          cout << x + j - (j >= n - i) << " ";
        }
        cout << "\n";
        return 0;
      }
    }
  }
  return 0;
}