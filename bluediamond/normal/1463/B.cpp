#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
const int N = 50 + 7;
int n;
int s;
int a[N];
int b[N];

bool ok() {
  int cost = 0;
  for (int i = 1; i <= n; i++) {
    cost += abs(a[i] - b[i]);
  }
  return 2 * cost <= s;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    s = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      s += a[i];
    }
    for (int it = 0; it <= 1; it++) {
      for (int i = 1; i <= n; i++) {
        if (i % 2 == it) {
          b[i] = a[i];
        } else {
          b[i] = 1;
        }
      }
      if (ok()) {
        for (int i = 1; i <= n; i++) {
          cout << b[i] << " ";
        }
        cout << "\n";
        break;
      }
    }
  }

}