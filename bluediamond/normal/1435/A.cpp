#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n / 2; i++) {
      int x, y;
      cin >> x >> y;
      cout << -y << " " << x << " ";
    }
    cout << "\n";
  }
}