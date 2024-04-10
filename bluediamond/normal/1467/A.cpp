#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "9\n";
      continue;
    }
    if (n == 2) {
      cout << "98\n";
      continue;
    }
    cout << "98";
    for (int i = 1; i <= n - 2; i++) {
      cout << ((int) 1e9 + 8 + i) % 10;
    }
    cout << "\n";
  }
}