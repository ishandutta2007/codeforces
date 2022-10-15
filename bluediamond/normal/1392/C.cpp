#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

const int N = (int) 2e5 + 7;
int n, a[N];

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int sol = 0, b = a[1];
    for (int i = 2; i <= n; i++) {
      if (a[i] < a[i - 1]) {
        sol += a[i - 1] - a[i];
      } else {
        b = max(b, a[i]);
      }
    }
    cout << sol << "\n";
  }
  return 0;
}