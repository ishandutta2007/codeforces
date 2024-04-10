#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    if (n <= 2) {
      cout << "1\n";
    } else {
      cout << (n - 3) / x + 2 << "\n";
    }
  }
}