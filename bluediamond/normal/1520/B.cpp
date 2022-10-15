#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int sol = 0;
    long long n;
    cin >> n;
    for (long long x = 1; x <= 9; x++) {
      long long num = x;
      while (num <= n) {
        sol++;
        num = 10 * num + x;
      }
    }
    cout << sol << "\n";
  }
}