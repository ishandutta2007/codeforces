#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 /// freopen ("input", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (n % 2 == 0 && n >= 2 * k) {
      cout << "YES\n";
      for (int i = 1; i < k; i++) {
        cout << 2 << " ";
      }
      cout << n - 2 * (k - 1) << "\n";
      continue;
    }
    if ((n - k) % 2 == 0 && n >= k) {
      cout << "YES\n";
      for (int i = 1; i < k; i++) {
        cout << 1 << " ";
      }
      cout << n - (k - 1) << "\n";
      continue;
    }
    cout << "NO\n";
  }
  return 0;
}