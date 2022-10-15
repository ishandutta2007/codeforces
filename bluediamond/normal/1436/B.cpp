#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool prie(int x) {
  if (x <= 1) return 0;
  for (int i = 2; i * i <= x; i++) if (x % i == 0) return 0;
  return 1;
}


signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int x = 1;
    while (prie(x) || !prie(x + n - 1)) {
      x++;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j) cout << x << " ";
        else cout << "1 ";
      }
      cout << "\n";
    }
  }


}